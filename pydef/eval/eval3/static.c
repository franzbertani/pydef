#include <stdio.h>
#include <stdint.h>
#include "printf.h"
#include "sort.h"

#ifndef HEADER_H
#define HEADER_H
    #include "header.h"
#endif

#ifndef MSPLIB_H
#define MSPLIB_H
    #include <msp430fr6989.h>
#endif

DECLARE_OUTPUT_VARIABLES
EXTERN_VARS

int __attribute__ ((persistent)) resets = -1;
int __attribute__ ((persistent)) seen_resets = 0;
int __attribute__ ((persistent)) next_task = 0;
long int __attribute__ ((persistent)) tardis_time = 0;
long int __attribute__ ((persistent)) delta_cycles = 0;
long int __attribute__ ((persistent)) frequency = 0;
long int __attribute__ ((persistent)) exec_depth_x100 = 0;
long int __attribute__ ((persistent)) voltageX100 = 0;
long int __attribute__ ((persistent)) is_pruning = 0;
long int __attribute__ ((persistent)) isSenseEnabled = 1;
long int __attribute__ ((persistent)) slack = 0;
long int __attribute__ ((persistent)) selected_app = 0;
task_struct_t* __attribute ((persistent)) ordered_tasks_array[18] = {
    &task_struct_sense,
    &task_struct_median,
    &task_struct_lowpass,
    &task_struct_magnitude,
    &task_struct_classify,
    &task_struct_operate,
    &task_struct_sense,
    &task_struct_median,
    &task_struct_lowpass,
    &task_struct_magnitude,
    &task_struct_classify,
    &task_struct_operate,
    &task_struct_sense,
    &task_struct_median,
    &task_struct_lowpass,
    &task_struct_magnitude,
    &task_struct_classify,
    &task_struct_operate};
long int __attribute__ ((persistent)) over_counter[2] = {0,0};
long int __attribute__ ((persistent)) under_counter[2] = {0,0};



void activate_new_app();
void manage_underperf();
void manage_overperf();
int check_if_new(task_struct_t*);
void set_threshold(int);
unsigned long int get_exec_depth_x100();
void initialize();
void prune_tasks();
void subtract_cycles_from_all();

BEGIN_TASK_sense
    siren_command("PRINTF: running SENSE\n");
    acc_struct_t sense_out;
    __delay_cycles(80000);
    siren_command("START_TIME: misd(SENSE)\n");
    RETURN_sense
END_TASK


BEGIN_TASK_median
    siren_command("PRINTF: running MEDIAN\n");
    acc_struct_t* median_out;
    __delay_cycles(32000);
    RETURN_median
END_TASK

BEGIN_TASK_lowpass
    siren_command("PRINTF: running LOWPASS\n");
    acc_struct_t* lowpass_out;
    __delay_cycles(50000);
    RETURN_lowpass
END_TASK

BEGIN_TASK_magnitude
    siren_command("PRINTF: running MAGNITUDE\n");
    acc_struct_t* magnitude_out;
    __delay_cycles(15000);
    RETURN_magnitude
END_TASK

BEGIN_TASK_classify
    siren_command("PRINTF: running CLASSIFY\n");
    int classify_out;
    __delay_cycles(15000);
    RETURN_classify
END_TASK

BEGIN_TASK_operate
    siren_command("PRINTF: running OPERATE\n");
    int operate_out;
    __delay_cycles(30000);
    RETURN_operate
END_TASK

BEGIN_TASK_compress
    siren_command("PRINTF: running COMPRESS\n");
    int compress_out;
    __delay_cycles(20000);
    RETURN_compress
END_TASK

BEGIN_TASK_send
    siren_command("PRINTF: running SEND\n");
    int send_out;
    __delay_cycles(300000);
    RETURN_send
END_TASK

TASKS_STRUCTS
TASK_ARRAY
APP_STRUCTS
APP_ARRAY


void subtract_cycles_from_all(){
    for(short int i=0, version; i<enabled_task_count; i++){
        version = enabled_task_array[i]->deadlineVersion;
        enabled_task_array[i]->deadline[ ( !version ) & 0x1] = enabled_task_array[i]->deadline[version] - delta_cycles; //freq @ 1Mhz and deadline in microsec => cycles = microsec
        enabled_task_array[i]->deadlineVersion = ( !version ) & 0x1;
    }
    if(selected_app>0)
        slack-=delta_cycles;
}

