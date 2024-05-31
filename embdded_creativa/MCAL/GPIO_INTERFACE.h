/*
 * GPIO_INTERFACE.h
 *
 * Created: 3/18/2024 3:31:07 PM
 *  Author: mohaimen
 */ 


#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long int u32;


void GPIO_PINMODE(u8 PORT,u8 PIN,u8 DIR);
void GPIO_WRITE(u8 PORT,u8 PIN,u8 MODE );
u8 GPIO_READ(u8 PORT, u8 PIN);
void GPIO_WRITEPORT(u8 PORT,u8 VALUE);

#define port_c 2
#define port_a 0
#define port_b 1
#define port_d 3

#define output 1
#define input 0
#define pin0 0
#define pin1 1
#define pin2 2
#define pin3 3
#define pin4 4
#define pin5 5
#define pin6 6
#define pin7 7

#define high 1
#define low  0



#endif /* GPIO_INTERFACE_H_ */