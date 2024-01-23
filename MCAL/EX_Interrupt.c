#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "EX_Interrupt_Interface.h"
/************************ Pointer to func To be assigned in ISR ***************************/ 
static void(*INT0_Fptr)(void)=NULLPTR;
static void(*INT1_Fptr)(void)=NULLPTR;
static void(*INT2_Fptr)(void)=NULLPTR;

/***********************Enable-Disable Functions*****************/
void EXI_Enable(EX_InterruptSource_type Interrupt)
{
	switch(Interrupt)
	{
		case EX_INT0:
		SET_BIT(GICR,INT0);
		break;
		
		case EX_INT1:
		SET_BIT(GICR,INT1);
		break;
		
		case EX_INT2:
		SET_BIT(GICR,INT2);
		break;
	}
}
void EXI_Disble(EX_InterruptSource_type Interrupt)
{
	switch(Interrupt)
	{
		case EX_INT0:
		CLR_BIT(GICR,INT0);
		break;
		
		case EX_INT1:
		CLR_BIT(GICR,INT1);
		break;
		
		case EX_INT2:
		CLR_BIT(GICR,INT2);
		break;
	}
}
void EXI_Init(void)
{
	EXI_TriggerEdge(EX_INT0,FALLING_EDGE);
	EXI_TriggerEdge(EX_INT1,FALLING_EDGE);
	EXI_TriggerEdge(EX_INT2,FALLING_EDGE);
}
/***********************Control Function*****************/
void EXI_TriggerEdge(EX_InterruptSource_type Interrupt,TriggerEdge_type Edge)
{
	switch(Interrupt)
	{
		case EX_INT0:
		
		switch(Edge)
		{
			case LOW_LEVEL:
			
			CLR_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case ANY_LOGIC_CHANGE:
			
			SET_BIT(MCUCR,ISC00);
			CLR_BIT(MCUCR,ISC01);
			break;
			
			case FALLING_EDGE:
			
			CLR_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			
			case RISING_EDGE:
			
			SET_BIT(MCUCR,ISC00);
			SET_BIT(MCUCR,ISC01);
			break;
			 
		}
		
		break;
		
		case EX_INT1:
		
		switch(Edge)
		{
			case LOW_LEVEL:
			
			CLR_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case ANY_LOGIC_CHANGE:
			
			SET_BIT(MCUCR,ISC10);
			CLR_BIT(MCUCR,ISC11);
			break;
			
			case FALLING_EDGE:
			
			CLR_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
			case RISING_EDGE:
			
			SET_BIT(MCUCR,ISC10);
			SET_BIT(MCUCR,ISC11);
			break;
			
		}
		
		break;
		
		case EX_INT2:
		
		switch(Edge)
		{
			
			case FALLING_EDGE:
			
			CLR_BIT(MCUCSR,ISC2);
			
			break;
			
			case RISING_EDGE:
			
			SET_BIT(MCUCSR,ISC2);
		
			break;
			
		}
		
		break;
	}
}

/********************************************EXI CALL BACK function  ************************************/
void EXI_SetCallBack(EX_InterruptSource_type Interrupt,void(*LocalPtr)(void))//setter
{
  switch(Interrupt)
  {
	  case EX_INT0:
	  INT0_Fptr=LocalPtr;
	  break;
	  
	  case EX_INT1:
	  INT1_Fptr=LocalPtr;
	  break;
	  
	  case EX_INT2:
	  INT2_Fptr=LocalPtr;
	  break;
	  
  }
 
}
ISR(INT0_vect)/* ISR */
{
	/***call back*****/
	
	if(INT0_Fptr!=NULLPTR)
	{
		INT0_Fptr();
	}

	
	/****call out *****/
	/*
	Ex_Func1();
	*/

	
}

ISR(INT1_vect)/* ISR */
{
	

	if(INT1_Fptr!=NULLPTR)
	{
		INT1_Fptr();
	}

}

ISR(INT2_vect)/* ISR */
{
	

	if(INT2_Fptr!=NULLPTR)
	{
		INT2_Fptr();
	}

}

/*
ISR(BAD_vect)
{
	DIO_WritePin(PINC2,HIGH);
}
*/