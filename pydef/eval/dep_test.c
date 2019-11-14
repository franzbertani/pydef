#include "header.h"
#include "printf.h"
#include <msp430fr6989.h>

DECLARE_OUTPUT_VARIABLES
EXTERN_VARS


int __attribute__ ((persistent)) resets = -1;
int __attribute__ ((persistent)) seen_resets = 0;
int __attribute__ ((persistent)) next_task = 0;
int __attribute__ ((persistent)) tardis_time = 0;
unsigned long int __attribute__ ((persistent)) delta_cycles = 0;
unsigned long int __attribute__ ((persistent)) frequency = 0;
unsigned long int __attribute__ ((persistent)) exec_depth_x100 = 0;
unsigned int __attribute__ ((persistent)) voltageX100 = 0;
void activate_new_app();
void manage_underperf();
void manage_overperf();

BEGIN_TASK_sense
    siren_command("PRINTF: running SENSE\n");
    int sense_out;
    sense_out = 1;
    __delay_cycles(40000);
    RETURN_sense
END_TASK

BEGIN_TASK_lowpass
    siren_command("PRINTF: running LOWPASS\n");
    int lowpass_out;
    lowpass_out = 1;
    __delay_cycles(25000);
    RETURN_lowpass
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


void heapify(task_struct_t* a[],int n) {
    task_struct_t *item;
    int k,i,j;
    for (k=1;k<n;k++) {
        item = a[k];
        i = k;
        j = (i-1)/2;
        while((i>0)&&(item->deadline[item->deadlineVersion] > a[j]->deadline[a[j]->deadlineVersion])) {
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
           if(a[i]->deadline[a[i]->deadlineVersion] < a[i+1]->deadline[a[i+1]->deadlineVersion])
            i++;
        if(item->deadline[item->deadlineVersion] < a[i]->deadline[a[i]->deadlineVersion]) {
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



void initialize(){
    siren_command("PRINTF: initialize after first boot\n");
    siren_command("SET_TARDIS_VARIABLE: %u\n", &tardis_time);

    /* activate first app and its tasks L:4-5 */
    app_struct_t *app = app_array[active_app_count];
    short int version = app->isActiveVersion;
    app->isActive[!version & 0x1] |= 0x1;
    active_app_array[active_app_count] = app;
    app->isActiveVersion = !version & 0x1;
    active_app_count++;

    for(int i=0; i<app->tasks_count; i++){
        version = (app->app_tasks)[i]->isActiveVersion;
        (app->app_tasks)[i]->isActive[!version & 0x1] |= 0x1;
        (app->app_tasks)[i]->isActiveVersion = !version & 0x1;
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
            new_tasks[i]->isActive[!version & 0x1] |= 0x1;
            new_tasks[i]->isActiveVersion = !version & 0x1;
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
            active_task_array[i]->deadline[!version & 0x1] = app->x_min;
            active_task_array[i]->deadlineVersion = !version & 0x1;
            version = active_task_array[i]->isEnabledVersion;
            active_task_array[i]->isEnabled[!version & 0x1] |= 0x1;
            active_task_array[i]->isEnabledVersion = !version & 0x1;
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

    siren_command("START_CCOUNT: sched\n");

    if(seen_resets != resets){ // a reset occurred
        seen_resets = resets;
        if(next_task == 1){
            siren_command("PRINTF: restore\n");
            //RESTORE(g_task_1, var_struct_task_1, 0);
        }
    }

    siren_command("GET_CCOUNT: sched-%l\n", &delta_cycles);
    siren_command("TEST_EXECUTION_CCOUNT: %l, scheduler restore\n", delta_cycles);

    short int version;
    while(1){
        siren_command("START_CCOUNT: sched\n");
        //sort array of enabled tasks based on deadlines, probably a rb tree is better
        heapsort(enabled_task_array, enabled_task_count);

        siren_command("PRINTF: sense[%l,%l] version=%u\n", task_struct_sense.deadline[0],task_struct_sense.deadline[1], task_struct_sense.deadlineVersion);
        siren_command("PRINTF: lowpass[%l,%l] version=%u\n", task_struct_lowpass.deadline[0],task_struct_lowpass.deadline[1], task_struct_lowpass.deadlineVersion);

        siren_command("PRINTF: selected task deadline %l\n", enabled_task_array[0]->deadline[enabled_task_array[0]->deadlineVersion]);
        //select and exec task with lowest deadline that fits the exec depth
        int selection = 0;
        unsigned long int exec_depth = get_exec_depth_x100();
        while(selection < enabled_task_count && exec_depth<=(enabled_task_array[selection]->e_wc) * 10) selection++; //e_wc is 10^3cycles, exec_depth is 10^2cycles
        if(selection==enabled_task_count) {
            siren_command("PRINTF: no task fits the current energy budget\n");
            siren_command("SLEEP_FOR_TIME: 1000\n"); //1ms
        } else {
            next_task_struct = *(enabled_task_array[selection]);
            (next_task_struct.function_pointer)();

            //subtract to all deadlines of other tasks exec time (not to the one that we just run)
            siren_command("PRINTF: delta_cycles = %l\n", delta_cycles);
            siren_command("PRINTF: enabled_tasks %u\n", enabled_task_count);
            for(int i=0; i<enabled_task_count; i++){
                /* if(i==selection) continue; */
                version = enabled_task_array[i]->deadlineVersion;
                enabled_task_array[i]->deadline[!version & 0x1] = enabled_task_array[i]->deadline[version] - delta_cycles; //freq @ 1Mhz and deadline in microsec => cycles = microsec
                enabled_task_array[i]->deadlineVersion = !version & 0x1;
            }
        }
        siren_command("GET_CCOUNT: sched-%l\n", &delta_cycles);
        siren_command("TEST_EXECUTION_CCOUNT: %l, schedule\n", delta_cycles);
        manage_overperf();
    }
}

void remove_last_app(){
    app_struct_t *app = active_app_array[active_app_count-1];
    short int isActiveVersion = app->isActiveVersion;
    app->isActive[!isActiveVersion & 0x1] = 0x0;
    active_app_count--;
    app->isActiveVersion = !isActiveVersion & 0x1;
    return;
}

void prune_tasks(){
    return;
}

void reset_threshold(){
    return;
}

void increase_threshold(){
    return;
}

void manage_underperf(){
    char found = 0;
    for(int i=0; i<active_app_count && !found; i++){
        if(active_app_array[i]->x_ok[active_app_array[i]->x_okVersion] == -1){ //underperforming
            found = 1;
            if(i!=active_app_count){ //there are other active apps beside me
                remove_last_app();
                prune_tasks();
                reset_threshold();
            } else {
                increase_threshold();
            }
        }
    }
    return;
}

void activate_new_app(){
    if(active_app_count==1){
        siren_command("PRINTF: just one app...\n");
        return;
    }
    app_struct_t *app = app_array[active_app_count]; //activate first not active app
    short int appVersion = app->isActiveVersion;
    app->isActive[!appVersion & 0x1] |= 0x1;

    int added_tasks = 0;
    short int taskVersion;
    for(int i=0; i<app->tasks_count; i++){
        taskVersion = (app->app_tasks)[i]->isActiveVersion;
        if(!((app->app_tasks)[i]->isActive[taskVersion])){
            (app->app_tasks)[i]->isActive[!taskVersion & 0x1] |= 0x1;
            (app->app_tasks)[i]->isActiveVersion = !taskVersion & 0x1;
            active_task_array[active_task_count] = (app->app_tasks)[i];
            active_task_count++;
            added_tasks++;
        }
    }
    app->isActiveVersion = !appVersion & 0x1;
    active_app_array[active_app_count] = app;

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
            new_tasks[i]->isActive[!taskVersion & 0x1] |= 0x1;
            new_tasks[i]->isActiveVersion = !taskVersion & 0x1;
            active_task_array[active_task_count] = new_tasks[i];
            active_task_count++;
        }
    } while(new_task_counter != 0);

    //set the deadlines
    for(int i=0; i<active_task_count; i++){
        taskVersion = active_task_array[i]->deadlineVersion;
        if(active_task_array[i]->in_set_count == 0 && !(active_task_array[i]->isActive[active_task_array[i]->isActiveVersion])){
            active_task_array[i]->deadline[!taskVersion & 0x1] = app->x_min;
            active_task_array[i]->deadlineVersion = !taskVersion & 0x1;
            taskVersion = active_task_array[i]->isEnabledVersion;
            active_task_array[i]->isEnabled[!taskVersion & 0x1] |= 0x1;
            active_task_array[i]->isEnabledVersion = !taskVersion & 0x1;
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
        if(active_app_array[i]->x_ok[version] == 1){ //overperforming
            found = 1;
            activate_new_app();
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
            enabled_task_array[i]->deadline[!version & 0x1] -= tardis_time;
            enabled_task_array[i]->deadlineVersion = !version & 0x1;
        }
    }

    // just to limit the exec time
    if(resets==10){
        siren_command("PRINTF: done, restarted %u\r\n", resets);
        return 0;
    }
    siren_command("GET_CCOUNT: main-%l\n", &delta_cycles);
    siren_command("TEST_EXECUTION_CCOUNT: %l, main\n", delta_cycles);

    scheduler();
    return 0;
}



