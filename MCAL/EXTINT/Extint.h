/*
 * Extint.h
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#ifndef MCAL_EXTINT_EXTINT_H_
#define MCAL_EXTINT_EXTINT_H_

#include"../../Private/Types.h"
#include"Extint_Priv.h"
#include"Extint_Cfg.h"




typedef enum {
    EXTINT_ID_INT0 = 6,
    EXTINT_ID_INT1 = 7,
    EXTINT_ID_INT2 = 5,
} ExtInt_IDType;

typedef enum {
    EXTINT_TRIGGER_EDGE_LOW_LEVEL = 0,
    EXTINT_TRIGGER_EDGE_ON_CHANGE = 1,
    EXTINT_TRIGGER_EDGE_FALLING = 2,
    EXTINT_TRIGGER_EDGE_RISING = 3
} ExtInt_TriggerEdgeType;


void Extint_voidEnable(ExtInt_IDType id, ExtInt_TriggerEdgeType edge);
void Extint_voidDisable(ExtInt_IDType id);
void Extint_SetCallback(ExtInt_IDType id, void (*funcptr)(void));

#endif /* MCAL_EXTINT_EXTINT_H_ */
