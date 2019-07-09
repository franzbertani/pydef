import re
from collections import namedtuple

import networkx as nx
from headergen import Header

Variable = namedtuple("Variable", "name type")
Dependency = namedtuple("Dependency", "task_id dependency_type")
Task = namedtuple("Task", "id in_set output e_bc e_wc")


class Tasks:

    def __init__(self):
        self.tasks_dict = {}
        self.tasks_graph = nx.DiGraph()

    def get_tasks_dict(self):
        return self.tasks_dict

    def get_tasks_graph(self):
        return self.tasks_graph

    def check_task_consistency(self, new_task):
        """Check if the new task is compatible with the existing ones.

            Args:
                new_taks: the Task named tuple of the new task

            Returns:
                A boolean value.
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

            In particular this function checks if all the in set of tasks
            are variables produced by existing tasks.

            Returns:
                A boolean value.
        """
        # sostituire il for con un for su iter e chiave,valore
        # perche' e' piu' efficiente
        for task_id in self.tasks_dict:
            task_dependencies = [
                dep.task_id for dep in self.tasks_dict[task_id].in_set]
            for dep_id in task_dependencies:
                if dep_id not in self.tasks_dict:
                    print("ERROR: unsatisfied dependency %s -> %s" %
                          (dep_id, task_id))
                    return False
        return True

    def build_tasks_dict(self, config_dict):
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
        for task_id in self.tasks_dict:
            self.tasks_graph.add_node(task_id)
        for task_id in self.tasks_dict:
            self.tasks_graph.add_edges_from([(dep.task_id, task_id)
                                             for dep in self.tasks_dict[task_id].in_set])

    def add_tasks_variables_declarations(self, header):
        declarations_list = []
        var_template = ""
        with open("vartemplate.c") as template_file:
            var_template = template_file.read().replace("\n", "\t\\\n\t")
        for task_id in self.tasks_dict:
            task_struct = (var_template
                           .replace("TASK", task_id)
                           .replace("TYPE", self.tasks_dict[task_id].output.type)
                           .replace("VERSIONS_COUNT", "1"))
            header.add_define((task_id + "_output_var", task_struct))
            declarations_list.append(task_id + "_output_var")
        header.add_define(("DECLARE_OUTPUT_VARIABLES",
                           "\t\\\n\t".join(declarations_list)))

    def add_tasks_begin_declarations(self, header):
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
        header.add_define(("END_TASK", "}\n"))

    def add_tasks_returns(self, header):
        template = ""
        with open("return_template.c") as template_file:
            template = template_file.read().replace("\n","\t\\\n\t")
        for task in self.tasks_dict:
            define_key = "RETURN_%s" % (task)
            define_value = template.replace("TASK", task).replace("LOCAL_VAR", self.tasks_dict[task].output.name)
            # define_value = "g_%s = %s;\t\\\n\treturn;" % (
            #     task, self.tasks_dict[task].output.name)
            header.add_define((define_key, define_value))

    def generate_tasks_defines(self, header):
        self.add_tasks_variables_declarations(header)
        self.add_tasks_begin_declarations(header)
        self.add_tasks_returns(header)
        self.add_tasks_end(header)
