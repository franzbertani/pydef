from collections import namedtuple


class Application:

    def __init__(self, id):
        self.id = id
        self.tasks_dict = {}
        self._initial_task = None
        self.x_min = 0

    def __str__(self):
        rep = "tasks_dict = %s, initial_task = %s, x_min = %s" % (
            str(self.tasks_dict), self._initial_task, self.x_min)
        return rep

    def build_tasks_dict(self, tasks_id_list, tasks_dict):
        """Populates the application tasks dictionary

        Parameters
        ----------

        tasks_id_list : list
            list of tasks id to be added to the collection
        tasks_dict : dict
            dictionary containing all tasks details
        """
        for task_id in tasks_id_list:
            if task_id not in tasks_dict:
                print("ERROR: task %s does not exists, skipping it" % (task_id))
                continue
            self.tasks_dict[task_id] = tasks_dict[task_id]

    def set_initial_task(self, task_id):
        """Set the private attribute `_initial_task` checking its validity

        Parameters
        ----------

        task_id : str
            initial task unique id, must be one of the application tasks
            (i.e. a task contained in application tasks dictionary)
        """
        if task_id not in self.tasks_dict:
            print("ERROR: initial task %s must be an application task" % (task_id))
            return
        self._initial_task = task_id


class Applications:

    def __init__(self):
        self.apps_dict = {}

    def build_apps_dict(self, config_dict, tasks_dict):
        """Build an internal list with all the application task

        Parameters
        ----------

        config_dict : dict
            configuration dict built by `read_yaml_file`
        tasks_dict : dict
            the complete tasks dict
        """
        for app in config_dict["APPLICATIONS"]:
            if app["id"] in self.apps_dict:
                print("ERROR: app id must be unique, %s duplicated" % (app["id"],))
                continue
            new_app = Application(app["id"])
            new_app.x_min = app.get("x_min", 0)
            new_app.build_tasks_dict(app.get("tasks", []), tasks_dict)
            new_app.set_initial_task(app["initial_task"])
            self.apps_dict[app["id"]] = new_app

    def generate_apps_defines(self, header):
        header.add_define(("APPS_COUNT", len(self.apps_dict)))
