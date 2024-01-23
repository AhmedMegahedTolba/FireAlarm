

#ifndef EX_EEPROM_INTERFACE_H_
#define EX_EEPROM_INTERFACE_H_

typedef enum 
{
	EEMPROM_W_OK=0,
	EEMPROM_W_NOK,
	EEMPROM_R_OK,
	EEMPROM_R_NOK,
	
	}EEPROM_STATE_T;

	void EEPROM_WriteChar(u8 loc,u8 data);
void EEPROM_ReadChar(u8 loc,u8 *data);

#endif /* EX_EEPROM_INTERFACE_H_ */
