struct task_a_var_struct { int version_array[1 + 1]; short int versions_count; short int window_begin_index; short int write_index; char is_full; }; struct task_a_var_struct __attribute__ ((persistent)) var_struct_task_a = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0}; int g_task_a; struct task_1_var_struct { int version_array[1 + 1]; short int versions_count; short int window_begin_index; short int write_index; char is_full; }; struct task_1_var_struct __attribute__ ((persistent)) var_struct_task_1 = {.versions_count = 1, .window_begin_index = 0, .write_index = 0, .is_full = 0}; int g_task_1;

int __attribute__ ((persistent)) resets = -1;
int __attribute__ ((persistent)) seen_resets = 0;
int __attribute__ ((persistent)) next_task = 0;

void task_a(){
    int ta_out;
    siren_command("PRINTF: running producer task a\n");
    ta_out = get_sample();
    g_task_a = ta_out; var_struct_task_a.version_array[var_struct_task_a.write_index] = g_task_a; var_struct_task_a.write_index = (var_struct_task_a.write_index + 1) % (var_struct_task_a.versions_count + 1); if(var_struct_task_a.is_full){ var_struct_task_a.window_begin_index = (var_struct_task_a.window_begin_index + 1) % (var_struct_task_a.versions_count + 1); } else if(var_struct_task_a.write_index == 0){ var_struct_task_a.is_full = 1; var_struct_task_a.window_begin_index = (var_struct_task_a.window_begin_index + 1) % (var_struct_task_a.versions_count + 1); }
}

void task_1(){ int task_a = g_task_a;
    int t1_output;
    t1_output = task_a + 10;
    siren_command("PRINTF: running consumer task 1\n");
    g_task_1 = t1_output; var_struct_task_1.version_array[var_struct_task_1.write_index] = g_task_1; var_struct_task_1.write_index = (var_struct_task_1.write_index + 1) % (var_struct_task_1.versions_count + 1); if(var_struct_task_1.is_full){ var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % (var_struct_task_1.versions_count + 1); } else if(var_struct_task_1.write_index == 0){ var_struct_task_1.is_full = 1; var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % (var_struct_task_1.versions_count + 1); }
}

task_struct_t __attribute__ ((persistent)) task_struct_task_a = {.e_wc = 450.0, .in_set = {}, .in_set_count = 0, .function_pointer = &task_a}; task_struct_t __attribute__ ((persistent)) task_struct_task_1 = {.e_wc = 150.0, .in_set = {&task_struct_task_a}, .in_set_count = 1, .function_pointer = &task_1};
task_struct_t* __attribute__ ((persistent)) task_array[2] = {&task_struct_task_a, &task_struct_task_1}; app_struct_t* __attribute__ ((persistent)) active_task_array[2]; app_struct_t* __attribute__ ((persistent)) enabled_task_array[2];
app_struct_t __attribute__ ((persistent)) app_struct_app_1 = {.x_min = 1, .tasks_count = 2, .app_tasks = {&task_struct_task_a, &task_struct_task_1}, .initial_task = &task_struct_task_a};
app_struct_t* __attribute__ ((persistent)) app_array[1] = {&app_struct_app_1}; app_struct_t* __attribute__ ((persistent)) active_app_array[1];

void scheduler(){
    task_struct_t next_task_struct;
    if(seen_resets != resets){
        seen_resets = resets;
        if(next_task == 1){
            siren_command("PRINTF: restore\r\n");
            g_task_a = var_struct_task_a.version_array[(var_struct_task_a.window_begin_index + 0) % (var_struct_task_a.versions_count + 1)];
        }
    }
    while(1){
        next_task_struct = *(task_array[next_task]);
        (next_task_struct.function_pointer)();
        next_task = (next_task+1) % 2;
        siren_command("RESET: a\n");
    }
}

int main(){
    resets++;
    if(resets==10){
        siren_command("PRINTF: done, restarted %u\r\n", resets);
        return 0;
    }
    siren_command("PRINTF: restart\n");
    scheduler();
    return 0;
}
