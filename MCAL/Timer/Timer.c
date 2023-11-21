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
void (*Timer_Callback_TIM1_ICU) (void) = NULL_PTR;
void (*Timer_Callback_TIM1_A_COMP) (void) = NULL_PTR;
void (*Timer_Callback_TIM1_B_COMP) (void) = NULL_PTR;
void (*Timer_Callback_TIM1_OVF) (void) = NULL_PTR;

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

ISR(VECTOR_TIM1_ICU)
{
	if (NULL_PTR != Timer_Callback_TIM1_ICU)
	{
		Timer_Callback_TIM1_ICU();
	}
}

ISR(VECTOR_TIM1_COMPA)
{
	if (NULL_PTR != Timer_Callback_TIM1_A_COMP)
	{
		Timer_Callback_TIM1_A_COMP();
	}
}

ISR(VECTOR_TIM1_COMPB)
{
	if (NULL_PTR != Timer_Callback_TIM1_B_COMP)
	{
		Timer_Callback_TIM1_B_COMP();
	}
}

ISR(VECTOR_TIM1_OVF)
{
	if (NULL_PTR != Timer_Callback_TIM1_OVF)
	{
		Timer_Callback_TIM1_OVF();
	}
}




void M_Timer_Init(Timer_ChannelType channel, Timer_CfgType* config)
{
    switch (channel)
    {
    case TIMER_CHANNEL_TIM0:
        switch (config->mode)
        {
        case TIMER0_NORMAL:
            CLR_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);
            break;

        case TIMER0_PWM_PHASE_CORRECT:
            SET_BIT(TCCR0,WGM00);
            CLR_BIT(TCCR0,WGM01);
            break;

        case TIMER0_CTC:
            CLR_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);
            break;

        case TIMER0_FAST_PWM:
            SET_BIT(TCCR0,WGM00);
            SET_BIT(TCCR0,WGM01);
            break;

        default:
            break;
        }

        /*Compare Output Mode*/
        TCCR0 &= COMP_OUTPUT_MODE_MASKING;
        TCCR0 |= (config->compareOutputMode << 4);
        break;

    case TIMER_CHANNEL_TIM1:
        switch (config->mode)
        {
        case TIMER1_NORMAL:
            CLR_BIT(TCCR1A,WGM10);
            CLR_BIT(TCCR1A,WGM11);
            CLR_BIT(TCCR1B,WGM12);
            CLR_BIT(TCCR1B,WGM13);
            break;
        
        case TIMER1_PWM_PHASE_CORRECT_8BIT:
            SET_BIT(TCCR1A,WGM10);
            CLR_BIT(TCCR1A,WGM11);
            CLR_BIT(TCCR1B,WGM12);
            CLR_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_PWM_PHASE_CORRECT_9BIT:
            CLR_BIT(TCCR1A,WGM10);
            SET_BIT(TCCR1A,WGM11);
            CLR_BIT(TCCR1B,WGM12);
            CLR_BIT(TCCR1B,WGM13);
            break;
        
        case TIMER1_PWM_PHASE_CORRECT_10BIT:
            SET_BIT(TCCR1A,WGM10);
            SET_BIT(TCCR1A,WGM11);
            CLR_BIT(TCCR1B,WGM12);
            CLR_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_CTC_OCR:
            CLR_BIT(TCCR1A,WGM10);
            CLR_BIT(TCCR1A,WGM11);
            SET_BIT(TCCR1B,WGM12);
            CLR_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_FAST_PWM_8BIT:
            SET_BIT(TCCR1A,WGM10);
            CLR_BIT(TCCR1A,WGM11);
            SET_BIT(TCCR1B,WGM12);
            CLR_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_FAST_PWM_9BIT:
            CLR_BIT(TCCR1A,WGM10);
            SET_BIT(TCCR1A,WGM11);
            SET_BIT(TCCR1B,WGM12);
            CLR_BIT(TCCR1B,WGM13);
            break;
        
        case TIMER1_FAST_PWM_10BIT:
            SET_BIT(TCCR1A,WGM10);
            SET_BIT(TCCR1A,WGM11);
            SET_BIT(TCCR1B,WGM12);
            CLR_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICR:
            CLR_BIT(TCCR1A,WGM10);
            CLR_BIT(TCCR1A,WGM11);
            CLR_BIT(TCCR1B,WGM12);
            SET_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OCR:
            SET_BIT(TCCR1A,WGM10);
            CLR_BIT(TCCR1A,WGM11);
            CLR_BIT(TCCR1B,WGM12);
            SET_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_PWM_PHASE_CORRECT_ICR:
            CLR_BIT(TCCR1A,WGM10);
            SET_BIT(TCCR1A,WGM11);
            CLR_BIT(TCCR1B,WGM12);
            SET_BIT(TCCR1B,WGM13);
            break;
        
        case TIMER1_PWM_PHASE_CORRECT_OCR:
            SET_BIT(TCCR1A,WGM10);
            SET_BIT(TCCR1A,WGM11);
            CLR_BIT(TCCR1B,WGM12);
            SET_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_CTC_ICR:
            CLR_BIT(TCCR1A,WGM10);
            CLR_BIT(TCCR1A,WGM11);
            SET_BIT(TCCR1B,WGM12);
            SET_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_FAST_PWM_ICR:
            CLR_BIT(TCCR1A,WGM10);
            SET_BIT(TCCR1A,WGM11);
            SET_BIT(TCCR1B,WGM12);
            SET_BIT(TCCR1B,WGM13);
            break;

        case TIMER1_FAST_PWM_OCR:
            SET_BIT(TCCR1A,WGM10);
            SET_BIT(TCCR1A,WGM11);
            SET_BIT(TCCR1B,WGM12);
            SET_BIT(TCCR1B,WGM13);
            break;

        default:
            break;
        }

        switch (config->compareOutputMode)
        {
            case TIMER1_A_COMP_OUTPUT_DISCONNECTED:
                TCCR1A &= 0b00111111;
                TCCR1A |= (TIMER1_A_COMP_OUTPUT_DISCONNECTED << 6);
                break;
                
            case TIMER1_A_COMP_OUTPUT_TOGGLE:
                TCCR1A &= 0b00111111;
                TCCR1A |= (TIMER1_A_COMP_OUTPUT_TOGGLE << 6);
                break;
            
            case TIMER1_A_COMP_OUTPUT_CLEAR:
                TCCR1A &= 0b00111111;
                TCCR1A |= (TIMER1_A_COMP_OUTPUT_CLEAR << 6);
                break;
            
            case TIMER1_A_COMP_OUTPUT_SET:
                TCCR1A &= 0b00111111;
                TCCR1A |= (TIMER1_A_COMP_OUTPUT_SET << 6);
                break;

            case TIMER1_B_COMP_OUTPUT_DISCONNECTED:
                TCCR1A &= 0b11001111;
                TCCR1A |= (0 << 4);
                break;
                
            case TIMER1_B_COMP_OUTPUT_TOGGLE:
                TCCR1A &= 0b11001111;
                TCCR1A |= (1 << 4);
                break;
            
            case TIMER1_B_COMP_OUTPUT_CLEAR:
                TCCR1A &= 0b11001111;
                TCCR1A |= (2 << 4);
                break;
            
            case TIMER1_B_COMP_OUTPUT_SET:
                TCCR1A &= 0b11001111;
                TCCR1A |= (3 << 4);
                break;
            
            default:
                break;
        }
        break;
    
        default:
        break;
    }
    
}

