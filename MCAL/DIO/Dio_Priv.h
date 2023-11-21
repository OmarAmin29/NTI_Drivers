/*
 * Dio_Priv.h
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#ifndef MCAL_DIO_DIO_PRIV_H_
#define MCAL_DIO_DIO_PRIV_H_

#include "../../Private/Types.h"

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







#define DIO_PORTA                ( DIO_PrephieralType *)0x39
#define DIO_PORTB                ( DIO_PrephieralType *)0x36
#define DIO_PORTC                ( DIO_PrephieralType *)0x33
#define DIO_PORTD                ( DIO_PrephieralType *)0x30


#endif /* MCAL_DIO_DIO_PRIV_H_ */
