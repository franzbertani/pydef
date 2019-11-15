typedef struct acc_struct {
    unsigned int x_acc;
    unsigned int y_acc;
    unsigned int z_acc;
} acc_struct_t;
typedef struct task_struct {
    unsigned int e_wc;
    struct task_struct* in_set[3];
    int in_set_count;
    long int deadline[2];
    short int deadlineVersion;
    void (*function_pointer)();
    char isEnabled[2];
    short int isEnabledVersion;
    char isActive[2];
    short int isActiveVersion;
    short int marked_to_remove[2];
    short int stopped;
} task_struct_t;

typedef struct app_struct {
    task_struct_t* app_tasks[6];
    task_struct_t* initial_task;
    task_struct_t* final_task;
    int tasks_count;
    unsigned long int x_min;
    short int x_ok[2];
    short int x_okVersion;
    short int isActive[2];
    short int isActiveVersion;
} app_struct_t;

#define sense_output_var struct sense_var_struct {	\
	    acc_struct_t version_array[30 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    short int write_count;	\
	    char is_full;	\
	};	\
	struct sense_var_struct __attribute__ ((persistent)) var_struct_sense = {.versions_count = 30, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count=0};	\
	acc_struct_t g_sense;	\
		\
	
#define median_output_var struct median_var_struct {	\
	    acc_struct_t* version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    short int write_count;	\
	    char is_full;	\
	};	\
	struct median_var_struct __attribute__ ((persistent)) var_struct_median = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count=0};	\
	acc_struct_t* g_median;	\
		\
	
#define lowpass_output_var struct lowpass_var_struct {	\
	    acc_struct_t* version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    short int write_count;	\
	    char is_full;	\
	};	\
	struct lowpass_var_struct __attribute__ ((persistent)) var_struct_lowpass = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count=0};	\
	acc_struct_t* g_lowpass;	\
		\
	
#define magnitude_output_var struct magnitude_var_struct {	\
	    acc_struct_t* version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    short int write_count;	\
	    char is_full;	\
	};	\
	struct magnitude_var_struct __attribute__ ((persistent)) var_struct_magnitude = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count=0};	\
	acc_struct_t* g_magnitude;	\
		\
	
#define classify_output_var struct classify_var_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    short int write_count;	\
	    char is_full;	\
	};	\
	struct classify_var_struct __attribute__ ((persistent)) var_struct_classify = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count=0};	\
	int g_classify;	\
		\
	
#define operate_output_var struct operate_var_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    short int write_count;	\
	    char is_full;	\
	};	\
	struct operate_var_struct __attribute__ ((persistent)) var_struct_operate = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count=0};	\
	int g_operate;	\
		\
	
#define compress_output_var struct compress_var_struct {	\
	    acc_struct_t* version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    short int write_count;	\
	    char is_full;	\
	};	\
	struct compress_var_struct __attribute__ ((persistent)) var_struct_compress = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count=0};	\
	acc_struct_t* g_compress;	\
		\
	
#define send_output_var struct send_var_struct {	\
	    int version_array[1 + 1];	\
	    short int versions_count;	\
	    short int window_begin_index;	\
	    short int write_index;	\
	    short int write_count;	\
	    char is_full;	\
	};	\
	struct send_var_struct __attribute__ ((persistent)) var_struct_send = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0, .write_count=0};	\
	int g_send;	\
		\
	
#define DECLARE_OUTPUT_VARIABLES sense_output_var	\
	median_output_var	\
	lowpass_output_var	\
	magnitude_output_var	\
	classify_output_var	\
	operate_output_var	\
	compress_output_var	\
	send_output_var
void sense();
void median();
void lowpass();
void magnitude();
void classify();
void operate();
void compress();
void send();
#define EXTERN_VARS extern app_struct_t* active_app_array[APPS_COUNT];	\
	extern int active_app_count;	\
	extern task_struct_t* enabled_task_array[TASK_COUNT];	\
	extern int enabled_task_count;	\
	extern task_struct_t task_struct_sense;extern task_struct_t task_struct_median;extern task_struct_t task_struct_lowpass;extern task_struct_t task_struct_magnitude;extern task_struct_t task_struct_classify;extern task_struct_t task_struct_operate;extern task_struct_t task_struct_compress;extern task_struct_t task_struct_send;extern app_struct_t app_struct_app_1;extern app_struct_t app_struct_app_2;
