#ifndef PM25_SENSOR_H
#define PM25_SENSOR_H

#include "main.h"

extern UART_HandleTypeDef huart1;
extern uint16_t pm2_5_value;

void PM25_Init(void);
void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart);
void PM25_Task(void const *argument);

#endif
