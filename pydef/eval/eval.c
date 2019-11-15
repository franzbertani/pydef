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
unsigned long int __attribute__ ((persistent)) delta_cycles = 0;
unsigned long int __attribute__ ((persistent)) frequency = 0;
unsigned long int __attribute__ ((persistent)) exec_depth_x100 = 0;
unsigned int __attribute__ ((persistent)) voltageX100 = 0;
short int __attribute__ ((persistent)) is_pruning = 0;
short int __attribute__ ((persistent)) isSenseEnabled = 1;


void activate_new_app();
void manage_underperf();
void manage_overperf();
int check_if_new(task_struct_t*);
void set_threshold(int);
unsigned long int get_exec_depth_x100();
void initialize();
void prune_tasks();

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
    __delay_cycles(40000);
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
    __delay_cycles(40000);
    RETURN_compress
END_TASK

BEGIN_TASK_send
    siren_command("PRINTF: running SEND\n");
    int send_out;
    __delay_cycles(90000);
    RETURN_send
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
    siren_command("PRINTF: initialize after first boot\n");
    siren_command("SET_TARDIS_VARIABLE: %u\n", &tardis_time);

    /* activate first app and its tasks L:4-5 */
    app_struct_t *app = app_array[active_app_count];
    short int version = app->isActiveVersion;
    app->isActive[ ( !version ) & 0x1] |= 0x1;
    active_app_array[active_app_count] = app;
    app->isActiveVersion = ( !version ) & 0x1;
    active_app_count=1;

    for(int i=0; i<app->tasks_count; i++){
        version = (app->app_tasks)[i]->isActiveVersion;
        (app->app_tasks)[i]->isActive[ ( !version ) & 0x1] |= 0x1;
        (app->app_tasks)[i]->isActiveVersion = ( !version ) & 0x1;
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
            version = new_tasks[i]->isActiveVersion;
            new_tasks[i]->isActive[ ( !version ) & 0x1] |= 0x1;
            new_tasks[i]->isActiveVersion = ( !version ) & 0x1;
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
            version = active_task_array[i]->deadlineVersion;
            active_task_array[i]->deadline[ ( !version ) & 0x1] = app->x_min;
            active_task_array[i]->deadlineVersion = ( !version ) & 0x1;
            version = active_task_array[i]->isEnabledVersion;
            active_task_array[i]->isEnabled[ (!version) & 0x1] |= 0x1;
            active_task_array[i]->isEnabledVersion = ( !version ) & 0x1;
            enabled_task_array[enabled_task_count] = active_task_array[i];
            enabled_task_count++;
        }
    }

    /* L:23 */
    /* set_threshold(30); */
    set_threshold(max_energy_prediction + AVG_OVERHEAD);
    return;
}

