/*
 * Extint.c
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */



#include"../../Private/Types.h"
#include "../../Private/Macros.h"
#include"Extint.h"


void (*callback_EXT_INT[3]) (void) = {NULL_PTR,NULL_PTR,NULL_PTR};

ISR(VECTOR_EXT_INT0)
{
    if (NULL_PTR != callback_EXT_INT[0]) {
        callback_EXT_INT[0]();
    }
}

ISR(VECTOR_EXT_INT1)
{
    if (NULL_PTR != callback_EXT_INT[0]) {
        callback_EXT_INT[1]();
    }
}

ISR(VECTOR_EXT_INT2)
{
    if (NULL_PTR != callback_EXT_INT[0]) {
        callback_EXT_INT[2]();
    }
}




void Extint_voidEnable(ExtInt_IDType id, ExtInt_TriggerEdgeType edge)
{
    SET_BIT(GICR,id);

    if(id == EXTINT_ID_INT0)
    {
        MCUCR &= 0b11111100;
        MCUCR |= edge;
    }
    else if(id == EXTINT_ID_INT1)
    {
        MCUCR &= 0b11110011;
        MCUCR |= (edge<<2);
    }
    else
    {
        MCUCSR &= 0b10111111;
        MCUCSR |= ((edge-2)<<6);
    }
}

void Extint_voidDisable(ExtInt_IDType id)
{
    CLR_BIT(GICR,id);
}
void Extint_SetCallback(ExtInt_IDType id, void (*funcptr)(void))
{
    switch (id)
    {
    case EXTINT_ID_INT0:
        callback_EXT_INT[0] = funcptr;
        break;

    case EXTINT_ID_INT1:
        callback_EXT_INT[1] = funcptr;
        break;

    case EXTINT_ID_INT2:
        callback_EXT_INT[2] = funcptr;
        break;

    default:
        break;
    }
}
