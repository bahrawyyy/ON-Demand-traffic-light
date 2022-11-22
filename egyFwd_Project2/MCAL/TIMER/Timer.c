/*
 * Timer.c
 *
 * Created: 11/15/2022 2:24:18 PM
 *  Author: Abdallah
 */ 


#include "Timer.h"
#include <avr/interrupt.h>
#include "../../Bit_Math.h"

/************************************************************************/
/*                    Timer 0                                         */
/************************************************************************/



/************************************************************************/
/* Intialaization of timer 0                                        */
/************************************************************************/

void timer_init(void){
	//Initial value
	TCNT0 = 0;

	#if Timer0_Mode_Select == Timer0_Normal_Mode
	//Normal mode
	CLR_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	#elif Timer0_Mode_Select == Timer0_CTC_Mode
	CLR_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#elif Timer0_Mode_Select == Timer0_PWM_FAST_Mode
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);
	#elif Timer0_Mode_Select == Timer0_PWM_PHASE_Mode
	SET_BIT(TCCR0,WGM00);
	CLR_BIT(TCCR0,WGM01);
	#endif



	#if TIM0_PRSECALAR_SELECT == Timer0_NO_CLK_SOURCE
	CLR_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	#elif TIM0_PRSECALAR_SELECT == Timer0_NO_PRESCALAR
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	#elif TIM0_PRSECALAR_SELECT == Timer0_8_PRESCALAR
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	#elif TIM0_PRSECALAR_SELECT == Timer0_64_PRESCALAR
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLR_BIT(TCCR0,CS02);
	#elif TIM0_PRSECALAR_SELECT == Timer0_256_PRESCALAR
	//CLR_BIT(TCCR0,CS00);
	//CLR_BIT(TCCR0,CS01);
	//SET_BIT(TCCR0,CS02);
	//Prescalar 1024
	#elif TIM0_PRSECALAR_SELECT == Timer0_1024_PRESCALAR
	SET_BIT(TCCR0,CS00);
	CLR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#elif TIM0_PRSECALAR_SELECT == Timer0_EXT_FALLING
	CLR_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#elif TIM0_PRSECALAR_SELECT == Timer0_EXT_RISING
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	#endif

	#if TIME0_INTERRUPT_MODE == TIME0_TOV
	SET_BIT(TIMSK,TOIE0);
	#elif TIME0_INTERRUPT_MODE == TIME0_TOC
	SET_BIT(TIMSK,OCIE0);
	#endif
}


/************************************************************************/
/* Wati until the overflow happens                                                                     */
/************************************************************************/

void waitOVF_timer0(void){
	while(GET_BIT(TIFR,TOV0)==0);  //When the overflow happens(Not used in interrupt mode)
	SET_BIT(TIFR,TOV0);   //Clear the overflow manually
}

/************************************************************************/
/* Stop the timer                                                                     */
/************************************************************************/

void timer_stop(void){
	TCCR0 = 0x00;
}

/************************************************************************/
/* To  generate time delay in milliseconds                      */
/************************************************************************/

void Timer0_delay_ms(uint32_t delay){
	// Tick time is 256/10^6 Prescalar/F_CPU Tick time = 0.256 ms
	uint32_t MaxDelay = 256 * 0.256;
	uint32_t NUM_OF_OVERFLOW = ceil(delay/MaxDelay);  
	uint8_t InitialVal = 256 - ((delay/0.256)/NUM_OF_OVERFLOW);
	
	
	TCNT0 = InitialVal;
	TCCR0 |= (1<<2);    // Choose the prescalar so, the timer will start
	unsigned int overflowcounter = 0;
	while(overflowcounter < NUM_OF_OVERFLOW){
		waitOVF_timer0();
		overflowcounter++;
	}
	overflowcounter = 0;
	timer_stop();
}

/************************************************************************/
/*                    Timer 2                                           */
/************************************************************************/

void waitOVF_timer2(void){
	while(GET_BIT(TIFR,TOV2)==0);  //When the overflow happens(Not used in interrupt mode)
	SET_BIT(TIFR,TOV2);   //Clear the overflow manually
}

void timer2_stop(void){
	TCCR2 = 0x00;
}

void Timer2_delay_ms(uint32_t delay){
	// Tick time is 256/10^6 Prescalar/F_CPU Tick time = 0.256 ms
	uint32_t MaxDelay = 256 * 0.256;
	uint32_t NUM_OF_OVERFLOW = ceil(delay/MaxDelay);
	uint8_t InitialVal = 256 - ((delay/0.256)/NUM_OF_OVERFLOW);
	
	
	TCNT2 = InitialVal;
	TCCR2 |= (1<<1)|(1<<2);    // Choose the prescalar so, the timer will start
	unsigned int overflowcounter = 0;
	while(overflowcounter < NUM_OF_OVERFLOW){
		waitOVF_timer2();
		overflowcounter++;
	}
	overflowcounter = 0;
	timer2_stop();
}