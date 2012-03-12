#ifndef _SERIAL_LCD_H_
#define _SERIAL_LCD_H_

#include "general.h"

void_t  serial_lcd_initialize();
uint8_t serial_lcd_get_nr_of_rows();
uint8_t serial_lcd_get_nr_of_cols();
uint8_t serial_lcd_is_backlight_supported();
void_t  serial_lcd_set_backlight(uint8_t flag);
void_t  serial_lcd_move_cursor(uint8_t row, uint8_t pos);
void_t  serial_lcd_carriage_return();
void_t  serial_lcd_clear(); 
void_t  serial_lcd_display_ascii_char(uint8_t c);
void_t  serial_lcd_define_custom_char(uint8_t index, const uint8_t data[8]); 
void_t  serial_lcd_display_custom_char(uint8_t index);
int     serial_lcd_printf(const char* format, ...);  

#endif /* _SERIAL_LCD_H_ */
