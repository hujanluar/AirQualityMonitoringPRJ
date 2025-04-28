#include "mock_adc.h"

static uint16_t mock_value = 0;

void mock_adc_set_value(uint16_t value) {
    mock_value = value;
}

uint16_t mock_adc_read(uint8_t channel) {
    (void)channel;
    return mock_value;
}
