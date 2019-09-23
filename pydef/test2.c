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
int __attribute__ ((persistent)) tardis_time = 0;

BEGIN_TASK_task_1
    int t1_out;
    siren_command("PRINTF: running task 1\n");
    t1_out = get_sample();
    RETURN_task_1
END_TASK

BEGIN_TASK_task_2
    int t2_output;
    t2_output = task_1 + 10;
    siren_command("PRINTF: running task 2\n");
    RETURN_task_2
END_TASK

TASKS_STRUCTS
TASK_ARRAY
APP_STRUCTS
APP_ARRAY

int check_if_new(task_struct_t *task){
    for(int i=0; i<active_task_count; i++){
        if(active_task_array[i] == task)
            return 0;
    }
    return 1;
}

void set_threshold(int threshold){
    return;
}

void initialize(){
    siren_command("PRINTF: initialize after first boot\n");
    /* activate first app */
    app_struct_t *app = app_array[active_app_count];
    active_app_array[active_app_count] = app;

    /* adding app tasks to active_tasks_array*/
    for(int i=0; i<app->tasks_count; i++){
        active_task_array[active_task_count] = (app->app_tasks)[i];
        active_task_count++;
    }

    /* completing tasks set with extra app dependencies */
    task_struct_t* new_tasks[TASK_COUNT];
    int new_task_counter;
    do {
        new_task_counter = 0;
        for(int i=0; i<active_task_count; i++){             // for every active task
            task_struct_t *task = active_task_array[i];
            for(int j=0; j<task->in_set_count; j++){        // for every in_set task
                task_struct_t *in_task = task->in_set[j];
                if(check_if_new(in_task)){                  // if the in_set task is not already active
                    new_tasks[new_task_counter] = in_task;  // activate it
                    new_task_counter++;
                }
            }
        }
        /* pouring new tasks into active task */
        for(int i=0; i<new_task_counter; i++){
            active_task_array[active_task_count] = new_tasks[i];
            active_task_count++;
        }
    } while(new_task_counter != 0);

    /* computing the wakeup threshold */
    int energy_prediction[TASK_COUNT];
    int max_energy_prediction = -10;
    for(int i=0; i<active_task_count; i++){
        energy_prediction[i] = active_task_array[i]->e_wc + RESTORE_OVERHEAD*active_task_array[i]->in_set_count;
        max_energy_prediction = MAX(max_energy_prediction, energy_prediction[i]);
    }

    /* set the deadlines */
    //TODO

    siren_command("PRINTF: max energy prediction %u\n", max_energy_prediction);
    set_threshold(max_energy_prediction + AVG_OVERHEAD);
    return;
}

void scheduler(){
    task_struct_t next_task_struct;
    if(seen_resets != resets){
        seen_resets = resets;
        if(next_task == 1){
            siren_command("PRINTF: restore\n");
            RESTORE(g_task_1, var_struct_task_1, 0);
        }
    }
    while(1){
        next_task_struct = *(task_array[next_task]);
        (next_task_struct.function_pointer)();
        next_task = (next_task+1) % 2;
        siren_command("CHVAR:%u\n", &tardis_time);
        siren_command("PRINTF: nuovo valore%u\n", tardis_time);
    }
}


int main(){
    WDTCTL = WDTPW | WDTHOLD;

    resets++;
    if(resets==0){
        initialize();
    }
    if(resets==10){
        siren_command("PRINTF: done, restarted %u\r\n", resets);
        return 0;
    }
    siren_command("PRINTF: restart\n");
    scheduler();
    return 0;
}

