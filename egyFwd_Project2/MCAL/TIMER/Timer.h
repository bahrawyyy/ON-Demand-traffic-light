/*
 * Timer.h
 *
 * Created: 11/15/2022 2:23:51 PM
 *  Author: Abdallah
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include "../../STD_Types.h"
#include "TimerConfig.h"
#include <math.h>

void timer_init(void);
void waitOVF_timer0(void);
void waitOVF_timer2(void);
void timer_stop(void);
void timer2_stop(void);
void Timer0_delay_ms(uint32_t delay);
void Timer2_delay_ms(uint32_t delay);

#endif /* TIMER_H_ */