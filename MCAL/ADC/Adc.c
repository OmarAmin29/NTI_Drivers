/*
 * Adc.c
 *
 *  Created on: Oct 24, 2023
 *      Author: lenovo
 */

#include"../../Private/Types.h"
#include"../../Private/Macros.h"
#include"Adc_Priv.h"

#include"Adc.h"

/*void ADC_Init(Adc_ConfigurationsType* config)
{
    /*Make sure the register is zero*/
   /* ADMUX = 0;
    switch (config->reference)
    {
    case ADC_REF_AREF:
        CLR_BIT(ADMUX,REFS0);
        CLR_BIT(ADMUX,REFS1);        
        break;
    case ADC_REF_AVCC:
        SET_BIT(ADMUX,REFS0);
        CLR_BIT(ADMUX,REFS1);        
        break;
    case ADC_REF_Internal_2_56V:
        SET_BIT(ADMUX,REFS0);
        SET_BIT(ADMUX,REFS1);        
        break;
    

    
    default:
        break;
    }

}*/

void ADC_Init()
{
    ADMUX = 0;
    /*AVCC with external capacitor at AREF pin*/
    CLR_BIT(ADMUX,REFS1);
    SET_BIT(ADMUX,REFS0);

    /* ADC Left Adjust Result */
    CLR_BIT(ADMUX, ADLAR); // Right

    /* ADC Prescaler Select Bits */
    SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);

    SET_BIT(ADMUX,ADLAR);

    /* ADC Enable*/
    SET_BIT(ADCSRA,ADEN);
}

u16 ADC_getDigitalValueSynchNonBlocking(Adc_ChannelType channel)
{
    switch (channel)
    {
        /*Select channel*/
    case ADC_CHANNEL_ADC0:
        CLR_BIT(ADMUX, MUX0);
        CLR_BIT(ADMUX, MUX1);
        CLR_BIT(ADMUX, MUX2);
        CLR_BIT(ADMUX, MUX3);  
        CLR_BIT(ADMUX, MUX4);
        break;
    
    default:
        break;
    }
    SET_BIT(ADCSRA, ADSC);

    u16 result;
    /* Wait for flag*/
    while (GET_BIT(ADCSRA, 4) == 0);
    /* Clear Flag */
    SET_BIT(ADCSRA, 4);
    result = ADCH;
    return result;
    //return ADC;

}


u16 Adc_GetResult(void) {
	u16 result;
    /* Wait for flag*/
    while (GET_BIT(ADCSRA, 4) == 0);
    /* Clear Flag */
    SET_BIT(ADCSRA, 4);
    result = ADCDATA & 0xFF;
    /* Return Result */
    return result;
}

