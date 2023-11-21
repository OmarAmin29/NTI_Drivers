/*
 * I2c_Priv.h
 *
 *  Created on: Oct 31, 2023
 *      Author: lenovo
 */

#ifndef MCAL_I2C_I2C_PRIV_H_
#define MCAL_I2C_I2C_PRIV_H_

/***************I2C REGISTERS**************/
#define TWBR            *((volatile u8*) 0x20)
#define TWCR            *((volatile u8*) 0x56)
#define TWSR            *((volatile u8*) 0x21)
#define TWDR            *((volatile u8*) 0x23)
#define TWAR            *((volatile u8*) 0x22)

/***********TWCR PINS**********/
#define TWINT           7
#define TWEA            6
#define TWSTA           5
#define TWSTO           4
#define TWWC            3
#define TWEN            2
#define TWIE            0


/********MASKABLE**********/
#define TWI_Status_REG          0xF8

#endif /* MCAL_I2C_I2C_PRIV_H_ */
