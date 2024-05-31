/*
 * LCD.h
 *
 * Created: 3/22/2024 10:47:07 AM
 *  Author: mohaimen
 */ 


#ifndef LCD_H_
#define LCD_H_

#define LCD_CLEAR_COMMAND                    0x01
#define LCD_GO_TO_HOME                       0x02
#define DDRAM_INCREASE_BY1                   0x06
#define LCD_TWO_LINES_EIGHT_BITS_MODE        0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE         0x28
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT1   0x33
#define LCD_TWO_LINES_FOUR_BITS_MODE_INIT2   0x32
#define LCD_CURSOR_OFF                       0x0C
#define LCD_CURSOR_ON                        0x0E
#define LCD_SET_CURSOR_LOCATION              0x80

#define LCD_PORT                            port_c
#define LCD_RS                              pin0
#define LCD_RW								pin1
#define LCD_ENABLE                          pin2
#define LCD_D4                              pin3
#define LCD_D5                              pin4
#define LCD_D6                              pin5
#define LCD_D7                              pin6




void LCD_INIT(void);
void LCD_SEND_COMMAND(u8 cmd);
void LCD_CLEAR();
void LCD_SEND_DATA(char data);
void LCD_DISPLAY_NUMBER(float number);
void LCD_SET_CURSOR(u8 row, u8 col);
void LCD_DISPLAY_STRING(const char *str);
 void lcd_puts(const char *s);
  static void lcd_send_data(u8 data);

#endif /* LCD_H_ */