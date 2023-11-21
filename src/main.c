
/*
 * main.c
 *
 *  Created on: Oct 20, 2023
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




void Handler_EXT_Int1 (void)
{
   static u8 counter = 0;
    if(counter % 2 == 0)
    DIO_SetPinValue(DIO_PORTA,DIO_PIN6, DIO_VALUE_HIGH);
    else
    {
        DIO_SetPinValue(DIO_PORTA,DIO_PIN6, DIO_VALUE_LOW);
    }
    counter++;
}

void Handler_TIM0_OVF (void)
{
    static u16 counter = 0;
    static u8 flip = 0;
	counter++;
	if (counter == 30 && (flip % 2) == 0) {
		counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTA, DIO_PIN6,DIO_VALUE_HIGH);
	}
    else if(counter == 30 && (flip % 2) == 1)
    {
        counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTA, DIO_PIN6,DIO_VALUE_LOW);
    }
}

void Handler_TIM0_COMP (void)
{
    static u16 counter = 0;
    static u8 flip = 0;
	counter++;
	if (counter == 61 && (flip % 2) == 0) {
		counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTA, DIO_PIN6,DIO_VALUE_HIGH);
	}
    else if(counter == 61 && (flip % 2) == 1)
    {
        counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTA, DIO_PIN6,DIO_VALUE_LOW);
    }
}



void Handler_TIM1_OVF (void)
{
    static u16 counter = 0;
    static u8 flip = 0;
	counter++;
	if (counter == 6 && (flip % 2) == 0) {
		counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTA, DIO_PIN6,DIO_VALUE_HIGH);
	}
    else if(counter == 6 && (flip % 2) == 1)
    {
        counter = 0;
        flip++;
		DIO_SetPinValue(DIO_PORTA, DIO_PIN6,DIO_VALUE_LOW);
    }
}


u16 reading1 = 0;
u16 reading2 = 0;
u16 reading3 = 0;
u16 time_on = 0;
u16 period = 0;
void Handler_TIM1_ICU (void)
{
    static u8 counter = 0;
    if(counter == 0)
    {
        reading1 = (ICR1H << 8) | ICR1L; 
        M_Timer1_ICU_void_setTrigg(ICU_TRIGGER_FALLING);
        counter++;
    }
    /*else if(counter == 1)
    {
        reading2 = ((ICR1H << 8) | ICR1L);
        time_on = reading2 - reading1; 
        M_Timer1_ICU_void_setTrigg(ICU_TRIGGER_RISING);
        counter++;
    }
    else if(counter == 2)
    {
        reading3 = ((ICR1H << 8) | ICR1L);
        period = reading3 - reading1;
    }*/
}


u8 save_string[10] = {0};
void Handler_Usart_Rx (u8 value)
{
	H_LCD_void_sendData(value);
}

int main()
{
    #if 0
    H_LCD_void_Init();
    H_LCD_void_sendData('O');
    H_LCD_void_sendData('M');
    H_LCD_void_sendData('A');
    H_LCD_void_sendData('R');

    H_LCD_void_sendString(" Mohamed");

    H_LCD_void_sendIntNum(-105);

    
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN6, DIO_DIRECTION_OUTPUT);

    Extint_voidEnable(EXTINT_ID_INT1,EXTINT_TRIGGER_EDGE_FALLING);
    Extint_SetCallback(EXTINT_ID_INT1,Handler_EXT_Int1);
    Gie_Enable();
    
    while (1)
    {
            
    }
    #endif

#if 0
    u16 result = 0;
	u8 i ;
	ADC_Init();
	H_LCD_void_Init();
	//DIO_SetPinDirection(DIO_PORTA, DIO_PIN0, DIO_DIRECTION_INPUT_FLOATING);
	H_LCD_void_sendIntNum(result);

				result = ADC_getDigitalValueSynchNonBlocking(ADC_CHANNEL_ADC0);
				//_delay_ms(500);
	            H_LCD_void_sendIntNum(result);
	while (1)
	{
		//result = 0;
		//for(i = 0; i < 10; i++)
		//{
            //H_LCD_void_sendIntNum(result);

			//result = ADC_getDigitalValueSynchNonBlocking(ADC_CHANNEL_ADC0);
			//_delay_ms(500);
            //H_LCD_void_sendIntNum(result);
            //_delay_ms(5000);
		//}

		//result/=10;
		/*ADC_getDigitalValueSynchNonBlocking(ADC_CHANNEL_ADC0);
		result = Adc_GetResult();
		Lcd_ClearDisplay();
		Lcd_DisplayString("intensity ");
		Lcd_DisplayString(" = ");
		Lcd_DisplayNumber(((u32)result*5000/1024));
		_delay_ms(500);*/
	}

    #endif

