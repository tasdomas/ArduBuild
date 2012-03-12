#include <stdio.h>
#include <stdarg.h> /* Argument list functionality */
#include "WProgram.h"
#include "HardwareSerial.h"
#include "serial_lcd.h"

/* NOTE: This implementation is based on the Parallax serial LCD (4 rows, 20 cols) */

void_t serial_lcd_initialize()
{
  /* Setup serial connection */
  Serial1.begin(19200);
  
  /* Turn display on (no cursor, no blink) */
  Serial1.write(0x16); 
  
  /* Clear display */
  serial_lcd_clear();
}

uint8_t serial_lcd_get_nr_of_rows()
{
  return 4;
}

uint8_t serial_lcd_get_nr_of_cols()
{
  return 20;
}

uint8_t serial_lcd_is_backlight_supported()
{
  return TRUE;
}

void_t serial_lcd_set_backlight(uint8_t flag)
{
  switch(flag)
  {
    case TRUE:
      Serial1.write(0x11); /* Turn backlight on */
      break;
    case FALSE:
      Serial1.write(0x12); /* Turn backlight off */
      break;
  }
}

void_t serial_lcd_move_cursor(uint8_t row, uint8_t pos)
{
  /* Abort if row or pos is incorrect */
  if (row > 3 || pos > 19) return;
  
  /* Prepare control command */
  uint8_t c = 0x80;
  c += (row*20) + pos;
  
  /* Send command */
  Serial1.write(c);
}

void_t serial_lcd_carriage_return()
{
  Serial1.write(0x0d); /* Carriage return: move to next row, pos 0; will wrap to row 0 when going beyond the screen */
}

void_t serial_lcd_clear()
{
  Serial1.write(0x0c); /* Form feed: move to row 0, pos 0 and clear display */
  delayMicroseconds(5000); /* Sleep 5ms according to LCD specification so that the device will go to the right state */
}

void_t serial_lcd_display_ascii_char(uint8_t c)
{
  /* Send character if it is within the ASCII range (7 bit range excluding control characters) */
  if (c >= 0x20 && c<= 0x7f)
  {
    Serial1.write(c); 
  }
}

void_t serial_lcd_define_custom_char(uint8_t index, const uint8_t data[8])
{
  /* Abort if the index is incorrect */
  if (index > 7) return;
  
  /* Send custom char command based on index */
  Serial1.write( 0xf8 + index );

  /* Send character description data */
  uint8_t i;
  for (i=0;i<8;i++)
  {
    Serial1.write(data[i]);
  }
}

void_t serial_lcd_display_custom_char(uint8_t index)
{
  /* Display custom char if the index is correct */
  if (index <= 7)
  {
    Serial1.write(index);
  }
}
#define SERIAL_BUFFER_LENGTH 200
static char serial_buffer[SERIAL_BUFFER_LENGTH];
int  serial_lcd_printf(const char* format, ...)
{
  /* Make the argument list available */
  va_list arg_list;
  va_start(arg_list,format);

  /* Create string in pre allocated memory based on printf arguments */
  int res;
  res = vsnprintf(serial_buffer, 200, format, arg_list); /* vsnprintf will NULL terminate */
  va_end(arg_list);
  
  /* Write string to LCD controller */  
  uint8_t* text_p = (uint8_t*) serial_buffer;
  while(*text_p != '\0')
  {
    if (*text_p == '\n') /* Newline character (0x0a) */
    {
      /* Send carriage return instead of line feed */
      Serial1.write(0x0d);
    }
    else if (*text_p >= 0x20 && *text_p<= 0x7f) /* Restrict char range */
    {
      Serial1.write(*text_p);
    }
    
    /* Go to next character */
    text_p++;
  }

  /* Return success status */
  return 0;
}

