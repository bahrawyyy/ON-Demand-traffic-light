/*
 * Dio_Cfg.c
 *
 * Created: 11/15/2022 10:15:21 AM
 *  Author: Abdallah
 */ 


#include "Dio_Cfg.h"
#include "Dio.h"

/************************************************************************/
/* This is the array of structures that store each pin whether it is input or output  */
/************************************************************************/

Dio_Pin_Config Dio_Cfg_Pins[PIN_COUNT] = {
	{PORT_A,PIN_0,OUTPUT,PULLUP_OFF},  
	{PORT_A,PIN_1,OUTPUT,PULLUP_OFF},
	{PORT_A,PIN_2,OUTPUT,PULLUP_OFF},
	{PORT_B,PIN_0,OUTPUT,PULLUP_OFF},
	{PORT_B,PIN_1,OUTPUT,PULLUP_OFF},
	{PORT_B,PIN_2,OUTPUT,PULLUP_OFF},
	{PORT_D,PIN_2,INPUT,PULLUP_OFF}
};