int check_if_new(task_struct_t *task){
    for(int i=0; i<active_task_count; i++){
        if(active_task_array[i] == task)
            return 0;
    }
    return 1;
}

void set_threshold(int energy){
    siren_command("SET_VON: %u\n",energy);
    return;
}

unsigned long int get_exec_depth_x100(){
    siren_command("GET_CAP_VOLTAGE: %u\n", &voltageX100);
    exec_depth_x100 = voltageX100*voltageX100*235;
    return exec_depth_x100;
}

void initialize(){
    siren_command("PRINTF: initializing board after first boot.\n");
    siren_command("SET_TARDIS_VARIABLE: %u\n", &tardis_time);

    set_tasks_app_pointers(); 
    set_threshold(90);
    return;
}

void scheduler(){
    task_struct_t next_task_struct;

    siren_command("START_CCOUNT: scheduler\n");

    if(seen_resets != resets){ // a reset occurred
        seen_resets = resets;
        if(next_task == 1){

#if DEBUG
            siren_command("PRINTF: restoring after power failure.\n");
#endif

        }
    }

    siren_command("GET_CCOUNT: scheduler-%l\n", &delta_cycles);
    siren_command("TEST_EXECUTION_CCOUNT: %l, scheduler restore\n", delta_cycles);
    subtract_cycles_from_all();

    while(1){

        /* Just for the eval example*/
        siren_command("GET_TIME: misd(SENSE)-%u\n", &isSenseEnabled);

        /* Re enabling SENSE if misd satisfied. */
        if(isSenseEnabled){ //50Hz set in SIREN
            task_struct_sense.stopped=0;
        }
        next_task_struct = *(ordered_tasks_array[next_task]);
        if(next_task_struct.stopped){
            siren_command("SLEEP_FOR_TIME: 1000\n");
        } else {
            (next_task_struct.function_pointer)(); //run
            siren_command("START_CCOUNT: scheduler\n");
            if(next_task_struct.function_pointer == task_struct_sense.function_pointer ){
                task_struct_sense.stopped = 1;
            }
            if(next_task_struct.function_pointer == task_struct_operate.function_pointer){
                siren_command("LOG_EVENT: app_1 done\n");
            } else if(next_task_struct.function_pointer == task_struct_send.function_pointer){
                siren_command("LOG_EVENT: app_2 done\n");
            }
            next_task = (next_task+1)%18;
            siren_command("GET_CCOUNT: scheduler-%l\n", &delta_cycles);
            siren_command("TEST_EXECUTION_CCOUNT: %l, schedule\n", delta_cycles);
        }
        subtract_cycles_from_all();
    }
}

void reset_threshold(){
    return;
}

void increase_threshold(){
    return;
}

//should be generated by the preprocessor
//this approach replaces task pruning since it's more efficient.
void deactivate_2(){
    return;
}

void manage_underperf(){
    return;
}

void activate_new_app(){
    return;
}

void manage_overperf(){
    return;
}

int main(){
    siren_command("START_CCOUNT: main\n");
    siren_command("GET_FREQ: %u\n", &frequency);
    siren_command("PRINTF: running @ %l Hz\n", frequency);
    WDTCTL = WDTPW | WDTHOLD;
    slack=0;

    resets++;
    if(resets==0){
        initialize();
    } else {
        // restarted after power failure, must subtract to deadlines the tardis time
        siren_command("PRINTF: restarted after %l microseconds\n", tardis_time);
        short int version;
        for(int i=0; i<enabled_task_count; i++){
            version = enabled_task_array[i]->deadlineVersion;
            enabled_task_array[i]->deadline[ ( !version ) & 0x1] -= tardis_time;
            enabled_task_array[i]->deadlineVersion = ( !version ) & 0x1;

        }
        if(selected_app>0)
            slack-=tardis_time;
    }

    siren_command("GET_CCOUNT: main-%l\n", &delta_cycles);
    siren_command("TEST_EXECUTION_CCOUNT: %l, main\n", delta_cycles);
    subtract_cycles_from_all();

    scheduler();
    return 0;
}

