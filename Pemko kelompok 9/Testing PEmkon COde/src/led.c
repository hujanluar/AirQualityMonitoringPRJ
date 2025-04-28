#include "led.h"

static uint8_t led_status = 0; // 0 = OFF, 1 = ON

void led_init(void) {
    led_status = 0;
}

void led_on(void) {
    led_status = 1;
}

void led_off(void) {
    led_status = 0;
}

uint8_t led_get_status(void) {
    return led_status;
}
