#include <avr/io.h>
#include <util/delay.h>
#include <stdio.h>
#include "util/delay.h"
#include "MCAL/BIT_MATH.h"
#include "MCAL/GPIO_PRIVATE.h"
#include "MCAL/GPIO_INTERFACE.h"
#include "HAL/LCD.h"
#include "MCAL/ADC/ADC_IINTERFACE.h"

u8 ADC_READ0(u8 channel) {
	ADMUX = (ADMUX & 0xF0) | (channel & 0x0F);
	ADCSRA |= (1 << ADSC);
	while (ADCSRA & (1 << ADSC));
	return ADC;
}
float readTemperature() {
	u16 adcValue = ADC_READ0(0);
	float voltage = adcValue * 5.0 / 1024.0;
	float temperature = voltage * 100.0;
	return temperature;
}

int main(void) {
	char temp_string[16];
	u16 adcValue ;
	float voltage;
	float temperature;
	
	GPIO_PINMODE(port_d, 0, output);
	GPIO_PINMODE(port_d, 1, output);
	GPIO_PINMODE(port_d, 2, output);
		GPIO_PINMODE(port_d, 3, output);

	LCD_INIT();
	ADC_INIT();
	
 	
	while (1) {
		temperature=readTemperature();
		
		LCD_CLEAR();
		LCD_DISPLAY_STRING("Temp: ");
		
		sprintf(temp_string, "Temp: %.2f C", temperature);
		
		LCD_SET_CURSOR(0, 6);
		LCD_DISPLAY_STRING(temp_string);
		//LCD_DISPLAY_NUMBER(temperature);
		
		if (temperature > 50.0) {
			GPIO_WRITE(port_d, 0, high);
			GPIO_WRITE(port_d, 1, low);
			GPIO_WRITE(port_d, 2, low);
						GPIO_WRITE(port_d, 3, high);

			LCD_SET_CURSOR(1, 0);
			LCD_DISPLAY_STRING("ALERT");
			} else if (temperature >= 30.0 && temperature <= 50.0) {
			GPIO_WRITE(port_d, 0, low);
			GPIO_WRITE(port_d, 1, high);
			GPIO_WRITE(port_d, 2, low);
									GPIO_WRITE(port_d, 3, low);

			LCD_SET_CURSOR(1, 0);
			LCD_DISPLAY_STRING("WARNING");
			} else {
			GPIO_WRITE(port_d, 0, low);
			GPIO_WRITE(port_d, 1, low);
			GPIO_WRITE(port_d, 2, high);
			
			LCD_SET_CURSOR(1, 0);
			LCD_DISPLAY_STRING("GOOD");
		}
	
		
		_delay_ms(1000);
	}
}
