extern task_struct_t TASK_NAME;
if(!(TASK_NAME.isEnabled) && (APP_CONDITION)){
    TASK_NAME.isEnabled |= 0x1;
    enabled_task_array[enabled_task_count] = &TASK_NAME;
    enabled_task_count++;
    DEADLINES_UPDATE
}
