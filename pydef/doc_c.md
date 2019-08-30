# Table of content
[TOC]

# Tasks

## Define

### `TASK_COUNT`
The number of deployed tasks.

## Typedef

### `task_struct_t`
A struct to store task metadata 
```c
typedef struct task_struct {
  float e_wc;
  struct task_struct *in_set[3];
  int in_set_count;
  void (*function_pointer)();
} task_struct_t;
```
- `float e_wc` task worst case energy consumption;
- `task_struct *in_set[]` an array of pointers to the struct of the tasks included in the in set;
- `int in_set_count` number of tasks in the in set;
- `void (*function_pointer)()` function pointer to task code segment.

## Variables
### *persistent* `task_struct_t task_struct_<task_id>`
One struct per task is stored on non volatile memory with the following naming convention: `task_struct_<task_id>` (e.g. for task `task_1` a struct is stored on non volatile memory with the identifier `task_struct_task_1`.).
### *persistent* `task_struct_t *task_array[TASK_COUNT]`
An array with pointers to all the deployed tasks metadata struct.
### *persistent* `task_struct_t *active_task_array[TASK_COUNT]`
An array with pointers to all currently running tasks metadata struct.
### *persistent* `int active_task_count`
Counter of active tasks, initialized to 0.
### *persistent* `task_struct_t *enabled_task_array[TASK_COUNT]`
An array with pointers to all the struct of tasks of active applications with satisfied dependencies.
### *persistent* `int enabled_task_count`
Counter of enabled tasks, initialized to 0.

# Applications

## Define

### `APP_COUNT` 
The number of deployed applications

## Typedef

### `app_struct_t`
A struct to store application metadata
```c
typedef struct app_struct {
  task_struct_t *app_tasks[5];
  task_struct_t *initial_task;
  int tasks_count;
  float x_min;
} app_struct_t;
```
- `task_struct_t* app_tasks[]` an array of pointers to the struct of the tasks included in the application;
- `task_struct_t* initial_task[]` a pointer to the struct of application initial task;
- `int task_count` the number of tasks included in the application;
- `x_min` the minimum requested throughput.

## Variables

### *persistent* `app_struct_t app_struct_<app_id>`
One struct per application is stored on non volatile memory with the following naming convention: `app_struct_<app_id>` (e.g. for application `app_1` a struct is stored on non volatile memory with the identifier `app_struct_app_1`.)
### *persistent* `app_struct_t *app_array[APP_COUNT]`
An array with pointers to all the deployed applications metadata struct
### *persistent* `app_struct_t *active_app_array[APP_COUNT]`
An array with pointers to all the active applications. The array is initially empty.
### *persistent* `int active_app_count`
Counter of active apps, initialized to 0.

