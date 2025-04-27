#include "pm25sensor.h"
#include "cmsis_os.h"
#define PM25_TASK_DELAY 500
#define PM25_MIN_VALUE 0
#define PM25_MAX_VALUE 500
uint8_t uart_buffer[32];
uint16_t pm2_5_value = 0;

void PM25_Init(void) {
    HAL_UART_Receive_IT(&huart1, uart_buffer, 32);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART1) {
        if (uart_buffer[0] == 0x42 && uart_buffer[1] == 0x4D) {
            uint16_t value = (uart_buffer[10] << 8) | uart_buffer[11];
					if (value <= PM25_MIN_VALUE) {
                pm2_5_value = value;
            } else {
                Error_Handler();
            }
        } else {
            Error_Handler();
        }
        HAL_UART_Receive_IT(&huart1, uart_buffer, 32);
    }
}
void PM25_Task(void const *argument) {
    PM25_Init();
    for (;;) {
        osDelay(PM25_TASK_DELAY);
    }
}

