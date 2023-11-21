/*
 * I2c.c
 *
 *  Created on: Oct 31, 2023
 *      Author: lenovo
 */

#include"../../Private/Types.h"
#include"../../Private/Macros.h"

#include"../../MCAL/USART/Usart.h"
#include"I2c_Priv.h"
#include"I2c.h"

void M_I2c_Init(I2c_SclFreqType freq)
{

    switch (freq)
    {
    case I2C_SCL_FREQ_100_KHZ:
        TWBR = 72;
        break;
    
    case I2C_SCL_FREQ_400_KHZ:
        TWBR = 12;
        break;

    default:
        break;
    }

    SET_BIT(TWCR,TWEN);
}

void M_I2c_sendStart(void)
{
    /*Send START condition*/
    TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);

    /*Wait for TWINT Flag set. This indicates that the START condition has been transmitted*/
    while (!(TWCR & (1<<TWINT)));
}

void M_I2c_sendStop(void)
{
    /*Transmit STOP condition*/
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}

void M_I2c_sendByte(u8 copy_u8data)
{
    /*Load SLA_W or data into TWDR Register. Clear TWINT bit in TWCR to start transmission of address*/
    TWDR = copy_u8data;
    TWCR = (1<<TWINT) | (1<<TWEN);
     /*Wait for TWINT Flag set. This indicates that the SLA+W has been transmitted, and ACK/NACK has been received.*/
    while (!(TWCR & (1<<TWINT)));
    //while(GET_BIT(TWCR, TWINT) == 0);

}

void M_I2c_receiveByte_ACK(u8* ptr)
{
    /* Clear Flag */
    TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
    /* Wait for flag */
    while (!(TWCR & (1<<TWINT)));
    /* Read Data */
    *ptr = TWDR;
    /*Send Acknwoldgement*/
   // SET_BIT(TWCR,TWEA);
}

void M_I2c_receiveByte_NoACK(u8 * ptr)
{
    /* Clear Flag */
    TWCR = (1<<TWINT) | (1<<TWEN);
    /* Wait for flag */
    while (!(TWCR & (1<<TWINT)));
    /* Read Data */
    *ptr = TWDR;
    /*Send No Acknwoldgement*/
    CLR_BIT(TWCR,TWEA);
}

void M_I2c_getStatus(u8* status)
{
    *status = (TWSR & TWI_Status_REG);
}

