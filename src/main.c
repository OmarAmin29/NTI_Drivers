/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: lenovo
 */

#include "../MCAL/DIO/Dio.h"
#include "../HAL/Seven_Segment/Ssd.h"


int main()
{

	SS_Init();
    DIO_SetPinDirection(DIO_PORTA, DIO_PIN6, DIO_DIRECTION_OUTPUT);

    while(1)
    {
    	SS_DisplayNumber(0);

        DIO_SetPinValue(DIO_PORTA, DIO_PIN6, DIO_VALUE_HIGH);
    }

}
