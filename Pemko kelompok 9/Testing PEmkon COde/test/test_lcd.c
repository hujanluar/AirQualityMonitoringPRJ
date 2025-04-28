#define UNITY_INCLUDE_STRING
#include "unity.h"
#include "mock_lcd.h"
#include "lcd.h"

#include <string.h>

void setUp(void) {}
void tearDown(void) {}

void test_lcd_init_should_clear_display(void) {
    lcd_print("Hello");
    lcd_init();
    mock_lcd_set_display(lcd_get_display());
    TEST_ASSERT_EQUAL_STRING("", mock_lcd_get_display());
}

void test_lcd_clear_should_empty_display(void) {
    lcd_print("World");
    lcd_clear();
    mock_lcd_set_display(lcd_get_display());
    TEST_ASSERT_EQUAL_STRING("", mock_lcd_get_display());
}

void test_lcd_print_should_update_display(void) {
    lcd_print("Test123");
    mock_lcd_set_display(lcd_get_display());
    TEST_ASSERT_EQUAL_STRING("Test123", mock_lcd_get_display());
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_lcd_init_should_clear_display);
    RUN_TEST(test_lcd_clear_should_empty_display);
    RUN_TEST(test_lcd_print_should_update_display);
    return UNITY_END();
}
