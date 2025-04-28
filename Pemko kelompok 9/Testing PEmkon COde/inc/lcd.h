#ifndef LCD_H
#define LCD_H

#include <stdint.h>

void lcd_init(void);
void lcd_clear(void);
void lcd_print(const char* text);
const char* lcd_get_display(void);

#endif // LCD_H
