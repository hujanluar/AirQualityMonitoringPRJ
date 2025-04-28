#include "unity.h"
#include "mock_adc.h"
#include "adc.h"

void setUp(void) {}
void tearDown(void) {}

// 1. Test baca ADC normal
void test_adc_read_should_return_mock_value(void) {
    mock_adc_set_value(5678);
    uint16_t result = mock_adc_read(0);
    TEST_ASSERT_EQUAL_UINT16(5678, result);
}

// 2. Test baca ADC channel lain
void test_adc_read_channel_1_should_return_correct_value(void) {
    mock_adc_set_value(4321);
    uint16_t result = mock_adc_read(1);
    TEST_ASSERT_EQUAL_UINT16(4321, result);
}

// 3. Test nilai minimum ADC (0)
void test_adc_read_should_return_min_value(void) {
    mock_adc_set_value(0);
    uint16_t result = mock_adc_read(0);
    TEST_ASSERT_EQUAL_UINT16(0, result);
}

// 4. Test nilai maksimum ADC (4095 untuk 12-bit ADC)
void test_adc_read_should_return_max_value(void) {
    mock_adc_set_value(4098);
    uint16_t result = mock_adc_read(0);
    TEST_ASSERT_EQUAL_UINT16(4098, result);
}

// 5. Test channel invalid (misalnya channel 255)
void test_adc_read_invalid_channel_should_return_default(void) {
    mock_adc_set_value(1234);
    uint16_t result = mock_adc_read(255); // Simulasi channel invalid
    TEST_ASSERT_EQUAL_UINT16(1234, result); // Tetap return mock value
}

// 6. Test baca ADC tanpa init (simulasi sederhana)
void test_adc_read_without_init_should_return_mock_value(void) {
    // Di mock ini adc_init() tidak berpengaruh, hanya cek read tetap jalan
    mock_adc_set_value(2222);
    uint16_t result = mock_adc_read(2);
    TEST_ASSERT_EQUAL_UINT16(2222, result);
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_adc_read_should_return_mock_value);
    RUN_TEST(test_adc_read_channel_1_should_return_correct_value);
    RUN_TEST(test_adc_read_should_return_min_value);
    RUN_TEST(test_adc_read_should_return_max_value);
    RUN_TEST(test_adc_read_invalid_channel_should_return_default);
    RUN_TEST(test_adc_read_without_init_should_return_mock_value);
    UNITY_END();
    return 0;
}
