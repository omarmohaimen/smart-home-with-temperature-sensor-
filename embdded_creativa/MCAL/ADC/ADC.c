/*
 * ADC.c
 *
 * Created: 4/5/2024 1:57:25 PM
 *  Author: mohaimen
 */ 
#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "../GPIO_INTERFACE.h"
#include "../BIT_MATH.h"
#include "ADC_IINTERFACE.h"
#include "ADC_PRIVATE.h"

void ADC_INIT(void){
	ADMUX |= (1 << REFS0);
	ADCSRA |= (1 << ADEN);
	
}

u16 ADC_READ(u8 channel){
	ADMUX|=channel;
	set_bit(ADCSRA,ADSC);
	while ((get_bit(ADCSRA,ADIF))==0);
	set_bit(ADCSRA,ADIF);
	u16 val;
	val=((u16)(ADCH<<8))|((u16)ADCL);
	return val;
}


