task_struct_t* __attribute__ ((persistent)) task_array[TASKS_COUNT] = {TASKS_STRUCTS};
app_struct_t* __attribute__ ((persistent)) active_task_array[TASKS_COUNT];
app_struct_t* __attribute__ ((persistent)) enabled_task_array[TASKS_COUNT];
