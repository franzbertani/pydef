import re
from collections import namedtuple

import networkx as nx
from headergen import Header

Variable = namedtuple("Variable", "name type")
Dependency = namedtuple("Dependency", "task_id dependency_type condition")
Task = namedtuple("Task", "id in_set output e_bc e_wc apps")

variable_struct_template = "templates/variable_struct_template.c"
return_template = "templates/return_template.c"
tasks_array = "templates/tasks_array_template.c"
task_struct_template = "templates/tasks_struct_define.c"
task_enabler_template = "templates/task_enabler.c"
task_tput_update_template = "templates/tput_update.c"
extern_variables_template = "templates/extern_variables_template.c"


class Tasks:
    """A class to store set of tasks"""

    def __init__(self):
        self.tasks_dict = {}
        self.tasks_graph = nx.DiGraph()

    def get_tasks_dict(self):
        return self.tasks_dict

    def get_tasks_graph(self):
        return self.tasks_graph

    def set_apps_dict(self, apps_dict):
        self.apps_dict = apps_dict
        self.sorted_app_id_list = [x[0] for x in sorted(self.apps_dict.items(), key=lambda x: x[1].x_min, reverse=False)]


    def check_task_consistency(self, new_task):
        """Check if the new task is compatible with the existing ones.

        Parameters
        ----------

        new_taks: collections.namedtuple Task
            the Task named tuple of the new task

        Returns
        -------

        bool
            True if the task has been succesfully added, False otherwise
        """
        if new_task.id in self.tasks_dict:
            print("ERROR: tasks id must be unique (%s)" % (new_task.id))
            return False
        identifier_pattern = re.compile("^[a-zA-Z_][a-zA-Z0-9_]*$")
        if not identifier_pattern.match(new_task.output.name):
            print("ERROR: invalid C variable identifier (%s)"
                  % (new_task.output.name))
            return False
        return True

    def check_dependencies_consistency(self):
        """Check if the task list is consistent.

        It checks if all the in set of tasks are variables
        produced by existing tasks.

        Returns
        -------
        bool
        """
        for task_id, task_props in self.tasks_dict.items():
            task_dependencies = (dep.task_id for dep in task_props.in_set)
            for dep_id in task_dependencies:
                if dep_id not in self.tasks_dict:
                    print("ERROR: unsatisfied dependency %s -> %s" %
                          (dep_id, task_id))
                    return False
        return True

    def get_task_condition(self, in_task, dep_type):
        if(dep_type.startswith("w")): #TODO fix with a regex
            return "var_struct_%s.write_count >= %s" %(in_task,dep_type.split("w")[1])
        else:
            return "1"

    def build_tasks_dict(self, config_dict):
        """It creates the task dictionary from the config dictionary

        Parameters
        ----------

        config_dict : dict
            configuration dictionary as produced by `read_yaml_file` function
        """
        self.config_dict = config_dict
        for task in config_dict["TASKS"]:
            apps_list = []
            for app in config_dict.get("APPLICATIONS", []):
                if task["id"] in app.get("tasks", []):
                    apps_list.append(app["id"])
            new_task = Task(
                id=task["id"],
                in_set=[Dependency(
                    task_id=dep["task_id"],
                    dependency_type=["dependency_type"],
                    condition=self.get_task_condition(
                        dep["task_id"],
                        dep["dependency_type"])
                    ) for dep in task["in_set"]],
                output=Variable(**task["output"]),
                e_bc=int(task["e_bc"]),
                e_wc=int(task["e_wc"]),
                apps=apps_list)
            if(self.check_task_consistency(new_task)):
                self.tasks_dict[new_task.id] = new_task
            else:
                print("WARN: skipped task %s" % (new_task.id))

    def build_tasks_graph(self):
        """Builds a networkx graph from the task dictionary

        It must be used AFTER `build_task_dict`
        """
        for task_id in self.tasks_dict:
            self.tasks_graph.add_node(task_id)
        for task_id, task_props in self.tasks_dict.items():
            self.tasks_graph.add_edges_from(
                [(dep.task_id, task_id) for dep in task_props.in_set])

    def add_tasks_signatures(self, header):
        for task_id in self.tasks_dict:
            header.add_line("void %s();" %(task_id,))

    def add_tasks_variables_declarations(self, header):
        """Generates the header define to declare tasks variables

        Parameters
        ----------

        header : Header
            an Header object
        """
        declarations_list = []
        var_template = ""
        with open(variable_struct_template, "r") as template_file:
            var_template = template_file.read().replace("\n", "\t\\\n\t")
        for task_id, task_props in self.tasks_dict.items():
            versions_count = task_props.output.type.split(" ")[1] if(len(task_props.output.type.split(" ")) > 1) else "1"
            task_struct = (var_template
                           .replace("TASK", task_id)
                           .replace("TYPE", task_props.output.type.split(" ")[0])
                           .replace("VERSIONS_COUNT", versions_count))
            header.add_define((task_id + "_output_var", task_struct))
            declarations_list.append(task_id + "_output_var")
        header.add_define(("DECLARE_OUTPUT_VARIABLES",
                           "\t\\\n\t".join(declarations_list)))

    def add_tasks_begin_declarations(self, header):
        """Generates the header define to begin a task based on tasks dict

        Parameters
        ----------

        header : Header
            an Header object
        """
        for task in self.tasks_dict:
            define_key = "BEGIN_TASK_%s" % (task)
            define_value = []
            signature_string = "void %s(){" % (task)
            define_value.append(signature_string)
            for dep in self.tasks_dict[task].in_set:
                define_value.append(
                    header.get_var_declaration_string(
                        self.tasks_dict[dep.task_id].output.type.split(" ")[0],
                        dep.task_id,
                        "g_%s" % (dep.task_id)))
            define_value.append(
                'siren_command("START_CCOUNT: task\\n");')
            header.add_define((define_key, "\t\\\n\t".join(define_value)))

    def add_tasks_end(self, header):
        """Generates the header define to end a task based on tasks dict

        Parameters
        ----------

        header : Header
            an Header object
        """
        header.add_define(("END_TASK", "}\n"))

    def add_deadline_restore(
            self, task_id, father_id=None, updating_children=False,
            subtract_exec_time=False, exec_time_var_name="delta_cycles"):
        """Generates a string with C instructions to restore task deadlines.

        Deadlines are updated on task exit as follows:
        1. if the task has no father then the deadline is reset to twice
            the app deadline, otherwise it is reset to the father's old value;
        2. the deadline of enabled children is set to father's old value;
        3. the task execution time is subtracted to *all* the deadlines.

        This function produces C code to take care of point 1 or 2,
        depending on `updating_children` argument value.
        Point 3 is in charge of scheduler C firmware.

        Parameters
        ----------

        task_id : str
            the id of the task whose deadline we are restoring.
        father_id: str
            the name of task_id father (default value is None, meaning that you
            are the first task of an app.
        subtract_exec_time: boolean
            if set to True then `exec_time_var_name` is subtracted to the
            deadline (default value is False).
        exec_time_var_name: str
            the identifier of the variable storing the execution cycles in C
            firmware (default value is "delta_cycles").

        Returns
        _______

        deadline_string: str
            a string representing an header define that stores the code to
            properly update the deadline.
        """
        version = "!task_struct_%s.deadlineVersion & 0x1" % (
            father_id,)  # old version
        # if(updating_children):
        #     version = "!task_struct_%s.deadlineVersion & 0x1" %(father_id,)#old version
        # else:
        #     version = "task_struct_%s.deadlineVersion" %(father_id,)#current version

        app_list_iter = iter(sorted(
            self.tasks_dict[task_id].apps, key=lambda x: self.apps_dict[x].x_min, reverse=False))
        app_id = next(app_list_iter)

        # your father is in your app
        if(father_id and (set(self.tasks_dict[father_id].apps) & set(self.tasks_dict[task_id].apps))):
            # TODO: probably does not work with apps with shared tasks
            new_deadline = "task_struct_%s.deadline[%s]" % (father_id, version)
            if(subtract_exec_time):
                new_deadline += " -%s" % (exec_time_var_name,)
        else:
            new_deadline = 2*self.apps_dict[app_id].x_min
            if(subtract_exec_time):
                new_deadline = str(new_deadline) + \
                    " -%s" % (exec_time_var_name,)

        deadline_string = "if(app_struct_%s.isActive[app_struct_%s.isActiveVersion]) { task_struct_%s.deadline[!task_struct_%s.deadlineVersion & 0x1] = %s; task_struct_%s.deadlineVersion = !task_struct_%s.deadlineVersion & 0x1;}" % (
            app_id, app_id, task_id, task_id, new_deadline, task_id, task_id)

        for app_id in app_list_iter:
            # your father is in your app
            if(father_id and (set(self.tasks_dict[father_id].apps) & set(self.tasks_dict[task_id].apps))):
                # TODO: probably does not work with apps with shared tasks
                new_deadline = "task_struct_%s.deadline[%s]" % (
                    father_id, version)  # previous father's deadline
                if(subtract_exec_time):
                    new_deadline += " -%s" % (exec_time_var_name,)
            else:
                new_deadline = 2*self.apps_dict[app_id].x_min
                if(subtract_exec_time):
                    new_deadline = str(new_deadline) + \
                        " -%s" % (exec_time_var_name,)

            deadline_string += "else if(app_struct_%s.isActive[app_struct_%s.isActiveVersion]) { task_struct_%s.deadline[!task_struct_%s.deadlineVersion & 0x1] = %s; task_struct_%s.deadlineVersion = !task_struct_%s.deadlineVersion & 0x1;}" % (
                app_id, app_id, task_id, task_id, new_deadline, task_id, task_id)

        return deadline_string

    def add_tasks_enabler_function(self, father_task_id):
        """Returns the string that enable all child tasks

        Parameters
        ----------

        father_task_id: str
            unique id of the task that needs the enabler function

        Returns
        -------

        function_string: str
            a string with the enabler function code
        """
        template = ""
        function_string = ""
        with open(task_enabler_template, "r") as template_file:
            template = template_file.read().replace("\n", "\t\\\n\t")
        successors = self.tasks_graph.successors(father_task_id)

        task_enabler_string = ""

        for child_name in successors:
            # enable tasks
            condition_string = [dep.condition for dep in self.tasks_dict[child_name].in_set if dep.task_id==father_task_id][0]
            task_enabler_string = template.replace(
                "TASK_NAME", "task_struct_%s" % (child_name))
            app_struct_list = ["app_struct_%s.isActive[app_struct_%s.isActiveVersion]" % (app_name, app_name)
                               for app_name in self.tasks_dict[child_name].apps]
            task_enabler_string = task_enabler_string.replace(
                "APP_CONDITION", " || ".join(app_struct_list))
            task_enabler_string = task_enabler_string.replace(
                "DEP_COND", condition_string)

            # set deadlines for newly enabled tasks
            task_enabler_string = task_enabler_string.replace(
                "DEADLINES_UPDATE", self.add_deadline_restore(child_name, father_id=father_task_id, updating_children=True))

            function_string += task_enabler_string

        return function_string

    def add_throughput_update(self, task_id, app_id):
        template = ""
        with open(task_tput_update_template, "r") as template_file:
            template = template_file.read().replace("\n", "\t\\\n\t")
            template = template.replace(
                "ORIGINAL_DEADLINE", str(self.apps_dict[app_id].x_min))
            template = template.replace("TASK_ID", task_id)
            template = template.replace("APP_ID", app_id)
            if(app_id == self.sorted_app_id_list[0]):
                # I'm the final task of the first app
                # in that case I set the slack to the time left to my deadline and
                # I set the app to run to the next app (if it exists).
                # Fulvio suggested to discount the old slack by a discount parameter
                # so that old power failures are less relevant.
                # Discount parameter is a value in [0,1].
                # This parameter is somehow a measure of the energy source stability:
                # an high value means that the source is subject to frequent drops,
                # a low value means that the source is fairly stable.
                discount_parameter = self.config_dict.get("discount_parameter", 1)
                slack_update_instruction = "slack={}*slack + value;".format(discount_parameter)
                template = template.replace("SLACK_UPDATE", slack_update_instruction)
            else:
                #otherwise I have nothing to do with the slack
                template = template.replace("SLACK_UPDATE", " ")
        return template

    def add_tasks_returns(self, header):
        """Generates the header define for tasks return statement

        Parameters
        ----------

        header : Header
            an Header object
        """
        template = ""
        with open(return_template, "r") as template_file:
            template = template_file.read().replace("\n", "\t\\\n\t")
        for task_id, task_props in self.tasks_dict.items():
            define_key = "RETURN_%s" % (task_id)
            define_value = template.replace("TASK", task_id).replace(
                "LOCAL_VAR", task_props.output.name)
            for app in task_props.apps:
                if task_id == self.apps_dict[app].get_final_task():
                    define_value += self.add_throughput_update(task_id, app)
                    break

            # first restore my deadline, then my children's one
            # if I'm the initial task then my deadline is initialized to 1/tput,
            # otherwise it's set to my father's previous deadline
            # TODO: multiple fathers are not yet fully supported

            predecessors = list(self.tasks_graph.predecessors(task_id))
            if(len(predecessors) > 1):
                print(
                    "WARNING: multiple fathers are not yet fully supported, probably...")
            if(predecessors and set(self.tasks_dict[predecessors[0]].apps) & set(task_props.apps)):
                father_name = predecessors[0]
            else:
                father_name = None
            define_value += self.add_deadline_restore(
                task_id, father_id=father_name)

            # children deadline is update thanks to the add_tasks_enabler_function
            define_value += self.add_tasks_enabler_function(task_id)

            # if I'm not the first app, then I'm running inside a slack,
            # therefore I have to subtrack delta_cycles to the current slack
            # to account for my execution.
            if(self.sorted_app_id_list.index(task_props.apps[0])>0): #TODO currently not working with shared tasks
                define_value = define_value.replace("SLACK_SUB", "slack-=delta_cycles;")
            else:
                define_value = define_value.replace("SLACK_SUB", " ")

            header.add_define((define_key, define_value))

    def add_tasks_structs(self, header):
        """Generates the header define to declare tasks structures

        Parameters
        ----------

        header : Header
            an Header object
        """
        topological_order = nx.topological_sort(self.tasks_graph)
        with open(task_struct_template, "r") as ts:
            template = ts.read().replace("\n", "")
        structs = []
        for task in topological_order:
            task_id = str(task)
            predecessors = self.tasks_graph.predecessors(task)
            predecessors_list = ["&task_struct_%s" %
                                 (x,) for x in predecessors]
            predecessors_string = ", ".join(predecessors_list)

            task_struct_define = template.replace("TASK", task_id)
            task_struct_define = task_struct_define.replace(
                "ENERGY", str(self.tasks_dict[task_id].e_wc))
            task_struct_define = task_struct_define.replace(
                "DEPENDENCIES_COUNT", str(len(predecessors_list)))
            task_struct_define = task_struct_define.replace(
                "DEPENDENCIES", predecessors_string)
            task_struct_define = task_struct_define.replace(
                "POINTER", "&%s" % (task_id,))
            structs.append(task_struct_define)
        define_string = "\t\\\n\t".join(structs)
        header.add_define(("TASKS_STRUCTS", define_string))

    def add_tasks_array(self, header):
        """Generates the header define to declare an array of tasks pointers

        Parameters
        ----------

        header : Header
            an Header object
        """
        tasks = ["&task_struct_%s" % (x,) for x in self.tasks_dict.keys()]
        tasks_string = ", ".join(tasks)

        with open(tasks_array, "r") as ta:
            array_template = ta.read().replace("\n", "\t\\\n\t")

        array_template = array_template.replace("TASK_COUNT", str(
            len(self.tasks_dict))).replace("TASKS_STRUCTS", tasks_string)

        header.add_define(("TASK_ARRAY", array_template))

    def add_extern_variables(self, header):
        """Generates the header define to declare all extern variables

        Parameters
        ----------

        header : Header
            an Header object
        """
        template = ""
        with open(extern_variables_template, "r") as template_file:
            template = template_file.read().replace("\n", "\t\\\n\t")
        define_value = template
        for task_id in self.tasks_dict:
            define_value += "extern task_struct_t task_struct_%s;" % (task_id)
        for app_id in self.apps_dict:
            define_value += "extern app_struct_t app_struct_%s;" % (app_id)

        header.add_define(("EXTERN_VARS", define_value))

    def generate_tasks_defines(self, header):
        """Creates the tasks defines by running the needed methods in the correct order

        Parameters
        ----------

        header : Header
            an Header object
        """
        self.add_tasks_variables_declarations(header)
        self.add_tasks_signatures(header)
        self.add_extern_variables(header)
        self.add_tasks_begin_declarations(header)
        self.add_tasks_returns(header)
        self.add_tasks_end(header)
        self.add_tasks_structs(header)
        self.add_tasks_array(header)
        header.add_define(("TASK_COUNT", len(self.tasks_dict)))
