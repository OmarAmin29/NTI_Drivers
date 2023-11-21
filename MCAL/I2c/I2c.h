/*
 * I2c.h
 *
 *  Created on: Oct 31, 2023
 *      Author: lenovo
 */

#ifndef MCAL_I2C_I2C_H_
#define MCAL_I2C_I2C_H_


#include"../../Private/Types.h"


typedef enum
{

    /****************************************************
     *                  MASTER STATUS                   *
     ****************************************************/

    /**********MASTER TRANSMITTER MODE******************/
    /* A START condition has been transmitted */
    I2C_STATUS_MASTER_START_SENT = 0x08,

    /* A repeated START condition has been transmitted */
    I2C_STATUS_MASTER_REP_START_SENT = 0x10,

    /* SLA+W has been transmitted; ACK has been received */
    I2C_STATUS_MASTER_SA_W_ACK = 0x18,

    /* SLA+W has been transmitted; NOT ACK has been received */
    I2C_STATUS_MASTER_SA_W_NACK = 0x20,

    /* Data byte has been transmitted; ACK has been received */
    I2C_STATUS_MASTER_DATA_SENT_ACK = 0x28,

    /* Data byte has been transmitted; NOT ACK has been received */
    I2C_STATUS_MASTER_DATA_SENT_NACK = 0x30,

    /* Arbitration lost in SLA+W or data bytes */
    /*Arbitration lost in SLA+R or NOT ACK bit*/
    I2C_STATUS_MASTER_ARBITRATION_LOST = 0x38,
    
    /****************MASTER RECIVER MODE******************/
    /* SLA+R has been transmitted; ACK has been received */
    I2C_STATUS_MASTER_SA_R_ACK = 0x40,

    /* SLA+R has been transmitted; NOT ACK has been received */
    I2C_STATUS_MASTER_SA_R_NACK = 0x48,

    /* Data byte has been received; ACK has been returned */
    I2C_STATUS_MASTER_DATA_RECEIVED_ACK = 0x50,

    /* Data byte has been received; NOT ACK has been returned */
    I2C_STATUS_MASTER_DATA_RECEIVED_NACK = 0x58
} I2c_StatusType;

typedef enum
{
    I2C_NO_ERROR,
    I2C_ERROR_SLA_NACK,
    I2C_ERROR_DATA_NACK,
    I2C_ERROR_DATA_NOT_RECEIVED,
    I2C_ERROR_WRITE_REQUEST_NOT_RECEIVED,
    I2C_ERROR_READ_REQUEST_NOT_RECEIVED,
    I2C_ERROR_START_NOT_SENT
} I2c_ErrorType;






typedef enum{
    I2C_SCL_FREQ_100_KHZ,
    I2C_SCL_FREQ_400_KHZ
}I2c_SclFreqType;



void M_I2c_Init(I2c_SclFreqType freq);
void M_I2c_sendStart(void);
void M_I2c_sendStop(void);
/*SendByte Send data and adress of the slave*/
void M_I2c_sendByte(u8 copy_u8data);
void M_I2c_receiveByte_ACK(u8* ptr);
void M_I2c_receiveByte_NoACK(u8* ptr);
void M_I2c_getStatus(u8* status);



#endif /* MCAL_I2C_I2C_H_ */