void scheduler(){
    task_struct_t next_task_struct;

    siren_command("START_CCOUNT: scheduler\n");

    if(seen_resets != resets){ // a reset occurred
        seen_resets = resets;
        if(next_task == 1){

#if DEBUG
            siren_command("PRINTF: restore\n");
#endif

            if(is_pruning) prune_tasks();
            //RESTORE(g_task_1, var_struct_task_1, 0);
        }
    }

    siren_command("GET_CCOUNT: scheduler-%l\n", &delta_cycles);
    siren_command("TEST_EXECUTION_CCOUNT: %l, scheduler restore\n", delta_cycles);

    short int version;
    while(1){
        siren_command("START_CCOUNT: scheduler\n");

        //just for the eval example
        siren_command("GET_TIME: misd(SENSE)-%u\n", &isSenseEnabled);

#if DEBUG
        siren_command("PRINTF: SENSE enabled? %u\n", isSenseEnabled);
#endif

        if(isSenseEnabled){ //50Hz set in SIREN

#if DEBUG
            siren_command("PRINTF: SENSE re enabled\n");
#endif

            task_struct_sense.stopped=0;
        }

        //sort array of enabled tasks based on deadlines, probably a rb tree is better
        heapsort(enabled_task_array, enabled_task_count);

#if DEBUG
        siren_command("PRINTF: sense[%l,%l] version=%u\n", task_struct_sense.deadline[0],task_struct_sense.deadline[1], task_struct_sense.deadlineVersion);
        siren_command("PRINTF: median[%l,%l] version=%u\n", task_struct_median.deadline[0],task_struct_median.deadline[1], task_struct_median.deadlineVersion);
        siren_command("PRINTF: lowpass[%l,%l] version=%u\n", task_struct_lowpass.deadline[0],task_struct_lowpass.deadline[1], task_struct_lowpass.deadlineVersion);
        siren_command("PRINTF: magnitude[%l,%l] version=%u\n", task_struct_magnitude.deadline[0],task_struct_magnitude.deadline[1], task_struct_magnitude.deadlineVersion);
        siren_command("PRINTF: classify[%l,%l] version=%u\n", task_struct_classify.deadline[0],task_struct_classify.deadline[1], task_struct_classify.deadlineVersion);
        siren_command("PRINTF: operate[%l,%l] version=%u\n", task_struct_operate.deadline[0],task_struct_operate.deadline[1], task_struct_operate.deadlineVersion);
        siren_command("PRINTF: compress[%l,%l] version=%u\n", task_struct_compress.deadline[0],task_struct_compress.deadline[1], task_struct_compress.deadlineVersion);
        siren_command("PRINTF: send[%l,%l] version=%u\n", task_struct_send.deadline[0],task_struct_send.deadline[1], task_struct_send.deadlineVersion);
        siren_command("PRINTF: selected task deadline %l\n", enabled_task_array[0]->deadline[enabled_task_array[0]->deadlineVersion]);
#endif

        //select and exec task with lowest deadline that fits the exec depth
        int selection = 0;
        unsigned long int exec_depth = get_exec_depth_x100();

        while(selection < enabled_task_count && (enabled_task_array[selection]->stopped == 1 || exec_depth<=(enabled_task_array[selection]->e_wc) * 10)){ //e_wc is 10^3cycles, exec_depth is 10^2cycles
            if(enabled_task_array[selection]->stopped == 1)
                siren_command("PRINTF: skipping task %u, misd condition not satisfied\n", selection);
            else
                siren_command("PRINTF: skipping task %u, does not fit current energy budget\n", selection);
            selection++;
        }

        if(selection==enabled_task_count) {
            siren_command("PRINTF: no task is currently available, sleeping for 1ms\n");
            siren_command("SLEEP_FOR_TIME: 1000\n"); //1ms
            for(short int i=0; i<enabled_task_count; i++){
                enabled_task_array[i]->deadline[enabled_task_array[i]->deadlineVersion]-=1000;
            }
        } else {
            next_task_struct = *(enabled_task_array[selection]);
            if(next_task_struct.function_pointer == task_struct_sense.function_pointer ){
                task_struct_sense.stopped = 1;
            }
            siren_command("GET_CCOUNT: scheduler-%l\n", &delta_cycles);
            siren_command("TEST_EXECUTION_CCOUNT: %l, schedule\n", delta_cycles);

            (next_task_struct.function_pointer)();

            if(next_task_struct.function_pointer == task_struct_sense.function_pointer){
                if(var_struct_sense.write_count<10){
                    version = task_struct_sense.deadlineVersion;
                    task_struct_sense.deadline[version]=task_struct_sense.deadline[ ( !version ) &0x1];
                }
            } else if(next_task_struct.function_pointer == task_struct_operate.function_pointer){
                siren_command("LOG_EVENT: app_1 done\n");
            } else if(next_task_struct.function_pointer == task_struct_send.function_pointer){
                siren_command("LOG_EVENT: app_2 done\n");
            }

#if DEBUG
            siren_command("PRINTF: delta_cycles = %l\n", delta_cycles);
            siren_command("PRINTF: enabled_tasks %u\n", enabled_task_count);
            siren_command("PRINTF: active apps %u\n", active_app_count);
#endif
            //subtract to all deadlines tasks exec time
            for(int i=0; i<enabled_task_count; i++){
                /* if(i==selection) continue; */
                version = enabled_task_array[i]->deadlineVersion;
                enabled_task_array[i]->deadline[ ( !version ) & 0x1] = enabled_task_array[i]->deadline[version] - delta_cycles; //freq @ 1Mhz and deadline in microsec => cycles = microsec
                enabled_task_array[i]->deadlineVersion = ( !version ) & 0x1;
            }
        }
    }
}


