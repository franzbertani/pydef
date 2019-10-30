typedef struct task_struct {
    int e_wc;
    struct task_struct* in_set[3];
    int in_set_count;
    unsigned long int deadline[2];
    short int deadlineVersion;
    void (*function_pointer)();
    char isEnabled[2];
    short int isEnabledVersion;
    char isActive[2];
    short int isActiveVersion;
} task_struct_t;

typedef struct app_struct {
    task_struct_t* app_tasks[5];
    task_struct_t* initial_task;
    task_struct_t* final_task;
    int tasks_count;
    unsigned long int x_min;
    char x_ok[2];
    short int x_okVersion;
    char isActive[2];
    short int isActiveVersion;
} app_struct_t;

