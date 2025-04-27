#include "main.h"
#include "pm25sensor.h"
#include "mq135_sensor.h"

#define PM25_THRESHOLD  500
#define MQ135_THRESHOLD 5000

void update_led_status(void) {
		if (pm2_5_value > PM25_THRESHOLD || mq135_value > MQ135_THRESHOLD) {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_RESET); // ON
    } else {
        HAL_GPIO_WritePin(GPIOC, GPIO_PIN_13, GPIO_PIN_SET);   // OFF
    }
}

