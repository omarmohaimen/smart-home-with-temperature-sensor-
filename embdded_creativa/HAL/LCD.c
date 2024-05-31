/*
 * LCD.c
 *
 * Created: 3/22/2024 10:48:11 AM
 *  Author: mohaimen
 */ 
#include <avr/io.h>
#include <stdio.h> // for dtostrf
#define F_CPU 16000000
#include "../MCAL/GPIO_INTERFACE.h"
#include "LCD.h"
#include "util/delay.h"


void LCD_INIT(void){
	// set the port is output

 _delay_ms(20);
GPIO_PINMODE(LCD_PORT,LCD_RS,output);
GPIO_PINMODE(LCD_PORT,LCD_RW,output);

GPIO_PINMODE(LCD_PORT,LCD_ENABLE,output);
GPIO_PINMODE(LCD_PORT,LCD_D4,output);
GPIO_PINMODE(LCD_PORT,LCD_D5,output);
GPIO_PINMODE(LCD_PORT,LCD_D6,output);
GPIO_PINMODE(LCD_PORT,LCD_D7,output);

_delay_ms(20);

LCD_SEND_COMMAND(LCD_TWO_LINES_FOUR_BITS_MODE_INIT1);
LCD_SEND_COMMAND(LCD_TWO_LINES_FOUR_BITS_MODE_INIT2);

LCD_SEND_COMMAND(LCD_TWO_LINES_FOUR_BITS_MODE);

LCD_SEND_COMMAND(LCD_CURSOR_OFF);
LCD_SEND_COMMAND(LCD_CLEAR_COMMAND);
		
}
void LCD_SET_CURSOR(uint8_t row, uint8_t col) {
	// Calculate the address based on the row and column
	uint8_t address = (row * 0x40) + col;
	
	// Send the set cursor command (usually 0x80 plus the address)
	LCD_SEND_COMMAND(0x80 | address);
}
void LCD_DISPLAY_NUMBER(float number) {
  // Convert the float number to a string with 2 decimal places
    char buffer[16]; // A buffer to hold the formatted string
    snprintf(buffer, sizeof(buffer), "%.2f", number); // Format the float with 2 decimal places
    
    // Display the string on the LCD
    LCD_CLEAR(); // Clear the LCD
    LCD_DISPLAY_STRING(buffer); // Display the formatted string
}

void LCD_CLEAR() {
	// Send the clear display command (usually 0x01)
	LCD_SEND_COMMAND(0x01);
	
	// Delay for a short period to allow the LCD to clear the screen
	_delay_ms(2);
}

void LCD_SEND_COMMAND(u8 cmd){
	GPIO_WRITE(LCD_PORT,LCD_RS,low);
	_delay_ms(1);
	GPIO_WRITE(LCD_PORT,LCD_D4,((cmd>>4)&1));
	GPIO_WRITE(LCD_PORT,LCD_D5,((cmd>>5)&1));
	GPIO_WRITE(LCD_PORT,LCD_D6,((cmd>>6)&1));
	GPIO_WRITE(LCD_PORT,LCD_D7,((cmd>>7)&1));
	
	
	_delay_ms(1);
	
	GPIO_WRITE(LCD_PORT,LCD_ENABLE,high);
	_delay_ms(1);
	GPIO_WRITE(LCD_PORT,LCD_ENABLE,low);
	
	_delay_ms(1);
	
	GPIO_WRITE(LCD_PORT,LCD_D4,((cmd>>0)&1));
	GPIO_WRITE(LCD_PORT,LCD_D5,((cmd>>1)&1));
	GPIO_WRITE(LCD_PORT,LCD_D6,((cmd>>2)&1));
	GPIO_WRITE(LCD_PORT,LCD_D7,((cmd>>3)&1));

		_delay_ms(1);

		GPIO_WRITE(LCD_PORT,LCD_ENABLE,high);
		_delay_ms(1);
		GPIO_WRITE(LCD_PORT,LCD_ENABLE,low);
	_delay_ms(1);
	
}

void LCD_SEND_DATA(char data){
	
	GPIO_WRITE(LCD_PORT,LCD_RS,high);
	_delay_ms(1);
	GPIO_WRITE(LCD_PORT,LCD_D4,((data>>4)&1));
	GPIO_WRITE(LCD_PORT,LCD_D5,((data>>5)&1));
	GPIO_WRITE(LCD_PORT,LCD_D6,((data>>6)&1));
	GPIO_WRITE(LCD_PORT,LCD_D7,((data>>7)&1));
	_delay_ms(1);
	GPIO_WRITE(LCD_PORT,LCD_ENABLE,high);
	_delay_ms(1);
	GPIO_WRITE(LCD_PORT,LCD_ENABLE,low);
		_delay_ms(1);
	GPIO_WRITE(LCD_PORT,LCD_D4,((data>>0)&1));
	GPIO_WRITE(LCD_PORT,LCD_D5,((data>>1)&1));
	GPIO_WRITE(LCD_PORT,LCD_D6,((data>>2)&1));
	GPIO_WRITE(LCD_PORT,LCD_D7,((data>>3)&1));
	
	_delay_ms(1);
	
	GPIO_WRITE(LCD_PORT,LCD_ENABLE,high);
	_delay_ms(1);
	GPIO_WRITE(LCD_PORT,LCD_ENABLE,low);
	_delay_ms(1);
}
void LCD_DISPLAY_STRING(const char *str){
	while (*str!='\0')
	{
		LCD_SEND_DATA(*str);
		str++;
	}
}
 void lcd_puts(const char *s) {
	 while (*s) {
		 LCD_SEND_DATA(*s++);
	 }
 }