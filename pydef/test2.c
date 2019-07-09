#include "header.h"
#include <stdio.h>
#include <stdint.h>
#include "printf.h"
#include <msp430fr6989.h>

DECLARE_OUTPUT_VARIABLES

int counter = 0;
/* int __attribute__ ((persistent)) counter = 0; */

BEGIN_TASK_task_a
    int ta_out;
    siren_command("PRINTF: running task a\n");
    ta_out = counter;
    siren_command("PRINTF: task a output %u\r\n", ta_out);
    counter++;
    RETURN_task_a
END_TASK

BEGIN_TASK_task_1
    int t1_output;
    t1_output = task_a + 10;
    siren_command("PRINTF: injected %u\r\n", task_a);
    siren_command("PRINTF: %u\r\n", t1_output);
    RETURN_task_1
END_TASK

int main(){
    siren_command("PRINTF: restart\n");
    while(1){
        task_a();
        __delay_cycles(9999000);
        g_task_a = 9;
        RESTORE(g_task_a, var_struct_task_a, 0);
        task_1();
    }
    siren_command("PRINTF: done\n");
    return 0;
}

