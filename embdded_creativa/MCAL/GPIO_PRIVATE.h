/*
 * GPIO_PRIVATE.h
 *
 * Created: 3/18/2024 3:29:39 PM
 *  Author: mohaimen
 */ 


#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_


#define PORTC_DDR  *((volatile u8*) (0x34))
#define PORTC_PORT *((volatile u8*) (0x35))
#define PORTC_PIN  *((volatile u8*) (0x33))

#define PORTB_DDR  *((volatile u8*) (0x37))
#define PORTB_PORT *((volatile u8*) (0x38))
#define PORTB_PIN  *((volatile u8*) (0x36))

#define PORTA_DDR *((volatile u8*) (0x3A))
#define PORTA_PORT *((volatile u8*) (0x3B))
#define PORTA_PIN *((volatile u8*) (0x39))


#define PORTD_DDR *((volatile u8*) (0x31))
#define PORTD_PORT *((volatile u8*) (0x32))
#define PORTD_PIN *((volatile u8*) (0x30))




#endif /* GPIO_PRIVATE_H_ */