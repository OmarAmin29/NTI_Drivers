/*
 * Spi.h
 *
 *  Created on: Oct 30, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SPI_SPI_H_
#define MCAL_SPI_SPI_H_


typedef enum{
    SPI_SLAVE = 0,
    SPI_MASTER = 1
}spi_MasterSlaveType;


typedef enum{
    SPI_CLK_POLARITY_LEADING_RISING = 0,
    SPI_CLK_POLARITY_LEADING_FALLING = 1
}Spi_ClkPolarityType;

typedef enum{
    SPI_CLK_PHASE_LEADING_SAMPLE = 0,
    SPI_CLK_PHASE_LEADING_SETUP = 1
}Spi_ClkPhaseType;

typedef enum
{
    SPI_PRESCALER_4 = 0,
    SPI_PRESCALER_16 = 1,
    SPI_PRESCALER_64 = 2,
    SPI_PRESCALER_128 = 3
} Spi_PrescalerType;

typedef enum{
    SPI_DATA_ORDER_MSB = 0,
    SPI_DATA_ORDER_LSB = 1
}Spi_DataOrderType;

typedef struct{
    spi_MasterSlaveType master_slave_select;
    Spi_ClkPolarityType clk_polarity;
    Spi_ClkPhaseType clk_phase;
    Spi_PrescalerType prescaler;
    Spi_DataOrderType data_order;
}Spi_ConfgType;


void M_Spi_Init(Spi_ConfgType* confg);
void M_Spi_Transmit(u8 copy_u8data, u8* pch);
void M_spi_SetcallBack(void (*funcptr)(void));

#endif /* MCAL_SPI_SPI_H_ */
