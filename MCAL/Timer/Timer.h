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


typedef enum{
    TIMER_NORMAL = 0,
    TIMER_PWM_PHASE_CORRECT = 1,
    TIMER_CTC = 2,
    TIMER_FAST_PWM = 3
}Timer_ModeType;

typedef enum{
    TIMER_COMP_OUTPUT_DISCONNECTED = 0,
    TIMER_COMP_OUTPUT_TOGGLE = 1,
    TIMER_COMP_OUTPUT_CLEAR = 2,
    TIMER_COMP_OUTPUT_SET = 3
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
    TIMER0_INT_SOURCE_OVF
} Timer_InterruptSourceType;

typedef struct
{
    Timer_ModeType mode;
    Timer_CompareOutModeType compareOutputMode;
}Timer_CfgType;

void M_Timer_Init(Timer_CfgType* mode);
void M_Timer_Start(TIMER_PrescalerType prescaler);
void M_Timer_Stop();
u32 M_Timer_GetCounts();
void M_Timer_EnableInt(Timer_InterruptSourceType source);
void M_Timer_DisableInt(Timer_InterruptSourceType source);
void M_Timer_setCallBack(Timer_InterruptSourceType source, void (*funcPtr) (void));

#endif /* MCAL_TIMER_TIMER_H_ */
