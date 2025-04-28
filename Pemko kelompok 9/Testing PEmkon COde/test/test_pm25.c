#include "unity.h"
#include "mock_pm25.h"
#include "pm25.h"
#include <stdint.h>
void setUp(void) {}
void tearDown(void) {}

// Test normal PM2.5 value
void test_pm25_read_should_return_mock_value(void) {
    mock_pm25_set_value(50);
    uint16_t result = mock_pm25_read_value();
    TEST_ASSERT_EQUAL_UINT16(50, result);
}

// Test minimum PM2.5 value
void test_pm25_read_should_return_min_value(void) {
    mock_pm25_set_value(0);
    uint16_t result = mock_pm25_read_value();
    TEST_ASSERT_EQUAL_UINT16(0, result);
}

// Test very high PM2.5 value (severe pollution)
void test_pm25_read_should_return_high_value(void) {
    mock_pm25_set_value(999);
    uint16_t result = mock_pm25_read_value();
    TEST_ASSERT_EQUAL_UINT16(999, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_pm25_read_should_return_mock_value);
    RUN_TEST(test_pm25_read_should_return_min_value);
    RUN_TEST(test_pm25_read_should_return_high_value);
    UNITY_END();
    return 0;
}
