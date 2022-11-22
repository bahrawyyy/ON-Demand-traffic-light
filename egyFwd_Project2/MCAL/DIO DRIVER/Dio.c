/*
 * dio.c
 *
 * Created: 11/15/2022 10:13:13 AM
 *  Author: Abdallah
 */ 


#include "Dio.h"


/************************************************************************/
/* This function to write high or low on a specific pin in a specific port based on the parameters recieved */
/************************************************************************/


void Dio_write(channel_type channel , Dio_Status_Type state){
	Dio_Port_Type port = channel / 8;
	Dio_Pin_Type pin = channel % 8;

	if(port == PORT_A){
		if(state == HIGH){
			SET_BIT(PORTA,pin);
			}else{
			CLR_BIT(PORTA,pin);
		}
		}else if(port == PORT_B){
		if(state == HIGH){
			SET_BIT(PORTB,pin);
			}else{
			CLR_BIT(PORTB,pin);
		}
		}else if(port == PORT_C){
		if(state == HIGH){
			SET_BIT(PORTC,pin);
			}else{
			CLR_BIT(PORTC,pin);
		}
		}else if(port == PORT_D){
		if(state == HIGH){
			SET_BIT(PORTD,pin);
			}else{
			CLR_BIT(PORTD,pin);
		}
	}
}

/************************************************************************/
/* To read a specific pin and store the value read in *value */
/************************************************************************/

void Dio_read(channel_type channel,uint8_t *value){
	Dio_Port_Type port = channel / 8;
	Dio_Pin_Type pin = channel % 8;
	//Dio_Status_Type status = 0;


	if(port == PORT_A){
		*value = GET_BIT(PINA,pin);
		}else if(port == PORT_B){
		*value = GET_BIT(PINB,pin);
		}else if(port == PORT_C){
		*value = GET_BIT(PINC,pin);
		}else if(port == PORT_D){
		*value = GET_BIT(PIND,pin);
	}
}

/************************************************************************/
/* To write on the whole port */
/************************************************************************/

void Dio_writePort(Dio_Port_Type port , unsigned char level){
	if(port == PORT_A){
		PORTA = level;
		}else if(port == PORT_B){
		PORTB = level;
		}else if(port == PORT_C){
		PORTC = level;
		}else if(port == PORT_D){
		PORTD = level;
	}
}

/************************************************************************/
/* To initialize the pins used (output or input)
 Which are stored in an array of structures in configuration.c file  */
/************************************************************************/


void Dio_init(void){
	int i = 0;
	for(i=0 ; i<PIN_COUNT ; i++){
		if(Dio_Cfg_Pins[i].PinPort == PORT_A){
			if(Dio_Cfg_Pins[i].dir == OUTPUT){
				SET_BIT(DDRA,Dio_Cfg_Pins[i].Pin);
				}else{
				CLR_BIT(DDRA,Dio_Cfg_Pins[i].Pin);
				if(Dio_Cfg_Pins[i].PullUp == PULLUP_ON){
					SET_BIT(PORTA,Dio_Cfg_Pins[i].Pin);
				}
			}
			}else if(Dio_Cfg_Pins[i].PinPort == PORT_B){
			if(Dio_Cfg_Pins[i].dir == OUTPUT){
				SET_BIT(DDRB,Dio_Cfg_Pins[i].Pin);
				}else{
				CLR_BIT(DDRB,Dio_Cfg_Pins[i].Pin);
				if(Dio_Cfg_Pins[i].PullUp == PULLUP_ON){
					SET_BIT(PORTB,Dio_Cfg_Pins[i].Pin);
				}
			}
			}else if(Dio_Cfg_Pins[i].PinPort == PORT_C){
			if(Dio_Cfg_Pins[i].dir == OUTPUT){
				SET_BIT(DDRC,Dio_Cfg_Pins[i].Pin);
				}else{
				CLR_BIT(DDRC,Dio_Cfg_Pins[i].Pin);
				if(Dio_Cfg_Pins[i].PullUp == PULLUP_ON){
					SET_BIT(PORTC,Dio_Cfg_Pins[i].Pin);
				}
			}
			}else if(Dio_Cfg_Pins[i].PinPort == PORT_D){
			if(Dio_Cfg_Pins[i].dir == OUTPUT){
				SET_BIT(DDRD,Dio_Cfg_Pins[i].Pin);
				}else{
				CLR_BIT(DDRD,Dio_Cfg_Pins[i].Pin);
				if(Dio_Cfg_Pins[i].PullUp == PULLUP_ON){
					SET_BIT(PORTD,Dio_Cfg_Pins[i].Pin);
				}
			}
		}
	}
}

/************************************************************************/
/* To toggle a specifi pin                           */
/************************************************************************/

void Dio_FlipChannel(channel_type channel){
	Dio_Port_Type port = channel / 8;
	Dio_Pin_Type pin = channel % 8;

	if(port == PORT_A){
		TOG_BIT(PORTA,pin);
		}else if(port == PORT_B){
		TOG_BIT(PORTB,pin);
		}else if(port == PORT_C){
		TOG_BIT(PORTC,pin);
		}else if(port == PORT_D){
		TOG_BIT(PORTD,pin);
	}
}
