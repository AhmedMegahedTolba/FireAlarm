#include "StdTypes.h"
#include "MemMap.h"
#include "ADC_register.h"
#include "Utils.h"
#include "ADC_interface.h"
#include "ADC_Private.h"
#include "ADC_Cfg.h"
#include "LCD_Inerface.h"


static void (*ADC_Fptr)(void)=0;



#if ADC_MODE==SINGLE_CONERSION



void ADC_Init(void)
{
	//VREF
   #if ADC_VREF==VREF_AREF

	CLR_BIT(ADMUX,REFS1);
	CLR_BIT(ADMUX,REFS0);



   #elif ADC_VREF==VREF_AVCC

	CLR_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);

   #elif ADC_VREF==VREF_2_56V
	SET_BIT(ADMUX,REFS1);
	SET_BIT(ADMUX,REFS0);

   #endif

	//prescaler
	ADCSRA&=0xF8;
	ADCSRA|=ADC_PRESCALER;


	//ADC_Enable
	SET_BIT(ADCSRA,ADEN);


}

//busy wait
u16 ADC_Read(u8 channel)
{

	//choose channel
	ADMUX&=0xE0;
	ADMUX|=channel;

	//start_conversion
	SET_BIT(ADCSRA,ADSC);
	//wait for flag to be set
	while(READ_BIT(ADCSRA,ADSC)==1);


	return ADC_Reg;

}

u16 ADC_Volt_Read(u8 channel)
{
	u16 adc,volt;

	adc=ADC_Read(channel);
	volt=((u32)adc *VREF)/1024;
   return volt;
}


//INT

void ADC_StartConversion(u8 channel)
{
	//choose channel
		ADMUX&=0xE0;
		ADMUX|=channel;

	//start_conversion
	SET_BIT(ADCSRA,ADSC);
}

void ADC_IntEnable(void)
{
	SET_BIT(ADCSRA,ADIE);
}

void ADC_IntDisable(void)
{
	CLR_BIT(ADCSRA,ADIE);
}
void ADC_SetCallback(void(*local_fptr)(void))
{
  ADC_Fptr=local_fptr;
}

ISR(ADC_vect)
{
	if(ADC_Fptr!=0)
	{
		ADC_Fptr();
	}
}

#else

#endif