#if 0
    Keypad_Init();
    H_LCD_void_Init();
    u8 flag = 0;
    DIO_SetPinDirection(DIO_PORTA, DIO_PIN6, DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(DIO_PORTA, DIO_PIN5, DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(DIO_PORTA, DIO_PIN4, DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_DIRECTION_OUTPUT);


    while (1)
    {

        if(Keypad_GetButtonState() == '5')
        {
        	DIO_SetPinValue(DIO_PORTA, DIO_PIN6, DIO_VALUE_HIGH);
        	H_LCD_void_sendIntNum(1);
        }
        if(Keypad_GetButtonState() == '2')
        {
            DIO_SetPinValue(DIO_PORTA, DIO_PIN5, DIO_VALUE_HIGH);
            H_LCD_void_sendIntNum(2);
        }
        if(Keypad_GetButtonState() == '3')
        {
            DIO_SetPinValue(DIO_PORTA, DIO_PIN4, DIO_VALUE_HIGH);
            H_LCD_void_sendIntNum(3);
        }
        if(Keypad_GetButtonState() == 'A')
        {
            DIO_SetPinValue(DIO_PORTB, DIO_PIN7, DIO_VALUE_HIGH);
            H_LCD_void_sendIntNum(4);
        }
    }


#endif

#if 0

    Timer_CfgType confg = {
            TIMER0_CTC,
    		TIMER0_COMP_OUTPUT_TOGGLE
        };

    M_Timer_Init(TIMER_CHANNEL_TIM0, &confg);
    M_Timer_Start(TIMER_CHANNEL_TIM0, TIMER_PRESCALER_1024);

    M_Timer_EnableInt(TIMER0_INT_SOURCE_COMP);
    M_Timer_setCallBack(TIMER0_INT_SOURCE_COMP,Handler_TIM0_COMP);
    M_Timer_SetCompareReg(200);
    Gie_Enable();

    DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_DIRECTION_OUTPUT);

    DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_DIRECTION_OUTPUT);
    DIO_SetPinValue(DIO_PORTB, DIO_PIN3,DIO_VALUE_HIGH);
    while (1)
    {

    }
    


#endif

#if 0
    Timer_CfgType confg = {
                TIMER0_PWM_PHASE_CORRECT,
				TIMER0_COMP_OUTPUT_CLEAR
            };

    M_Timer_Init(TIMER_CHANNEL_TIM0, &confg);
    M_Timer_Start(TIMER_CHANNEL_TIM0, TIMER_PRESCALER_1024);

    //M_Timer_EnableInt(TIMER1_INT_SOURCE_OVF);
    //M_Timer_setCallBack(TIMER1_INT_SOURCE_OVF,Handler_TIM1_OVF);
   // M_Timer_SetCompareReg(50);
    //Gie_Enable();
    DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_DIRECTION_OUTPUT);

    DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_DIRECTION_OUTPUT);
    while (1)
    {
    	//OCR0 = 126;
        M_Timer_SetPhasePWM(25);
    }
    



#endif

