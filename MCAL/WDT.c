#include "StdTypes.h"
#include "MemMap.h"
#include "Utils.h"
#include "WDT_Interface.h"



void WDT_Set(WDT_Timeout_type Timeout)
{
    u8 reg=0;
    reg&=0xf8;
    reg|=Timeout;
    SET_BIT(reg,WDE);
    WDTCR=reg;

}

void WDT_Stop(void)
{
	u8 reg=0;
	SET_BIT(reg,WDE);
	SET_BIT(reg,WDTOE);

	WDTCR=reg;
	GLOBAL_DISABLE();
	WDTCR=0;
	GLOBAL_ENABLE();
}
void WDT_Reset(WDT_Timeout_type Timeout)
{
	WDT_Stop();
	WDT_Set(Timeout);

}















