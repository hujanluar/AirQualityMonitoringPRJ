
#define UNITY_INCLUDE_PRINT_FORMATTED
#define UNITY_OUTPUT_CHAR(a) putchar(a)
#include "unity.h"
#include "mock_uart.h"
#include "uart.h"

void setUp(void) {}
void tearDown(void) {}

// Test uart_send stores data
void test_uart_send_should_store_data(void) {
    uart_send(0x55);
    mock_uart_set_buffer(uart_receive());
    TEST_ASSERT_EQUAL_UINT8(0x55, mock_uart_get_buffer());
}

// Test uart_receive reads last sent data
void test_uart_receive_should_return_last_data(void) {
    uart_send(0xAA);
    mock_uart_set_buffer(uart_receive());
    uint8_t received = mock_uart_get_buffer();
    TEST_ASSERT_EQUAL_UINT8(0xAA, received);
}

// Test uart init clears buffer
void test_uart_init_should_clear_buffer(void) {
    uart_send(0xFF);
    uart_init();
    mock_uart_set_buffer(uart_receive());
    TEST_ASSERT_EQUAL_UINT8(0x00, mock_uart_get_buffer());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_uart_send_should_store_data);
    RUN_TEST(test_uart_receive_should_return_last_data);
    RUN_TEST(test_uart_init_should_clear_buffer);
    UNITY_END();
    return 0;
}
