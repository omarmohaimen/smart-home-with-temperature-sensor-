/*
 * KEYPAD.c
 *
 * Created: 3/18/2024 3:52:31 PM
 *  Author: mohaimen
 */ 
#include "../MCAL/GPIO_INTERFACE.h"
#include "KEYPAD_INTERFACE.h"


u8 row_arr[4]={pin4,pin5,pin6,pin7};
u8 column_arr[4]={pin2,pin3,pin4,pin5};

u8 keypad[4][4]={
	{1,2,3,4},
	{5,6,7,8},
	{9,10,11,12},
	{13,14,15,16},
};


void KEYPAD_ININT(void){
	GPIO_PINMODE(port_b,pin4,output);
	GPIO_PINMODE(port_b,pin5,output);
	GPIO_PINMODE(port_b,pin6,output);
	GPIO_PINMODE(port_b,pin7,output);

	GPIO_PINMODE(port_d,pin2,input);
	GPIO_PINMODE(port_d,pin3,input);
	GPIO_PINMODE(port_d,pin4,input);
	GPIO_PINMODE(port_d,pin5,input);
}

u8 KEYPAD_READ(void){
	
	u8 read =0;
	u8 out =0;
	
	for (u8 i=0;i<4;i++)
	{
		GPIO_WRITE(port_b,row_arr[i],low);
		
		for (u8 j=0;j<4;j++)
		{
			read=GPIO_READ(port_d,column_arr[j]);
			if (read==0)
			{
				out=keypad[i][j];
			}
			
		}
		
		GPIO_WRITE(port_b,row_arr[i],high);
		
	}
	return out;
}