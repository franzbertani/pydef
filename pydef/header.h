#define task_a_output_var struct task_a_struct {	\
	    int version_array[1 + 1];	\
	    short int size;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct __attribute__ ((persistent)) task_a_struct var_struct_task_a = {.size = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
	int g_task_a;	\
		\
	
#define task_1_output_var struct task_1_struct {	\
	    int version_array[1 + 1];	\
	    short int size;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct __attribute__ ((persistent)) task_1_struct var_struct_task_1 = {.size = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
	int g_task_1;	\
		\
	
#define task_2_output_var struct task_2_struct {	\
	    int version_array[1 + 1];	\
	    short int size;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct __attribute__ ((persistent)) task_2_struct var_struct_task_2 = {.size = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
	int g_task_2;	\
		\
	
#define DECLARE_OUTPUT_VARIABLES task_a_output_var	\
	task_1_output_var	\
	task_2_output_var
#define BEGIN_TASK_task_a void task_a(){
#define BEGIN_TASK_task_1 void task_1(){	\
	int task_a = g_task_a;
#define BEGIN_TASK_task_2 void task_2(){	\
	int task_a = g_task_a;
#define RETURN_task_a g_task_a = ta_out;	\
	var_struct_task_a.version_array[var_struct_task_a.write_index] = g_task_a;	\
		\
	switch(var_struct_task_a.is_full){	\
		\
	    case 1: var_struct_task_a.write_index = (var_struct_task_a.write_index + 1) % (var_struct_task_a.size + 1);	\
	            var_struct_task_a.window_begin_index = (var_struct_task_a.window_begin_index + 1) % var_struct_task_a.size;	\
	            break;	\
		\
	    case 0: if((var_struct_task_a.write_index = (var_struct_task_a.write_index + 1) % (var_struct_task_a.size + 1))){	\
	                var_struct_task_a.is_full = 1;	\
	                var_struct_task_a.window_begin_index = (var_struct_task_a.window_begin_index + 1) % var_struct_task_a.size;	\
	            }	\
		\
	};	\
	
#define RETURN_task_1 g_task_1 = t1_output;	\
	var_struct_task_1.version_array[var_struct_task_1.write_index] = g_task_1;	\
		\
	switch(var_struct_task_1.is_full){	\
		\
	    case 1: var_struct_task_1.write_index = (var_struct_task_1.write_index + 1) % (var_struct_task_1.size + 1);	\
	            var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % var_struct_task_1.size;	\
	            break;	\
		\
	    case 0: if((var_struct_task_1.write_index = (var_struct_task_1.write_index + 1) % (var_struct_task_1.size + 1))){	\
	                var_struct_task_1.is_full = 1;	\
	                var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % var_struct_task_1.size;	\
	            }	\
		\
	};	\
	
#define RETURN_task_2 g_task_2 = t2_output;	\
	var_struct_task_2.version_array[var_struct_task_2.write_index] = g_task_2;	\
		\
	switch(var_struct_task_2.is_full){	\
		\
	    case 1: var_struct_task_2.write_index = (var_struct_task_2.write_index + 1) % (var_struct_task_2.size + 1);	\
	            var_struct_task_2.window_begin_index = (var_struct_task_2.window_begin_index + 1) % var_struct_task_2.size;	\
	            break;	\
		\
	    case 0: if((var_struct_task_2.write_index = (var_struct_task_2.write_index + 1) % (var_struct_task_2.size + 1))){	\
	                var_struct_task_2.is_full = 1;	\
	                var_struct_task_2.window_begin_index = (var_struct_task_2.window_begin_index + 1) % var_struct_task_2.size;	\
	            }	\
		\
	};	\
	
#define END_TASK }
#define RESTORE(global_var, struct_address, version) global_var = struct_address.version_array[(struct_address.window_begin_index + version) % struct_address.size]

