/*
 * SEG.c
 *
 * Created: 3/18/2024 3:53:46 PM
 *  Author: mohaimen
 */ 
#include "../MCAL/GPIO_INTERFACE.h"
#include "../MCAL/SEG_INTERFACE.h"

u8 segment_codes[10] = {
	0b01111110,  // 0 (little-endian order) - segments a-g reversed
	0b00001100,  // 1
	0b11010110,  // 2 - order remains the same for some digits
	0b10011110,  // 3
	0b01000100,  // 4
	0b11011010,  // 5
	0b11111010,  // 6
	0b00001110,  // 7
	0b11111110,  // 8
	0b11011110   // 9
};


void seg_init(void){
	GPIO_PINMODE(port_a,pin7,output);

	GPIO_PINMODE(port_c,pin7,output);
	GPIO_PINMODE(port_c,pin6,output);

	GPIO_WRITE(port_c,pin7,high);
	GPIO_WRITE(port_c,pin6,high);


	GPIO_WRITE(port_a,pin6,high);
	GPIO_WRITE(port_a,pin1,high);
	GPIO_WRITE(port_a,pin3,high);
	GPIO_WRITE(port_a,pin4,high);
	GPIO_WRITE(port_a,pin7,high);
}

void seg_display(u8 num , u8 pos){
	switch(pos){
		case 1:
		GPIO_WRITE(port_c,pin6,high);
		GPIO_WRITE(port_c,pin7,low);
		GPIO_WRITEPORT(port_a,segment_codes[num]);
		break;
		case 2:
		
		GPIO_WRITE(port_c,pin6,low);
		GPIO_WRITE(port_c,pin7,high);
		GPIO_WRITEPORT(port_a,segment_codes[num]);
		break;
		
		
	}
}