typedef struct queue {
    task_struct_t* array[TASK_COUNT];
    short int size;
} queue_t;

queue_t __attribute__ ((persistent)) queues[2];
short int __attribute__ ((persistent)) valid_queue = 0;
app_struct_t __attribute__ ((persistent)) *removed;

app_struct_t* remove_last_app(){
    siren_command("PRINTF: removing app %u\n", active_app_count);
    app_struct_t *app = active_app_array[active_app_count-1];
    short int isActiveVersion = app->isActiveVersion;
    active_app_count = 1; //HACK FEST
    app->isActive[(!isActiveVersion) & 0x1] = 0x0;
    removed = app;
    queues[(!valid_queue) & 0x1].array[0] = removed->final_task;
    queues[(!valid_queue) & 0x1].size++;
    removed->final_task->marked_to_remove[(!valid_queue)&0x1] = 1;
    is_pruning = 1;
    valid_queue = (!valid_queue) & 0x1;
    app->isActiveVersion = (!isActiveVersion) & 0x1;
    return app;
}

void prune_tasks(){
    if(removed->isActive[removed->isActiveVersion]){ //spento prima del flip finale in remove_last_app
        queues[valid_queue].size=0;
        is_pruning = 0;
        return;
    }
    while(queues[valid_queue].size!=0){
        task_struct_t *task = queues[valid_queue].array[queues[valid_queue].size-1];
        queues[(!valid_queue) & 0x1].size--;
        for(short int i=0; i<task->in_set_count; i++){
            //controllo che le app del task iesimo siano tutte disattivate
            short int remove=1;
            for(short int j=0; j<APPS_COUNT && remove; j++){
                for(short int k=0; k<app_array[j]->tasks_count && remove; k++){
                    if(app_array[j]->app_tasks[k]==task && app_array[j]->isActive[app_array[j]->isActiveVersion])
                        remove=0;
                }
            }
            if(remove)
                if(task->in_set[i]->marked_to_remove[valid_queue] != 1){
                    //lo aggiungo
                    //lo marko
                    short int size = queues[(!valid_queue) & 0x1].size;
                    queues[(!valid_queue) & 0x1].array[size] = task->in_set[i];
                    queues[(!valid_queue) & 0x1].size++;
                    task->in_set[i]->marked_to_remove[(!valid_queue) & 0x1] = 1;
                }
        } //flippo valid_queue
        valid_queue = (!valid_queue) & 0x1;
    }
    //rimuovo i marcati
    for(short int i=0; i<TASK_COUNT; i++){
        if(task_array[i]->marked_to_remove[valid_queue] ==1){

            for(int j=0; j<active_task_count; j++){
                if(active_task_array[j]==task_array[i]){
                    siren_command("PRINTF: ACTIVE TASK COUNT %u\n", active_task_count);
                    active_task_array[j] = active_task_array[active_task_count-1];
                    active_task_count--;
                }
            }
            siren_command("PRINTF: ACTIVE %u\n", active_app_count);

            for(int j=0; j<enabled_task_count; j++){
                if(enabled_task_array[j]==task_array[i]){
                    enabled_task_array[j] = enabled_task_array[enabled_task_count-1];
                    enabled_task_count--;
                }
            }
            task_array[i]->marked_to_remove[valid_queue] = 0;
            task_array[i]->deadline[0] = 0;
            task_array[i]->deadline[1] = 0;
            task_array[i]->isEnabled[0] = 0;
            task_array[i]->isEnabled[1] = 0;
            task_array[i]->isActive[0] = 0;
            task_array[i]->isActive[1] = 0;
        }
    }
    is_pruning = 0;
    return;
}

