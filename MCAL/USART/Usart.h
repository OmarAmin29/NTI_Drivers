/*
 * Usart.h
 *
 *  Created on: Oct 29, 2023
 *      Author: lenovo
 */

#ifndef MCAL_USART_USART_H_
#define MCAL_USART_USART_H_

#include"../../Private/Types.h"


typedef enum{
    USART_MODE_ASYNCH,
    USART_MODE_SYNCH
}Usart_ModeSelectType;

typedef enum{
    USART_PARITY_DISABLED = 0,
    USART_PARITY_EVEN = 2,
    USART_PARITY_ODD = 3
}Usart_ParitySelectType;

typedef enum{
    USART_STOP_BIT_1,
    USART_STOP_BIT_2
}Usart_StopBitsType;

typedef enum{
    USART_CHAR_SIZE_5 = 0,
    USART_CHAR_SIZE_6 = 1,
    USART_CHAR_SIZE_7 = 2,
    USART_CHAR_SIZE_8 = 3,
    USART_CHAR_SIZE_9 = 7
}Usart_CharSizeType;


typedef enum{
    USART_BAUD_RATE_4800 = 4800,
    USART_BAUD_RATE_9600 = 9600,
    USART_BAUD_RATE_57600 = 57600

}Usart_BaudRateType;

typedef enum{
    USART_CLK_POLARITY_RISING_TX,
    USART_CLK_POLARITY_FALLING_TX
}Usart_ClkPolarityType;

typedef enum {
    USART_INT_SOURCE_RX,
    USART_INT_SOURCE_TX,
    USART_INT_SOURCE_DATA_REG_EMPTY
}Usart_InterruptSourceType;

typedef struct
{
    Usart_ModeSelectType mode;
    Usart_ParitySelectType parity;
    Usart_StopBitsType stop_bits;
    Usart_CharSizeType size;
    Usart_BaudRateType baud_rate;
    Usart_ClkPolarityType clk_polarity;
}Usart_ConfgType;



void M_Usart_Init(const Usart_ConfgType* confg);
void M_Usart_Transmit(u8 data);
void M_USART_ReceiveByteSynchNonBlocking(u8* data);
void M_USART_sendString(u8* pStr);
void M_Usart_EnableNotification(Usart_InterruptSourceType source);
void M_Usart_DisableNotification(Usart_InterruptSourceType source);
void M_USART_ReceiveByteAsynchCallBack(void (*funcPtr) (u8));

#endif /* MCAL_USART_USART_H_ */
