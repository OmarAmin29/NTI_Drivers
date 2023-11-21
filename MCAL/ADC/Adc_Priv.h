/*
 * Adc_Priv.h
 *
 *  Created on: Oct 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_ADC_ADC_PRIV_H_
#define MCAL_ADC_ADC_PRIV_H_


#include "../../Private/Types.h"


/*typedef union
{
	u8 reg;
	struct
	{
		u8 B0 : 1;
		u8 B1 : 1;
		u8 B2 : 1;
		u8 B3 : 1;
		u8 B4 : 1;
		u8 B5 : 1;
		u8 B6 : 1;
		u8 B7 : 1;
	}BIT;

}Adc_RegType;

typedef struct
{
	Adc_RegisterType ADCL; 
	Adc_RegisterType ADCH; 
	Adc_RegisterType ADCSRA; 
	Adc_RegisterType ADMUX; 
}Adc_RegisterType;*/

/*#define ADC_BASE_ADRESS			(Adc_RegisterType*) 0x24*/			


#define ADMUX		*((volatile u8*) 0x27)
#define ADCSRA		*((volatile u8*) 0x26)
#define ADCDATA		*((volatile u16*) 0x24)
#define ADCL		*((volatile u8*) 0x24)
#define ADCH		*((volatile u8*) 0x25)
#define SFIOR		*((volatile u8*) 0x50)


/*BITS OF ADMUX REGISTER*/
#define REFS1	       7
#define REFS0	       6
#define ADLAR	       5
#define MUX4 	       4
#define MUX3 	       3
#define MUX2 	       2
#define MUX1 	       1
#define MUX0 	       0

/*BITS OF ADCSRA REGISTER*/
#define ADEN 	       7
#define ADSC 	       6
#define ADATE	       5
#define ADIF 	       4
#define ADIE 	       3
#define ADPS2	       2
#define ADPS1	       1
#define ADPS0	       0

/*BITS OF SFIOR REGISTER*/
#define ADTS2	       7
#define ADTS1	       6
#define ADTS0	       5


/****************BIT MASKING*************/
#define ADC_VOLTAGE_REF				0b00111111
#define ADC_PRESCALER				0b11111000
#define ADC_ANALOG_CHANNEL			0b11110000
#define ADC_AUTO_TRIGGER_SOURCE		0b00001111


#endif /* MCAL_ADC_ADC_PRIV_H_ */
