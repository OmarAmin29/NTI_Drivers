/*
 * Finger_Print_Prg.c
 *
 *  Created on: Nov 4, 2023
 *      Author: lenovo
 */

#include"../../Private/Types.h"
#include"../../Private/Macros.h"

#include"../../MCAL/USART/Usart.h"

#include "Finger_Print_Cfg.h"
#include"Finger_Print_Intf.h"



u8 hand_shake[] = {HAND_SHAKE};
u8 gen_img[] = {GEN_IMG};
u8 img_to_char[] = {IMG_TO_CHAR};
u8 gen_template[] = {GEN_TEMPLATE};
u8 store_tempelate[] = {STORE_TEMPELATE};
u8 search_finger[] = {SEARCH_FINGER};

u8 aura_red[] = {AURA_RED};
u8 aura_blue[] = {AURA_BLUE};


void H_FingerPS_HandShake(void)
{
#if TRANSMIT_BYTE
    /*2 Bytes Header*/
    M_Usart_Transmit(0xEF);
    M_Usart_Transmit(0x01);

    /*4 Bytes Module Address*/
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);

    /*1 Byte Package Identifier*/
    M_Usart_Transmit(0x01);

    /*2 Byte Package Length*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x03);

    /*1 Byte Instruction Code*/
    M_Usart_Transmit(0x40);

    /*2 Bytes Checksum*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x44);
#endif

#if TRANSMIT_STRING
	M_USART_sendString(hand_shake);

#endif
}

void H_FingerPS_GenImg(void)
{
	#if TRANSMIT_BYTE
    /*2 Bytes Header*/
    M_Usart_Transmit(0xEF);
    M_Usart_Transmit(0x01);

    /*4 Bytes Module Address*/
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);

    /*1 Byte Package Identifier*/
    M_Usart_Transmit(0x01);

    /*2 Byte Package Length*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x03);

    /*1 Byte Instruction Code*/
    M_Usart_Transmit(0x01);

    /*2 Bytes Checksum*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x05);
#endif

#if TRANSMIT_STRING
	M_USART_sendString(gen_img);

#endif

}

void H_FingerPS_ConvertImg2CharFile(u8 buffer_id)
{
	#if TRANSMIT_BYTE
    /*2 Bytes Header*/
    M_Usart_Transmit(0xEF);
    M_Usart_Transmit(0x01);

    /*4 Bytes Module Address*/
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);

    /*1 Byte Package Identifier*/
    M_Usart_Transmit(0x01);

    /*2 Byte Package Length*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x04);

    /*1 Byte Instruction Code*/
    M_Usart_Transmit(0x01);

    /*1 Byte Buffer Number*/
    M_Usart_Transmit(0x01);

    /*2 Bytes Checksum*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x08);
#endif

#if TRANSMIT_STRING
    img_to_char[10] = buffer_id;

    img_to_char[11] = 0;
    img_to_char[12] = 0;

    u16 result = H_FingerPS_CalcCheckSum(img_to_char);

    img_to_char[11] = result >> 8;
    img_to_char[12] = result;

	M_USART_sendString(img_to_char);

#endif
}

void H_FingerPS_GenTemplate(void)
{
#if TRANSMIT_BYTE
    /*2 Bytes Header*/
    M_Usart_Transmit(0xEF);
    M_Usart_Transmit(0x01);

    /*4 Bytes Module Address*/
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);

    /*1 Byte Package Identifier*/
    M_Usart_Transmit(0x01);

    /*2 Byte Package Length*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x03);

    /*1 Byte Instruction Code*/
    M_Usart_Transmit(0x05);

    /*2 Bytes Checksum*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x09);
#endif

#if TRANSMIT_STRING

    M_USART_sendString(gen_template);

#endif

}

void H_FingerPS_StrTemplate(u8 buffer_id, u16 page_id)
{
#if TRANSMIT_BYTE
    /*2 Bytes Header*/
    M_Usart_Transmit(0xEF);
    M_Usart_Transmit(0x01);

    /*4 Bytes Module Address*/
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);
    M_Usart_Transmit(0xFF);

    /*1 Byte Package Identifier*/
    M_Usart_Transmit(0x01);
    
    /*2 Byte Package Length*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x06);

    /*1 Byte Instruction Code*/
    M_Usart_Transmit(0x06);

    /*1 Byte Buffer Number*/
    M_Usart_Transmit(0x01);

    /*2 Bytes Location Number*/
    M_Usart_Transmit(0x00); 
    M_Usart_Transmit(0x01);

    /*2 Bytes Checksum*/
    M_Usart_Transmit(0x00);
    M_Usart_Transmit(0x0F); 

#endif

#if TRANSMIT_STRING
    store_tempelate[10] = buffer_id;
    store_tempelate[11] = page_id >> 8;
    store_tempelate[12] = page_id;

    store_tempelate[13] = 0;
    store_tempelate[14] = 0;
    u16 result = H_FingerPS_CalcCheckSum(store_tempelate);
    store_tempelate[13] = result >> 8;
    store_tempelate[14] = result;

    M_USART_sendString(store_tempelate);
#endif
}


void H_FingerPS_SearchFinger(void)
{
#if TRANSMIT_STRING

	M_USART_sendString(search_finger);

#endif
}

void H_FingerPS_Aura(FP_AuraColorType color)
{
#if TRANSMIT_BYTE
	/*2 Bytes Header*/
	M_Usart_Transmit(0xEF);
	M_Usart_Transmit(0x01);

	/*4 Bytes Module Address*/
	M_Usart_Transmit(0xFF);
	M_Usart_Transmit(0xFF);
	M_Usart_Transmit(0xFF);
	M_Usart_Transmit(0xFF);

	/*1 Byte Package Identifier*/
	M_Usart_Transmit(0x01);

	/*2 Byte Package Length*/
	M_Usart_Transmit(0x00);
	M_Usart_Transmit(0x07);

	/*1 Byte Instruction Code*/
	M_Usart_Transmit(0x35);

	/*1 Byte Buffer Number*/
	M_Usart_Transmit(0x02);

	/*2 Bytes Location Number*/
	M_Usart_Transmit(0x0F);
	M_Usart_Transmit(0x02);

	/*2 Bytes Checksum*/
	M_Usart_Transmit(0x7D);
	M_Usart_Transmit(0x00);
	M_Usart_Transmit(0xCD);
#endif

#if TRANSMIT_STRING
	if(color == FP_AURA_RED)
	{
		M_USART_sendString(aura_red);
	}
	else if(color == FP_AURA_BLUE)
	{
		M_USART_sendString(aura_blue);
	}

#endif
}

u16 H_FingerPS_CalcCheckSum(u8* data)
{
	u16 result = 0;
	/*to calculate check sum of data start from index 6*/
	u8 i = 6;
	while(data[i] != '#')
	{
		result += data[i];
		i++;
	}
	return result;
}

