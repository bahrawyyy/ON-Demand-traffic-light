/*
 * led.h
 *
 * Created: 11/15/2022 11:35:22 AM
 *  Author: Abdallah
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO DRIVER/Dio.h"
#include "../../MCAL/TIMER/Timer.h"
#include "../../MCAL/EXT_INTERRUPTS/EXT_INTERRUPTS.h"

void LED_init(void);
void LED_ON(channel_type channel);
void LED_OFF(channel_type channel);
void LED_TOGGLE(channel_type channel);
void STATE_LED(channel_type channel,uint8_t *val);
void YellowBlink(channel_type channel1);
void BothYellowBlink(channel_type channel1,channel_type channel2);

#endif /* LED_H_ */