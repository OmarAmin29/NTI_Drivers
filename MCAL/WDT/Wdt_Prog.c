/*
 * Wdt_Prog.c
 *
 *  Created on: Nov 5, 2023
 *      Author: lenovo
 */


#include"../../Private/Types.h"
#include"../../Private/Macros.h"

#include"Wdt_Priv.h"
#include"Wdt_Intf.h"

void M_WDT_Enable(void)
{
    SET_BIT(WDTCR,WDE);
}

void M_WDT_Disable(void)
{
    /* Write logical one to WDTOE and WDE */
    WDTCR = (1<<WDTOE) | (1<<WDE);
    /* Turn off WDT */
    WDTCR = 0x00;
}

void M_WDT_sleep(Wdt_SleepTimeType sleepTime)
{
    if (sleepTime <= WDT_TIME_OUT_2100_MS) 
    {
        /*Write values of the prescaler in the register*/
        WDTCR &= PRESCALER_MASKABLE;
        WDTCR |= sleepTime;
    }    
}

void M_WDT_refresh(void)
{
	asm("WDR");
}
