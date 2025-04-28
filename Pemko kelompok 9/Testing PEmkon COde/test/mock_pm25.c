#include "mock_pm25.h"
#include <stdint.h>
static uint16_t mock_value = 0;

void mock_pm25_set_value(uint16_t value) {
    mock_value = value;
}

uint16_t mock_pm25_read_value(void) {
    return mock_value;
}
