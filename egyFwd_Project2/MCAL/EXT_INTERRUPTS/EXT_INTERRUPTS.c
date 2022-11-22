/*
 * EXT_INTERRUPTS.c
 *
 * Created: 11/17/2022 3:54:29 PM
 *  Author: Abdallah
 */ 

#include "EXT_INTERRUPTS.h"
#include <avr/interrupt.h>
#include "../../Bit_Math.h"

//1) These are pointer to functions to store the address of a funtion
//To use it in CallBack function to implement ISR

void (*p2f_INT0)(void);
void (*p2f_INT1)(void);
void (*p2f_INT2)(void);



/*
 * These configurations only happen before compiling (at the preprocessing stage)
 * So, why do we take this whole code in consideration ?
 * So, instead of using if we use #if
 */

/************************************************************************/
/* Initialaization of interrupts                             */
/************************************************************************/

void EXTI_init(){
#if EXT_INT0_MODE == ENABLE
		EXTI_enable(EXTI0);
#if INT0_SENSE_MODE == LOW_LEVEL_TRIG
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
#elif INT0_SENSE_MODE == ANY_LOGIC_TRIG
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
#elif INT0_SENSE_MODE == FAL_EDGE_TRIG
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
#elif INT0_SENSE_MODE == RIS_EDGE_TRIG          //We notice that this part isn't shaded
			SET_BIT(MCUCR,ISC00);				//Because at configuration we choose RIS_EDGE
			SET_BIT(MCUCR,ISC01);				//And the rest of the code doesn't matter
#endif
#endif

#if EXT_INT1_MODE == ENABLE
		EXTI_enable(EXTI1);
#if INT0_SENSE_MODE == LOW_LEVEL_TRIG)
			CLR_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
#elif INT0_SENSE_MODE == ANY_LOGIC_TRIG
			SET_BIT(MCUCR, ISC10);
			CLR_BIT(MCUCR, ISC11);
#elif INT0_SENSE_MODE == FAL_EDGE_TRIG
			CLR_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
#elif INT0_SENSE_MODE == RIS_EDGE_TRIG
			SET_BIT(MCUCR, ISC10);
			SET_BIT(MCUCR, ISC11);
#endif
#endif

#if EXT_INT2_MODE == ENABLE						//Notice that INT2 works only at
		EXTI_enable(EXTI2);						// Rising and Falling edges
#if INT0_SENSE_MODE == FAL_EDGE_TRIG
			CLR_BIT(MCUCSR, ISC2);
#elif INT0_SENSE_MODE == RIS_EDGE_TRIG
			SET_BIT(MCUCSR, ISC2);
#endif
#endif
}


// Enable a specific interrupt

void EXTI_enable(EXTI_type interrupt){
	switch(interrupt){
	case EXTI0:
		SET_BIT(GICR,INT0);
		break;
	case EXTI1:
		SET_BIT(GICR,INT1);
		break;
	case EXTI2:
		SET_BIT(GICR,INT2);
		break;
	}
}

// Disable a specific interrupt

void EXTI_disable(EXTI_type interrupt){
	switch (interrupt) {
	case EXTI0:
		CLR_BIT(GICR, INT0);
		break;
	case EXTI1:
		CLR_BIT(GICR, INT1);
		break;
	case EXTI2:
		CLR_BIT(GICR, INT2);
		break;
	}
}

void SetCallback_INT0(void (*p2f)(void)){
	p2f_INT0 = p2f;
}
void SetCallback_INT1(void (*p2f)(void)){
	p2f_INT1 = p2f;
}
void SetCallback_INT2(void (*p2f)(void)){
	p2f_INT2 = p2f;
}



//Interrupt service routine
ISR(INT0_vect){                       //ISR is related to interrupts
	if(p2f_INT0!=0){    //To check that it hold an address
		p2f_INT0();			//So, it isn't supposed to be in main
	}
}										//It should be in the lower layer

ISR(INT1_vect){
	if(p2f_INT1!=0){
		p2f_INT1();
	}
}

ISR(INT2_vect){
	if(p2f_INT2!=0){
		p2f_INT2();
	}
}

//We are in MCAL and we call the function(Dio_FlipChannel)
//which is also in MCAL
//It doesn't make sense
//It will run, but in the concept of Layered Architecture
//The lower layer can't call the upper layer
//So, we use call back function

//Another way to implement ISR
//void __vector_1(void)__attribute__((signal,used));
//void __vector_1(void)
//{
//	Dio_FlipChannel(PORTD_4);
//}
