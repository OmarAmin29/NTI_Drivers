/*
 * Eeprom.c
 *
 *  Created on: Oct 31, 2023
 *      Author: lenovo
 */


#include"../../Private/Types.h"
#include"../../Private/Macros.h"

#include"../../MCAL/I2c/I2c.h"
#include"../../MCAL/USART/Usart.h"
#include"Eeprom_Cfg.h"
#include"Eeprom.h"

void H_Eeprom_Init(void)
{
    M_I2c_Init(I2C_SCL_FREQ_100_KHZ);
}

I2c_ErrorType H_Eeprom_WriteByte(u16 adress, u8 data)
{
    /*Status variable to check I2c conditions*/
    u8 status;
    /*Send start condition*/
    M_I2c_sendStart();
    /*Check status of start condition*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_START_SENT)
    {
        return I2C_ERROR_START_NOT_SENT;
    }

    /*Send address of EEPROM and write*/
    M_I2c_sendByte(EEPROM_ADRESS | 0);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_SA_W_ACK)
    {
        return I2C_ERROR_SLA_NACK;
    }

    /*Send address of byte in the EEPROM*/
    M_I2c_sendByte((u8)adress);
    /*Check status of send data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_SENT_ACK)
    {
        return I2C_ERROR_DATA_NACK;
    }

    /*Send data*/
    M_I2c_sendByte(data);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_SENT_ACK)
    {
        return I2C_ERROR_DATA_NACK;
    }

    /*Send stop condition*/
    M_I2c_sendStop();

    return I2C_NO_ERROR;
}

I2c_ErrorType H_Eeprom_ReadByte(u16 adress, u8* data)
{
    /*Status variable to check I2c conditions*/
    u8 status;

    /*Send satrt condition*/
    M_I2c_sendStart();
    /*Check status of start condition*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_START_SENT)
    {
        return I2C_ERROR_START_NOT_SENT;
    }

    /*Send address of EEPROM and write*/
    M_I2c_sendByte(EEPROM_ADRESS | 0);
    /*Check status of send data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_SA_W_ACK)
    {
        return I2C_ERROR_SLA_NACK;
    }

    /*Send address of byte in the EEPROM*/
    M_I2c_sendByte((u8)adress);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_SENT_ACK)
    {
        return I2C_ERROR_DATA_NACK;
    }

    /*Send repeated start*/
    M_I2c_sendStart();
    /*check status of repeated start*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_REP_START_SENT)
    {
        return I2C_ERROR_START_NOT_SENT;
    }

    /*Send address of EEPROM and read*/
    M_I2c_sendByte(EEPROM_ADRESS | 1);
    /*Check status of sent data*/
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_SA_R_ACK)
    {
        return I2C_ERROR_SLA_NACK;
    }

    /*Read the data and send ACK*/
    M_I2c_receiveByte_ACK(data);
    M_I2c_getStatus(&status);
    if(status != I2C_STATUS_MASTER_DATA_RECEIVED_ACK)
    {
        return I2C_ERROR_DATA_NOT_RECEIVED;
    }

    /*Send Stop*/
    M_I2c_sendStop();
    return I2C_NO_ERROR;
}
