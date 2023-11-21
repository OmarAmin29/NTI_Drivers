/*
 * Spi.c
 *
 *  Created on: Oct 30, 2023
 *      Author: lenovo
 */



#include"../../Private/Types.h"
#include"../../Private/Macros.h"

#include"Spi_Priv.h"
#include"Spi.h"
#include"Spi_Cfg.h"


void M_Spi_Init(Spi_ConfgType* confg)
{
    u8 temp = 0;
    temp |= ((confg->master_slave_select) << MSTR);
    temp |= ((confg->clk_polarity) << CPOL);
    temp |= ((confg->clk_phase) << CPHA);
    temp |= ((confg->prescaler) << SPR0);
    temp |= ((confg->data_order) << DORD);
    SET_BIT(temp,SPE);
    SPCR = temp;
}

void M_Spi_Transmit(u8 copy_u8data, u8* pch)
{
    SPDR = copy_u8data; 
    while (GET_BIT(SPSR,SPIF) == 0);
    *pch = SPDR;  
}
//void M_spi_SetcallBack(void (*funcptr)(void));
