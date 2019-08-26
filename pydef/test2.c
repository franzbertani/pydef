#include "header.h"
#include <stdio.h>
#include <stdint.h>
#include "printf.h"

#ifndef MSPLIB_H
#define MSPLIB_H
    #include <msp430fr6989.h>
#endif

#include "fake_sensor.h"

DECLARE_OUTPUT_VARIABLES

int __attribute__ ((persistent)) resets = -1;
int __attribute__ ((persistent)) seen_resets = 0;
int __attribute__ ((persistent)) next_task = 0;

BEGIN_TASK_task_a
    int ta_out;
    siren_command("PRINTF: running producer task a\n");
    ta_out = get_sample();
    RETURN_task_a
END_TASK

BEGIN_TASK_task_1
    int t1_output;
    t1_output = task_a + 10;
    siren_command("PRINTF: running consumer task 1\n");
    RETURN_task_1
END_TASK

/* void __attribute__ ((persistent)) (*task_array[2])() = {task_a, task_1}; */
TASK_ARRAY

void scheduler(){
    if(seen_resets != resets){
        seen_resets = resets;
        if(next_task == 1){
            siren_command("PRINTF: restore\r\n");
            RESTORE(g_task_a, var_struct_task_a, 0);
        }
    }
    while(1){
        (*task_array[next_task])();
        next_task = (next_task+1) % 2;
        siren_command("RESET: a\n");
    }
}

int main(){
    resets++;
    if(resets==10){
        siren_command("PRINTF: done, restarted %u\r\n", resets);
        return 0;
    }
    siren_command("PRINTF: restart\n");
    scheduler();
    return 0;
}

