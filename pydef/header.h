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

#define task_a_output_var struct task_a_var_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct task_a_var_struct __attribute__ ((persistent)) var_struct_task_a = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
	int g_task_a;	\
		\
	
#define task_1_output_var struct task_1_var_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct task_1_var_struct __attribute__ ((persistent)) var_struct_task_1 = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
	int g_task_1;	\
		\
	
#define DECLARE_OUTPUT_VARIABLES task_a_output_var	\
	task_1_output_var
#define BEGIN_TASK_task_a void task_a(){
#define BEGIN_TASK_task_1 void task_1(){	\
	int task_a = g_task_a;
#define RETURN_task_a g_task_a = ta_out;	\
	var_struct_task_a.version_array[var_struct_task_a.write_index] = g_task_a;	\
		\
	var_struct_task_a.write_index = (var_struct_task_a.write_index + 1) % (var_struct_task_a.versions_count + 1);	\
		\
	if(var_struct_task_a.is_full){	\
	    var_struct_task_a.window_begin_index = (var_struct_task_a.window_begin_index + 1) % (var_struct_task_a.versions_count + 1);	\
	} else if(var_struct_task_a.write_index == 0){	\
	    var_struct_task_a.is_full = 1;	\
	    var_struct_task_a.window_begin_index = (var_struct_task_a.window_begin_index + 1) % (var_struct_task_a.versions_count + 1);	\
	}	\
		\
	/* siren_command("PRINTF: var_struct_task_a :\r\n"); */	\
	/* for(int i=0; i<var_struct_task_a.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_task_a.version_array[(var_struct_task_a.window_begin_index + i) % (var_struct_task_a.versions_count + 1)]); */	\
	
#define RETURN_task_1 g_task_1 = t1_output;	\
	var_struct_task_1.version_array[var_struct_task_1.write_index] = g_task_1;	\
		\
	var_struct_task_1.write_index = (var_struct_task_1.write_index + 1) % (var_struct_task_1.versions_count + 1);	\
		\
	if(var_struct_task_1.is_full){	\
	    var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % (var_struct_task_1.versions_count + 1);	\
	} else if(var_struct_task_1.write_index == 0){	\
	    var_struct_task_1.is_full = 1;	\
	    var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % (var_struct_task_1.versions_count + 1);	\
	}	\
		\
	/* siren_command("PRINTF: var_struct_task_1 :\r\n"); */	\
	/* for(int i=0; i<var_struct_task_1.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_task_1.version_array[(var_struct_task_1.window_begin_index + i) % (var_struct_task_1.versions_count + 1)]); */	\
	
#define END_TASK }

#define TASKS_STRUCTS task_struct_t __attribute__ ((persistent)) task_struct_task_a = {.e_wc = 450.0, .in_set = {}, .in_set_count = 0, .function_pointer = &task_a};	\
	task_struct_t __attribute__ ((persistent)) task_struct_task_1 = {.e_wc = 150.0, .in_set = {&task_struct_task_a}, .in_set_count = 1, .function_pointer = &task_1};
#define TASK_ARRAY task_struct_t* __attribute__ ((persistent)) task_array[2] = {&task_struct_task_a, &task_struct_task_1};	\
	app_struct_t* __attribute__ ((persistent)) active_task_array[2];	\
	int __attribute__ ((persistent)) active_task_count = 0;	\
	app_struct_t* __attribute__ ((persistent)) enabled_task_array[2];	\
	int __attribute__ ((persistent)) enabled_task_count = 0;	\
	
#define TASK_COUNT 2
#define APPS_COUNT 1
#define APP_STRUCTS app_struct_t __attribute__ ((persistent)) app_struct_app_1 = {.x_min = 1, .tasks_count = 2, .app_tasks = {&task_struct_task_a, &task_struct_task_1}, .initial_task = &task_struct_task_a};
#define APP_ARRAY app_struct_t* __attribute__ ((persistent)) app_array[1] = {&app_struct_app_1};	\
	app_struct_t* __attribute__ ((persistent)) active_app_array[1];	\
	int __attribute__ ((persistent)) active_app_count = 0;	\
	
#define RESTORE(global_var, struct_address, version) global_var = struct_address.version_array[(struct_address.window_begin_index + version) % (struct_address.versions_count + 1)]

