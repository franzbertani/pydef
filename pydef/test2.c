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
int __attribute__ ((persistent)) delta_time = 0;

BEGIN_TASK_task_1
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


/* BEGIN OF HEAPSORT IMPLEMENTATION */

void heapify(task_struct_t* a[],int n) {
    task_struct_t *item;
    int k,i,j;
    for (k=1;k<n;k++) {
        item = a[k];
        i = k;
        j = (i-1)/2;
        while((i>0)&&(item->deadline > a[j]->deadline)) {
            a[i] = a[j];
            i = j;
            j = (i-1)/2;
        }
        a[i] = item;
    }
}

void adjust(task_struct_t* a[],int n) {
    int i,j;
    task_struct_t* item;
    j = 0;
    item = a[j];
    i = 2*j+1;
    while(i<=n-1) {
        if(i+1 <= n-1)
           if(a[i]->deadline < a[i+1]->deadline)
            i++;
        if(item->deadline < a[i]->deadline) {
            a[j] = a[i];
            j = i;
            i = 2*j+1;
        } else
           break;
    }
    a[j] = item;
}

void heapsort(task_struct_t* a[],int n) {
    task_struct_t* t;
    int i;
    heapify(a,n);
    for (i=n-1;i>0;i--) {
        t = a[0];
        a[0] = a[i];
        a[i] = t;
        adjust(a,i);
    }
}

/* END OF HEAPSORT IMPLEMENTATION */


void initialize(){
    siren_command("PRINTF: initialize after first boot\n");
    siren_command("SET_TARDIS_VARIABLE: %u\n", &tardis_time);

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
            active_task_array[i]->deadline = app->x_min;
            active_task_array[i]->isEnabled |= 0x1;
            enabled_task_array[enabled_task_count] = active_task_array[i];
            enabled_task_count++;
        }
    }

    /* currently just a stub L:23*/
    set_threshold(max_energy_prediction + AVG_OVERHEAD);
    return;
}

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
        //sort array of enabled tasks based on deadlines
        heapsort(enabled_task_array, enabled_task_count);
        //select and exec task with lowest deadline
        next_task_struct = *(enabled_task_array[0]);
        (next_task_struct.function_pointer)();

        //subtract to all deadlines of other tasks exec time (not to the first which we just run)
        for(int i=1; i<enabled_task_count; i++)
            enabled_task_array[i]->deadline -= delta_time;
    }
}


int main(){
    WDTCTL = WDTPW | WDTHOLD;

    resets++;
    if(resets==0){
        initialize();
    } else {
        // restarted after power failure, must subtract to deadlines the tardis time
        siren_command("PRINTF: restarted after %l microseconds\n", tardis_time);
        for(int i=0; i<enabled_task_count; i++)
            enabled_task_array[i]->deadline -= tardis_time;
    }

    // just to limit the exec time
    if(resets==10){
        siren_command("PRINTF: done, restarted %u\r\n", resets);
        return 0;
    }

    scheduler();
    return 0;
}