void M_Timer_Start(Timer_ChannelType channel,TIMER_PrescalerType prescaler)
{
    switch (channel)
    {
    case TIMER_CHANNEL_TIM0:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= prescaler;
        break;
    
    case TIMER_CHANNEL_TIM1:
        switch (prescaler)
        {
        case TIMER_PRESCALER_1:
            TCCR1B &= TIMER0_PRESCALING_MASKING;
            TCCR1B |= TIMER_PRESCALER_1;
            break;

        case TIMER_PRESCALER_8:
            TCCR1B &= TIMER0_PRESCALING_MASKING;
            TCCR1B |= TIMER_PRESCALER_8;
            break;

        case TIMER_PRESCALER_64:
            TCCR1B &= TIMER0_PRESCALING_MASKING;
            TCCR1B |= TIMER_PRESCALER_64;
            break;

        case TIMER_PRESCALER_256:
            TCCR1B &= TIMER0_PRESCALING_MASKING;
            TCCR1B |= TIMER_PRESCALER_256;
            break;

        case TIMER_PRESCALER_1024:
            TCCR1B &= TIMER0_PRESCALING_MASKING;
            TCCR1B |= TIMER_PRESCALER_1024;
            break;

        case TIMER_PRESCALER_EXT_FALLING:
            TCCR1B &= TIMER0_PRESCALING_MASKING;
            TCCR1B |= TIMER_PRESCALER_EXT_FALLING;
            break;

        case TIMER_PRESCALER_EXT_RISING:
            TCCR1B &= TIMER0_PRESCALING_MASKING;
            TCCR1B |= TIMER_PRESCALER_EXT_RISING;
            break; 

        default:
            break;
        }
        break;
    
    default:
        break;
    }
    
}


