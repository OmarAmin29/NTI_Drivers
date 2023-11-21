/*
 * Wdt_Priv.h
 *
 *  Created on: Nov 5, 2023
 *      Author: lenovo
 */

#ifndef MCAL_WDT_WDT_PRIV_H_
#define MCAL_WDT_WDT_PRIV_H_


/*********Watcdog Register***********/
#define WDTCR		*((volatile u8*) 0x41)

/*********WDTCR Pins*********/
#define WDP0            0            
#define WDP1            1
#define WDP2            2
#define WDE             3
#define WDTOE           4

#define PRESCALER_MASKABLE          0b11111000

#endif /* MCAL_WDT_WDT_PRIV_H_ */
