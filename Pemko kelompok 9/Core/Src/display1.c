#include "display1.h"
#include "i2c-lcd.h"
#include "pm25sensor.h"
#include "mq135_sensor.h"
#include "led_control.h"
#include <stdio.h>
#include "cmsis_os.h"

char lcd_line[32];

void Display_Task(void const *argument) {
    lcd_init();
    lcd_clear();
    lcd_put_cur(0, 0);
    lcd_send_string("Air Quality");

    for (;;) {
				if (pm2_5_value > 500 || mq135_value > 5000) {
            Error_Handler();
        }
        lcd_put_cur(1, 0);
        snprintf(lcd_line, sizeof(lcd_line), "PM2.5:%4d MQ:%4u", pm2_5_value, mq135_value);
        lcd_send_string("                ");
        lcd_put_cur(1, 0);
        lcd_send_string(lcd_line);

        update_led_status();

        osDelay(1000);
    }
}
