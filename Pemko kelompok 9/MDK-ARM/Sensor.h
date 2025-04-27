#ifndef SENSOR_H
#define SENSOR_H

#include "main.h"

extern uint16_t pm2_5_value;
extern uint32_t mq135_value;

void start_pm_uart_interrupt(void);
void read_mq135(void);

#endif
