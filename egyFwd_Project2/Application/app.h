/*
 * app.h
 *
 * Created: 11/17/2022 12:30:28 PM
 *  Author: Abdallah
 */ 


#ifndef APP_H_
#define APP_H_

#include "../Registers.h"
#include "../ECUAL/LED DRIVER/led.h"
#include "../ECUAL/BUTTON DRIVER/button.h"


#define F_CPU 1000000UL

#define SWITCH PORTD_2

#define LED_GREEN_CARS PORTA_0
#define LED_YELLOW_CARS PORTA_1
#define LED_RED_CARS PORTA_2

#define LED_GREEN_PEDS PORTB_0
#define LED_YELLOW_PEDS PORTB_1
#define LED_RED_PEDS PORTB_2

typedef enum{
	NORMAL_MODE,
	PEDESTRIAN_MODE
}Mode_Selected;

void APP_init(void);
void APP_start(void);

void ChooseMode(Mode_Selected Mode);
void Button_State(void);



#endif /* APP_H_ */