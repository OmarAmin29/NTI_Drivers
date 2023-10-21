/*
 * Dio.c
 *
 *  Created on: Oct 20, 2023
 *      Author: lenovo
 */



#include "Dio.h"
#include "Dio_Cfg.h"

void DIO_SetPinDirection(DIO_PrephieralType* port, DIO_PinType pin, DIO_DirectionType direction)
{
    switch (pin)
    {
    case DIO_PIN0:
    if(DIO_DIRECTION_OUTPUT == direction)
    {
        port->ddr->BIT.B0 = 1;
    }
    else if(DIO_DIRECTION_INPUT_FLOATING == direction)
    {
        port->ddr->BIT.B0 = 0;
        port->port->BIT.B0 = 0; 
    }
    else if(DIO_DIRECTION_INPUT_PULLUP == direction)
    {
        port->ddr->BIT.B0 = 0;
        port->port->BIT.B0 = 1;
    }
        break;

    case DIO_PIN1:
    if(DIO_DIRECTION_OUTPUT == direction)
    {
        port->ddr->BIT.B1 = 1;
    }
    else if(DIO_DIRECTION_INPUT_FLOATING == direction)
    {
        port->ddr->BIT.B1 = 0;
        port->port->BIT.B1 = 0; 
    }
    else if(DIO_DIRECTION_INPUT_PULLUP == direction)
    {
        port->ddr->BIT.B1 = 0;
        port->port->BIT.B1 = 1;
    }
        break;

    case DIO_PIN2:
    if(DIO_DIRECTION_OUTPUT == direction)
    {
        port->ddr->BIT.B2 = 1;
    }
    else if(DIO_DIRECTION_INPUT_FLOATING == direction)
    {
        port->ddr->BIT.B2 = 1;
        port->port->BIT.B2 = 0; 
    }
    else if(DIO_DIRECTION_INPUT_PULLUP == direction)
    {
        port->ddr->BIT.B2 = 0;
        port->port->BIT.B2 = 1;
    }
        break;
    
    case DIO_PIN3:
    if(DIO_DIRECTION_OUTPUT == direction)
    {
        port->ddr->BIT.B3 = 1;
    }
    else if(DIO_DIRECTION_INPUT_FLOATING == direction)
    {
        port->ddr->BIT.B3 = 0;
        port->port->BIT.B3 = 0; 
    }
    else if(DIO_DIRECTION_INPUT_PULLUP == direction)
    {
        port->ddr->BIT.B3 = 0;
        port->port->BIT.B3 = 1;
    }
        break;
    
    case DIO_PIN4:
    if(DIO_DIRECTION_OUTPUT == direction)
    {
        port->ddr->BIT.B4 = 1;
    }
    else if(DIO_DIRECTION_INPUT_FLOATING == direction)
    {
        port->ddr->BIT.B4 = 0;
        port->port->BIT.B4 = 0; 
    }
    else if(DIO_DIRECTION_INPUT_PULLUP == direction)
    {
        port->ddr->BIT.B4 = 0;
        port->port->BIT.B4 = 1;
    }
        break;
    
    case DIO_PIN5:
    if(DIO_DIRECTION_OUTPUT == direction)
    {
        port->ddr->BIT.B5 = 1;
    }
    else if(DIO_DIRECTION_INPUT_FLOATING == direction)
    {
        port->ddr->BIT.B5 = 0;
        port->port->BIT.B5 = 0; 
    }
    else if(DIO_DIRECTION_INPUT_PULLUP == direction)
    {
        port->ddr->BIT.B5 = 0;
        port->port->BIT.B5 = 1;
    }
        break;
    
    case DIO_PIN6:
    if(DIO_DIRECTION_OUTPUT == direction)
    {
        port->ddr->BIT.B6 = 1;
    }
    else if(DIO_DIRECTION_INPUT_FLOATING == direction)
    {
        port->ddr->BIT.B6 = 0;
        port->port->BIT.B6 = 0; 
    }
    else if(DIO_DIRECTION_INPUT_PULLUP == direction)
    {
        port->ddr->BIT.B6 = 0;
        port->port->BIT.B6 = 1;
    }
        break;
    
    case DIO_PIN7:
    if(DIO_DIRECTION_OUTPUT == direction)
    {
        port->ddr->BIT.B7 = 1;
    }
    else if(DIO_DIRECTION_INPUT_FLOATING == direction)
    {
        port->ddr->BIT.B7 = 0;
        port->port->BIT.B7 = 0; 
    }
    else if(DIO_DIRECTION_INPUT_PULLUP == direction)
    {
        port->ddr->BIT.B7 = 0;
        port->port->BIT.B7 = 1;
    }
        break;
    
    default:
        break;
    }
}

