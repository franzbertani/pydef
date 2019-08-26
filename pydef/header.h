#define task_a_output_var struct task_a_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct task_a_struct __attribute__ ((persistent)) var_struct_task_a = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
	int g_task_a;	\
		\
	
#define task_1_output_var struct task_1_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct task_1_struct __attribute__ ((persistent)) var_struct_task_1 = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
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

#define TASK_ARRAY void __attribute__ ((persistent)) (*task_array[2])() = {task_a, task_1};
#define TASKS_COUNT 2
#define APPS_COUNT 1
#define RESTORE(global_var, struct_address, version) global_var = struct_address.version_array[(struct_address.window_begin_index + version) % (struct_address.versions_count + 1)]

