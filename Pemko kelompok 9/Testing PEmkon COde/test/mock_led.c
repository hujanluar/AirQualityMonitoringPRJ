#include "mock_led.h"
#include <stdint.h>

static uint8_t mock_status = 0;

void mock_led_set_status(uint8_t status) {
    mock_status = status;
}

uint8_t mock_led_get_status(void) {
    return mock_status;
}
