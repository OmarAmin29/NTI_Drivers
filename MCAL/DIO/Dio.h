/*
 * Gpio.h
 *
 *  Created on: Oct 20, 2023
 *      Author: lenovo
 */



#ifndef DIO_DIO_H_
#define DIO_DIO_H_

#include "../../Private/Types.h"
#include "Dio_Cfg.h"
#include "Dio_Priv.h"

typedef union
{
    u8 reg;
    struct
    {
        u8 B0 : 1;
        u8 B1 : 1;
        u8 B2 : 1;
        u8 B3 : 1;
        u8 B4 : 1;
        u8 B5 : 1;
        u8 B6 : 1;
        u8 B7 : 1;
    }BIT;
    
}DIO_RegisterType;



typedef struct
{
    DIO_RegisterType pin;
    DIO_RegisterType ddr;
    DIO_RegisterType port;
}DIO_PrephieralType;

typedef enum
{
    DIO_DIRECTION_OUTPUT,
    DIO_DIRECTION_INPUT_FLOATING,
    DIO_DIRECTION_INPUT_PULLUP
}DIO_DirectionType;

typedef enum
{
    DIO_VALUE_LOW = 0,
    DIO_VALUE_HIGH = 1
}DIO_ValueType;

typedef enum 
{
    DIO_PIN0,
    DIO_PIN1,
    DIO_PIN2,
    DIO_PIN3,
    DIO_PIN4,
    DIO_PIN5,
    DIO_PIN6,
    DIO_PIN7
}DIO_PinType;



void DIO_SetPinDirection(DIO_PrephieralType* port, DIO_PinType pin, DIO_DirectionType direction);
void DIO_SetPinValue(DIO_PrephieralType* port, DIO_PinType pin, DIO_ValueType value);
DIO_ValueType DIO_GetPinValue(DIO_PrephieralType* port, DIO_PinType pin);

void DIO_SetPortDirection(DIO_PrephieralType* port, DIO_DirectionType direction);
void DIO_SetPortValue(DIO_PrephieralType* port, DIO_ValueType value);
u8   DIO_GetPortValue(DIO_PrephieralType* port);




#endif /* DIO_DIO_H_ */


