/*
 * Adc.c
 *
 *  Created on: Oct 24, 2023
 *      Author: lenovo
 */

#include"../../Private/Types.h"
#include"../../Private/Macros.h"
#include"Adc_Priv.h"
#include "Adc_Int.h"

#include "../../HAL/LCD/Lcd.h"


void M_ADC_Init(Adc_ConfigurationsType* config)
{
    /*Make sure the register is zero*/
    ADMUX = 0;

    /*Voltage Reference*/
    ADMUX &= ADC_VOLTAGE_REF;
    ADMUX |= (config->reference) << 6;

    /*Adjust Result*/
    if(config->ajust == ADC_ADJUST_LEFT)
    {
        SET_BIT(ADMUX, ADLAR);
    }
    else if(config->ajust == ADC_ADJUST_RIGHT)
    {
        CLR_BIT(ADMUX, ADLAR);
    }

    /*Prescaler*/
    ADCSRA &= ADC_PRESCALER;
    ADCSRA |= config->prescaler;

    /*Auto Trigger*/
    if(config->trigger == ADC_AUTO_TRIGGER_OFF)
    {
        CLR_BIT(ADCSRA, ADATE);
    }
    else
    {
        SET_BIT(ADCSRA, ADATE);
        SFIOR &= ADC_AUTO_TRIGGER_SOURCE;
        SFIOR |= config->trigger << 5;
    }

    /*ADC Enable*/
    SET_BIT(ADCSRA, ADEN);
    /*ADC Start Conversion*/
    //SET_BIT(ADCSRA, ADSC);

    
   /* switch (config->reference)
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
    }*/

}

/*void ADC_Init()
{
    ADMUX = 0;
    /*AVCC with external capacitor at AREF pin*/
    /*CLR_BIT(ADMUX,REFS1);
    SET_BIT(ADMUX,REFS0);

    /* ADC Left Adjust Result */
    /*CLR_BIT(ADMUX, ADLAR); // Right

    /* ADC Prescaler Select Bits */
    /*SET_BIT(ADCSRA, ADPS2);
    SET_BIT(ADCSRA, ADPS1);
    SET_BIT(ADCSRA, ADPS0);

    SET_BIT(ADMUX,ADLAR);

    /* ADC Enable*/
    /*SET_BIT(ADCSRA,ADEN);
}*/

u16 M_ADC_getDigitalValueSynchNonBlocking(Adc_ChannelType channel)
{
    /*Analog Channel*/
    ADMUX &= ADC_ANALOG_CHANNEL;
    ADMUX |= channel;

    /*switch (channel)
    {
        /*Select channel*/
    /*case ADC_CHANNEL_ADC0:
        CLR_BIT(ADMUX, MUX0);
        CLR_BIT(ADMUX, MUX1);
        CLR_BIT(ADMUX, MUX2);
        CLR_BIT(ADMUX, MUX3);  
        CLR_BIT(ADMUX, MUX4);
        break;
    
    default:
        break;
    }*/

    /*ADC Start Conversion*/
    SET_BIT(ADCSRA, ADSC);

    u16 result;
    /* Wait for flag*/
    //H_LCD_void_sendIntNum(2);
    while (GET_BIT(ADCSRA, ADIF) == 0);
    //H_LCD_void_sendIntNum(1);
    /* Clear Flag */
    SET_BIT(ADCSRA, ADIF);

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

