/*
 * Timer.c
 *
 *  Created on: Oct 27, 2023
 *      Author: lenovo
 */

#include"../../Private/Macros.h"
#include"Timer_Priv.h"
#include"Timer_Cfg.h"
#include"Timer.h"

void (*Timer_Callback_TIM0_COMP) (void) = NULL_PTR;
void (*Timer_Callback_TIM0_OVF) (void) = NULL_PTR;

ISR(VECTOR_TIMER0_COMP)
{
	if (NULL_PTR != Timer_Callback_TIM0_COMP)
	{
		Timer_Callback_TIM0_COMP();
	}

}

ISR(VECTOR_TIMER0_OVF)
{
	if (NULL_PTR != Timer_Callback_TIM0_OVF)
	{
		Timer_Callback_TIM0_OVF();
	}
}

void M_Timer_Init(Timer_CfgType* config)
{
    switch (config->mode)
    {
    case TIMER_NORMAL:
        CLR_BIT(TCCR0,WGM00);
        CLR_BIT(TCCR0,WGM01);
        break;

    case TIMER_PWM_PHASE_CORRECT:
        SET_BIT(TCCR0,WGM00);
        CLR_BIT(TCCR0,WGM01);
        break;
    
    case TIMER_CTC:
        CLR_BIT(TCCR0,WGM00);
        SET_BIT(TCCR0,WGM01);
        break;

    case TIMER_FAST_PWM:
        SET_BIT(TCCR0,WGM00);
        SET_BIT(TCCR0,WGM01);
        break;
    
    default:
        break;
    }

    switch (config->compareOutputMode)
    {
    case TIMER_COMP_OUTPUT_DISCONNECTED:
        TCCR0 &= COMP_OUTPUT_MODE_MASKING;
        TCCR0 |= TIMER_COMP_OUTPUT_DISCONNECTED;
        break;
    
    case TIMER_COMP_OUTPUT_TOGGLE:
        TCCR0 &= COMP_OUTPUT_MODE_MASKING;
        TCCR0 |= TIMER_COMP_OUTPUT_TOGGLE;
        break;
    
    case TIMER_COMP_OUTPUT_CLEAR:
        TCCR0 &= COMP_OUTPUT_MODE_MASKING;
        TCCR0 |= TIMER_COMP_OUTPUT_CLEAR;
        break;
    
    case TIMER_COMP_OUTPUT_SET:
        TCCR0 &= COMP_OUTPUT_MODE_MASKING;
        TCCR0 |= TIMER_COMP_OUTPUT_SET;
        break;

    default:
        break;
    }
}

void M_Timer_Start(TIMER_PrescalerType prescaler)
{
    switch (prescaler)
    {
    case TIMER_PRESCALER_1:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= TIMER_PRESCALER_1;
        break;
    
    case TIMER_PRESCALER_8:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= TIMER_PRESCALER_8;
        break;
    
    case TIMER_PRESCALER_64:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= TIMER_PRESCALER_64;
        break;

    case TIMER_PRESCALER_256:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= TIMER_PRESCALER_256;
        break;

    case TIMER_PRESCALER_1024:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= TIMER_PRESCALER_1024;
        break;

    case TIMER_PRESCALER_EXT_FALLING:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= TIMER_PRESCALER_EXT_FALLING;
        break;

    case TIMER_PRESCALER_EXT_RISING:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= TIMER_PRESCALER_EXT_RISING;
        break; 

    default:
        break;
    }
}


void M_Timer_Stop()
{
    TCCR0 &= TIMER0_PRESCALING_MASKING;
    TCCR0 |= TIMER_NO_CLOCK;
}

u32 M_Timer_GetCounts()
{
    u32 ret_value = 0;
    ret_value = TCNT0;
    return ret_value;
}

void M_Timer_EnableInt(Timer_InterruptSourceType source)
{
    switch (source)
    {
    case TIMER0_INT_SOURCE_COMP:
        SET_BIT(TIMSK,OCIE0);
        break;

    case TIMER0_INT_SOURCE_OVF:
        SET_BIT(TIMSK,TOIE0);
        break;
    
    default:
        break;
    }
}

void M_Timer_DisableInt(Timer_InterruptSourceType source)
{
    switch (source)
    {
    case TIMER0_INT_SOURCE_COMP:
        CLR_BIT(TIMSK,OCIE0);
        break;

    case TIMER0_INT_SOURCE_OVF:
        CLR_BIT(TIMSK,TOIE0);
        break;
    
    default:
        break;
    }
}

void M_Timer_setCallBack(Timer_InterruptSourceType source, void (*funcPtr) (void))
{
    switch (source)
    {
    case TIMER0_INT_SOURCE_COMP:
        Timer_Callback_TIM0_COMP = funcPtr;
        break;

    case TIMER0_INT_SOURCE_OVF:
        Timer_Callback_TIM0_OVF = funcPtr;
        break;
    
    default:
        break;
    }
}