void reset_threshold(){
    int energy_prediction[TASK_COUNT];
    int max_energy_prediction = -10;
    for(int i=0; i<active_task_count; i++){
        energy_prediction[i] = active_task_array[i]->e_wc + RESTORE_OVERHEAD*active_task_array[i]->in_set_count;
        max_energy_prediction = MAX(max_energy_prediction, energy_prediction[i]);
    }
    set_threshold(max_energy_prediction + AVG_OVERHEAD);
    return;
}

void increase_threshold(){
    siren_command("INCREASE_THRESHOLD:\n");
    return;
}

void deactivate_2(){

    short int appVersion = app_struct_app_2.isActiveVersion;
    app_struct_app_2.isActive[(!appVersion)&0x1] = 0;

    short int send_index;
    short int compress_index;
    for(short int i=0; i<active_task_count; i++){
        if(active_task_array[i]==&task_struct_send){
            send_index = i;
        } else if(active_task_array[i]==&task_struct_compress){
            compress_index = i;
        }
    }
    active_task_array[compress_index] = active_task_array[active_task_count-1];
    active_task_count--;

    active_task_array[send_index] = active_task_array[active_task_count-1];
    active_task_count--;

    for(short int i=0; i<enabled_task_count; i++){
        if(enabled_task_array[i]==&task_struct_send){
            send_index = i;
        } else if(enabled_task_array[i]==&task_struct_compress){
            compress_index = i;
        }
    }
    enabled_task_array[compress_index] = enabled_task_array[active_task_count-1];
    enabled_task_count--;

    enabled_task_array[send_index] = enabled_task_array[active_task_count-1];
    enabled_task_count--;

    //should use versioning
    task_struct_compress.deadline[0] = 0;
    task_struct_compress.deadline[1] = 0;
    task_struct_send.deadline[0] = 0;
    task_struct_send.deadline[1] = 0;

    task_struct_compress.isEnabled[0] = 0;
    task_struct_compress.isEnabled[1] = 0;
    task_struct_send.isEnabled[0] = 0;
    task_struct_send.isEnabled[1] = 0;

    task_struct_compress.isActive[0] = 0;
    task_struct_compress.isActive[1] = 0;
    task_struct_send.isActive[0] = 0;
    task_struct_send.isActive[1] = 0;

    active_app_count = 1;
    app_struct_app_2.isActiveVersion = (!appVersion) &0x1;

    is_pruning =0;
    siren_command("LOG_EVENT: app_2 OFF\n");
}

void manage_underperf(){
    siren_command("START_CCOUNT: underperf\n");
    char found = 0;

    if(app_struct_app_1.x_ok[app_struct_app_1.x_okVersion]==-1){
        if(active_app_count ==1){
            increase_threshold();
        }
        else{
            is_pruning = 1;
            deactivate_2();
            reset_threshold();
        }
    } else if(app_struct_app_2.x_ok[app_struct_app_2.x_okVersion]==-1){
        increase_threshold();
    }
    siren_command("GET_CCOUNT: underperf-%u\n", &delta_cycles);
    siren_command("TEST_EXECUTION_CCOUNT: %u, underperf management\n", delta_cycles);

    /* for(int i=0; i<active_app_count && !found; i++){ */
    /*     if(active_app_array[i]->x_ok[active_app_array[i]->x_okVersion] == -1){ //underperforming */
    /*         found = 1; */
    /*         if(i<(active_app_count-1)){ //not the last app */
    /*             remove_last_app(); */
    /*             prune_tasks(); */
    /*             reset_threshold(); */
    /*             siren_command("GET_CCOUNT: underperf-%u\n", &delta_cycles); */
    /*             siren_command("TEST_EXECUTION_CCOUNT: %u, underperf management\n", delta_cycles); */
    /*         } else { */
    /*             siren_command("GET_CCOUNT: underperf-%u\n", &delta_cycles); */
    /*             siren_command("TEST_EXECUTION_CCOUNT: %u, underperf management\n", delta_cycles); */
    /*             increase_threshold(); */
    /*         } */
    /*     } */
    /* } */
    return;
}

