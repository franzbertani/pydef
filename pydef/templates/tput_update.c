unsigned long int value = ORIGINAL_DEADLINE - task_struct_TASK_ID.deadline[task_struct_TASK_ID.deadlineVersion] - delta_cycles;
siren_command("PRINTF: updating tput aftrer TASK_ID\n");
if (value < 0){
    siren_command("PRINTF: underperforming\n");
    app_struct_APP_ID.x_ok[!app_struct_APP_ID.x_okVersion & 0x1] = -1;
    app_struct_APP_ID.x_okVersion = !app_struct_APP_ID.x_okVersion & 0x1;
} else if (value > 0) {
    siren_command("PRINTF: overperforming\n");
    app_struct_APP_ID.x_ok[!app_struct_APP_ID.x_okVersion & 0x1] = 1;
    app_struct_APP_ID.x_okVersion = !app_struct_APP_ID.x_okVersion & 0x1;
} else {
    siren_command("PRINTF: performance ok\n");
    app_struct_APP_ID.x_ok[!app_struct_APP_ID.x_okVersion & 0x1] = 0;
    app_struct_APP_ID.x_okVersion = !app_struct_APP_ID.x_okVersion & 0x1;
}
