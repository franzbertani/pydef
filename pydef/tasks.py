import re
from collections import namedtuple

import networkx as nx
from headergen import Header

Variable = namedtuple("Variable", "name type")
Dependency = namedtuple("Dependency", "task_id dependency_type")
Task = namedtuple("Task", "id in_set output e_bc e_wc apps")

variable_struct_template = "templates/variable_struct_template.c"
return_template = "templates/return_template.c"
tasks_array = "templates/tasks_array_template.c"
task_struct_template = "templates/tasks_struct_define.c"
task_enabler_template = "templates/task_enabler.c"
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
                in_set=[Dependency(**dep) for dep in task["in_set"]],
                output=Variable(**task["output"]),
                e_bc=int(task["e_bc"]),
                e_wc=int(task["e_wc"]),
                apps=apps_list)
            if(self.check_task_consistency(new_task)):
                self.tasks_dict[new_task.id] = new_task
            else:
                print("WARN: skipped task %s" % (new_task.id))
        print(self.tasks_dict)

    def build_tasks_graph(self):
        """Builds a networkx graph from the task dictionary

        It must be used AFTER `build_task_dict`
        """
        for task_id in self.tasks_dict:
            self.tasks_graph.add_node(task_id)
        for task_id, task_props in self.tasks_dict.items():
            self.tasks_graph.add_edges_from(
                [(dep.task_id, task_id) for dep in task_props.in_set])

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
            task_struct = (var_template
                           .replace("TASK", task_id)
                           .replace("TYPE", task_props.output.type)
                           .replace("VERSIONS_COUNT", "1"))
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
                        self.tasks_dict[dep.task_id].output.type,
                        dep.task_id,
                        "g_%s" % (dep.task_id)))
            define_value.append(
                'siren_command("TEST_RESET: %u\\n", &tardis_time);')
            header.add_define((define_key, "\t\\\n\t".join(define_value)))

    def add_tasks_end(self, header):
        """Generates the header define to end a task based on tasks dict

        Parameters
        ----------

        header : Header
            an Header object
        """
        header.add_define(("END_TASK", "}\n"))

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
        for child_name in successors:
            task_enabler_string = template.replace(
                "TASK_NAME", "task_struct_%s" % (child_name))
            app_struct_list = ["app_struct_%s.isActive" % (app_name) for app_name in
                               self.tasks_dict[child_name].apps]
            task_enabler_string = task_enabler_string.replace(
                "APP_CONDITION", " || ".join(app_struct_list))
            app_list_iter = iter(self.tasks_dict[child_name].apps)
            app_id = next(app_list_iter)
            deadline_string = "if(%s && app_struct_%s.isActive) task_struct_%s.deadline = 1/%s;" % (
                self.apps_dict[app_id].x_min, app_id, child_name, self.apps_dict[app_id].x_min)
            for app_id in app_list_iter:
                deadline_string += "else if(%s && app_struct_%s.isActive) task_struct_%s.deadline = 1/%s;" % (
                self.apps_dict[app_id].x_min, app_id, child_name, self.apps_dict[app_id].x_min)
            task_enabler_string = task_enabler_string.replace("DEADLINES_UPDATE", deadline_string)
            function_string += task_enabler_string
        return function_string

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
            define_value += self.add_tasks_enabler_function(task_id)
            # define_value = "g_%s = %s;\t\\\n\treturn;" % (
            #     task, self.tasks_dict[task].output.name)
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
        print(define_string)
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
        self.add_extern_variables(header)
        self.add_tasks_begin_declarations(header)
        self.add_tasks_returns(header)
        self.add_tasks_end(header)
        self.add_tasks_structs(header)
        self.add_tasks_array(header)
        header.add_define(("TASK_COUNT", len(self.tasks_dict)))
