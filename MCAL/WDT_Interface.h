/*
 * WDT_Interface.h
 *
 *  Created on: Dec 21, 2023
 *      Author: HIFINE
 */

#ifndef WDT_INTERFACE_H_
#define WDT_INTERFACE_H_



typedef enum{
  WDT_TIMEOUT_16MS,
  WDT_TIMEOUT_32MS,
  WDT_TIMEOUT_65MS,
  WDT_TIMEOUT_130MS,
  WDT_TIMEOUT_260MS,
  WDT_TIMEOUT_520MS,
  WDT_TIMEOUT_1000MS,
  WDT_TIMEOUT_2100MS

}WDT_Timeout_type;//start count down from that num
void  WDT_Set(WDT_Timeout_type timeout);
void  WDT_Stop(void);
void  WDT_Reset(WDT_Timeout_type timeout);
#endif /* WDT_INTERFACE_H_ */
