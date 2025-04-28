#ifndef MOCK_ADC_H
#define MOCK_ADC_H

#include <stdint.h>

void mock_adc_set_value(uint16_t value);
uint16_t mock_adc_read(uint8_t channel);

#endif // MOCK_ADC_H
