/*
 * button.c
 *
 * Created: 11/15/2022 12:12:36 PM
 *  Author: Abdallah
 */ 

#include "../../MCAL/DIO DRIVER/Dio.h"

/************************************************************************/
/* Get Button status                                                                    */
/************************************************************************/

void BUTTON_read(channel_type channel,uint8_t *val){
	Dio_read(channel, val);
}