void M_Timer_Stop(Timer_ChannelType channel)
{
    switch (channel)
    {
    case TIMER_CHANNEL_TIM0:
        TCCR0 &= TIMER0_PRESCALING_MASKING;
        TCCR0 |= TIMER_NO_CLOCK;
        break;
    
    case TIMER_CHANNEL_TIM1:
        TCCR1B &= TIMER0_PRESCALING_MASKING;
        TCCR1B |= TIMER_NO_CLOCK;
        break;

    default:
        break;
    }
    
}

u32 M_Timer_GetCounts()
{
    u32 ret_value = 0;
    ret_value = TCNT0;
    return ret_value;
}

void M_Timer_SetCompareReg(u8 value)
{
    OCR0 = value;
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
    case TIMER1_INT_SOURCE_ICU:
        SET_BIT(TIMSK,TICIE1);
        break;

    case TIMER1_A_INT_SOURCE_COMP:
        SET_BIT(TIMSK,OCIE1A);
        break;

    case TIMER1_B_INT_SOURCE_COMP:
        SET_BIT(TIMSK,OCIE1B);
        break;
    
    case TIMER1_INT_SOURCE_OVF:
        SET_BIT(TIMSK,TOIE1);
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
    
    case TIMER1_INT_SOURCE_ICU:
        CLR_BIT(TIMSK,TICIE1);
        break;

    case TIMER1_A_INT_SOURCE_COMP:
        CLR_BIT(TIMSK,OCIE1A);
        break;

    case TIMER1_B_INT_SOURCE_COMP:
        CLR_BIT(TIMSK,OCIE1B);
        break;
    
    case TIMER1_INT_SOURCE_OVF:
        CLR_BIT(TIMSK,TOIE1);
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
    
    case TIMER1_INT_SOURCE_ICU:
        Timer_Callback_TIM1_ICU = funcPtr;
        break;

    case TIMER1_A_INT_SOURCE_COMP:
        Timer_Callback_TIM1_A_COMP = funcPtr;
        break;

    case TIMER1_B_INT_SOURCE_COMP:
        Timer_Callback_TIM1_B_COMP = funcPtr;
        break;
    
    case TIMER1_INT_SOURCE_OVF:
        Timer_Callback_TIM1_OVF = funcPtr;
        break;
    
    
    default:
        break;
    }
}

void M_Timer_SetFastPWM(u8 duty_cycle)
{
    if(duty_cycle <= 100)
    {
        OCR0 = (((u16)duty_cycle*255) / 100);
    }

}
void M_Timer_SetPhasePWM(u8 duty_cycle)
{
    if(duty_cycle <= 100)
    {
        OCR0 = (((u16)duty_cycle*255) / 100);
    }
}



/*u8 M_Timer_GetSignalDuty(Timer_IcuTrigger trigger)
{
    if(trigger == ICU_TRIGGER_FALLING)
    {
        
    }

    else if(trigger == ICU_TRIGGER_RISING)
    {
        
        M_Timer1_ICU_void_setTrigg(ICU_TRIGGER_FALLING);

        
    }


}*/

void M_Timer1_ICU_void_setTrigg(Timer_IcuTrigger trigger)
{
    if(trigger == ICU_TRIGGER_FALLING)
    {
        CLR_BIT(TCCR1B,ICES1);
    }
    else
    {
        SET_BIT(TCCR1B,ICES1);
    }
}
