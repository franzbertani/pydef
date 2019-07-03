g_TASK = LOCAL_VAR;
var_struct_TASK.version_array[var_struct_TASK.write_index] = g_TASK;

switch(var_struct_TASK.is_full){

    case 1: var_struct_TASK.write_index = (var_struct_TASK.write_index + 1) % (var_struct_TASK.size + 1);
            var_struct_TASK.window_begin_index = (var_struct_TASK.window_begin_index + 1) % var_struct_TASK.size;
            break;

    case 0: if((var_struct_TASK.write_index = (var_struct_TASK.write_index + 1) % (var_struct_TASK.size + 1))){
                var_struct_TASK.is_full = 1;
                var_struct_TASK.window_begin_index = (var_struct_TASK.window_begin_index + 1) % var_struct_TASK.size;
            }

};
