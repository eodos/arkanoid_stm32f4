#include "timed_tasks.h"
#include <stdio.h>

float get_time();

typedef struct
{
  TaskType f; // function pointer
  float t; // function repetition time interval
  float t_prev; // last-called time
} TimedTask;

static TimedTask timed_tasks[N_TASKS]; // fixed-size array of TimedTask's

static int n_tasks = 0; // number of tasks currently used


// add a TimedTask corresponding to function pointer f and repetition time interval t
void add_timed_task(TaskType f, float t)
{
  if (n_tasks < N_TASKS)
  {
    timed_tasks[n_tasks].f = f;
    timed_tasks[n_tasks].t =t;
    n_tasks ++;
  }
}

// check which functions are to be called based on current time, call functions and update timed_tasks elements appropriately
void update()
{
  int i;
  float t = get_time();
  for (i=0; i<n_tasks; i++)
  {
    if ( t >= (timed_tasks[i].t_prev + timed_tasks[i].t) )
    {
      timed_tasks[i].f();
      timed_tasks[i].t_prev = t;
    }
  }
}