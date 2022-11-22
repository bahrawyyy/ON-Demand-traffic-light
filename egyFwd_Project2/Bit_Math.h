/*
 * Bit_Math.h
 *
 * Created: 11/15/2022 9:59:13 AM
 *  Author: Abdallah
 */ 


#ifndef BIT_MATH_H_
#define BIT_MATH_H_


/************************************************************************/
/* Some BitMath operations that are the foundation of Dio functions */
/************************************************************************/

#define SET_BIT(REG,PIN) (REG |= (1<<PIN))
#define CLR_BIT(REG,PIN) (REG &= ~(1<<PIN))
#define TOG_BIT(REG,PIN) (REG ^= (1<<PIN))
#define GET_BIT(REG,PIN) ((REG>>PIN) & 0x1)
#define ROT_L(REG,PIN)   ((REG<<PIN) | (REG>>(8-PIN)))
#define ROT_R(REG,PIN)   ((REG>>PIN) | (REG<<(8-PIN)))


#endif /* BIT_MATH_H_ */