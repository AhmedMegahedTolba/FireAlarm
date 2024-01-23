#include "StdTypes.h"
#include "MOTOR_Interface.h"
#include "DIO_Interface.h"
#include "MOTOR_Cfg.h"

/*
static const MOTOR_Pins_type MOTOR_PinsStatusArr[MOTOR_TOTAL_PINS]={
	{M1_IN1,MLOW,M1_IN2,MLOW,M1_EN,MLOW},
	{M1_IN1,MHIGH,M1_IN2,MLOW,M1_EN,MHIGH},
	{M1_IN1,MLOW,M1_IN2,MHIGH,M1_EN,MHIGH},
	
	{M2_IN1,MLOW,M2_IN2,MLOW,M2_EN,MLOW},
	{M2_IN1,MHIGH,M2_IN2,MLOW,M2_EN,MHIGH},
	{M2_IN1,MLOW,M2_IN2,MHIGH,M2_EN,MHIGH},
	
	{M3_IN1,MLOW,M3_IN2,MLOW,M3_EN,MLOW},
	{M3_IN1,MHIGH,M3_IN2,MLOW,M3_EN,MHIGH},
	{M3_IN1,MLOW,M3_IN2,MHIGH,M3_EN,MHIGH},
	
	{M4_IN1,MLOW,M4_IN2,MLOW,M4_EN,MLOW},
	{M4_IN1,MHIGH,M4_IN2,MLOW,M4_EN,MHIGH},
	{M4_IN1,MLOW,M4_IN2,MHIGH,M4_EN,MHIGH},
	
	
} ;
*/
/*
 const MOTOR_Pins_type MOTOR_PinsStatusArr[MOTOR_TOTAL_PINS]={
	{PIND0,MLOW,PIND1,MLOW,PIND4,MLOW},
	{PIND0,MHIGH,PIND1,MLOW,PIND4,MHIGH},
	{PIND0,MLOW,PIND1,MHIGH,PIND4,MHIGH},
	
	{PIND2,MLOW,PIND3,MLOW,PIND5,MLOW},
	{PIND2,MHIGH,PIND3,MLOW,PIND5,MHIGH},
	{PIND2,MLOW,PIND3,MHIGH,PIND5,MHIGH},
	
	{PINC0,MLOW,PINC1,MLOW,PINC4,MLOW},
	{PINC0,MHIGH,PINC1,MLOW,PINC4,MHIGH},
	{PINC0,MLOW,PINC1,MHIGH,PINC4,MHIGH},
	
	{PINC2,MLOW,PINC3,MLOW,PINC5,MLOW},
	{PINC2,MHIGH,PINC3,MLOW,PINC5,MHIGH},
	{PINC2,MLOW,PINC3,MHIGH,PINC5,MHIGH},
	
	
} ;
*/
const DIO_Pin_type MOTOR_PinsStatusArr[MOTORS_NUMBERS][3]={
{M1_IN1,M1_IN2,M1_EN}, //M1
{M2_IN1,M2_IN2,M2_EN}, //M2
{M3_IN1,M3_IN2,M3_EN}, //M3
{M4_IN1,M4_IN2,M4_EN}, //M4
	
};
	

