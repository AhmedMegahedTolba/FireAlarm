

#ifndef EX_INTERRUPT_INTERFACE_H_
#define EX_INTERRUPT_INTERFACE_H_

typedef enum{
	EX_INT0,
	EX_INT1,
	EX_INT2,

	
	}EX_InterruptSource_type;
	
typedef enum{
	LOW_LEVEL,
	ANY_LOGIC_CHANGE,
	FALLING_EDGE,
	RISING_EDGE,
	}TriggerEdge_type ;



void EXI_Init(void);
void EXI_Enable(EX_InterruptSource_type Interrupt);
void EXI_Disble(EX_InterruptSource_type Interrupt);
void EXI_TriggerEdge(EX_InterruptSource_type Interrupt,TriggerEdge_type Edge);
void EXI_SetCallBack(EX_InterruptSource_type Interrupt,void(*LocalPtr)(void));//setter




#endif /* EX_INTERRUPT_INTERFACE_H_ */