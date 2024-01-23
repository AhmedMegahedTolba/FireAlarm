

#ifndef ADC_CFG_H_
#define ADC_CFG_H_


#define ADC_VREF   VREF_AVCC
							   /*****
									   VREF_AREF
									   VREF_AVCC
									   VREF_2_56V

								***////


#define ADC_PRESCALER  ADC_SCALER_128   /****
                                           ADC_SCALER_2
										   ADC_SCALER_4
										   ADC_SCALER_8
										   ADC_SCALER_16
										   ADC_SCALER_32
										   ADC_SCALER_64
										   ADC_SCALER_128


										   ****////

#define ADC_MODE     SINGLE_CONERSION /*
                                          SINGLE_CONERSION
                                          FREE_RUNNING
                                      */
#define  VREF  5000 //to calculate Vin ->vref-> mv


#endif /* ADC_CFG_H_ */
