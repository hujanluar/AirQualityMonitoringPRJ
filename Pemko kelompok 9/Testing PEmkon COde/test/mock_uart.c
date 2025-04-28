#include "mock_uart.h"
#include <stdint.h>

static uint8_t mock_uart_buffer = 0;

void mock_uart_set_buffer(uint8_t data) {
    mock_uart_buffer = data;
}

uint8_t mock_uart_get_buffer(void) {
    return mock_uart_buffer;
}
