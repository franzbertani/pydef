from collections import namedtuple

app_struct_define = "templates/app_struct_define.c"
app_array_define = "templates/app_array_template.c"


class Application:

    def __init__(self, id):
        self.id = id
        self.tasks_dict = {}
        self._initial_task = None
        self._final_task = None
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

    def set_final_task(self, task_id):
        """Set the private attribute `_final_task` checking its validity

        Parameters
        ----------

        task_id : str
            initial task unique id, must be one of the application tasks
            (i.e. a task contained in application tasks dictionary)
        """
        if task_id not in self.tasks_dict:
            print("ERROR: initial task %s must be an application task" % (task_id))
            return
        self._final_task = task_id

    def get_initial_task(self):
        return self._initial_task

    def get_final_task(self):
        return self._final_task


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
                print("ERROR: app id must be unique, %s duplicated" %
                      (app["id"],))
                continue
            new_app = Application(app["id"])
            x_min = app.get("x_min", 0)
            if x_min > 0:
                # deadline for tasks in micro seconds
                x_min = int((1/x_min) * 1000000)
            new_app.x_min = x_min
            new_app.build_tasks_dict(app.get("tasks", []), tasks_dict)
            new_app.set_initial_task(app["initial_task"])
            new_app.set_final_task(app["final_task"])
            self.apps_dict[app["id"]] = new_app

    def get_apps_dict(self):
        return self.apps_dict

    def add_apps_structs(self, header):
        """Generates the header defines to declare an app struct for each app

        Parameters
        ----------

        header : Header
            an Header object
        """
        with open(app_struct_define, "r") as asd:
            template = asd.read().replace("\n", "")
        structs = []
        for k, v in self.apps_dict.items():
            app_define = template.replace("APP", k)
            app_define = app_define.replace("TP", str(v.x_min))
            app_define = app_define.replace(
                "TASKS_COUNT", str(len(v.tasks_dict)))
            tasks = ["&task_struct_%s" % (x,) for x in v.tasks_dict]
            tasks_string = ", ".join(tasks)
            app_define = app_define.replace("TASKS", tasks_string)
            app_define = app_define.replace(
                "INITIAL_TASK", "&task_struct_%s" % (v.get_initial_task(),))
            app_define = app_define.replace(
                "FINAL_TASK", "&task_struct_%s" % (v.get_final_task(),))
            structs.append(app_define)
        define_string = "\t\\\n\t".join(structs)
        #setting pointers to app in tasks_structs
        task_pointers = []
        for k,v in self.apps_dict.items():
            for task in v.tasks_dict:
                task_pointers.append("task_struct_%s.app_pointer = (void*) &(app_struct_%s);" %(task, k))
        function_string = "\t\\\n\tvoid set_tasks_app_pointers(){"
        function_string += "\t\\\n\t".join(task_pointers)
        function_string += "};"
        define_string += function_string
        header.add_define(("APP_STRUCTS", define_string))

    def add_apps_array(self, header):
        """Generates the header defines to declare app related array

        It generates the declarations for the app array and the active apps array

        Parameters
        ----------

        header : Header
            an Header object
        """
        with open(app_array_define, "r") as aad:
            template = aad.read().replace("\n", "\t\\\n\t")
        template = template.replace("APP_COUNT", str(len(self.apps_dict)))
        sorted_apps = [x[0] for x in sorted(
            self.apps_dict.items(), key=lambda x: x[1].x_min, reverse=False)]
        apps = ["&app_struct_%s" % (x,) for x in sorted_apps]
        apps_string = ", ".join(apps)
        template = template.replace("APP_STRUCTS", apps_string)
        header.add_define(("APP_ARRAY", template))

    def generate_apps_defines(self, header):
        header.add_define(("APPS_COUNT", len(self.apps_dict)))
        self.add_apps_structs(header)
        self.add_apps_array(header)
