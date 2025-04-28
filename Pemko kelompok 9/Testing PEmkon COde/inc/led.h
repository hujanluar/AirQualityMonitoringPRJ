#ifndef LED_H
#define LED_H

#include <stdint.h>

void led_init(void);
void led_on(void);
void led_off(void);
uint8_t led_get_status(void);

#endif // LED_H
