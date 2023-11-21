/*
 * Timer.h
 *
 *  Created on: Oct 27, 2023
 *      Author: lenovo
 */

#ifndef MCAL_TIMER_TIMER_H_
#define MCAL_TIMER_TIMER_H_


#include"../../Private/Types.h"
#include"Timer_Priv.h"
#include"Timer_Cfg.h"




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
}TIMER_RegisterType;*/

/*typedef struct
{
    TIMER_RegisterType ICR1L;
    TIMER_RegisterType ICR1H;
    TIMER_RegisterType OCR1BL;
    TIMER_RegisterType OCR1BH;
    TIMER_RegisterType OCR1AL;
    TIMER_RegisterType OCR1AH;
    TIMER_RegisterType TCNT1L;
    TIMER_RegisterType TCNT1H;
    TIMER_RegisterType TCCR1B;
    TIMER_RegisterType TCCR1A;

};*/




typedef enum {
    TIMER_CHANNEL_TIM0,
    TIMER_CHANNEL_TIM1,
    TIMER_CHANNEL_TIM2
} Timer_ChannelType;

typedef enum{
    TIMER0_NORMAL = 0,
    TIMER0_PWM_PHASE_CORRECT = 1,
    TIMER0_CTC = 2,
    TIMER0_FAST_PWM = 3,
    TIMER1_NORMAL = 0,
    TIMER1_PWM_PHASE_CORRECT_8BIT = 1,
    TIMER1_PWM_PHASE_CORRECT_9BIT = 2,
    TIMER1_PWM_PHASE_CORRECT_10BIT = 3,
    TIMER1_CTC_OCR = 4,
    TIMER1_FAST_PWM_8BIT = 5,
    TIMER1_FAST_PWM_9BIT = 6,
    TIMER1_FAST_PWM_10BIT = 7,
    TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR = 8,
    TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR = 9,
    TIMER1_PWM_PHASE_CORRECT_ICR = 10,
    TIMER1_PWM_PHASE_CORRECT_OCR = 11,
    TIMER1_CTC_ICR = 12,
    TIMER1_FAST_PWM_ICR = 14,
    TIMER1_FAST_PWM_OCR = 15
}Timer_ModeType;

typedef enum{
    TIMER0_COMP_OUTPUT_DISCONNECTED = 0,
    TIMER0_COMP_OUTPUT_TOGGLE = 1,
    TIMER0_COMP_OUTPUT_CLEAR = 2,
    TIMER0_COMP_OUTPUT_SET = 3,
    TIMER1_A_COMP_OUTPUT_DISCONNECTED = 0,
    TIMER1_A_COMP_OUTPUT_TOGGLE = 1,
    TIMER1_A_COMP_OUTPUT_CLEAR = 2,
    TIMER1_A_COMP_OUTPUT_SET = 3,
    TIMER1_B_COMP_OUTPUT_DISCONNECTED = 4,
    TIMER1_B_COMP_OUTPUT_TOGGLE = 5,
    TIMER1_B_COMP_OUTPUT_CLEAR = 6,
    TIMER1_B_COMP_OUTPUT_SET = 7,

}Timer_CompareOutModeType;

typedef enum {
    TIMER_NO_CLOCK = 0,
    TIMER_PRESCALER_1 = 1,
    TIMER_PRESCALER_8 = 2,
    TIMER_PRESCALER_64 = 3,
    TIMER_PRESCALER_256 = 4,
    TIMER_PRESCALER_1024 = 5,
    TIMER_PRESCALER_EXT_FALLING = 6,
    TIMER_PRESCALER_EXT_RISING = 7
} TIMER_PrescalerType;

typedef enum {
    TIMER0_INT_SOURCE_COMP,
    TIMER0_INT_SOURCE_OVF,
    TIMER1_INT_SOURCE_ICU,
    TIMER1_A_INT_SOURCE_COMP,
    TIMER1_B_INT_SOURCE_COMP,
    TIMER1_INT_SOURCE_OVF
} Timer_InterruptSourceType;

typedef enum{
    ICU_TRIGGER_FALLING,
    ICU_TRIGGER_RISING
}Timer_IcuTrigger;





typedef struct
{
    Timer_ModeType mode;
    Timer_CompareOutModeType compareOutputMode;
}Timer_CfgType;

void M_Timer_Init(Timer_ChannelType channel, Timer_CfgType* config);
void M_Timer_Start(Timer_ChannelType channel, TIMER_PrescalerType prescaler);
void M_Timer_Stop(Timer_ChannelType channel);
u32 M_Timer_GetCounts();
void M_Timer_SetCompareReg(u8 value);
void M_Timer_EnableInt(Timer_InterruptSourceType source);
void M_Timer_DisableInt(Timer_InterruptSourceType source);
void M_Timer_setCallBack(Timer_InterruptSourceType source, void (*funcPtr) (void));
void M_Timer_SetFastPWM(u8 duty_cycle);
void M_Timer_SetPhasePWM(u8 duty_cycle);
u8 M_Timer_GetEventDuration(void);
u8 M_Timer_GetSignalFrequency(void);
u8 M_Timer_GetSignalDuty(Timer_IcuTrigger trigger);
void M_Timer1_ICU_IntEnable();
void M_Timer1_ICU_void_setTrigg(Timer_IcuTrigger trigger);
#endif /* MCAL_TIMER_TIMER_H_ */
