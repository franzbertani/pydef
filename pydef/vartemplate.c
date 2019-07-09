struct TASK_struct {
    TYPE version_array[VERSIONS_COUNT + 1];
    short int size;
    short int window_begin_index;
    short int write_index;
    char is_full;
};
struct __attribute__ ((persistent)) TASK_struct var_struct_TASK = {.size = VERSIONS_COUNT, .window_begin_index = 0, .write_index = 0, .is_full = 0};
TYPE g_TASK;

