/*
 * Ssd.c
 *
 *  Created on: Oct 21, 2023
 *      Author: lenovo
 */


#include "../../Private/Types.h"
#include "../../MCAL/DIO/Dio.h"
#include "Ssd.h"

void SS_Init(void)
{
    DIO_SetPinDirection(DIO_PORTB,DIO_PIN0,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(DIO_PORTB,DIO_PIN1,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(DIO_PORTB,DIO_PIN2,DIO_DIRECTION_OUTPUT);
    DIO_SetPinDirection(DIO_PORTB,DIO_PIN4,DIO_DIRECTION_OUTPUT);

#if (SEVEN_SEGEMENT_1 == ENABLE)
    DIO_SetPinDirection(DIO_PORTA,DIO_PIN3,DIO_DIRECTION_OUTPUT);
#endif
#if (SEVEN_SEGEMENT_2 == ENABLE)
    DIO_SetPinDirection(DIO_PORTA,DIO_PIN2,DIO_DIRECTION_OUTPUT);
#endif
#if (SEVEN_SEGEMENT_3 == ENABLE)
    DIO_SetPinDirection(DIO_PORTB,DIO_PIN5,DIO_DIRECTION_OUTPUT);
#endif
#if(SEVEN_SEGEMENT_4 == ENABLE)
    DIO_SetPinDirection(DIO_PORTB,DIO_PIN6,DIO_DIRECTION_OUTPUT);
#endif

}

void SS_DisplayNumber(u8 number)
{
    switch (number)
    {
    case 0:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_LOW);
        break;
    
    case 1:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_LOW);
        break;
    
    case 2:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_LOW);
        break;
    
    case 3:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_LOW);
        break;
    
    case 4:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_LOW);
        break;
    
    case 5:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_LOW);
        break;
    
    case 6:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_LOW);
        break;
    
    case 7:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_LOW);
        break;

    case 8:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_HIGH);
        break;

    case 9:
        DIO_SetPinValue(DIO_PORTB,DIO_PIN0,DIO_VALUE_HIGH);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN1,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN2,DIO_VALUE_LOW);
        DIO_SetPinValue(DIO_PORTB,DIO_PIN4,DIO_VALUE_HIGH);
        break;
    
    default:
        break;
    }
}
