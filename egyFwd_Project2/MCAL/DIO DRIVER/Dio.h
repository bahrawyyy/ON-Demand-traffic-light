/*
 * dio.h
 *
 * Created: 11/15/2022 10:13:00 AM
 *  Author: Abdallah
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../Registers.h"
#include "../../STD_Types.h"
#include "../../Bit_Math.h"

#include "Dio_Types.h"
#include "Dio_Cfg.h"

void Dio_init(void);
void Dio_write(channel_type channel , Dio_Status_Type state);
void Dio_read(channel_type channel,uint8_t *value);
void Dio_writePort(Dio_Port_Type port , unsigned char level);
void Dio_FlipChannel(channel_type channel);


#endif /* DIO_H_ */