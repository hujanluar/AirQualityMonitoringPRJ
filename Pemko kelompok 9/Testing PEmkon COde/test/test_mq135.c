#include "unity.h"
#include "mock_mq135.h"
#include "mq135.h"

void setUp(void) {}
void tearDown(void) {}

void test_mq135_read_should_return_mock_ppm(void) {
    mock_mq135_set_ppm(500.0f);
    float result = mock_mq135_read_ppm();
    TEST_ASSERT_EQUAL_UINT16((int32_t)500, (int32_t)result);
}

void test_mq135_read_should_return_min_ppm(void) {
    mock_mq135_set_ppm(0.0f);
    float result = mock_mq135_read_ppm();
    TEST_ASSERT_EQUAL_UINT16((int32_t)0, (int32_t)result);
}

void test_mq135_read_should_return_high_ppm(void) {
    mock_mq135_set_ppm(2000.0f);
    float result = mock_mq135_read_ppm();
    TEST_ASSERT_EQUAL_UINT16((int32_t)2000, (int32_t)result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_mq135_read_should_return_mock_ppm);
    RUN_TEST(test_mq135_read_should_return_min_ppm);
    RUN_TEST(test_mq135_read_should_return_high_ppm);
    UNITY_END();
    return 0;
}
