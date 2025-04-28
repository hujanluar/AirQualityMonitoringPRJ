#include "unity.h"
#include "mock_led.h"
#include "led.h"

void setUp(void) {}
void tearDown(void) {}

// Test LED turn on
void test_led_on_should_set_status_to_on(void) {
    mock_led_set_status(0); // ensure start from OFF
    led_on();
    mock_led_set_status(led_get_status());
    TEST_ASSERT_EQUAL_UINT8(1, mock_led_get_status());
}

// Test LED turn off
void test_led_off_should_set_status_to_off(void) {
    mock_led_set_status(1); // ensure start from ON
    led_off();
    mock_led_set_status(led_get_status());
    TEST_ASSERT_EQUAL_UINT8(0, mock_led_get_status());
}

// Test LED init
void test_led_init_should_set_status_to_off(void) {
    mock_led_set_status(1); // start from ON
    led_init();
    mock_led_set_status(led_get_status());
    TEST_ASSERT_EQUAL_UINT8(0, mock_led_get_status());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_led_on_should_set_status_to_on);
    RUN_TEST(test_led_off_should_set_status_to_off);
    RUN_TEST(test_led_init_should_set_status_to_off);
    UNITY_END();
    return 0;
}
