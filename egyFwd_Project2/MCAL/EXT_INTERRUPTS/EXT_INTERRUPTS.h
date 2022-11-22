/*
 * EXT_INTERRUPTS.h
 *
 * Created: 11/17/2022 3:54:17 PM
 *  Author: Abdallah
 */ 


#ifndef EXT_INTERRUPTS_H_
#define EXT_INTERRUPTS_H_

#include "EXT_INTERRUPTSConfig.h"

void EXTI_init();
void EXTI_enable(EXTI_type interrupt);
void EXTI_disable(EXTI_type interrupt);


//These functions should receive the address of the function that is in upper layer
void SetCallback_INT0(void (*p2f)(void));        //The argument is a pointer to function
void SetCallback_INT1(void (*p2f)(void));
void SetCallback_INT2(void (*p2f)(void));



#endif /* EXT_INTERRUPTS_H_ */