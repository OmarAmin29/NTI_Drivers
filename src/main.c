/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: lenovo
 */

#include "../Private/Types.h"
#include "../MCAL/DIO/Dio.h"
#include "../HAL/Seven_Segment/Ssd.h"
#include "../MCAL/General_Interrupt/Gie.h"
#include "../MCAL/EXTINT/Extint.h"
#include"Delay.h"

void Handler_EXT_Int0 (void)
{
   static u8 counter = 0;
    if(counter % 2 == 0)
    DIO_SetPinValue(DIO_PORTD, DIO_PIN6, DIO_VALUE_HIGH);
    else
    {
        DIO_SetPinValue(DIO_PORTD, DIO_PIN6, DIO_VALUE_LOW);
    }
    counter++;
}



int main()
{
    DIO_SetPinDirection(DIO_PORTD, DIO_PIN6, DIO_DIRECTION_OUTPUT);

    Extint_voidEnable(EXTINT_ID_INT0,EXTINT_TRIGGER_EDGE_FALLING);
    Extint_SetCallback(EXTINT_ID_INT0,Handler_EXT_Int0);
    Gie_Enable();
    
    while (1)
    {
            
    }
}
