#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "Temp_Interface.h"
#include "Temp_Cfg.h"

static u16 adc,volt,temp;
void ADC_ReadFunc(void)
{

	adc=ADC;
    ADC_StartConversion(TEMP_CH);

}
void ADC_ReadVoltFunc(void)
{

	adc=ADC;
	volt=((u32)adc*VREF)/1024;
     ADC_StartConversion(TEMP_CH);

}

void Temp_Init(void)
{
	ADC_SetCallback(ADC_ReadFunc);
	ADC_IntEnable();
	ADC_StartConversion(TEMP_CH);
}

u16 Temp_Get(void)
{
	//using volt
	//temp=(volt/10);   //vref=1.5v

	//usin adc
	//temp=((u32)adc*150)/1024;//vref=1.5v
	//temp=((u32)adc*150)/307;//vref=5v

	//temp=((u32)adc*1500)/1024;//vref=1.5v-> c*10
	temp=(((u32)adc*1500))/308;//vref=5v  ->c*10

	return temp;

}

u16 Temp_Get_Synch(void)
{
	//using volt
	//temp=(volt/10);   //vref=1.5v

	//usin adc
	//temp=((u32)adc*150)/1024;//vref=1.5v
	//temp=((u32)adc*150)/307;//vref=5v

	//temp=((u32)adc*1500)/1024;//vref=1.5v-> c*10
	temp=(((u32)ADC_Read(TEMP_CH)*1500))/308;//vref=5v  ->c*10

	return temp;

}













