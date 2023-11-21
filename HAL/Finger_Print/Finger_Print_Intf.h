/*
 * Finger_Print_Intf.h
 *
 *  Created on: Nov 4, 2023
 *      Author: lenovo
 */

#ifndef HAL_FINGER_PRINT_FINGER_PRINT_INTF_H_
#define HAL_FINGER_PRINT_FINGER_PRINT_INTF_H_


typedef enum{
	FP_AURA_RED,
	FP_AURA_BLUE
}FP_AuraColorType;



void H_FingerPS_HandShake(void);
void H_FingerPS_GenImg(void);
void H_FingerPS_ConvertImg2CharFile(u8 buffer_id);
void H_FingerPS_GenTemplate(void);
void H_FingerPS_StrTemplate(u8 buffer_id, u16 page_id);
void H_FingerPS_SearchFinger(void);
void H_FingerPS_EmptyLibrary(void);
void H_FingerPS_DeleteFinger(void);
void H_FingerPS_LoadCharFile(void);
u16 H_FingerPS_CalcCheckSum(u8* data);
void H_FingerPS_Match(void);
void H_FingerPS_Aura(FP_AuraColorType color);

#endif /* HAL_FINGER_PRINT_FINGER_PRINT_INTF_H_ */
