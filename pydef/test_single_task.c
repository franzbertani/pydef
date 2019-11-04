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

int __attribute__ ((persistent)) delta_cycles = 0;
float __attribute__ ((persistent)) tputs[2] = {0,0};

void
task_1()
{
  /* siren_command("START_CCOUNT: task\n"); */
  /* siren_command("PRINTF: running task 1\n"); */
  int t1_out;
  t1_out = get_sample();
  g_task_1 = t1_out;
  var_struct_task_1.version_array[var_struct_task_1.write_index] = g_task_1;
  var_struct_task_1.write_index = (var_struct_task_1.write_index + 1) % (var_struct_task_1.versions_count + 1);
  if(var_struct_task_1.is_full) {
    var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % (var_struct_task_1.versions_count + 1);
  } else if(var_struct_task_1.write_index == 0) {
    var_struct_task_1.is_full = 1;
    var_struct_task_1.window_begin_index = (var_struct_task_1.window_begin_index + 1) % (var_struct_task_1.versions_count + 1);
  }
  extern task_struct_t task_struct_task_2;
  if(!(task_struct_task_2.isEnabled) && (app_struct_app_1.isActive)) {
    task_struct_task_2.isEnabled |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_task_2;
    enabled_task_count++;
    if(app_struct_app_1.isActive) {
      task_struct_task_2.deadline = 1000000;
    }
  }
  extern task_struct_t task_struct_task_3;
  if(!(task_struct_task_3.isEnabled) && (app_struct_app_2.isActive)) {
    task_struct_task_3.isEnabled |= 0x1;
    enabled_task_array[enabled_task_count] = &task_struct_task_3;
    enabled_task_count++;
    if(app_struct_app_2.isActive) {
      task_struct_task_3.deadline = 333333;
    }
  }
  if(app_struct_app_2.isActive) {
    task_struct_task_1.deadline = 333333;
  } else if(app_struct_app_1.isActive) {
    task_struct_task_1.deadline = 1000000;
  }
  /* siren_command("GET_CCOUNT: task- %u\n", &delta_cycles); */
  /* siren_command("PRINTF: task 1 ccount = %u\n", delta_cycles); */
}
void
task_2()
{
  int task_1 = g_task_1;
  siren_command("START_TIME: task\n");
  siren_command("PRINTF: running task 2\n");
  int t2_output;
  t2_output = task_1 + 10;
  siren_command("LOG_EVENT: end app1\n");
  g_task_2 = t2_output;
  var_struct_task_2.version_array[var_struct_task_2.write_index] = g_task_2;
  var_struct_task_2.write_index = (var_struct_task_2.write_index + 1) % (var_struct_task_2.versions_count + 1);
  if(var_struct_task_2.is_full) {
    var_struct_task_2.window_begin_index = (var_struct_task_2.window_begin_index + 1) % (var_struct_task_2.versions_count + 1);
  } else if(var_struct_task_2.write_index == 0) {
    var_struct_task_2.is_full = 1;
    var_struct_task_2.window_begin_index = (var_struct_task_2.window_begin_index + 1) % (var_struct_task_2.versions_count + 1);
  }
  siren_command("GET_TIME: task- %u\n", &delta_cycles);
  siren_command("TEST_EXECUTION: %u\n", delta_cycles);
  unsigned long int value = 1000000 - task_struct_task_2.deadline - delta_cycles;
  siren_command("PRINTF: updating tput aftrer task_2\n");
  if(value < 0) {
    siren_command("PRINTF: underperforming\n");
    app_struct_app_1.x_ok = -1;
  } else if(value > 0) {
    siren_command("PRINTF: overperforming\n");
    app_struct_app_1.x_ok = 1;
  } else {
    siren_command("PRINTF: performance ok\n");
    app_struct_app_1.x_ok = 0;
  } if(app_struct_app_1.isActive) {
    task_struct_task_2.deadline = 1000000;
  }
}
void
task_3()
{
  int task_1 = g_task_1;
  siren_command("START_TIME: task\n");
  siren_command("PRINTF: running task 3\n");
  int t3_output;
  t3_output = task_1 * 10;
  siren_command("LOG_EVENT: end app2\n");
  g_task_3 = t3_output;
  var_struct_task_3.version_array[var_struct_task_3.write_index] = g_task_3;
  var_struct_task_3.write_index = (var_struct_task_3.write_index + 1) % (var_struct_task_3.versions_count + 1);
  if(var_struct_task_3.is_full) {
    var_struct_task_3.window_begin_index = (var_struct_task_3.window_begin_index + 1) % (var_struct_task_3.versions_count + 1);
  } else if(var_struct_task_3.write_index == 0) {
    var_struct_task_3.is_full = 1;
    var_struct_task_3.window_begin_index = (var_struct_task_3.window_begin_index + 1) % (var_struct_task_3.versions_count + 1);
  }
  siren_command("GET_TIME: task- %u\n", &delta_cycles);
  siren_command("TEST_EXECUTION: %u\n", delta_cycles);
  unsigned long int value = 333333 - task_struct_task_3.deadline - delta_cycles;
  siren_command("PRINTF: updating tput aftrer task_3\n");
  if(value < 0) {
    siren_command("PRINTF: underperforming\n");
    app_struct_app_2.x_ok = -1;
  } else if(value > 0) {
    siren_command("PRINTF: overperforming\n");
    app_struct_app_2.x_ok = 1;
  } else {
    siren_command("PRINTF: performance ok\n");
    app_struct_app_2.x_ok = 0;
  } if(app_struct_app_2.isActive) {
    task_struct_task_3.deadline = 333333;
  }
}

TASKS_STRUCTS
TASK_ARRAY
APP_STRUCTS
APP_ARRAY

int main(){
   task_1(); 
   return 0;
}
