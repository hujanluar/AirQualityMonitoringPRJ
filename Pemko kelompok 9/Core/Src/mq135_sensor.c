#include "mq135_sensor.h"
#include "main.h"
#include "cmsis_os.h"
uint32_t mq135_value = 0;

#define MQ135_TASK_DELAY 1000
#define MQ135_ADC_MIN    0
#define MQ135_ADC_MAX    4095

extern ADC_HandleTypeDef hadc1;
void MQ135_Task(void const *argument) {
    for (;;) {
        HAL_ADC_Start(&hadc1);
        if (HAL_ADC_PollForConversion(&hadc1, HAL_MAX_DELAY) == HAL_OK) {
            uint32_t adc_value = HAL_ADC_GetValue(&hadc1);
            if (adc_value <= MQ135_ADC_MAX) {
                mq135_value = adc_value;
            } else {
                Error_Handler();
            }
        } else {
            Error_Handler();
        }
        HAL_ADC_Stop(&hadc1);
        osDelay(MQ135_TASK_DELAY);
    }
}

