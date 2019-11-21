long int value = task_struct_TASK_ID.deadline[task_struct_TASK_ID.deadlineVersion] - delta_cycles;

siren_command("PRINTF: updating tput aftrer TASK_ID, value=%l\n", value);
SLACK_UPDATE

if (value < 0 || slack < 0){
    siren_command("PRINTF: APP_ID underperforming\n");
    app_struct_APP_ID.x_ok[!app_struct_APP_ID.x_okVersion & 0x1] = -1;
    app_struct_APP_ID.x_okVersion = !app_struct_APP_ID.x_okVersion & 0x1;
    manage_underperf();
} else if (value > 0 && slack>0) {
    siren_command("PRINTF: APP_ID overperforming\n");
    app_struct_APP_ID.x_ok[!app_struct_APP_ID.x_okVersion & 0x1] = 1;
    app_struct_APP_ID.x_okVersion = !app_struct_APP_ID.x_okVersion & 0x1;
    manage_overperf();
} else {
    siren_command("PRINTF: APP_ID performance ok\n");
    app_struct_APP_ID.x_ok[!app_struct_APP_ID.x_okVersion & 0x1] = 0;
    app_struct_APP_ID.x_okVersion = !app_struct_APP_ID.x_okVersion & 0x1;
}
