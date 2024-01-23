#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "LCD_Inerface.h"
#include "KEYPAD_Interface.h"
#include "Temp_Interface.h"
#include "Pot_Interface.h"
#include "UART_Interface.h"
#include "I2C_Interface.h"
#include "EX_EEPROM_Interface.h"
#include "MOTOR_Interface.h"
#include "FireAlarm_Interface.h"
#include "String_Serive.h"
#include "EX_Interrupt_Interface.h"
#include "WDT_Interface.h"

#define F_CPU 8000000
#include"util/delay.h"

#define LED_FINE PINB0
#define LED_HEAT PINC5
#define LED_FIRE PINB1

static System_Status_t System_Flag=SYSTEM_FINE;
static u16 Temp;
static u16  pot;
static u8 key;
static u8 Flag_FireState=0;
static u8 pass_EEPROM[10]={0};
static u8 pass[10]={0};
static u8 pass_index=0;
static u8 Pass_Flag=0;

void Change_Pass(void)
{

	Pass_Flag=1;
	System_Flag=SYSTEM_NEWPASS;

}

void FireAlarm_Init(void)
{
	//LED_FINE ->ON  And Rest are off
	DIO_WritePin(LED_FINE,HIGH);
	DIO_WritePin(LED_HEAT,LOW);
	DIO_WritePin(LED_FIRE,LOW);

	EEPROM_ReadString(0,pass_EEPROM);
	EXI_SetCallBack(EX_INT2,Change_Pass);
	EXI_TriggerEdge(EX_INT2,FALLING_EDGE);
	EXI_Enable(EX_INT2);




	//Motor Stop
	MOTOR_Stop(M1);

	System_Flag=SYSTEM_FINE;

}

void FireAlarm_Runnable(void)
{
	Temp=FILTER_GetFilteredTemp();

	pot=Pot_Get_Synch();
    if(Pass_Flag==1)
    {
    	System_Flag=SYSTEM_NEWPASS;
    }
    else if(Flag_FireState==1)
	{
			System_Flag=SYSTEM_FIRE;
			if(Temp<450)
			{
				System_Flag=SYSTEM_FIRE_FINE;
			}

	}
	else if(Temp<450)
	{
		System_Flag=SYSTEM_FINE;

	}

	else if(Temp>500&&pot<45)
	{
		System_Flag=SYSTEM_HEAT;

	}

	else if(Temp>500&&pot>50)
	{
		System_Flag=SYSTEM_FIRE;
		Flag_FireState=1;

	}



	if(System_Flag==SYSTEM_FINE)
	{
		LCD_WriteStringGoTo(0,2,"SYSTEM FINE");
		DIO_WritePin(LED_FINE,HIGH);
		DIO_WritePin(LED_HEAT,LOW);
		DIO_WritePin(LED_FIRE,LOW);
		MOTOR_Stop(M1);
		LCD_WriteStringGoTo(1,0,"TEMP=");
		LCD_WriteNum(Temp/10);
		LCD_WriteChar('.');
		LCD_WriteNum(Temp%10);
		LCD_WriteString(" P=");
		LCD_WriteNum(pot);
		LCD_WriteString("  ");


	}
	else if(System_Flag==SYSTEM_HEAT)
	{
		LCD_WriteStringGoTo(0,2,"SYSTEM Heat");
		DIO_WritePin(LED_FINE,LOW);
		DIO_WritePin(LED_HEAT,HIGH);
		DIO_WritePin(LED_FIRE,LOW);
		MOTOR_Stop(M1);
		LCD_WriteStringGoTo(1,0,"TEMP=");
		LCD_WriteNum(Temp/10);
		LCD_WriteChar('.');
		LCD_WriteNum(Temp%10);
		LCD_WriteString(" P=");
		LCD_WriteNum(pot);
		LCD_WriteString("  ");


	}
	else if(System_Flag==SYSTEM_FIRE)
	{
		LCD_WriteStringGoTo(0,2,"SYSTEM FIRE");
		DIO_WritePin(LED_FINE,LOW);
		DIO_WritePin(LED_HEAT,LOW);
		DIO_WritePin(LED_FIRE,HIGH);
		MOTOR_Cw(M1);
		LCD_WriteStringGoTo(1,0,"TEMP=");
		LCD_WriteNum(Temp/10);
		LCD_WriteChar('.');
		LCD_WriteNum(Temp%10);
		LCD_WriteString(" P=");
		LCD_WriteNum(pot);
		LCD_WriteString("  ");

		UART_SendString("Fire");


	}
	else if(System_Flag==SYSTEM_FIRE_FINE)
	{

		LCD_WriteStringGoTo(0,0,"please enter 1");
		LCD_WriteStringGoTo(1,0,"to close motor");
		key=KEYPAD_GetKey();
		if(key!=NO_KEY)
		{



			if(key=='1')
			{
				LCD_Clear();
				LCD_WriteStringGoTo(0,0,"Enter Pass:");
				while(1)
				{
					key=KEYPAD_GetKey();
					if(key!=NO_KEY)
					{
						if(key>='0'&&key<='9')
						{
							pass[pass_index++]=key;
							LCD_WriteChar(key);
						}
						if(key=='=')
						{
							pass[pass_index]=0;
							pass_index=0;
							break;
						}
					}

				}
				if(String_Cmpr(pass,pass_EEPROM)==STRING_SAME)
				{
					LCD_Clear();
					LCD_WriteStringGoTo(0,0,"PASS OK");
					Flag_FireState=0;
					System_Flag=SYSTEM_FINE;
					_delay_ms(2000);
					LCD_Clear();


				}
				else
				{
					LCD_Clear();
					LCD_WriteStringGoTo(0,0,"PASS wrong");
					_delay_ms(2000);



				}

			}






		}




	}
	else if(System_Flag==SYSTEM_NEWPASS)
	{
		LCD_Clear();
			LCD_WriteStringGoTo(0,0,"NewPass:");
			u8 i=0;
			while(1)
			{
				key=KEYPAD_GetKey();
				if(key!=NO_KEY)
				{
					if(key>='0'&&key<='9')
					{
						EEPROM_WriteChar(i++,key);
						LCD_WriteChar(key);
						if(i==3)
						{
							LCD_Clear();
							LCD_WriteStringGoTo(0,0,"Passchange:");

							Pass_Flag=0;
							System_Flag=SYSTEM_FINE;
							WDT_Reset(WDT_TIMEOUT_16MS);
							while(1);

							break;
						}
					}
				}
			}

	}






}








