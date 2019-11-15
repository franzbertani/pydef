#include "header.h"
TASKS_STRUCTS
TASK_ARRAY
APP_STRUCTS
APP_ARRAY

void deactivate_2(){

    short int appVersion = app_struct_app_2.isActiveVersion;
    app_struct_app_2.isActive[(!appVersion)&0x1] = 0;

    short int send_index;
    short int compress_index;
    for(short int i=0; i<active_task_count; i++){
        if(active_task_array[i]==&task_struct_send){
            send_index = i;
        } else if(active_task_array[i]==&task_struct_compress){
            compress_index = i;
        }
    }
    active_task_array[compress_index] = active_task_array[active_task_count-1];
    active_task_count--;

    active_task_array[send_index] = active_task_array[active_task_count-1];
    active_task_count--;

    for(short int i=0; i<enabled_task_count; i++){
        if(enabled_task_array[i]==&task_struct_send){
            send_index = i;
        } else if(enabled_task_array[i]==&task_struct_compress){
            compress_index = i;
        }
    }
    enabled_task_array[compress_index] = enabled_task_array[active_task_count-1];
    enabled_task_count--;

    enabled_task_array[send_index] = enabled_task_array[active_task_count-1];
    enabled_task_count--;

    //should use versioning
    task_struct_compress.deadline[0] = 0;
    task_struct_compress.deadline[1] = 0;
    task_struct_send.deadline[0] = 0;
    task_struct_send.deadline[1] = 0;

    task_struct_compress.isEnabled[0] = 0;
    task_struct_compress.isEnabled[1] = 0;
    task_struct_send.isEnabled[0] = 0;
    task_struct_send.isEnabled[1] = 0;

    task_struct_compress.isActive[0] = 0;
    task_struct_compress.isActive[1] = 0;
    task_struct_send.isActive[0] = 0;
    task_struct_send.isActive[1] = 0;

    active_app_count = 1;
    app_struct_app_2.isActiveVersion = (!appVersion) &0x1;

    is_pruning =0;
}
