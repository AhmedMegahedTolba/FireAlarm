#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "LCD_Inerface.h"
#include "KEYPAD_Interface.h"
#include "Temp_Interface.h"
#include "UART_Interface.h"
#include "I2C_Interface.h"
#include "EX_EEPROM_Interface.h"
#include "MOTOR_Interface.h"
#include "FireAlarm_Interface.h"





int main()
{
	DIO_Init();
	LCD_Init();
	ADC_Init();
	UART_Init();
	
	FireAlarm_Init();
	I2C_Master_voidInit(50);
    GLOBAL_ENABLE();

	


u16 temp=10;

	while(1)
	{
		FILTER_Runnable();
		FireAlarm_Runnable();






	}
}











