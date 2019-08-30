task_struct_t* __attribute__ ((persistent)) task_array[TASK_COUNT] = {TASKS_STRUCTS};
task_struct_t* __attribute__ ((persistent)) active_task_array[TASK_COUNT] = {};
int __attribute__ ((persistent)) active_task_count = 0;
task_struct_t* __attribute__ ((persistent)) enabled_task_array[TASK_COUNT] = {};
int __attribute__ ((persistent)) enabled_task_count = 0;
