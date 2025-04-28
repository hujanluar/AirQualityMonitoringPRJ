#include "mock_lcd.h"
#include <string.h>

static char mock_display[32] = {0};

const char* mock_lcd_get_display(void) {
    return mock_display;
}

void mock_lcd_set_display(const char* text) {
    strncpy(mock_display, text, sizeof(mock_display) - 1);
    mock_display[sizeof(mock_display) - 1] = '\0'; // pastikan null-terminated
}
