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
EXTERN_VARS

int __attribute__ ((persistent)) resets = -1;
int __attribute__ ((persistent)) seen_resets = 0;
int __attribute__ ((persistent)) next_task = 0;
int __attribute__ ((persistent)) tardis_time = 0;

BEGIN_TASK_task_1
    extern task_struct_t task_struct_task_2;
    siren_command("PRINTF: running task 1\n");
    int t1_out;
    t1_out = get_sample();
    RETURN_task_1
END_TASK

BEGIN_TASK_task_2
    siren_command("PRINTF: running task 2\n");
    int t2_output;
    t2_output = task_1 + 10;
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

    /* activate first app and its tasks L:4-5 */
    app_struct_t *app = app_array[active_app_count];
    app->isActive |= 0x1;
    active_app_array[active_app_count] = app;

    for(int i=0; i<app->tasks_count; i++){
        active_task_array[active_task_count] = (app->app_tasks)[i];
        active_task_count++;
    }

    /* completing tasks set with extra app dependencies L:6-12 */
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
        for(int i=0; i<new_task_counter; i++){ // pouring new tasks into active task
            active_task_array[active_task_count] = new_tasks[i];
            active_task_count++;
        }
    } while(new_task_counter != 0);

    /* computing the wakeup threshold L:13-14*/
    int energy_prediction[TASK_COUNT];
    int max_energy_prediction = -10;
    for(int i=0; i<active_task_count; i++){
        energy_prediction[i] = active_task_array[i]->e_wc + RESTORE_OVERHEAD*active_task_array[i]->in_set_count;
        max_energy_prediction = MAX(max_energy_prediction, energy_prediction[i]);
    }

    /* set the deadlines L:17-22 */
    for(int i=0; i<active_task_count; i++){
        if(active_task_array[i]->in_set_count == 0){
            active_task_array[i]->deadline = 1/app->x_min;
            active_task_array[i]->isEnabled |= 0x1;
            enabled_task_array[enabled_task_count] = active_task_array[i];
            enabled_task_count++;
        }
    }

    siren_command("PRINTF: max energy prediction %u\n", max_energy_prediction);

    /* currently just a stub L:23*/
    set_threshold(max_energy_prediction + AVG_OVERHEAD);
    return;
}

//TODO
//currently static to test restore
void scheduler(){
    task_struct_t next_task_struct;
    if(seen_resets != resets){ // a reset occurred
        seen_resets = resets;
        if(next_task == 1){
            siren_command("PRINTF: restore\n");
            RESTORE(g_task_1, var_struct_task_1, 0);
        }
    }
    while(1){
        //enabled tasks array is updated on exit of father task
        //deadlines of added tasks are set on exit of father
        //TODO
        //halve deadlines
        //restore deadlines not to be halved
        //sort array of enabled tasks
        //select task
        next_task_struct = *(task_array[next_task]);
        (next_task_struct.function_pointer)();
        next_task = (next_task+1) % 2;
    }
}


int main(){
    WDTCTL = WDTPW | WDTHOLD;

    resets++;
    if(resets==0){
        initialize();
    } else {
        siren_command("PRINTF: restarted after %u milliseconds\n", tardis_time);
    }
    if(resets==10){
        siren_command("PRINTF: done, restarted %u\r\n", resets);
        return 0;
    }
    scheduler();
    return 0;
}

