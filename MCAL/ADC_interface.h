#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include "ADC_Cfg.h"



#define Channel_A0 0
#define Channel_A1 1
#define Channel_A2 2
#define Channel_A3 3
#define Channel_A4 4
#define Channel_A5 5
#define Channel_A6 6
#define Channel_A7 7

void ADC_Init (void); // ADC Initialization And Enable
u16 ADC_Read (u8 Channel); // Read From The ADC Channel
void ADC_StartConversion(u8 channel);
u16 ADC_Volt_Read(u8 channel);
void ADC_IntEnable(void);
void ADC_IntDisable(void);
void ADC_SetCallback(void(*local_fptr)(void));

#endif /* ADC_INTERFACE_H_ */
