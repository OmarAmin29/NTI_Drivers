/*
 * Finger_Print_app.c
 *
 *  Created on: Nov 10, 2023
 *      Author: lenovo
 */


#if 0


#include "../Private/Delay.h"
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
	Usart_ConfgType confg = {
		USART_MODE_ASYNCH,
		USART_PARITY_DISABLED,
		USART_STOP_BIT_1,
		USART_CHAR_SIZE_8,
		USART_BAUD_RATE_57600
	};

	M_Usart_Init(&confg);
	H_LCD_void_Init();
	Keypad_Init();

	u8 key = 0;
	u8 i = 0;
	u8 data [17] = {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
	data[16] = '#'; /*To Get out of loop in USART Send String*/

	u8 flag = 0;
	u8 counter = 0;

	while(1)
	{
		while(flag == 0)
		{
			H_LCD_void_ClearDisplay();
			H_LCD_void_sendString("Register:1");
			H_Lcd_SetCursorPosition(1,0);
			H_LCD_void_sendString("Login:2");
			flag = 1;
		}
		while(key == 0)
		{
			key = Keypad_GetButtonState();
		}

		if(key == '1')
		{
			key = 0;
			flag = 0;
			H_LCD_void_ClearDisplay();
			_delay_ms(1000);
			H_LCD_void_sendString("Enter Your Finger");
			_delay_ms(1000);

			//H_FingerPS_Aura(FP_AURA_RED);

			while(1)
			//while(data[9] != 0x00)
			{
				H_LCD_void_sendIntNum(1);
				H_FingerPS_HandShake();
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
				if(data[9] == 0)
				{
					break;
				}

			}
			data[9] = 1;

			while(data[9] != 0x00)
			{
				H_FingerPS_GenImg();
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
			}
			data[9] = 1;

			while(data[9] != 0x00)
			{
				H_FingerPS_ConvertImg2CharFile(1);
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
			}
			data[9] = 1;

			//_delay_ms(5000);
			H_LCD_void_ClearDisplay();
			H_LCD_void_sendString("Renter Your Finger");
			_delay_ms(2000);

			while(1)
			//while(data[9] != 0x00)
			{
				H_FingerPS_GenImg();
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
				if(data[9] == 0)
				{
					break;
				}
			}
			data[9] = 1;

			while(data[9] != 0x00)
			{
				H_FingerPS_ConvertImg2CharFile(2);
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
			}
			data[9] = 1;

			while(data[9] != 0x00)
			{
				H_FingerPS_GenTemplate();
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
			}
			data[9] = 1;

			while(data[9] != 0x00)
			{
				H_FingerPS_StrTemplate(1,1);
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
			}
			data[9] = 1;

			H_LCD_void_ClearDisplay();
			H_LCD_void_sendString("Finger Stored Successfully");
			_delay_ms(2000);
		}

		else if(key == '2')
		{
			H_LCD_void_ClearDisplay();
			H_LCD_void_sendString("Put your finger");
			_delay_ms(2000);

			key = 0;
			flag = 0;
			while(data[9] != 0x00)
			{
				H_FingerPS_GenImg();
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
			}
			data[9] = 1;

			while(data[9] != 0x00)
			{
				H_FingerPS_ConvertImg2CharFile(1);
				for(i = 0; i < 12; i++)
				{
					M_USART_ReceiveByteSynchNonBlocking(&data[i]);
				}
			}
			data[9] = 1;

			//H_FingerPS_Aura(FP_AURA_RED);

			H_FingerPS_SearchFinger();
			for(i = 0; i < 12; i++)
			{
				M_USART_ReceiveByteSynchNonBlocking(&data[i]);
			}
			if(data[9] != 0x00)
			{
				H_LCD_void_ClearDisplay();
				H_LCD_void_sendString("Wrong ID");
				_delay_ms(1000);
			}

			else
			{
				H_LCD_void_ClearDisplay();
				H_LCD_void_sendString("Welcome");
				_delay_ms(1000);
				data[9] = 1;
			}
			//H_FingerPS_Aura(FP_AURA_RED);
		}
			//H_FingerPS_Aura(FP_AURA_BLUE);
	}

}



#endif
