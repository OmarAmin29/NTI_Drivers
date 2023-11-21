/*
 * Spi_Priv.h
 *
 *  Created on: Oct 30, 2023
 *      Author: lenovo
 */

#ifndef MCAL_SPI_SPI_PRIV_H_
#define MCAL_SPI_SPI_PRIV_H_





#define SPCR            *((volatile u8*) 0x2D)  
#define SPSR            *((volatile u8*) 0x2E)
#define SPDR            *((volatile u8*) 0x2F)

/***********SPCR PINS***********/
#define SPIE            7            
#define SPE             6
#define DORD            5
#define MSTR            4
#define CPOL            3
#define CPHA            2
#define SPR1            1
#define SPR0            0

/**********SPSR PINS*********/
#define SPIF            7
#define WCOL            6
#define SPI2X           0


#endif /* MCAL_SPI_SPI_PRIV_H_ */
