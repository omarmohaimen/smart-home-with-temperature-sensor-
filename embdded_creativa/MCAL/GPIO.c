/*
 * GPIO.c
 *
 * Created: 3/18/2024 3:33:24 PM
 *  Author: mohaimen
 */ 
#include "BIT_MATH.h"
#include "GPIO_INTERFACE.h"
#include "GPIO_PRIVATE.h"


void GPIO_PINMODE(u8 PORT,u8 PIN,u8 DIR)
{
	switch (PORT)
	{
		case 0:
		
		switch(DIR){
			case 0:
			clear_bit(PORTA_DDR,PIN);
			break;
			case 1:
			set_bit(PORTA_DDR,PIN);
			break;
		}
		break;
		
		case 1:
		switch(DIR){
			case 0:
			clear_bit(PORTB_DDR,PIN);
			break;
			case 1:
			set_bit(PORTB_DDR,PIN);
			break;
		}
		break;
		
		case 2:
		switch(DIR){
			case 0:
			clear_bit(PORTC_DDR,PIN);
			break;
			case 1:
			set_bit(PORTC_DDR,PIN);
			break;
		}
		
		break;
		case 3:
		switch(DIR){
			case 0:
			clear_bit(PORTD_DDR,PIN);
			break;
			case 1:
			set_bit(PORTD_DDR,PIN);
			break;
		}
		default:
		break;
	}
	
}

void GPIO_WRITE(u8 PORT,u8 PIN,u8 MODE ){
	switch(PORT){
		case 0:
		
		switch(MODE){
			
			case 0:
			clear_bit(PORTA_PORT,PIN);
			break;
			case 1:
			set_bit(PORTA_PORT,PIN);
			
		}
		break;
		
		case 1:
		
		switch(MODE){
			case 0:
			clear_bit(PORTB_PORT,PIN);
			break;
			case 1:
			set_bit(PORTB_PORT,PIN);
			break;
			
		}
		break;
		
		
		case 2:
		
		switch(MODE){
			case 0:
			clear_bit(PORTC_PORT,PIN);
			break;
			case 1:
			set_bit(PORTC_PORT,PIN);
			break;
		}
		break;
		
		case 3:
		
		switch(MODE){
			case 0:
			clear_bit(PORTD_PORT,PIN);
			break;
			case 1:
			
			set_bit(PORTD_PORT,PIN);
			break;
		}
		break;
	}
	
}

u8 GPIO_READ(u8 PORT, u8 PIN){
	u8 read=0;
	switch(PORT){
		case 0:
		read=get_bit(PORTA_PIN,PIN);
		break;
		case 1:
		read=get_bit(PORTB_PIN,PIN);
		break;
		case 2:
		read=get_bit(PORTC_PIN,PIN);
		break;
		case 3:
		read=get_bit(PORTD_PIN,PIN);
		break;
		
	}
	return read;


}

void GPIO_WRITEPORT(u8 PORT,u8 VALUE){
	switch(PORT){
		case 0:
		PORTA_PORT=VALUE;
		break;
		case 1:
		PORTB_PORT=VALUE;

		break;
		case 2:
		PORTB_PORT=VALUE;

		break;
		case 3:
		PORTC_PORT=VALUE;

		break;
		case 4:
		PORTD_PORT=VALUE;
		break;
	}
}