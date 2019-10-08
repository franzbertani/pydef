typedef struct task_struct {
    int e_wc;
    struct task_struct* in_set[3];
    int in_set_count;
    unsigned long int deadline;
    void (*function_pointer)();
    char isEnabled;
} task_struct_t;

typedef struct app_struct {
    task_struct_t* app_tasks[5];
    task_struct_t* initial_task;
    int tasks_count;
    unsigned long int x_min;
    char isActive;
} app_struct_t;

