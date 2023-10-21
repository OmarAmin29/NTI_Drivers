/*
 * main.c
 *
 *  Created on: Oct 20, 2023
 *      Author: lenovo
 */

#include "../MCAL/DIO/Dio.h"

int main()
{
    DIO_PrephieralType* port = ( DIO_PrephieralType*)0x39;

    while(1)
    {
    	DIO_SetPinDirection(port, DIO_PIN5, DIO_DIRECTION_OUTPUT);
        DIO_SetPinValue(port, DIO_PIN5, DIO_VALUE_HIGH);

    }


}