#if 0
    Timer_CfgType confg = {
                TIMER1_NORMAL,
				TIMER1_A_COMP_OUTPUT_DISCONNECTED
            };

    Timer_CfgType confg_0 = {
                    TIMER0_FAST_PWM,
    				TIMER0_COMP_OUTPUT_CLEAR
                };

     M_Timer_Init(TIMER_CHANNEL_TIM0, &confg_0);
     M_Timer_Start(TIMER_CHANNEL_TIM0, TIMER_PRESCALER_1024);
     _delay_ms(500);

    M_Timer_Init(TIMER_CHANNEL_TIM1, &confg);
    M_Timer_Start(TIMER_CHANNEL_TIM1, TIMER_PRESCALER_1024);

    M_Timer1_ICU_void_setTrigg(ICU_TRIGGER_RISING);

    M_Timer_EnableInt(TIMER1_INT_SOURCE_ICU);
    M_Timer_setCallBack(TIMER1_INT_SOURCE_ICU,Handler_TIM1_ICU);
   // M_Timer_SetCompareReg(50);
    Gie_Enable();

    H_LCD_void_Init();
    DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_DIRECTION_OUTPUT);

    DIO_SetPinDirection(DIO_PORTB,DIO_PIN3,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(DIO_PORTD,DIO_PIN6,DIO_DIRECTION_INPUT_FLOATING);
    H_LCD_void_sendIntNum(reading1);
    H_LCD_void_sendString(" ");
    H_LCD_void_sendIntNum(period);
    while (1)
    {
    	M_Timer_SetFastPWM(50);
        /*H_LCD_void_sendIntNum(time_on*1000000);
        H_LCD_void_sendIntNum(period*1000000);*/

    }
    



#endif

#if 0

    u8 data = 0;
    Usart_Init();
    H_LCD_void_Init();
    Usart_EnableNotification(USART_INT_SOURCE_RX);
    Gie_Enable();
    Usart_SetReceiveCallback(Handler_Usart_Rx);
    //Usart_Transmit(data);
    while (1)
    {
        Usart_Receive(&data);
  //      Usart_Transmit(data);
  //      Usart_SetReceiveCallback(Handler_Usart_Rx);
    }


#endif


#if 0

    Spi_ConfgType confg = {
    	SPI_MASTER,
		SPI_CLK_POLARITY_LEADING_RISING,
		SPI_CLK_PHASE_LEADING_SAMPLE,
		SPI_PRESCALER_4,
		SPI_DATA_ORDER_MSB
    };
    DIO_SetPinDirection(DIO_PORTB, DIO_PIN5, DIO_DIRECTION_OUTPUT); // MOSI
    DIO_SetPinDirection(DIO_PORTB, DIO_PIN6, DIO_DIRECTION_INPUT_FLOATING); // MISO
    DIO_SetPinDirection(DIO_PORTB, DIO_PIN7, DIO_DIRECTION_OUTPUT); // SCK
    DIO_SetPinDirection(DIO_PORTB, DIO_PIN4, DIO_DIRECTION_OUTPUT);

    u8 data = '0';
    u8 recive = '0';
    Usart_Init();
    M_Spi_Init(&confg);
    M_Spi_Transmit(data,&recive);

    while(1)
    {
    	Usart_Receive(&data);
    	Usart_Transmit(data);
    	M_Spi_Transmit(data,&recive);


    }

#endif

#if 0


    extern Usart_ConfgType confg;
    u8 value = 0;
    H_Eeprom_Init();
    H_LCD_void_Init();
    M_Usart_Init(&confg);
    //M_Usart_EnableNotification(USART_INT_SOURCE_RX);
    //M_USART_ReceiveByteAsynchCallBack(Handler_Usart_Rx);
    //Gie_Enable();
    M_USART_sendString("Omar Mohamed");
    while (1)
    {
    	M_USART_ReceiveByteSynchNonBlocking(&value);
    	M_Usart_Transmit(value);
        H_Eeprom_WriteByte(10,value);
    	_delay_ms(500);
        H_Eeprom_ReadByte(10,&value);
    	M_Usart_Transmit(value);
    }







#endif


#if 0
    extern Usart_ConfgType confg;
    Rtc_TimeType time = {15, 32, 12};
    u8 sec, minute, hour;
    H_LCD_void_Init();
    M_Usart_Init(&confg);
    H_Rtc_Init();
    H_Rtc_SetTime(&time);



    while (1)
    {
        H_Rtc_GetTime(&sec, &minute, &hour);
        H_LCD_void_sendIntNum(hour);
        H_LCD_void_sendString(":");
        H_LCD_void_sendIntNum(minute);
        H_LCD_void_sendString(":");
        H_LCD_void_sendIntNum(sec);
        _delay_ms(500);
        H_LCD_void_ClearDisplay();

    }
    


#endif

#if 0

    	M_WDT_sleep(WDT_TIME_OUT_2100_MS);
    	M_WDT_Enable();

    	DIO_SetPinDirection(DIO_PORTA,DIO_PIN6,DIO_DIRECTION_OUTPUT);
    	DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_VALUE_HIGH);
    	_delay_ms(1000);
    	DIO_SetPinValue(DIO_PORTA,DIO_PIN6,DIO_VALUE_LOW);
    	while (1)
    	{
    		_delay_ms(800);
    		M_WDT_refresh();
    	}


#endif


#if 1

    	H_FingerPS_HandShake();

    while(1)
    {

    }

#endif

}

#endif


