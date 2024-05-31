/*
 * ADC_IINTERFACE.h
 *
 * Created: 4/5/2024 1:56:41 PM
 *  Author: mohaimen
 */ 


#ifndef ADC_IINTERFACE_H_
#define ADC_IINTERFACE_H_

#define ADEN 7
#define ADSC 6
#define ADIF 4

#define ADPS2 2
#define ADPS1 1
#define ADPS0 0

#define ADC7  7
#define ADC6  6
#define ADC5  5
#define ADC4  4
#define ADC3  3
#define ADC2  2
#define ADC1  1
#define ADC0  0

 

void ADC_INIT(void);
u16 ADC_READ(u8 channel);





#endif /* ADC_IINTERFACE_H_ */