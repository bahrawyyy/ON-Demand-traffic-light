/*
 * Registers.h
 *
 * Created: 11/15/2022 9:51:28 AM
 *  Author: Abdallah
 */ 


#ifndef REGISTERS_H_
#define REGISTERS_H_

/*
	All Microcontroller Registers
*/

#include "STD_Types.h"

/*************** DIO_REGISTERS *************/

#define PORTA *((volatile uint8_t*)0x3B)
#define DDRA *((volatile uint8_t*)0x3A)
#define PINA *((volatile uint8_t*)0x39)

#define PORTB *((volatile uint8_t*)0x38)
#define DDRB *((volatile uint8_t*)0x37)
#define PINB *((volatile uint8_t*)0x36)

#define PORTC *((volatile uint8_t*)0x35)
#define DDRC *((volatile uint8_t*)0x34)
#define PINC *((volatile uint8_t*)0x33)

#define PORTD *((volatile uint8_t*)0x32)
#define DDRD *((volatile uint8_t*)0x31)
#define PIND *((volatile uint8_t*)0x30)



/**************_EX_INT_REGISTERS_************/

#define SREG   (*(volatile uint8_t*)(0x5F))
#define GICR   (*(volatile uint8_t*)(0x5B))
#define GIFR   (*(volatile uint8_t*)(0x5A))
#define MCUCR  (*(volatile uint8_t*)(0x55))
#define MCUCSR (*(volatile uint8_t*)(0x54))




/***************_ADC_REGISTERS_**************/

#define ADMUX           (*(volatile uint8_t*)(0x27))
#define ADCSRA          (*(volatile uint8_t*)(0x26))
#define ADCH            (*(volatile uint8_t*)(0x25))
#define ADCL            (*(volatile uint8_t*)(0x24))
#define ADC_VALUE       (*(volatile uint16_t*)(0x24))




/***************_TIMER0_REGISTERS_**************/

#define TCNT0           (*(volatile uint8_t*)(0x52))
#define TIMSK           (*(volatile uint8_t*)(0x59))
#define TCCR0           (*(volatile uint8_t*)(0x53))
#define TIFR            (*(volatile uint8_t*)(0x58))
#define OCR0            (*(volatile uint8_t*)(0x5C))




/***************_TIMER1_REGISTERS_**************/

#define TCCR1B          (*(volatile uint8_t*)(0x4E))
#define TCCR1A          (*(volatile uint8_t*)(0x4F))
#define OCR1A           (*(volatile u16*)(0x4A))





/***************_WDT_REGISTERS_**************/

#define WDTCR          (*(volatile uint8_t*)(0x41))




/***************_UART_REGISTERS_**************/

#define UDR            (*(volatile uint8_t*)(0x2C))
#define UCSRA          (*(volatile uint8_t*)(0x2B))
#define UCSRB          (*(volatile uint8_t*)(0x2A))
#define UCSRC          (*(volatile uint8_t*)(0x40))
#define UBRRL          (*(volatile uint8_t*)(0x29))




/***************_SPI_REGISTERS_**************/

#define SPCR          (*(volatile uint8_t*)(0x2D))
#define SPDR          (*(volatile uint8_t*)(0x2F))
#define SPSR          (*(volatile uint8_t*)(0x2E))

#endif /* REGISTERS_H_ */