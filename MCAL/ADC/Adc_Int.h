/*
 * Adc.h
 *
 *  Created on: Oct 24, 2023
 *      Author: lenovo
 */

#ifndef MCAL_ADC_ADC_INT_H_
#define MCAL_ADC_ADC_INT_H_

typedef enum
{
    ADC_CHANNEL_ADC0 = 0,
    ADC_CHANNEL_ADC1 = 1,
    ADC_CHANNEL_ADC2,
    ADC_CHANNEL_ADC3,
    ADC_CHANNEL_ADC4,
    ADC_CHANNEL_ADC5,
    ADC_CHANNEL_ADC6,
    ADC_CHANNEL_ADC7,
    ADC_CHANNEL_ADC0_ADC0_10X,
    ADC_CHANNEL_ADC1_ADC0_10X,
    ADC_CHANNEL_ADC0_ADC0_200X,
    ADC_CHANNEL_ADC1_ADC0_200X,
    ADC_CHANNEL_ADC2_ADC2_10X,
    ADC_CHANNEL_ADC3_ADC2_10X,
    ADC_CHANNEL_ADC2_ADC2_200X,
    ADC_CHANNEL_ADC3_ADC2_200X,
    ADC_CHANNEL_ADC0_ADC1_1X,
    ADC_CHANNEL_ADC1_ADC1_1X,
    ADC_CHANNEL_ADC2_ADC1_1X,
    ADC_CHANNEL_ADC3_ADC1_1X,
    ADC_CHANNEL_ADC4_ADC1_1X,
    ADC_CHANNEL_ADC5_ADC1_1X,
    ADC_CHANNEL_ADC6_ADC1_1X,
    ADC_CHANNEL_ADC7_ADC1_1X,
    ADC_CHANNEL_ADC0_ADC2_1X,
    ADC_CHANNEL_ADC1_ADC2_1X,
    ADC_CHANNEL_ADC2_ADC2_1X,
    ADC_CHANNEL_ADC3_ADC2_1X,
    ADC_CHANNEL_ADC4_ADC2_1X,
    ADC_CHANNEL_ADC5_ADC2_1X,
    ADC_CHANNEL_1_22_V,
    ADC_CHANNEL_GND
} Adc_ChannelType;

typedef enum
{
    ADC_REF_AREF = 0,
    ADC_REF_AVCC = 1,
    ADC_REF_Internal_2_56V = 3
}Adc_VoltageReferenceType;

typedef enum{
    ADC_ADJUST_LEFT,
    ADC_ADJUST_RIGHT
}Adc_AdjustType;

typedef enum
{
    ADC_PRESCALER_2 = 0,
    ADC_PRESCALER_4 = 2,
    ADC_PRESCALER_8 = 3,
    ADC_PRESCALER_16 = 4,
    ADC_PRESCALER_32 = 5,
    ADC_PRESCALER_64 = 6,
    ADC_PRESCALER_128 = 7
} Adc_PrescalerType;

typedef enum
{
    ADC_AUTO_TRIGGER_OFF = 8,
    ADC_AUTO_TRIGGER_FREE_RUNNING = 0,
    ADC_AUTO_TRIGGER_ANAL_COMP = 1,
    ADC_AUTO_TRIGGER_EXTI0 = 2,
    ADC_AUTO_TRIGGER_TIM0_COMP = 3,
    ADC_AUTO_TRIGGER_TIM0_OVF = 4,
    ADC_AUTO_TRIGGER_TIMB_COMP = 5,
    ADC_AUTO_TRIGGER_TIM1_OVF = 6,
    ADC_AUTO_TRIGGER_TIM1_CAP = 7
} Adc_TriggerSourceType;

typedef struct{
    Adc_VoltageReferenceType reference;
    Adc_AdjustType ajust;
    Adc_PrescalerType prescaler;
    Adc_TriggerSourceType trigger;
}Adc_ConfigurationsType;



void M_ADC_Init(Adc_ConfigurationsType* config);
//void M_ADC_Init(void);
u16 M_ADC_getDigitalValueSynchNonBlocking(Adc_ChannelType channel);
void M_ADC_getDigitalValueAsynchCallBack(void);
//u16 M_Adc_GetResult(void);

#endif /* MCAL_ADC_ADC_INT_H_ */