#define BEGIN_TASK_sense void sense(){	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_median void median(){	\
	acc_struct_t sense = g_sense;	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_lowpass void lowpass(){	\
	acc_struct_t* median = g_median;	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_magnitude void magnitude(){	\
	acc_struct_t* lowpass = g_lowpass;	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_classify void classify(){	\
	acc_struct_t* magnitude = g_magnitude;	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_operate void operate(){	\
	int classify = g_classify;	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_compress void compress(){	\
	acc_struct_t* median = g_median;	\
	siren_command("START_CCOUNT: task\n");
#define BEGIN_TASK_send void send(){	\
	acc_struct_t* compress = g_compress;	\
	siren_command("START_CCOUNT: task\n");
#define RETURN_sense g_sense = sense_out;	\
	var_struct_sense.version_array[var_struct_sense.write_index] = g_sense;	\
		\
	var_struct_sense.write_index = (var_struct_sense.write_index + 1) % (var_struct_sense.versions_count + 1);	\
		\
	if(var_struct_sense.is_full){	\
	    var_struct_sense.window_begin_index = (var_struct_sense.window_begin_index + 1) % (var_struct_sense.versions_count + 1);	\
	} else if(var_struct_sense.write_index == 0){	\
	    var_struct_sense.is_full = 1;	\
	    var_struct_sense.window_begin_index = (var_struct_sense.window_begin_index + 1) % (var_struct_sense.versions_count + 1);	\
	}	\
	if(var_struct_sense.write_count < var_struct_sense.versions_count){	\
	    var_struct_sense.write_count++;	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l, sense\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_sense :\r\n"); */	\
	/* for(int i=0; i<var_struct_sense.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_sense.version_array[(var_struct_sense.window_begin_index + i) % (var_struct_sense.versions_count + 1)]); */	\
	if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_sense.deadline[!task_struct_sense.deadlineVersion & 0x1] = 666666; task_struct_sense.deadlineVersion = !task_struct_sense.deadlineVersion & 0x1;}extern task_struct_t task_struct_median;	\
	short int task_struct_median_enVersion = task_struct_median.isEnabledVersion;	\
	if(!(task_struct_median.isEnabled[task_struct_median_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (var_struct_sense.write_count >= 10)){	\
	    task_struct_median.isEnabled[!task_struct_median_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_median;	\
	    enabled_task_count++;	\
	    task_struct_median.isEnabledVersion = !task_struct_median_enVersion & 0x1;	\
	    if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_median.deadline[!task_struct_median.deadlineVersion & 0x1] = task_struct_sense.deadline[!task_struct_sense.deadlineVersion & 0x1]; task_struct_median.deadlineVersion = !task_struct_median.deadlineVersion & 0x1;}	\
	}	\
	
#define RETURN_median g_median = median_out;	\
	var_struct_median.version_array[var_struct_median.write_index] = g_median;	\
		\
	var_struct_median.write_index = (var_struct_median.write_index + 1) % (var_struct_median.versions_count + 1);	\
		\
	if(var_struct_median.is_full){	\
	    var_struct_median.window_begin_index = (var_struct_median.window_begin_index + 1) % (var_struct_median.versions_count + 1);	\
	} else if(var_struct_median.write_index == 0){	\
	    var_struct_median.is_full = 1;	\
	    var_struct_median.window_begin_index = (var_struct_median.window_begin_index + 1) % (var_struct_median.versions_count + 1);	\
	}	\
	if(var_struct_median.write_count < var_struct_median.versions_count){	\
	    var_struct_median.write_count++;	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l, median\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_median :\r\n"); */	\
	/* for(int i=0; i<var_struct_median.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_median.version_array[(var_struct_median.window_begin_index + i) % (var_struct_median.versions_count + 1)]); */	\
	if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_median.deadline[!task_struct_median.deadlineVersion & 0x1] = task_struct_sense.deadline[!task_struct_sense.deadlineVersion & 0x1]; task_struct_median.deadlineVersion = !task_struct_median.deadlineVersion & 0x1;}extern task_struct_t task_struct_lowpass;	\
	short int task_struct_lowpass_enVersion = task_struct_lowpass.isEnabledVersion;	\
	if(!(task_struct_lowpass.isEnabled[task_struct_lowpass_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (1)){	\
	    task_struct_lowpass.isEnabled[!task_struct_lowpass_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_lowpass;	\
	    enabled_task_count++;	\
	    task_struct_lowpass.isEnabledVersion = !task_struct_lowpass_enVersion & 0x1;	\
	    if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_lowpass.deadline[!task_struct_lowpass.deadlineVersion & 0x1] = task_struct_median.deadline[!task_struct_median.deadlineVersion & 0x1]; task_struct_lowpass.deadlineVersion = !task_struct_lowpass.deadlineVersion & 0x1;}	\
	}	\
	extern task_struct_t task_struct_compress;	\
	short int task_struct_compress_enVersion = task_struct_compress.isEnabledVersion;	\
	if(!(task_struct_compress.isEnabled[task_struct_compress_enVersion]) && (app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) && (1)){	\
	    task_struct_compress.isEnabled[!task_struct_compress_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_compress;	\
	    enabled_task_count++;	\
	    task_struct_compress.isEnabledVersion = !task_struct_compress_enVersion & 0x1;	\
	    if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) { task_struct_compress.deadline[!task_struct_compress.deadlineVersion & 0x1] = 2000000; task_struct_compress.deadlineVersion = !task_struct_compress.deadlineVersion & 0x1;}	\
	}	\
	
#define RETURN_lowpass g_lowpass = lowpass_out;	\
	var_struct_lowpass.version_array[var_struct_lowpass.write_index] = g_lowpass;	\
		\
	var_struct_lowpass.write_index = (var_struct_lowpass.write_index + 1) % (var_struct_lowpass.versions_count + 1);	\
		\
	if(var_struct_lowpass.is_full){	\
	    var_struct_lowpass.window_begin_index = (var_struct_lowpass.window_begin_index + 1) % (var_struct_lowpass.versions_count + 1);	\
	} else if(var_struct_lowpass.write_index == 0){	\
	    var_struct_lowpass.is_full = 1;	\
	    var_struct_lowpass.window_begin_index = (var_struct_lowpass.window_begin_index + 1) % (var_struct_lowpass.versions_count + 1);	\
	}	\
	if(var_struct_lowpass.write_count < var_struct_lowpass.versions_count){	\
	    var_struct_lowpass.write_count++;	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l, lowpass\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_lowpass :\r\n"); */	\
	/* for(int i=0; i<var_struct_lowpass.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_lowpass.version_array[(var_struct_lowpass.window_begin_index + i) % (var_struct_lowpass.versions_count + 1)]); */	\
	if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_lowpass.deadline[!task_struct_lowpass.deadlineVersion & 0x1] = task_struct_median.deadline[!task_struct_median.deadlineVersion & 0x1]; task_struct_lowpass.deadlineVersion = !task_struct_lowpass.deadlineVersion & 0x1;}extern task_struct_t task_struct_magnitude;	\
	short int task_struct_magnitude_enVersion = task_struct_magnitude.isEnabledVersion;	\
	if(!(task_struct_magnitude.isEnabled[task_struct_magnitude_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (1)){	\
	    task_struct_magnitude.isEnabled[!task_struct_magnitude_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_magnitude;	\
	    enabled_task_count++;	\
	    task_struct_magnitude.isEnabledVersion = !task_struct_magnitude_enVersion & 0x1;	\
	    if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_magnitude.deadline[!task_struct_magnitude.deadlineVersion & 0x1] = task_struct_lowpass.deadline[!task_struct_lowpass.deadlineVersion & 0x1]; task_struct_magnitude.deadlineVersion = !task_struct_magnitude.deadlineVersion & 0x1;}	\
	}	\
	
#define RETURN_magnitude g_magnitude = magnitude_out;	\
	var_struct_magnitude.version_array[var_struct_magnitude.write_index] = g_magnitude;	\
		\
	var_struct_magnitude.write_index = (var_struct_magnitude.write_index + 1) % (var_struct_magnitude.versions_count + 1);	\
		\
	if(var_struct_magnitude.is_full){	\
	    var_struct_magnitude.window_begin_index = (var_struct_magnitude.window_begin_index + 1) % (var_struct_magnitude.versions_count + 1);	\
	} else if(var_struct_magnitude.write_index == 0){	\
	    var_struct_magnitude.is_full = 1;	\
	    var_struct_magnitude.window_begin_index = (var_struct_magnitude.window_begin_index + 1) % (var_struct_magnitude.versions_count + 1);	\
	}	\
	if(var_struct_magnitude.write_count < var_struct_magnitude.versions_count){	\
	    var_struct_magnitude.write_count++;	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l, magnitude\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_magnitude :\r\n"); */	\
	/* for(int i=0; i<var_struct_magnitude.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_magnitude.version_array[(var_struct_magnitude.window_begin_index + i) % (var_struct_magnitude.versions_count + 1)]); */	\
	if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_magnitude.deadline[!task_struct_magnitude.deadlineVersion & 0x1] = task_struct_lowpass.deadline[!task_struct_lowpass.deadlineVersion & 0x1]; task_struct_magnitude.deadlineVersion = !task_struct_magnitude.deadlineVersion & 0x1;}extern task_struct_t task_struct_classify;	\
	short int task_struct_classify_enVersion = task_struct_classify.isEnabledVersion;	\
	if(!(task_struct_classify.isEnabled[task_struct_classify_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (1)){	\
	    task_struct_classify.isEnabled[!task_struct_classify_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_classify;	\
	    enabled_task_count++;	\
	    task_struct_classify.isEnabledVersion = !task_struct_classify_enVersion & 0x1;	\
	    if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_classify.deadline[!task_struct_classify.deadlineVersion & 0x1] = task_struct_magnitude.deadline[!task_struct_magnitude.deadlineVersion & 0x1]; task_struct_classify.deadlineVersion = !task_struct_classify.deadlineVersion & 0x1;}	\
	}	\
	
#define RETURN_classify g_classify = classify_out;	\
	var_struct_classify.version_array[var_struct_classify.write_index] = g_classify;	\
		\
	var_struct_classify.write_index = (var_struct_classify.write_index + 1) % (var_struct_classify.versions_count + 1);	\
		\
	if(var_struct_classify.is_full){	\
	    var_struct_classify.window_begin_index = (var_struct_classify.window_begin_index + 1) % (var_struct_classify.versions_count + 1);	\
	} else if(var_struct_classify.write_index == 0){	\
	    var_struct_classify.is_full = 1;	\
	    var_struct_classify.window_begin_index = (var_struct_classify.window_begin_index + 1) % (var_struct_classify.versions_count + 1);	\
	}	\
	if(var_struct_classify.write_count < var_struct_classify.versions_count){	\
	    var_struct_classify.write_count++;	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l, classify\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_classify :\r\n"); */	\
	/* for(int i=0; i<var_struct_classify.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_classify.version_array[(var_struct_classify.window_begin_index + i) % (var_struct_classify.versions_count + 1)]); */	\
	if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_classify.deadline[!task_struct_classify.deadlineVersion & 0x1] = task_struct_magnitude.deadline[!task_struct_magnitude.deadlineVersion & 0x1]; task_struct_classify.deadlineVersion = !task_struct_classify.deadlineVersion & 0x1;}extern task_struct_t task_struct_operate;	\
	short int task_struct_operate_enVersion = task_struct_operate.isEnabledVersion;	\
	if(!(task_struct_operate.isEnabled[task_struct_operate_enVersion]) && (app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) && (1)){	\
	    task_struct_operate.isEnabled[!task_struct_operate_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_operate;	\
	    enabled_task_count++;	\
	    task_struct_operate.isEnabledVersion = !task_struct_operate_enVersion & 0x1;	\
	    if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_operate.deadline[!task_struct_operate.deadlineVersion & 0x1] = task_struct_classify.deadline[!task_struct_classify.deadlineVersion & 0x1]; task_struct_operate.deadlineVersion = !task_struct_operate.deadlineVersion & 0x1;}	\
	}	\
	
#define RETURN_operate g_operate = operate_out;	\
	var_struct_operate.version_array[var_struct_operate.write_index] = g_operate;	\
		\
	var_struct_operate.write_index = (var_struct_operate.write_index + 1) % (var_struct_operate.versions_count + 1);	\
		\
	if(var_struct_operate.is_full){	\
	    var_struct_operate.window_begin_index = (var_struct_operate.window_begin_index + 1) % (var_struct_operate.versions_count + 1);	\
	} else if(var_struct_operate.write_index == 0){	\
	    var_struct_operate.is_full = 1;	\
	    var_struct_operate.window_begin_index = (var_struct_operate.window_begin_index + 1) % (var_struct_operate.versions_count + 1);	\
	}	\
	if(var_struct_operate.write_count < var_struct_operate.versions_count){	\
	    var_struct_operate.write_count++;	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l, operate\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_operate :\r\n"); */	\
	/* for(int i=0; i<var_struct_operate.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_operate.version_array[(var_struct_operate.window_begin_index + i) % (var_struct_operate.versions_count + 1)]); */	\
	long int value = task_struct_operate.deadline[task_struct_operate.deadlineVersion] < 0 ? -1 : 2*333333 - task_struct_operate.deadline[task_struct_operate.deadlineVersion] - delta_cycles;	\
	/* long int value = task_struct_operate.deadline[task_struct_operate.deadlineVersion] - delta_cycles; */	\
		\
	siren_command("PRINTF: updating tput aftrer operate\n");	\
	if (value < 0){	\
	    siren_command("PRINTF: app_1 underperforming\n");	\
	    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = -1;	\
	    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;	\
	    manage_underperf();	\
	} else if (value > 0) {	\
	    siren_command("PRINTF: app_1 overperforming\n");	\
	    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = 1;	\
	    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;	\
	    manage_overperf();	\
	} else {	\
	    siren_command("PRINTF: app_1 performance ok\n");	\
	    app_struct_app_1.x_ok[!app_struct_app_1.x_okVersion & 0x1] = 0;	\
	    app_struct_app_1.x_okVersion = !app_struct_app_1.x_okVersion & 0x1;	\
	}	\
	if(app_struct_app_1.isActive[app_struct_app_1.isActiveVersion]) { task_struct_operate.deadline[!task_struct_operate.deadlineVersion & 0x1] = task_struct_classify.deadline[!task_struct_classify.deadlineVersion & 0x1]; task_struct_operate.deadlineVersion = !task_struct_operate.deadlineVersion & 0x1;}
#define RETURN_compress g_compress = compress_out;	\
	var_struct_compress.version_array[var_struct_compress.write_index] = g_compress;	\
		\
	var_struct_compress.write_index = (var_struct_compress.write_index + 1) % (var_struct_compress.versions_count + 1);	\
		\
	if(var_struct_compress.is_full){	\
	    var_struct_compress.window_begin_index = (var_struct_compress.window_begin_index + 1) % (var_struct_compress.versions_count + 1);	\
	} else if(var_struct_compress.write_index == 0){	\
	    var_struct_compress.is_full = 1;	\
	    var_struct_compress.window_begin_index = (var_struct_compress.window_begin_index + 1) % (var_struct_compress.versions_count + 1);	\
	}	\
	if(var_struct_compress.write_count < var_struct_compress.versions_count){	\
	    var_struct_compress.write_count++;	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l, compress\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_compress :\r\n"); */	\
	/* for(int i=0; i<var_struct_compress.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_compress.version_array[(var_struct_compress.window_begin_index + i) % (var_struct_compress.versions_count + 1)]); */	\
	if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) { task_struct_compress.deadline[!task_struct_compress.deadlineVersion & 0x1] = 2000000; task_struct_compress.deadlineVersion = !task_struct_compress.deadlineVersion & 0x1;}extern task_struct_t task_struct_send;	\
	short int task_struct_send_enVersion = task_struct_send.isEnabledVersion;	\
	if(!(task_struct_send.isEnabled[task_struct_send_enVersion]) && (app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) && (1)){	\
	    task_struct_send.isEnabled[!task_struct_send_enVersion & 0x1] |= 0x1;	\
	    enabled_task_array[enabled_task_count] = &task_struct_send;	\
	    enabled_task_count++;	\
	    task_struct_send.isEnabledVersion = !task_struct_send_enVersion & 0x1;	\
	    if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) { task_struct_send.deadline[!task_struct_send.deadlineVersion & 0x1] = task_struct_compress.deadline[!task_struct_compress.deadlineVersion & 0x1]; task_struct_send.deadlineVersion = !task_struct_send.deadlineVersion & 0x1;}	\
	}	\
	
#define RETURN_send g_send = send_out;	\
	var_struct_send.version_array[var_struct_send.write_index] = g_send;	\
		\
	var_struct_send.write_index = (var_struct_send.write_index + 1) % (var_struct_send.versions_count + 1);	\
		\
	if(var_struct_send.is_full){	\
	    var_struct_send.window_begin_index = (var_struct_send.window_begin_index + 1) % (var_struct_send.versions_count + 1);	\
	} else if(var_struct_send.write_index == 0){	\
	    var_struct_send.is_full = 1;	\
	    var_struct_send.window_begin_index = (var_struct_send.window_begin_index + 1) % (var_struct_send.versions_count + 1);	\
	}	\
	if(var_struct_send.write_count < var_struct_send.versions_count){	\
	    var_struct_send.write_count++;	\
	}	\
		\
	siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);	\
	siren_command("TEST_EXECUTION_CCOUNT: %l, send\n", delta_cycles);	\
		\
	/* siren_command("PRINTF: var_struct_send :\r\n"); */	\
	/* for(int i=0; i<var_struct_send.versions_count; i++) */	\
	/*     siren_command("PRINTF: %u\r\n", var_struct_send.version_array[(var_struct_send.window_begin_index + i) % (var_struct_send.versions_count + 1)]); */	\
	long int value = task_struct_send.deadline[task_struct_send.deadlineVersion] < 0 ? -1 : 2*1000000 - task_struct_send.deadline[task_struct_send.deadlineVersion] - delta_cycles;	\
	/* long int value = task_struct_send.deadline[task_struct_send.deadlineVersion] - delta_cycles; */	\
		\
	siren_command("PRINTF: updating tput aftrer send\n");	\
	if (value < 0){	\
	    siren_command("PRINTF: app_2 underperforming\n");	\
	    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = -1;	\
	    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;	\
	    manage_underperf();	\
	} else if (value > 0) {	\
	    siren_command("PRINTF: app_2 overperforming\n");	\
	    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = 1;	\
	    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;	\
	    manage_overperf();	\
	} else {	\
	    siren_command("PRINTF: app_2 performance ok\n");	\
	    app_struct_app_2.x_ok[!app_struct_app_2.x_okVersion & 0x1] = 0;	\
	    app_struct_app_2.x_okVersion = !app_struct_app_2.x_okVersion & 0x1;	\
	}	\
	if(app_struct_app_2.isActive[app_struct_app_2.isActiveVersion]) { task_struct_send.deadline[!task_struct_send.deadlineVersion & 0x1] = task_struct_compress.deadline[!task_struct_compress.deadlineVersion & 0x1]; task_struct_send.deadlineVersion = !task_struct_send.deadlineVersion & 0x1;}
#define END_TASK }

#define TASKS_STRUCTS task_struct_t __attribute__ ((persistent)) task_struct_sense = {.e_wc = 80, .in_set = {}, .in_set_count = 0, .function_pointer = &sense, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = {0x0,0x0}, .stopped=0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_median = {.e_wc = 32, .in_set = {&task_struct_sense}, .in_set_count = 1, .function_pointer = &median, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = {0x0,0x0}, .stopped=0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_compress = {.e_wc = 40, .in_set = {&task_struct_median}, .in_set_count = 1, .function_pointer = &compress, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = {0x0,0x0}, .stopped=0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_send = {.e_wc = 90, .in_set = {&task_struct_compress}, .in_set_count = 1, .function_pointer = &send, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = {0x0,0x0}, .stopped=0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_lowpass = {.e_wc = 50, .in_set = {&task_struct_median}, .in_set_count = 1, .function_pointer = &lowpass, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = {0x0,0x0}, .stopped=0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_magnitude = {.e_wc = 15, .in_set = {&task_struct_lowpass}, .in_set_count = 1, .function_pointer = &magnitude, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = {0x0,0x0}, .stopped=0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_classify = {.e_wc = 40, .in_set = {&task_struct_magnitude}, .in_set_count = 1, .function_pointer = &classify, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = {0x0,0x0}, .stopped=0};	\
	task_struct_t __attribute__ ((persistent)) task_struct_operate = {.e_wc = 30, .in_set = {&task_struct_classify}, .in_set_count = 1, .function_pointer = &operate, .isEnabled = {0x0,0x0}, .isEnabledVersion = 0x0, .isActive = {0x0,0x0}, .isActiveVersion = 0x0, .deadlineVersion = 0x0, .marked_to_remove = {0x0,0x0}, .stopped=0};
#define TASK_ARRAY task_struct_t* __attribute__ ((persistent)) task_array[8] = {&task_struct_sense, &task_struct_median, &task_struct_lowpass, &task_struct_magnitude, &task_struct_classify, &task_struct_operate, &task_struct_compress, &task_struct_send};	\
	task_struct_t* __attribute__ ((persistent)) active_task_array[8] = {};	\
	int __attribute__ ((persistent)) active_task_count = 0;	\
	task_struct_t* __attribute__ ((persistent)) enabled_task_array[8] = {};	\
	int __attribute__ ((persistent)) enabled_task_count = 0;	\
	
#define TASK_COUNT 8
#define APPS_COUNT 2
#define APP_STRUCTS app_struct_t __attribute__ ((persistent)) app_struct_app_1 = {.x_min = 333333, .x_ok = {0,0}, .x_okVersion = 0x0, .tasks_count = 6, .app_tasks = {&task_struct_sense, &task_struct_median, &task_struct_lowpass, &task_struct_magnitude, &task_struct_classify, &task_struct_operate}, .initial_task = &task_struct_sense, .final_task = &task_struct_operate, .isActive = {0x0, 0x0}, .isActiveVersion = 0x0};	\
	app_struct_t __attribute__ ((persistent)) app_struct_app_2 = {.x_min = 1000000, .x_ok = {0,0}, .x_okVersion = 0x0, .tasks_count = 2, .app_tasks = {&task_struct_compress, &task_struct_send}, .initial_task = &task_struct_compress, .final_task = &task_struct_send, .isActive = {0x0, 0x0}, .isActiveVersion = 0x0};
#define APP_ARRAY app_struct_t* __attribute__ ((persistent)) app_array[2] = {&app_struct_app_1, &app_struct_app_2};	\
	app_struct_t* __attribute__ ((persistent)) active_app_array[2] = {};	\
	int __attribute__ ((persistent)) active_app_count = 0;	\
	
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define AVG_OVERHEAD 0
#define RESTORE_OVERHEAD 1.0
#define RESTORE(global_var, struct_address, version) global_var = struct_address.version_array[(struct_address.window_begin_index + version) % (struct_address.versions_count + 1)]

