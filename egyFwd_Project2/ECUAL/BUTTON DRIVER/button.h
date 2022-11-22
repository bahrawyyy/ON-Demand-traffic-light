/*
 * button.h
 *
 * Created: 11/15/2022 12:12:50 PM
 *  Author: Abdallah
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO DRIVER/Dio.h"

// All initializations are in Dio_init() which already called by led_init so, we don't need to create a function that initalize the button

// Button read
void BUTTON_read(channel_type channel,uint8_t *val);     // value is to store if it is pressed or not


#endif /* BUTTON_H_ */