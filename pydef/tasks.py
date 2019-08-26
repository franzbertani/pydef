import re
from collections import namedtuple

import networkx as nx
from headergen import Header

Variable = namedtuple("Variable", "name type")
Dependency = namedtuple("Dependency", "task_id dependency_type")
Task = namedtuple("Task", "id in_set output e_bc e_wc")


class Tasks:
    """A class to store set of tasks"""

    def __init__(self):
        self.tasks_dict = {}
        self.tasks_graph = nx.DiGraph()

    def get_tasks_dict(self):
        return self.tasks_dict

    def get_tasks_graph(self):
        return self.tasks_graph

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
        for task in config_dict["TASKS"]:
            new_task = Task(
                id=task["id"],
                in_set=[Dependency(**dep) for dep in task["in_set"]],
                output=Variable(**task["output"]),
                e_bc=float(task["e_bc"]),
                e_wc=float(task["e_wc"]))
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

    def add_tasks_variables_declarations(self, header):
        """Generates the header define to declare tasks variables

        Parameters
        ----------

        header : Header
            an Header object
        """
        declarations_list = []
        var_template = ""
        with open("vartemplate.c") as template_file:
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
            header.add_define((define_key, "\t\\\n\t".join(define_value)))

    def add_tasks_end(self, header):
        """Generates the header define to end a task based on tasks dict

        Parameters
        ----------

        header : Header
            an Header object
        """
        header.add_define(("END_TASK", "}\n"))

    def add_tasks_returns(self, header):
        """Generates the header define for tasks return statement

        Parameters
        ----------

        header : Header
            an Header object
        """
        template = ""
        with open("return_template.c") as template_file:
            template = template_file.read().replace("\n", "\t\\\n\t")
        for task_id, task_props in self.tasks_dict.items():
            define_key = "RETURN_%s" % (task_id)
            define_value = template.replace("TASK", task_id).replace(
                "LOCAL_VAR", task_props.output.name)
            # define_value = "g_%s = %s;\t\\\n\treturn;" % (
            #     task, self.tasks_dict[task].output.name)
            header.add_define((define_key, define_value))

    def add_tasks_array(self, header):
        tasks = ", ".join(self.tasks_dict.keys())
        string = "void __attribute__ ((persistent)) (*task_array[%s])() = {%s};" %(len(self.tasks_dict), tasks)
        header.add_define(("TASK_ARRAY", string))


    def generate_tasks_defines(self, header):
        """Creates the tasks defines by running the needed methods in the correct order

        Parameters
        ----------

        header : Header
            an Header object
        """
        self.add_tasks_variables_declarations(header)
        self.add_tasks_begin_declarations(header)
        self.add_tasks_returns(header)
        self.add_tasks_end(header)
        self.add_tasks_array(header)
        header.add_define(("TASKS_COUNT", len(self.tasks_dict)))
