
#include "StdTypes.h"
#include "MemMap.h"
#include "DIO_Interface.h"
#include "ADC_interface.h"
#include "Pot_Interface.h"
#include "Pot_Cfg.h"




u16 Pot_Get_Synch(void)
{
	u16 pot=0;

	pot=(((u32)ADC_Read(POT_CH)*100)+512)/1024;//vref=5v  ->c*10

	return pot;

}
