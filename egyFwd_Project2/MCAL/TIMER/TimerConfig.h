/*
 * TimerConfig.h
 *
 * Created: 11/15/2022 2:34:50 PM
 *  Author: Abdallah
 */ 


#ifndef TIMERCONFIG_H_
#define TIMERCONFIG_H_

#define Timer0_Normal_Mode	  0
#define Timer0_CTC_Mode		  1
#define Timer0_PWM_FAST_Mode  2
#define Timer0_PWM_PHASE_Mode 3

#define Timer0_Mode_Select Timer0_Normal_Mode

#define Timer0_NO_CLK_SOURCE  0
#define Timer0_NO_PRESCALAR   1
#define Timer0_8_PRESCALAR 	  2
#define Timer0_64_PRESCALAR   3
#define Timer0_256_PRESCALAR  4
#define Timer0_1024_PRESCALAR 5
#define Timer0_EXT_FALLING    6
#define Timer0_EXT_RISING     7

#define TIM0_PRSECALAR_SELECT Timer0_256_PRESCALAR

#define NO_INTERRUPT 0
#define TIME0_TOV    1
#define TIME0_TOC    2


#define TIME2_INTERRUPT_MODE NO_INTERRUPT

#define Timer2_Normal_Mode	  0
#define Timer2_CTC_Mode		  1
#define Timer2_PWM_FAST_Mode  2
#define Timer2_PWM_PHASE_Mode 3

#define Timer2_Mode_Select Timer2_Normal_Mode

#define Timer2_NO_CLK_SOURCE  0
#define Timer2_NO_PRESCALAR   1
#define Timer2_8_PRESCALAR 	  2
#define Timer2_64_PRESCALAR   3
#define Timer2_256_PRESCALAR  4
#define Timer2_1024_PRESCALAR 5
#define Timer2_EXT_FALLING    6
#define Timer2_EXT_RISING     7

#define TIM2_PRSECALAR_SELECT Timer2_256_PRESCALAR

#define NO_INTERRUPT 0
#define TIME2_TOV    1
#define TIME2_TOC    2

#define TIME2_INTERRUPT_MODE NO_INTERRUPT

#endif /* TIMERCONFIG_H_ */