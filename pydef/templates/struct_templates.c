typedef struct task_struct {
    float e_wc;
    struct task_struct* in_set[3];
    int in_set_count;
    void (*function_pointer)();
} task_struct_t;

typedef struct app_struct {
    task_struct_t* app_tasks[5];
    task_struct_t* initial_task;
    int tasks_count;
    float x_min;
} app_struct_t;

