#include "Sensor.h"

extern UART_HandleTypeDef huart1;
extern ADC_HandleTypeDef hadc1;
uint8_t uart_buffer[32];
uint16_t pm2_5_value = 0;
uint32_t mq135_value = 0;

void start_pm_uart_interrupt(void) {
    HAL_UART_Receive_IT(&huart1, uart_buffer, 32);
}

void HAL_UART_RxCpltCallback(UART_HandleTypeDef *huart) {
    if (huart->Instance == USART1) {
        if (uart_buffer[0] == 0x42 && uart_buffer[1] == 0x4D) {
            pm2_5_value = (uart_buffer[10] << 8) | uart_buffer[11];
        }
        HAL_UART_Receive_IT(&huart1, uart_buffer, 32);
    }
}

void read_mq135(void) {
    HAL_ADC_Start(&hadc1);
    if(HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK) {
        mq135_value = HAL_ADC_GetValue(&hadc1);
    }
    HAL_ADC_Stop(&hadc1);
}
