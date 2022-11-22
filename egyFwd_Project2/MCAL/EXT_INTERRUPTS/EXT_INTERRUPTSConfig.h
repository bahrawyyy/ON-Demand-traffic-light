/*
 * EXT_INTERRUPTSConfig.h
 *
 * Created: 11/17/2022 3:54:55 PM
 *  Author: Abdallah
 */ 


#ifndef EXT_INTERRUPTSCONFIG_H_
#define EXT_INTERRUPTSCONFIG_H_


typedef enum{
	EXTI0,
	EXTI1,
	EXTI2
}EXTI_type;


#define	DISABLE 0
#define	ENABLE 1

#define EXT_INT0_MODE ENABLE
#define EXT_INT1_MODE DISABLE
#define EXT_INT2_MODE DISABLE

#define LOW_LEVEL_TRIG 0
#define ANY_LOGIC_TRIG 1
#define FAL_EDGE_TRIG  2
#define RIS_EDGE_TRIG  3

// Select Sense Mode
#define INT0_SENSE_MODE RIS_EDGE_TRIG
#define INT1_SENSE_MODE RIS_EDGE_TRIG
#define INT2_SENSE_MODE RIS_EDGE_TRIG


#endif /* EXT_INTERRUPTSCONFIG_H_ */