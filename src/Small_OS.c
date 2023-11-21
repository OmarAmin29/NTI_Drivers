/*
 * Small_OS.c
 *
 *  Created on: Nov 16, 2023
 *      Author: lenovo
 */


#if 1

#include "util/delay.h"
#include "../Private/Types.h"
#include "../MCAL/DIO/Dio.h"
#include "../HAL/Seven_Segment/Ssd.h"
#include "../HAL/Keypad/Keypad.h"
#include "../MCAL/EXTINT/Extint.h"
#include "../MCAL/Global_Interrupt/Gie.h"
#include "../HAL/LCD/Lcd.h"
#include"../MCAL/ADC/Adc_Int.h"
#include "../MCAL/Timer/Timer.h"
#include "../MCAL/USART/Usart.h"
#include "../MCAL/SPI/Spi.h"
#include "../MCAL/I2c/I2c.h"
#include "../HAL/EEPROM/Eeprom.h"
#include"../HAL/RTC/Rtc_Intf.h"
#include "../MCAL/WDT/Wdt_Intf.h"
#include "../HAL/Finger_Print/Finger_Print_Intf.h"


void Handler_TIM1_OVF (void)
{
    static u16 counter = 0;
    static u8 flip = 0;
	counter++;
	if (counter == 45 && (flip % 2) == 0) {
		counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_HIGH);
	}
    else if(counter == 45 && (flip % 2) == 1)
    {
        counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_LOW);
    }
}


void Handler_TIM0_OVF (void)
{
    static u16 counter = 0;
    static u8 flip = 0;
	counter++;
	if(counter == 15)
	{
		if(DIO_GetPinValue(DIO_PORTB,DIO_PIN5) == DIO_VALUE_LOW)
		{
			if(DIO_GetPinValue(DIO_PORTB, DIO_PIN4) == DIO_VALUE_LOW)
			{
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4,DIO_VALUE_HIGH);
			}
			else if(DIO_GetPinValue(DIO_PORTB, DIO_PIN4) == DIO_VALUE_HIGH)
			{
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4,DIO_VALUE_LOW);
			}
		}
	}

	if (counter == 30 && (flip % 2) == 0)
	{
		counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTB, DIO_PIN3,DIO_VALUE_HIGH);

		if(DIO_GetPinValue(DIO_PORTB,DIO_PIN5) == DIO_VALUE_LOW)
		{
			if(DIO_GetPinValue(DIO_PORTB, DIO_PIN4) == DIO_VALUE_LOW)
			{
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4,DIO_VALUE_HIGH);
			}
			else if(DIO_GetPinValue(DIO_PORTB, DIO_PIN4) == DIO_VALUE_HIGH)
			{
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4,DIO_VALUE_LOW);
			}
		}
	}
    else if(counter == 30 && (flip % 2) == 1)
    {
        counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTB, DIO_PIN3,DIO_VALUE_LOW);

		if(DIO_GetPinValue(DIO_PORTB,DIO_PIN5) == DIO_VALUE_LOW)
		{
			if(DIO_GetPinValue(DIO_PORTB, DIO_PIN4) == DIO_VALUE_LOW)
			{
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4,DIO_VALUE_HIGH);
			}
			else if(DIO_GetPinValue(DIO_PORTB, DIO_PIN4) == DIO_VALUE_HIGH)
			{
				DIO_SetPinValue(DIO_PORTB, DIO_PIN4,DIO_VALUE_LOW);
			}
		}
    }
}


int main(void)
{
	Timer_CfgType config_1 = {
			TIMER1_NORMAL,
			TIMER1_A_COMP_OUTPUT_DISCONNECTED
	};

	Timer_CfgType config_0 = {
				TIMER0_NORMAL,
				TIMER0_COMP_OUTPUT_DISCONNECTED
		};

	M_Timer_Init(TIMER_CHANNEL_TIM1,&config_1);
	M_Timer_Start(TIMER_CHANNEL_TIM1, TIMER_PRESCALER_8);
	M_Timer_setCallBack(TIMER1_INT_SOURCE_OVF, Handler_TIM1_OVF);
	M_Timer_EnableInt(TIMER1_INT_SOURCE_OVF);

	M_Timer_Init(TIMER_CHANNEL_TIM1,&config_0);
	M_Timer_Start(TIMER_CHANNEL_TIM0, TIMER_PRESCALER_1024);
	M_Timer_setCallBack(TIMER0_INT_SOURCE_OVF, Handler_TIM0_OVF);
	M_Timer_EnableInt(TIMER0_INT_SOURCE_OVF);


	DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_DIRECTION_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_DIRECTION_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_DIRECTION_OUTPUT);

	DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_DIRECTION_INPUT_PULLUP);
	Gie_Enable();

	while(1)
	{


	}
}

#endif
