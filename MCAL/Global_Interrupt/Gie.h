/*
 * Gie.h
 *
 *  Created on: Oct 22, 2023
 *      Author: lenovo
 */

#ifndef MCAL_GLOBAL_INTERRUPT_GIE_H_
#define MCAL_GLOBAL_INTERRUPT_GIE_H_

#include "../../Private/Macros.h"
#include "../Global_Interrupt/Gie_Priv.h"

inline void Gie_Enable(void) {
    SET_BIT(SREG, SREG_I);
}

inline void Gie_Disable(void) {
    CLR_BIT(SREG, SREG_I);
}

#endif /* MCAL_GLOBAL_INTERRUPT_GIE_H_ */
