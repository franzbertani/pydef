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
	
#define task_2_output_var struct task_2_var_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct task_2_var_struct __attribute__ ((persistent)) var_struct_task_2 = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
	int g_task_2;	\
		\
	
#define task_3_output_var struct task_3_var_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    char is_full;	\
	};	\
	struct task_3_var_struct __attribute__ ((persistent)) var_struct_task_3 = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0};	\
	int g_task_3;	\
		\
	
#define DECLARE_OUTPUT_VARIABLES task_1_output_var	\
	task_2_output_var	\
	task_3_output_var
#define EXTERN_VARS extern app_struct_t* active_app_array[APPS_COUNT];	\
	extern int active_app_count;	\
	extern task_struct_t* enabled_task_array[TASK_COUNT];	\
	extern int enabled_task_count;	\
	extern task_struct_t task_struct_task_1;extern task_struct_t task_struct_task_2;extern task_struct_t task_struct_task_3;extern app_struct_t app_struct_app_1;extern app_struct_t app_struct_app_2;
#define BEGIN_TASK_task_1 void task_1(){	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_task_2 void task_2(){	\
	int task_1 = g_task_1;	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_task_3 void task_3(){	\
	int task_1 = g_task_1;	\
	siren_command("START_CCOUNT: task\n");
#define RETURN_task_1 g_task_1 = t1_out;	\
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
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_task_1 :\r\n"); */	\
	/* for(int i=0; i<var_struct_task_1.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_task_1.version_array[(var_struct_task_1.window_begin_index + i) % (var_struct_task_1.versions_count + 1)]); */	\
	extern task_struct_t task_struct_task_2;	\
	short int task_struct_task_2_enVersion = task_struct_task_2.isEnabledVersion;	\
	if(!(task_struct_task_2.isEnabled[task_struct_task_2_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion])){	\
	    task_struct_task_2.isEnabled[!task_struct_task_2_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_task_2;	\
	    enabled_task_count++;	\
	    task_struct_task_2.isEnabledVersion = !task_struct_task_2_enVersion & 0x1;	\
	    if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_task_2.deadline[!task_struct_task_2.deadlineVersion & 0x1] = 500000; task_struct_task_2.deadlineVersion = !task_struct_task_2.deadlineVersion & 0x1;}	\
	}	\
	extern task_struct_t task_struct_task_3;	\
	short int task_struct_task_3_enVersion = task_struct_task_3.isEnabledVersion;	\
	if(!(task_struct_task_3.isEnabled[task_struct_task_3_enVersion]) && (app_struct_app_2.isActive[app_struct_app_2.isActiveVersion])){	\
	    task_struct_task_3.isEnabled[!task_struct_task_3_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_task_3;	\
	    enabled_task_count++;	\
	    task_struct_task_3.isEnabledVersion = !task_struct_task_3_enVersion & 0x1;	\
	    if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) { task_struct_task_3.deadline[!task_struct_task_3.deadlineVersion & 0x1] = 555555; task_struct_task_3.deadlineVersion = !task_struct_task_3.deadlineVersion & 0x1;}	\
	}	\
	if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_task_1.deadline[!task_struct_task_1.deadlineVersion & 0x1] = 500000; task_struct_task_1.deadlineVersion = !task_struct_task_1.deadlineVersion & 0x1;}else if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) { task_struct_task_1.deadline[!task_struct_task_1.deadlineVersion & 0x1] = 555555; task_struct_task_1.deadlineVersion = !task_struct_task_1.deadlineVersion & 0x1;}
#define RETURN_task_2 g_task_2 = t2_output;	\
	var_struct_task_2.version_array[var_struct_task_2.write_index] = g_task_2;	\
		\
	var_struct_task_2.write_index = (var_struct_task_2.write_index + 1) % (var_struct_task_2.versions_count + 1);	\
		\
	if(var_struct_task_2.is_full){	\
	    var_struct_task_2.window_begin_index = (var_struct_task_2.window_begin_index + 1) % (var_struct_task_2.versions_count + 1);	\
	} else if(var_struct_task_2.write_index == 0){	\
	    var_struct_task_2.is_full = 1;	\
	    var_struct_task_2.window_begin_index = (var_struct_task_2.window_begin_index + 1) % (var_struct_task_2.versions_count + 1);	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_task_2 :\r\n"); */	\
	/* for(int i=0; i<var_struct_task_2.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_task_2.version_array[(var_struct_task_2.window_begin_index + i) % (var_struct_task_2.versions_count + 1)]); */	\
	unsigned long int value = 500000 - task_struct_task_2.deadline[task_struct_task_2.deadlineVersion] - delta_cycles;	\
	siren_command("PRINTF: updating tput aftrer task_2\n");	\
	if (value < 0){	\
	    siren_command("PRINTF: underperforming\n");	\
	    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = -1;	\
	    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;	\
	} else if (value > 0) {	\
	    siren_command("PRINTF: overperforming\n");	\
	    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = 1;	\
	    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;	\
	} else {	\
	    siren_command("PRINTF: performance ok\n");	\
	    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = 0;	\
	    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;	\
	}	\
	if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_task_2.deadline[!task_struct_task_2.deadlineVersion & 0x1] = 500000; task_struct_task_2.deadlineVersion = !task_struct_task_2.deadlineVersion & 0x1;}
#define RETURN_task_3 g_task_3 = t3_output;	\
	var_struct_task_3.version_array[var_struct_task_3.write_index] = g_task_3;	\
		\
	var_struct_task_3.write_index = (var_struct_task_3.write_index + 1) % (var_struct_task_3.versions_count + 1);	\
		\
	if(var_struct_task_3.is_full){	\
	    var_struct_task_3.window_begin_index = (var_struct_task_3.window_begin_index + 1) % (var_struct_task_3.versions_count + 1);	\
	} else if(var_struct_task_3.write_index == 0){	\
	    var_struct_task_3.is_full = 1;	\
	    var_struct_task_3.window_begin_index = (var_struct_task_3.window_begin_index + 1) % (var_struct_task_3.versions_count + 1);	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_task_3 :\r\n"); */	\
	/* for(int i=0; i<var_struct_task_3.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_task_3.version_array[(var_struct_task_3.window_begin_index + i) % (var_struct_task_3.versions_count + 1)]); */	\
	unsigned long int value = 555555 - task_struct_task_3.deadline[task_struct_task_3.deadlineVersion] - delta_cycles;	\
	siren_command("PRINTF: updating tput aftrer task_3\n");	\
	if (value < 0){	\
	    siren_command("PRINTF: underperforming\n");	\
	    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = -1;	\
	    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;	\
	} else if (value > 0) {	\
	    siren_command("PRINTF: overperforming\n");	\
	    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = 1;	\
	    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;	\
	} else {	\
	    siren_command("PRINTF: performance ok\n");	\
	    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = 0;	\
	    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;	\
	}	\
	if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) { task_struct_task_3.deadline[!task_struct_task_3.deadlineVersion & 0x1] = 555555; task_struct_task_3.deadlineVersion = !task_struct_task_3.deadlineVersion & 0x1;}
#define END_TASK }

#define TASKS_STRUCTS task_struct_t __attribute__ ((persistent)) task_struct_task_1 = {.e_wc = 80, .in_set = {}, .in_set_count = 0, .function_pointer = &task_1, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_task_3 = {.e_wc = 15, .in_set = {&task_struct_task_1}, .in_set_count = 1, .function_pointer = &task_3, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_task_2 = {.e_wc = 25, .in_set = {&task_struct_task_1}, .in_set_count = 1, .function_pointer = &task_2, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0};
#define TASK_ARRAY task_struct_t* __attribute__ ((persistent)) task_array[3] = {&task_struct_task_1, &task_struct_task_2, &task_struct_task_3};	\
	task_struct_t* __attribute__ ((persistent)) active_task_array[3] = {};	\
	int __attribute__ ((persistent)) active_task_count = 0;	\
	task_struct_t* __attribute__ ((persistent)) enabled_task_array[3] = {};	\
	int __attribute__ ((persistent)) enabled_task_count = 0;	\
	
#define TASK_COUNT 3
#define APPS_COUNT 2
#define APP_STRUCTS app_struct_t __attribute__ ((persistent)) app_struct_app_1 = {.x_min = 500000, .x_ok = {0,0}, .x_okVersion = 0x0, .tasks_count = 2, .app_tasks = {&task_struct_task_1, &task_struct_task_2}, .initial_task = &task_struct_task_1, .final_task = &task_struct_task_2, .isActive = {0x0, 0x0}, .isActiveVersion = 0x0};	\
	app_struct_t __attribute__ ((persistent)) app_struct_app_2 = {.x_min = 555555, .x_ok = {0,0}, .x_okVersion = 0x0, .tasks_count = 2, .app_tasks = {&task_struct_task_1, &task_struct_task_3}, .initial_task = &task_struct_task_1, .final_task = &task_struct_task_3, .isActive = {0x0, 0x0}, .isActiveVersion = 0x0};
#define APP_ARRAY app_struct_t* __attribute__ ((persistent)) app_array[2] = {&app_struct_app_1, &app_struct_app_2};	\
	app_struct_t* __attribute__ ((persistent)) active_app_array[2] = {};	\
	int __attribute__ ((persistent)) active_app_count = 0;	\
	
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define AVG_OVERHEAD 0
#define RESTORE_OVERHEAD 1.0
#define RESTORE(global_var, struct_address, version) global_var = struct_address.version_array[(struct_address.window_begin_index + version) % (struct_address.versions_count + 1)]

