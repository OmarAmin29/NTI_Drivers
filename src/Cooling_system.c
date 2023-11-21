/*
 * Cooling_system.c
 *
 *  Created on: Nov 8, 2023
 *      Author: lenovo
 */

#if 0
s
#include "util/delay.h"
#include "../Private/Types.h"
#include "../MCAL/DIO/Dio.h"
#include "../HAL/LCD/Lcd.h"
#include"../MCAL/ADC/Adc_Int.h"
#include "../MCAL/Timer/Timer.h"



int main()
{
	Adc_ConfigurationsType confg ={
			ADC_REF_Internal_2_56V,
			ADC_ADJUST_LEFT,
			ADC_PRESCALER_128,
			ADC_AUTO_TRIGGER_FREE_RUNNING
	};

	M_ADC_Init(&confg);
	u16 result = 0;

	Timer_CfgType confg_0 =
	{
	   TIMER0_FAST_PWM,
	   TIMER0_COMP_OUTPUT_CLEAR
	};

	M_Timer_Init(TIMER_CHANNEL_TIM0, &confg_0);
	M_Timer_Start(TIMER_CHANNEL_TIM0, TIMER_PRESCALER_1024);

	DIO_SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_DIRECTION_OUTPUT);
	DIO_SetPinDirection(DIO_PORTB, DIO_PIN3, DIO_DIRECTION_OUTPUT);

	H_LCD_void_Init();

	while(1)
	{
		result = M_ADC_getDigitalValueSynchNonBlocking(ADC_CHANNEL_ADC0);
		H_LCD_void_sendString("Temp: ");
		H_LCD_void_sendIntNum(result);
		_delay_ms(1000);
		H_LCD_void_ClearDisplay();

		if (result < 25)
		{
			M_Timer_SetFastPWM(0);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN0, DIO_VALUE_LOW);
		}

		else if(result >= 25 && result <= 35)
		{
			M_Timer_SetFastPWM(50);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN0, DIO_VALUE_HIGH);
		}

		else if(result > 35)
		{
			M_Timer_SetFastPWM(80);
			DIO_SetPinValue(DIO_PORTC,DIO_PIN0, DIO_VALUE_HIGH);
		}
	}

}
#endif