void activate_new_app(){
    if(active_app_count>=2) return; //HACK FEST
    app_struct_t *app = app_array[active_app_count]; //activate first not active app
    short int appVersion = app->isActiveVersion;
    app->isActive[(!appVersion) & 0x1] |= 0x1;

    active_app_count = 2; //HACK FEST
    int added_tasks = 0;
    short int taskVersion;
    for(int i=0; i<app->tasks_count; i++){
        taskVersion = (app->app_tasks)[i]->isActiveVersion;
        if(!((app->app_tasks)[i]->isActive[taskVersion])){
            (app->app_tasks)[i]->isActive[(!taskVersion) & 0x1] |= 0x1;
            (app->app_tasks)[i]->isActiveVersion = (!taskVersion) & 0x1;
            active_task_array[active_task_count] = (app->app_tasks)[i];
            active_task_count++;
            added_tasks++;
        }
    }
    app->isActiveVersion = (!appVersion) & 0x1;
    active_app_array[active_app_count-1] = app;

    if(added_tasks == 0) return;

    /* filling tasks set with extra app dependencies */
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
            new_tasks[i]->isActive[ ( !taskVersion ) & 0x1] |= 0x1;
            new_tasks[i]->isActiveVersion = ( !taskVersion ) & 0x1;
            active_task_array[active_task_count] = new_tasks[i];
            active_task_count++;
        }
    } while(new_task_counter != 0);

    //set the deadlines
    for(int i=0; i<active_task_count; i++){
        taskVersion = active_task_array[i]->deadlineVersion;
        if(active_task_array[i]->in_set_count == 0 && !(active_task_array[i]->isActive[active_task_array[i]->isActiveVersion])){
            active_task_array[i]->deadline[ ( !taskVersion ) & 0x1] = app->x_min;
            active_task_array[i]->deadlineVersion = ( !taskVersion ) & 0x1;
            taskVersion = active_task_array[i]->isEnabledVersion;
            active_task_array[i]->isEnabled[ ( !taskVersion ) & 0x1] |= 0x1;
            active_task_array[i]->isEnabledVersion = ( !taskVersion ) & 0x1;
            enabled_task_array[enabled_task_count] = active_task_array[i];
            enabled_task_count++;
        }
    }
    return;
}

void manage_overperf(){
    short int found = 0;
    short int version;
    for(int i=0; i<active_app_count && !found; i++){
        version = active_app_array[i]->x_okVersion;
        if(active_app_array[i]->x_ok[version] == 1 && active_app_count < 2){ //overperforming
            found = 1;
            activate_new_app();
            siren_command("LOG_EVENT: app_2 ON\n");
        }
    }
    return;
}

int main(){
    siren_command("START_CCOUNT: main\n");
    siren_command("GET_FREQ: %u\n", &frequency);
    siren_command("PRINTF: running @ %l Hz\n", frequency);
    WDTCTL = WDTPW | WDTHOLD;

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
    }

    siren_command("GET_CCOUNT: main-%l\n", &delta_cycles);
    siren_command("TEST_EXECUTION_CCOUNT: %l, main\n", delta_cycles);

    scheduler();
    return 0;
}

