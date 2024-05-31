/*
 * ADC_PRIVATE.h
 *
 * Created: 4/5/2024 1:56:06 PM
 *  Author: mohaimen
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_


#define ADMUX *((volatile u8*)(0X27))
#define ADCSRA *((volatile u8*)(0X26))
#define ADCL *((volatile u8*)(0X24))
#define ADCH *((volatile u8*)(0X25))




#endif /* ADC_PRIVATE_H_ */