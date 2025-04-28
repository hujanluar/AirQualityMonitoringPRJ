#include "lcd.h"
#include <string.h>

static char lcd_display[32] = {0};

void lcd_init(void) {
    memset(lcd_display, 0, sizeof(lcd_display));
}

void lcd_clear(void) {
    memset(lcd_display, 0, sizeof(lcd_display));
}

void lcd_print(const char* text) {
    strncpy(lcd_display, text, sizeof(lcd_display) - 1);
}

const char* lcd_get_display(void) {
    return lcd_display;
}
