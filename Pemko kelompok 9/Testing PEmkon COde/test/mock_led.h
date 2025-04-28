#ifndef MOCK_LED_H
#define MOCK_LED_H

#include <stdint.h>

void mock_led_set_status(uint8_t status);
uint8_t mock_led_get_status(void);

#endif // MOCK_LED_H
