#ifndef TASKS_H
#define TASKS_H

#include "cmsis_os.h"

extern osThreadId readPMTaskHandle;
extern osThreadId readMQTaskHandle;
extern osThreadId displayTaskHandle;

void StartReadPMTask(void const * argument);
void StartReadMQTask(void const * argument);
void StartDisplayTask(void const * argument);
void create_tasks(void);

#endif
