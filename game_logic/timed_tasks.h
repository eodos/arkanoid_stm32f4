#ifndef TIMED_TASKS_H
#define TIMED_TASKS_H

// number of tasks for which space will be pre-allocated in fixed-size array of TimedTask's
#define N_TASKS 1

// typedef TaskType -- pointer to function that takes no arguments and returns nothing (void)
typedef void (* TaskType) (void);

// add a TimedTask corresponding to function pointer f and repetition time interval t
void add_timed_task(TaskType f, float t);

// check which functions are to be called based on current time, call functions and update timed_tasks elements appropriately
void update();

#endif /* TIMED_TASKS_H */