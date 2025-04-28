#include "uart.h"

static uint8_t uart_buffer = 0;

void uart_init(void) {
    uart_buffer = 0;
}

void uart_send(uint8_t data) {
    uart_buffer = data;
}

uint8_t uart_receive(void) {
    return uart_buffer;
}
