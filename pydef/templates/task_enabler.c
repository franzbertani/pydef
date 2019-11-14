extern task_struct_t TASK_NAME;
short int TASK_NAME_enVersion = TASK_NAME.isEnabledVersion;
if(!(TASK_NAME.isEnabled[TASK_NAME_enVersion]) && (APP_CONDITION) && (DEP_COND)){
    TASK_NAME.isEnabled[!TASK_NAME_enVersion & 0x1] |= 0x1;
    enabled_task_array[enabled_task_count] = &TASK_NAME;
    enabled_task_count++;
    TASK_NAME.isEnabledVersion = !TASK_NAME_enVersion & 0x1;
    DEADLINES_UPDATE
}
