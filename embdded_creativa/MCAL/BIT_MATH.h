/*
 * BIT_MATH.h
 *
 * Created: 3/18/2024 3:34:20 PM
 *  Author: mohaimen
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_



#define set_bit(x,y) (x|=1<<y)
#define clear_bit(x,y) (x&=~(1<<y))
#define get_bit(x,y)((x>>y)&1)
#define tog_bit(x,y)(x^=(1<<y))



#endif /* BIT_MATH_H_ */