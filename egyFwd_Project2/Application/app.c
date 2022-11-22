/*
 * app.c
 *
 * Created: 11/17/2022 12:30:19 PM
 *  Author: Abdallah
 */ 


#include "app.h"

/************************************************************************/
/* This function to choose between normal mode and pedsterian mode based on the argument  */
/************************************************************************/

void ChooseMode(Mode_Selected Mode){
	if(Mode == NORMAL_MODE){
		LED_ON(LED_GREEN_CARS);
		Timer0_delay_ms(5000);
		// Yellow LED blinking for 5 seconds
		for (uint8_t i = 0;i<5;i++)
		{
			LED_OFF(LED_GREEN_CARS);
			YellowBlink(LED_YELLOW_CARS);
		}
		LED_OFF(LED_YELLOW_CARS);
		LED_ON(LED_RED_CARS);
		Timer0_delay_ms(5000);
		for (uint8_t i = 0;i<5;i++)
		{
			LED_OFF(LED_RED_CARS);
			LED_OFF(LED_GREEN_PEDS);
			YellowBlink(LED_YELLOW_CARS);
		}
		}else if(Mode == PEDESTRIAN_MODE){
		uint8_t ledredval,ledyellowval,ledgreenval;
		Dio_read(LED_RED_CARS,&ledredval);
		Dio_read(LED_GREEN_CARS,&ledgreenval);
		Dio_read(LED_YELLOW_CARS,&ledyellowval);
		if(ledredval == HIGH){
			LED_ON(LED_RED_CARS);
			LED_ON(LED_GREEN_PEDS);
			Timer0_delay_ms(5000);
			// Completing the states
			for (uint8_t i = 0;i<5;i++)
			{
				LED_OFF(LED_RED_CARS);
				BothYellowBlink(LED_YELLOW_CARS,LED_YELLOW_PEDS);
			}
			LED_OFF(LED_GREEN_PEDS);
			LED_ON(LED_RED_PEDS);
			LED_ON(LED_GREEN_CARS);
		}
		if((ledyellowval == HIGH)||(ledgreenval == HIGH)){
			LED_ON(LED_RED_PEDS);
			Timer0_delay_ms(1000);
			for (uint8_t i = 0;i<5;i++)
			{
				LED_ON(LED_RED_PEDS);
				LED_OFF(LED_GREEN_CARS);
				BothYellowBlink(LED_YELLOW_CARS,LED_YELLOW_PEDS);
			}
			LED_OFF(LED_YELLOW_CARS);
			LED_OFF(LED_YELLOW_PEDS);
			LED_OFF(LED_RED_PEDS);
			LED_ON(LED_RED_CARS);
			LED_ON(LED_GREEN_PEDS);
			Timer0_delay_ms(5000);
			// Completing the states
			for (uint8_t i = 0;i<5;i++)
			{
				LED_OFF(LED_RED_CARS);
				BothYellowBlink(LED_YELLOW_CARS,LED_YELLOW_PEDS);
			}
			LED_OFF(LED_GREEN_PEDS);
			LED_ON(LED_RED_PEDS);
			LED_ON(LED_GREEN_CARS);
		}
	}
}

/************************************************************************/
/* This function to switch between the two modes when the switch is pressed*/
/************************************************************************/

void Button_State(void){
	uint8_t ButtonState = 0;
	BUTTON_read(SWITCH,&ButtonState);
	if(ButtonState == HIGH){
		ChooseMode(PEDESTRIAN_MODE);
		}else if(ButtonState == LOW){
		ChooseMode(NORMAL_MODE);
	}
}

/************************************************************************/
/* HERE is all the intialization that we're going to use and Setting call back function (interrupt)*/
/************************************************************************/

void APP_init(void){
	LED_init();

	timer_init();
	
	SREG |= (1<<7); //Enable global interrupt
	//EXT_init_Interrupt0();
	EXTI_init();
	SetCallback_INT0(Button_State);
}


// Some variables that we'll use in app_start
uint8_t ButtonState = 0;
uint8_t ledredval = 0,ledyellowval = 0,ledgreenval = 0;


/************************************************************************/
/* Here is where all the process happens and switching between different states based on the previuos state and the input which is the switch   */
/************************************************************************/

void APP_start(void){
	BUTTON_read(SWITCH,&ButtonState);
	STATE_LED(LED_RED_CARS,&ledredval);
	STATE_LED(LED_GREEN_CARS,&ledgreenval);
	STATE_LED(LED_YELLOW_CARS,&ledyellowval);
	if((ButtonState == HIGH)&&(ledredval == HIGH)){
		LED_ON(LED_RED_CARS);
		LED_ON(LED_GREEN_PEDS);
		Timer0_delay_ms(5000);
		// Completing the states
		for (uint8_t i = 0;i<5;i++)
		{
			LED_OFF(LED_RED_CARS);
			BothYellowBlink(LED_YELLOW_CARS,LED_YELLOW_PEDS);
		}
		LED_OFF(LED_GREEN_PEDS);
		LED_ON(LED_RED_PEDS);
		LED_ON(LED_GREEN_CARS);
	}
	else if((ButtonState == HIGH)&&((ledyellowval == HIGH)||(ledgreenval == HIGH))){
		Timer0_delay_ms(1000);
		if(ButtonState == LOW){
			LED_ON(LED_RED_PEDS);
		Timer0_delay_ms(1000);
		for (uint8_t i = 0;i<5;i++)
		{
			LED_ON(LED_RED_PEDS);
			BothYellowBlink(LED_YELLOW_CARS,LED_YELLOW_PEDS);
		}
		LED_OFF(LED_YELLOW_CARS);
		LED_OFF(LED_YELLOW_PEDS);
		LED_OFF(LED_RED_PEDS);
		LED_ON(LED_RED_CARS);
		LED_ON(LED_GREEN_PEDS);
		Timer0_delay_ms(5000);
		// Completing the states
		for (uint8_t i = 0;i<5;i++)
		{
			LED_OFF(LED_RED_CARS);
			BothYellowBlink(LED_YELLOW_CARS,LED_YELLOW_PEDS);
		}
		LED_OFF(LED_GREEN_PEDS);
		LED_ON(LED_RED_PEDS);
		LED_ON(LED_GREEN_CARS);
		}
		
	}
	else if(ButtonState == LOW){
		ChooseMode(NORMAL_MODE);
	}
}