g_TASK = LOCAL_VAR;
var_struct_TASK.version_array[var_struct_TASK.write_index] = g_TASK;

var_struct_TASK.write_index = (var_struct_TASK.write_index + 1) % (var_struct_TASK.versions_count + 1);

if(var_struct_TASK.is_full){
    var_struct_TASK.window_begin_index = (var_struct_TASK.window_begin_index + 1) % (var_struct_TASK.versions_count + 1);
} else if(var_struct_TASK.write_index == 0){
    var_struct_TASK.is_full = 1;
    var_struct_TASK.window_begin_index = (var_struct_TASK.window_begin_index + 1) % (var_struct_TASK.versions_count + 1);
}
if(var_struct_TASK.write_count < var_struct_TASK.versions_count){
    var_struct_TASK.write_count++;
}

siren_command("GET_CCOUNT: task-%l\n", &delta_cycles);
siren_command("TEST_EXECUTION_CCOUNT: %l, TASK\n", delta_cycles);
SLACK_SUB
