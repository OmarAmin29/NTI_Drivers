/*
 * Keypad.c
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#include "../../Private/Types.h"
#include"../../MCAL/DIO/Dio.h"
#include<util/delay.h>
#include"Keypad_Cfg.h"
#include"Keypad.h"



void Keypad_Init(void)
{
	/*Configure all columns to be input pull up */
    DIO_SetPinDirection(KEYPAD_PORT_COLUMN0,KEYPAD_PIN_COLUMN0,DIO_DIRECTION_INPUT_PULLUP);
    DIO_SetPinDirection(KEYPAD_PORT_COLUMN1,KEYPAD_PIN_COLUMN1,DIO_DIRECTION_INPUT_PULLUP);
    DIO_SetPinDirection(KEYPAD_PORT_COLUMN2,KEYPAD_PIN_COLUMN2,DIO_DIRECTION_INPUT_PULLUP);
    DIO_SetPinDirection(KEYPAD_PORT_COLUMN3,KEYPAD_PIN_COLUMN3,DIO_DIRECTION_INPUT_PULLUP);

    /*Configure all rows to be output*/
    DIO_SetPinDirection(KEYPAD_PORT_ROW0,KEYPAD_PIN_ROW0,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(KEYPAD_PORT_ROW1,KEYPAD_PIN_ROW1,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(KEYPAD_PORT_ROW2,KEYPAD_PIN_ROW2,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(KEYPAD_PORT_ROW3,KEYPAD_PIN_ROW3,DIO_DIRECTION_OUTPUT);

    /* Set all rows to high */
    DIO_SetPinValue(KEYPAD_PORT_ROW0,KEYPAD_PIN_ROW0,DIO_VALUE_HIGH);
    DIO_SetPinValue(KEYPAD_PORT_ROW1,KEYPAD_PIN_ROW1,DIO_VALUE_HIGH);
    DIO_SetPinValue(KEYPAD_PORT_ROW2,KEYPAD_PIN_ROW2,DIO_VALUE_HIGH);
    DIO_SetPinValue(KEYPAD_PORT_ROW3,KEYPAD_PIN_ROW3,DIO_VALUE_HIGH);
}


u8 Keypad_GetButtonState(void)
{
    u8 i,j;
    u8 keypad_arr[4][4] = KEYPAD_CALC;
    u8 row_pin[] = {KEYPAD_PIN_ROW0,KEYPAD_PIN_ROW1,KEYPAD_PIN_ROW2,KEYPAD_PIN_ROW3};
    u8 column_pin[] = {KEYPAD_PIN_COLUMN0,KEYPAD_PIN_COLUMN1,KEYPAD_PIN_COLUMN2,KEYPAD_PIN_COLUMN3};
    u8 key = 0;

    for(i = 0; i < 4; i++)
    {
        DIO_SetPinValue(KEYPAD_PORT_ROW,row_pin[i],DIO_VALUE_LOW);
        for(j = 0; j < 4; j++)
        {
            if(DIO_GetPinValue(KEYPAD_PORT_COLUMN,column_pin[j]) == DIO_VALUE_LOW)
            {
                _delay_ms(10);
                if(DIO_GetPinValue(KEYPAD_PORT_COLUMN,column_pin[j]) == DIO_VALUE_LOW)
                {
                	while(DIO_GetPinValue(KEYPAD_PORT_COLUMN,column_pin[j]) == DIO_VALUE_LOW);
                    key = keypad_arr[i][j];
                }
            }
        }
        DIO_SetPinValue(KEYPAD_PORT_ROW,row_pin[i],DIO_VALUE_HIGH);
    }
    return key;
}

