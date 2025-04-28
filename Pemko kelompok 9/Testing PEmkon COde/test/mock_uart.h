#ifndef MOCK_UART_H
#define MOCK_UART_H

#include <stdint.h>

void mock_uart_set_buffer(uint8_t data);
uint8_t mock_uart_get_buffer(void);

#endif // MOCK_UART_H
