#include "git/scheduler/pydef/header.h"
#include <stdio.h>

DECLARE_OUTPUT_VARIABLES

int counter = 0;

BEGIN_TASK_task_a
    int ta_out;
    ta_out = counter;
    counter++;
    RETURN_task_a
END_TASK

BEGIN_TASK_task_1
    int t1_output;
    t1_output = task_a + 2;
    RETURN_task_1
END_TASK

int main(){
    task_a();
    task_1();
    printf("[%d, %d]\n", var_struct_task_1.version_array[0], var_struct_task_1.version_array[1]);
    task_a();
    task_1();
    printf("[%d, %d]\n", var_struct_task_1.version_array[0], var_struct_task_1.version_array[1]);
    task_a();
    task_1();
    printf("[%d, %d]\n", var_struct_task_1.version_array[0], var_struct_task_1.version_array[1]);
    task_a();
    task_1();
    printf("[%d, %d]\n", var_struct_task_1.version_array[0], var_struct_task_1.version_array[1]);
    return 0;
}

