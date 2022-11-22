/*
 * Dio_Cfg.h
 *
 * Created: 11/15/2022 10:15:32 AM
 *  Author: Abdallah
 */ 


#ifndef DIO_CFG_H_
#define DIO_CFG_H_


#include "Dio_Types.h"


#define PIN_COUNT 7     // NO. of pins that we're going to use

typedef struct{
	Dio_Port_Type PinPort;
	Dio_Pin_Type Pin;
	Dio_Dir_Type dir;
	Dio_PULLUP_Type PullUp;
}Dio_Pin_Config;

extern Dio_Pin_Config Dio_Cfg_Pins[PIN_COUNT];


#endif /* DIO_CFG_H_ */