/*
 * led.c
 *
 * Created: 11/15/2022 11:35:44 AM
 *  Author: Abdallah
 */ 


#include "led.h"
/************************************************************************/
/* Intitialize LED By calling DIO_INIT                                                                     */
/************************************************************************/
void LED_init(){
	Dio_init();
}


/************************************************************************/
/* Turn on the LED                                                                     */
/************************************************************************/
void LED_ON(channel_type channel){
	Dio_write(channel,HIGH);
}



/************************************************************************/
/* Turn off the led                                                                     */
/************************************************************************/
void LED_OFF(channel_type channel){
	Dio_write(channel,LOW);
}



/************************************************************************/
/* Toggle the led                                                                     */
/************************************************************************/
void LED_TOGGLE(channel_type channel){
	Dio_FlipChannel(channel);
}




/************************************************************************/
/* Get the status of the LED (ON/OFF)                                                                    */
/************************************************************************/
void STATE_LED(channel_type channel,uint8_t *val){
	Dio_read(channel, val);
}

/************************************************************************/
/* To make only a specific LED blinking                                                                     */
/************************************************************************/
void YellowBlink(channel_type channel1){
	LED_ON(channel1);
	Timer0_delay_ms(500);
	LED_OFF(channel1);
	Timer0_delay_ms(500);
}
/************************************************************************/
/* To  make both Yellow Leds blinking                                                                     */
/************************************************************************/
void BothYellowBlink(channel_type channel1,channel_type channel2){
	LED_ON(channel1);
	LED_ON(channel2);
	Timer0_delay_ms(500);
	LED_OFF(channel1);
	LED_OFF(channel2);
	Timer0_delay_ms(500);
}
