/*
 * Keypad.c
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#include "../../Private/Types.h"
#include"../../MCAL/DIO/Dio.h"
#include"Keypad.h"


void Keypad_Init(void)
{
    /*Configure all the columns to input*/
    DIO_SetPinDirection(KEYPAD_CO, DIO_DIRECTION_INPUT_FLOATING);
    DIO_SetPinDirection(KEYPAD_C1, DIO_DIRECTION_INPUT_FLOATING);
    DIO_SetPinDirection(KEYPAD_C2, DIO_DIRECTION_INPUT_FLOATING);
    DIO_SetPinDirection(KEYPAD_C3, DIO_DIRECTION_INPUT_FLOATING);

    /*Configure all the rows to output*/
    DIO_SetPinDirection(KEYPAD_RO, DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(KEYPAD_R1, DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(KEYPAD_R2, DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(KEYPAD_R3, DIO_DIRECTION_OUTPUT);

    /*Configure all the columns to low*/
    DIO_SetPinValue(KEYPAD_RO, DIO_VALUE_HIGH);
    DIO_SetPinValue(KEYPAD_R1, DIO_VALUE_HIGH);
    DIO_SetPinValue(KEYPAD_R2, DIO_VALUE_HIGH);
    DIO_SetPinValue(KEYPAD_R3, DIO_VALUE_HIGH);
}

Keypad_ButtonSTateType Keypad_GetButtonState(Keypad_ButtonType button)
{
    Keypad_ButtonSTateType state = KEYPAD_BUTTON_NOT_PRESSED;

    switch (button)
    {
    case KEYPAD_BUTTON_00:
        DIO_SetPinValue(KEYPAD_CO,DIO_VALUE_HIGH);
        if(DIO_GetPinValue(KEYPAD_RO) == DIO_VALUE_HIGH)
        {
            state = KEYPAD_BUTTON_PRESSED;
        }
        DIO_SetPinValue(KEYPAD_CO,DIO_VALUE_LOW);
        break;
    
    default:
        break;
    }

    return state;
}
