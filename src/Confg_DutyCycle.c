/*
 * Confg_DutyCycle.c
 *
 *  Created on: Nov 14, 2023
 *      Author: lenovo
 */

#if 0

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

int main(void)
{
	H_LCD_void_Init();
	Keypad_Init();

	Timer_CfgType confg = {
			TIMER0_FAST_PWM,
			TIMER0_COMP_OUTPUT_CLEAR
	};
	M_Timer_Init(TIMER_CHANNEL_TIM0,&confg);
	M_Timer_Start(TIMER_CHANNEL_TIM0, TIMER_PRESCALER_1024);

	DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_DIRECTION_OUTPUT);

	u8 key = 0;
	u8 duty_cycle = 0;
	u8 flag = 0;

	while(1)
	{
		while(flag == 0)
		{
			H_LCD_void_sendString("Enter Duty Cycle:");
			flag = 1;
			duty_cycle = 0;
		}

		while(duty_cycle <= 100)
		{
			key = Keypad_GetButtonState();
			if(key == '=')
			{
				break;
			}
			else if(key != 0)
			{
				H_LCD_void_sendData(key);
				duty_cycle = duty_cycle*10 + (key - '0');
			}
		}

		if(duty_cycle > 100)
		{
			H_LCD_void_ClearDisplay();
			H_LCD_void_sendString("Invalid Duty Cycle");
			_delay_ms(5000);
			H_LCD_void_ClearDisplay();
			flag = 0;
		}

		else
		{
			M_Timer_SetFastPWM(duty_cycle);
			H_LCD_void_ClearDisplay();
			H_LCD_void_sendString("Duty Cycle:");
			H_LCD_void_sendIntNum(duty_cycle);
			_delay_ms(5000);
			H_LCD_void_ClearDisplay();
			flag = 0;
		}
	}
}














#endif

