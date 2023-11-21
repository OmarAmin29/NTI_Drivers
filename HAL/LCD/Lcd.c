/*
 * Lcd.c
 *
 *  Created on: Oct 23, 2023
 *      Author: lenovo
 */

#include "../../MCAL/DIO/Dio.h"
#include"../../Private/Macros.h"
#include "util/delay.h"
#include "Lcd.h"
#include "Lcd_Priv.h"

static void H_LCD_void_latchByte(u8 copy_u8Byte);

void H_LCD_void_Init(void)
{
    u8 command;
    #if(LCD_MODE == _8BIT_MODE)
    DIO_SetPinDirection(LCD_PIN_EN,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_RS,DIO_DIRECTION_OUTPUT);    
    DIO_SetPinDirection(LCD_PIN_DB0,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB1,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB2,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB3,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB4,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB5,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB6,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB7,DIO_DIRECTION_OUTPUT);

    #elif(LCD_MODE == _4BIT_MODE)
    DIO_SetPinDirection(LCD_PIN_EN,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_RS,DIO_DIRECTION_OUTPUT); 
    DIO_SetPinDirection(LCD_PIN_DB4,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB5,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB6,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(LCD_PIN_DB7,DIO_DIRECTION_OUTPUT);


    DIO_SetPinValue(LCD_PIN_RS,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_HIGH);
    _delay_ms(1);

    DIO_SetPinValue(LCD_PIN_DB4,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_DB5,DIO_VALUE_HIGH);
    DIO_SetPinValue(LCD_PIN_DB6,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_DB7,DIO_VALUE_LOW);

    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_LOW);
    _delay_ms(1);

    //DIO_SetPinValue(LCD_PIN_RS,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_HIGH);
    _delay_ms(1);

    DIO_SetPinValue(LCD_PIN_DB4,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_DB5,DIO_VALUE_HIGH);
    DIO_SetPinValue(LCD_PIN_DB6,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_DB7,DIO_VALUE_LOW);

    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_LOW);
    _delay_ms(1);

    //DIO_SetPinValue(LCD_PIN_RS,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_HIGH);
    _delay_ms(1);

    DIO_SetPinValue(LCD_PIN_DB4,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_DB5,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_DB6,DIO_VALUE_HIGH);
    DIO_SetPinValue(LCD_PIN_DB7,DIO_VALUE_HIGH);

    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_LOW);
    _delay_ms(1);

    _delay_ms(2);

    command = 0b00001111;
    H_LCD_void_sendCommand(command);

    /*command = 0b10110000;
    H_LCD_void_sendCommand(command);*/
    _delay_ms(2);

    command = 0b00000001;
    H_LCD_void_sendCommand(command); 

    /*command = 0b00010000;
    H_LCD_void_sendCommand(command);*/
    _delay_ms(22); 

    command = 0b00000110;
    H_LCD_void_sendCommand(command);

    /*command = 0b01000000;
    H_LCD_void_sendCommand(command);  */

    #endif
}

void H_LCD_void_sendData(u8 copy_u8data)
{
    DIO_SetPinValue(LCD_PIN_RS,DIO_VALUE_HIGH);
    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_HIGH);
    _delay_ms(1);
    H_LCD_void_latchByte(copy_u8data);

    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_LOW);
    _delay_ms(5);  


}
void H_LCD_void_sendCommand(u8 copy_u8command)
{
   DIO_SetPinValue(LCD_PIN_RS,DIO_VALUE_LOW);
    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_HIGH);
    _delay_ms(1);

    H_LCD_void_latchByte(copy_u8command);

    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_LOW);
    _delay_ms(5);

}

void H_LCD_void_ClearDisplay(void)
{
	H_LCD_void_sendCommand(1);
}

void H_LCD_void_sendString(const u8 * pstr)
{
    while (*pstr != '\0')
    {
        H_LCD_void_sendData(*pstr);
        pstr++;
    }
    
}

void H_LCD_void_sendIntNum(s32 copy_s32Num)
{
    u32 reversed = 0;
    u8 count = 0;

    if(copy_s32Num < 0)
    {
        H_LCD_void_sendData('-');
        copy_s32Num *= -1;
    }
    else if(copy_s32Num == 0)
    {
        H_LCD_void_sendData('0');
    }

    while (copy_s32Num != 0) 
    {
        reversed = (reversed*10) + (copy_s32Num%10);
        copy_s32Num /= 10;
        count++;
    }
    while (count != 0)
    {
        H_LCD_void_sendData(reversed%10 + '0');
        reversed /= 10;
        count--;
    } 
}

void H_Lcd_SetCursorPosition(u8 row, u8 column)
{
    u8 address = row*0x40 + column;
    SET_BIT(address, 7);
    H_LCD_void_sendCommand(address);
}

















static void H_LCD_void_latchByte(u8 copy_u8Byte)
{

    #if(LCD_MODE == _8BIT_MODE)
    DIO_SetPinValue(LCD_PIN_DB0,GET_BIT(copy_u8Byte,0));
    DIO_SetPinValue(LCD_PIN_DB1,GET_BIT(copy_u8Byte,1));
    DIO_SetPinValue(LCD_PIN_DB2,GET_BIT(copy_u8Byte,2));
    DIO_SetPinValue(LCD_PIN_DB3,GET_BIT(copy_u8Byte,3));
    DIO_SetPinValue(LCD_PIN_DB4,GET_BIT(copy_u8Byte,4));
    DIO_SetPinValue(LCD_PIN_DB5,GET_BIT(copy_u8Byte,5));
    DIO_SetPinValue(LCD_PIN_DB6,GET_BIT(copy_u8Byte,6));
    DIO_SetPinValue(LCD_PIN_DB7,GET_BIT(copy_u8Byte,7));

    #elif(LCD_MODE == _4BIT_MODE)
    DIO_SetPinValue(LCD_PIN_DB4,GET_BIT(copy_u8Byte,4));
    DIO_SetPinValue(LCD_PIN_DB5,GET_BIT(copy_u8Byte,5));
    DIO_SetPinValue(LCD_PIN_DB6,GET_BIT(copy_u8Byte,6));
    DIO_SetPinValue(LCD_PIN_DB7,GET_BIT(copy_u8Byte,7));

    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_LOW);
    _delay_ms(1);
    DIO_SetPinValue(LCD_PIN_EN,DIO_VALUE_HIGH);
    _delay_ms(1);

    DIO_SetPinValue(LCD_PIN_DB4,GET_BIT(copy_u8Byte,0));
    DIO_SetPinValue(LCD_PIN_DB5,GET_BIT(copy_u8Byte,1));
    DIO_SetPinValue(LCD_PIN_DB6,GET_BIT(copy_u8Byte,2));
    DIO_SetPinValue(LCD_PIN_DB7,GET_BIT(copy_u8Byte,3));

    #endif
}
