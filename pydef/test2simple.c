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

BEGIN_TASK_task_1
    int t1_out;
#ifdef DEBUG
    siren_command("PRINTF: running task 1\n");
#endif
    t1_out = get_sample();
    RETURN_task_1
END_TASK

BEGIN_TASK_task_2
    int t2_output;
    t2_output = task_1 + 10;
#ifdef DEBUG
    siren_command("PRINTF: running task 2\n");
#endif
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
#ifdef DEBUG
    siren_command("PRINTF: initialize after first boot\n");
#endif
    /* activate first app */
    siren_command("GRAPH-EVENT: initialize\n");
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

#ifdef DEBUG
    siren_command("PRINTF: max energy prediction %u\n", max_energy_prediction);
#endif
    set_threshold(max_energy_prediction + AVG_OVERHEAD);
    return;
}

void scheduler(){
    task_struct_t next_task_struct;
    if(seen_resets != resets){
        seen_resets = resets;
        if(next_task == 1){
#ifdef DEBUG
            siren_command("PRINTF: restore\n");
#endif
            RESTORE(g_task_1, var_struct_task_1, 0);
        }
    }
    while(1){
        next_task_struct = *(task_array[next_task]);
        (next_task_struct.function_pointer)();
        next_task = (next_task+1) % 2;
        //siren_command("RESET:\n");
    }
}








#define DATA_POINTS_N 65
#define MILLI_INTERVAL 123
#define SHIFT_BITS 6
/* This is an array of times (in milliseconds) mapped to a 12-bit ADC */
const uint16_t _current_curve[DATA_POINTS_N] ={65535,6666,5551,4900,4438,4081,3789,3542,3328,3139,2970,2818,2679,2550,2432,2321,2218,2121,2029,1943,1861,1783,1708,1637,1569,1504,1441,1380,1322,1266,1212,1159,1109,1059,1012,965,920,876,834,792,751,712,673,636,599,563,528,493,460,427,394,363,332,301,271,242,213,185,157,129,103,76,50,25,0};

/**
 * Call this to get the time elapsed (ms) for a 0.1uF CusTARD capacitor (20MΩ discharge) on a 1.8V VCC
 * @param  _adc_14_value [description]
 * @return               [description]
 */
uint16_t fast_tardis(uint16_t _adc_14_value)
{
    int16_t left = _adc_14_value >> SHIFT_BITS;
    return  _current_curve[left] -
                ((
                    (uint32_t)(_current_curve[left] - _current_curve[left+1]) *
                    (uint32_t)(_adc_14_value - (left << SHIFT_BITS))
                ) >> SHIFT_BITS);
}


uint16_t read_voltage_adc()
{

  int voltage;
  ADC12CTL0 &= ~ADC12ENC;                    // Disable conversions to change input
  ADC12MCTL0 |= BIT2;                       // Input 4
  ADC12CTL0 |= ADC12ENC;                   // Re-enable conversions
  ADC12CTL0 |= ADC12SC;                   // Start conversion-software trigger
  while (!(ADC12IFGR0 & BIT0));
  voltage = 4 + ((double) ADC12MEM0 / 32);
  return voltage;                     // Read conversion result
}













int main(){
	int i, a;
	float b;

    WDTCTL = WDTPW | WDTHOLD;

    siren_command("PRINTF: starting\n");
    resets++;

    for(i = 0; i < 10000; i++) {
    	a = i;
    	a--;
    	a = a * 50 + i / 7;

    	b = (float)a / (float)i * 5;

/*    	if((i+1) % 200 == 0) {
    		siren_command("RESET: \n");
    	}
*/
    	if(i %150 == 0) {
    		siren_command("PRINTF: dai cazzo gianluca\n");
    		siren_command("PRINTF: %u\n", resets);
    		siren_command("PRINTF: %u\n", i);
    		siren_command("PRINTF: \n");
    	}
    }

    return 0;
}