void DIO_SetPinValue(DIO_PrephieralType* port, DIO_PinType pin, DIO_ValueType value)
{
    switch (pin)
    {
    case DIO_PIN0:
    if(DIO_VALUE_HIGH == value)
    {
        port->port->BIT.B0 = 1;
    }
    else if(DIO_VALUE_LOW == value)
    {
        port->port->BIT.B0 = 0;
    }
        break;
    
    case DIO_PIN1:
    if(DIO_VALUE_HIGH == value)
    {
        port->port->BIT.B1 = 1;
    }
    else if(DIO_VALUE_LOW == value)
    {
        port->port->BIT.B1 = 0;
    }
        break;
    
    case DIO_PIN2:
    if(DIO_VALUE_HIGH == value)
    {
        port->port->BIT.B2 = 1;
    }
    else if(DIO_VALUE_LOW == value)
    {
        port->port->BIT.B2 = 0;
    }
        break;
    
    case DIO_PIN3:
    if(DIO_VALUE_HIGH == value)
    {
        port->port->BIT.B3 = 1;
    }
    else if(DIO_VALUE_LOW == value)
    {
        port->port->BIT.B3 = 0;
    }
        break;
    
    case DIO_PIN4:
    if(DIO_VALUE_HIGH == value)
    {
        port->port->BIT.B4 = 1;
    }
    else if(DIO_VALUE_LOW == value)
    {
        port->port->BIT.B4 = 0;
    }
        break;
    
    case DIO_PIN5:
    if(DIO_VALUE_HIGH == value)
    {
        port->port->BIT.B5 = 1;
    }
    else if(DIO_VALUE_LOW == value)
    {
        port->port->BIT.B5 = 0;
    }
        break;
    
    case DIO_PIN6:
    if(DIO_VALUE_HIGH == value)
    {
        port->port->BIT.B6 = 1;
    }
    else if(DIO_VALUE_LOW == value)
    {
        port->port->BIT.B6 = 0;
    }
        break;
    
    case DIO_PIN7:
    if(DIO_VALUE_HIGH == value)
    {
        port->port->BIT.B7 = 1;
    }
    else if(DIO_VALUE_LOW == value)
    {
        port->port->BIT.B7 = 0;
    }
        break;
    
    default:
        break;
    }

}

DIO_ValueType DIO_GetPinValue(DIO_PrephieralType* port, DIO_PinType pin)
{
    DIO_ValueType value = DIO_VALUE_LOW;

    switch (pin)
    {
    case DIO_PIN0:
        value = port->port->BIT.B0;
        break;
    
    case DIO_PIN1:
    value = port->port->BIT.B1;
        break;
    
    case DIO_PIN2:
    value = port->port->BIT.B2;
        break;
    
    case DIO_PIN3:
    value = port->port->BIT.B3;
        break;
    
    case DIO_PIN4:
    value = port->port->BIT.B4;
        break;
    
    case DIO_PIN5:
    value = port->port->BIT.B5;
        break;
    
    case DIO_PIN6:
    value = port->port->BIT.B6;
        break;
    
    case DIO_PIN7:
    value = port->port->BIT.B7;
        break;
    
    default:
        break;
    }

    return value;
}



