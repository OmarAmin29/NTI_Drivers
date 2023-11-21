/*
 * Usart.c
 *
 *  Created on: Oct 29, 2023
 *      Author: lenovo
 */


#include"../../Private/Types.h"
#include"../../Private/Macros.h"

#include"Usart_Priv.h"
#include"Usart.h"
#include"Usart_Cfg.h"


void (*Usart_RxCallback) (u8 data) = NULL_PTR;
void (*Usart_TxCallback) (void) = NULL_PTR;
void (*Usart_RegEmptyCallback) (void) = NULL_PTR;

ISR(VECTOR_UART_RX)
{
    if(Usart_RxCallback != NULL_PTR)
    {
        Usart_RxCallback(UDR); 
    }
}

ISR(VECTOR_UART_TX)
{
    if(Usart_TxCallback != NULL_PTR)
    {
        Usart_RxCallback(UDR);
    }
}

Usart_ConfgType confg = {
    USART_MODE_ASYNCH,
    USART_PARITY_ODD,
    USART_STOP_BIT_1,
    USART_CHAR_SIZE_8,
    USART_BAUD_RATE_57600
};

void M_Usart_Init(const Usart_ConfgType* confg)
{
    /*Temp variable to write the UCSRC register in one operation as said in the datasheet*/
    u8 temp = 0;

    /*Accessing the UCSRC register*/
    SET_BIT(temp,URSEL);

    if(confg->mode == USART_MODE_ASYNCH)
    {
       CLR_BIT(temp,UMSEL); 
    }
    else if(confg->mode == USART_MODE_SYNCH)
    {
       SET_BIT(temp,UMSEL); 
    }

    if(confg->parity == USART_PARITY_DISABLED)
    {
        CLR_BIT(temp,UPM0); 
        CLR_BIT(temp,UPM1); 
    }
    else if(confg->parity == USART_PARITY_EVEN)
    {
        CLR_BIT(temp,UPM0);
        SET_BIT(temp,UPM1); 
    }
    else if(confg->parity == USART_PARITY_ODD)
    {
        SET_BIT(temp,UPM0);
        SET_BIT(temp,UPM1); 
    }

    if(confg->stop_bits == USART_STOP_BIT_1)
    {
        CLR_BIT(temp,USBS); 
    }
    else if(confg->stop_bits == USART_STOP_BIT_2)
    {
        SET_BIT(temp,USBS);
    }

    if(confg->size == USART_CHAR_SIZE_5)
    {
        CLR_BIT(temp,UCSZ0);        
        CLR_BIT(temp,UCSZ1);
    }
    else if(confg->size == USART_CHAR_SIZE_6)
    {
        SET_BIT(temp,UCSZ0);        
        CLR_BIT(temp,UCSZ1);
    }
    else if(confg->size == USART_CHAR_SIZE_7)
    {
        CLR_BIT(temp,UCSZ0);        
        SET_BIT(temp,UCSZ1);
    }
    else if(confg->size == USART_CHAR_SIZE_8)
    {
        SET_BIT(temp,UCSZ0);        
        SET_BIT(temp,UCSZ1);
    }
    /*Set the UCSRC register with the configured data*/
    UCSRC = temp;

    /*Enable Tx and Rx*/
    SET_BIT(UCSRB,TXEN);
    SET_BIT(UCSRB,RXEN);

    /*Variable To Save The Baud Rate*/
    u16 baud_register_val = 0;

    if (confg->baud_rate > USART_FREQ_OSC/16)
    {
        /* Double the USART Transmission Speed */
        SET_BIT(UCSRA, U2X);
        baud_register_val = (USART_FREQ_OSC/((u32)8 * confg->baud_rate)) - 1;
    }
    /*else if(confg->baud_rate == 57600)
    {
    	baud_register_val = 8;
    }*/
    else
    {
        /*USART Transmission Speed Unchanged*/
        CLR_BIT(UCSRA, U2X);
        baud_register_val = (USART_FREQ_OSC/((u32)16 * confg->baud_rate)) - 1;
    }
    UBRRL = (u8) baud_register_val;
    UBRRH = (u8) ((baud_register_val >> 8) & 0x0F);
}

void M_Usart_Transmit(u8 data)
{
    /* Wait for USART Data Register Empty */
    while (GET_BIT(UCSRA, UDRE) == 0);
    /* Write Data Register */
    UDR = data;
    /* Wait for USART Transmit Complete */
    while (GET_BIT(UCSRA, TXC) == 0);
    /* Clear USART Transmit Complete Flag */
    SET_BIT(UCSRA, TXC);
}

void M_USART_ReceiveByteSynchNonBlocking(u8* data)
{
    /* Wait for USART Receive Complete */
    while (GET_BIT(UCSRA, RXC) == 0);
    *data = UDR;
}

void M_USART_sendString(u8* pStr)
{
    while (*pStr != '#')
    {
        M_Usart_Transmit(*pStr);
        pStr++;
    }   
}


void M_Usart_EnableNotification(Usart_InterruptSourceType source)
{
    switch (source)
    {
    case USART_INT_SOURCE_RX:
        SET_BIT(UCSRB,RXCIE);
        break;
    
    case USART_INT_SOURCE_TX:
        SET_BIT(UCSRB,TXCIE);
        break;

    case USART_INT_SOURCE_DATA_REG_EMPTY:
        SET_BIT(UCSRB,UDRIE);
        break;

    default:
        break;
    }
}
void M_Usart_DisableNotification(Usart_InterruptSourceType source)
{
    switch (source)
    {
    case USART_INT_SOURCE_RX:
        CLR_BIT(UCSRB,RXCIE);
        break;
    
    case USART_INT_SOURCE_TX:
        CLR_BIT(UCSRB,TXCIE);
        break;

    case USART_INT_SOURCE_DATA_REG_EMPTY:
        CLR_BIT(UCSRB,UDRIE);
        break;

    default:
        break;
    }
}


void M_USART_ReceiveByteAsynchCallBack(void (*funcPtr) (u8))
{
	Usart_RxCallback = funcPtr;
}
