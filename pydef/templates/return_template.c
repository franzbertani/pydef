g_TASK = LOCAL_VAR;
var_struct_TASK.version_array[var_struct_TASK.write_index] = g_TASK;

var_struct_TASK.write_index = (var_struct_TASK.write_index + 1) % (var_struct_TASK.versions_count + 1);

if(var_struct_TASK.is_full){
    var_struct_TASK.window_begin_index = (var_struct_TASK.window_begin_index + 1) % (var_struct_TASK.versions_count + 1);
} else if(var_struct_TASK.write_index == 0){
    var_struct_TASK.is_full = 1;
    var_struct_TASK.window_begin_index = (var_struct_TASK.window_begin_index + 1) % (var_struct_TASK.versions_count + 1);
}

siren_command("GET_CCOUNT: task-%u\n", &delta_time);
siren_command("TEST_EXECUTION_CCOUNT: %u\n", delta_time);

/* siren_command("PRINTF: var_struct_TASK :\r\n"); */
/* for(int i=0; i<var_struct_TASK.versions_count; i++) */
/*     siren_command("PRINTF: %u\r\n", var_struct_TASK.version_array[(var_struct_TASK.window_begin_index + i) % (var_struct_TASK.versions_count + 1)]); */
