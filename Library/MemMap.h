


#ifndef MEMMAP_H_
#define MEMMAP_H_

/*******************************DIO Registers*////////////////
#define PORTA (*(volatile unsigned char*)0x3B)
#define DDRA (*(volatile unsigned char*)0x3A)
#define PINA (*(volatile unsigned char*)0x39)

#define PORTB (*(volatile unsigned char*)0x38)
#define DDRB (*(volatile unsigned char*)0x37)
#define PINB (*(volatile unsigned char*)0x36)

#define PORTC (*(volatile unsigned char*)0x35)
#define DDRC (*(volatile unsigned char*)0x34)
#define PINC (*(volatile unsigned char*)0x33)

#define PORTD (*(volatile unsigned char*)0x32)
#define DDRD (*(volatile unsigned char*)0x31)
#define PIND (*(volatile unsigned char*)0x30)

/***************************************************************************/

/*   ADC Registers  *///////////////

#define ADMUX (*(volatile unsigned char*)0x27)
/*
#define MUX0 0
#define MUX1 1
#define MUX2 2
#define MUX3 3
#define MUX4 4
*/

#define ADLAR 5

#define REFS0 6
#define REFS1 7

#define ADCSRA (*(volatile unsigned char*)0x26)

#define ADPS0 0
#define ADPS1 1
#define ADPS2 2
#define ADIE  3
#define ADIF  4
#define ADATE 5
#define ADSC  6
#define ADEN  7
 
#define ADCH (*(volatile unsigned char*)0x25)
#define ADCL (*(volatile unsigned char*)0x24)
 
#define ADC (*(volatile unsigned short*)0x24)
  
/***************************************************************************/
 /* Interrupt Registers  */
 
#define MCUCR (*(volatile unsigned char*)0x55)
#define ISC00 0
#define ISC01 1
#define ISC10 2
#define ISC11 3
 
#define MCUCSR  (*(volatile unsigned char*)0x54)
#define ISC2  6
 
#define  GICR (*(volatile unsigned char*)0x5B)
#define INT1 7
#define INT0 6
#define INT2 5

#define  GIFR (*(volatile unsigned char*)0x5A)
#define INTF1 7
#define INTF0 6
#define INTF2 5

/* Interrupt vectors */ 

/* External Interrupt Request 0 */
#define INT0_vect			__vector_1
/* External Interrupt Request 1 */
#define INT1_vect			__vector_2
/* External Interrupt Request 2 */
#define INT2_vect			__vector_3
/* Timer/Counter2 Compare Match */
#define TIMER2_OC_vect		__vector_4
/* Timer/Counter2 Overflow */
#define TIMER2_OVF_vect			__vector_5
/* Timer/Counter1 Capture Event */
#define TIMER1_ICU_vect		__vector_6
/* Timer/Counter1 Compare Match A */
#define TIMER1_OCA_vect		__vector_7
/* Timer/Counter1 Compare Match B */
#define TIMER1_OCB_vect		__vector_8
/* Timer/Counter1 Overflow */
#define TIMER1_OVF_vect			__vector_9
/* Timer/Counter0 Compare Match */
#define TIMER0_OC_vect		__vector_10
/* Timer/Counter0 Overflow */
#define TIMER0_OVF_vect			__vector_11
/* Serial Transfer Complete */
#define SPI_STC_vect			__vector_12
/* USART, Rx Complete */
#define UART_RX_vect			__vector_13
/* USART Data Register Empty */
#define UART_UDRE_vect			__vector_14
/* USART, Tx Complete */
#define UART_TX_vect			__vector_15
/* ADC Conversion Complete */
#define ADC_vect			   __vector_16
/* EEPROM Ready */
#define EE_RDY_vect			   __vector_17
/* Analog Comparator */
#define ANA_COMP_vect			__vector_18
/* 2-wire Serial Interface */
#define TWI_vect			    __vector_19
/* Store Program Memory Ready */
#define SPM_RDY_vect			__vector_20

#define  BAD_vect              __vector_default
/***************************************************************************/

/* Interrupt Functions */ 

#define sei() __asm__ __volatile__ ("sei" ::)
#define cli() __asm__ __volatile__ ("cli" ::)
#define reti() __asm__ __volatile__ ("reti" ::)
#define ret() __asm__ __volatile__ ("ret" ::)

#define GLOBAL_ENABLE() sei()
#define GLOBAL_DISABLE() cli()

#define ISR_NOBLOCK  __attribute__((interrupt))
#define ISR_NAKED  __attribute__((naked))

#  define ISR(vector,...)            \
void vector (void) __attribute__ ((signal))__VA_ARGS__ ; \
void vector (void)

/***************************************************************************/

/* Timer 0 */
#define TCNT0   (*(volatile unsigned char*)0X52)
#define TCCR0   (*(volatile unsigned char*)0X53)
#define FOC0   7
#define WGM00  6
#define COM01  5
#define COM00  4
#define WGM01  3
#define CS02   2
#define CS01   1
#define CS00   0

#define TWCR    (*(volatile unsigned char*)0X56)
#define SPMCR   (*(volatile unsigned char*)0X57)
#define TIFR    (*(volatile unsigned char*)0X58)
#define TIMSK   (*(volatile unsigned char*)0X59)
#define OCIE2  7
#define TOIE2  6
#define TICIE1 5
#define OCIE1A 4
#define OCIE1B 3
#define TOIE1  2
#define OCIE0  1
#define TOIE0  0

#define OCR0    (*(volatile unsigned char*)0X5C)

/* Timer 1 */
#define TCCR1A   (*(volatile unsigned char*)0X4F)
#define COM1A1  7
#define COM1A0  6
#define COM1B1  5
#define COM1B0  4
#define FOC1A   3
#define FOC1B   2
#define WGM11   1
#define WGM10   0

#define TCCR1B   (*(volatile unsigned char*)0X4E)
#define ICNC1   7
#define ICES1   6

#define WGM13   4
#define WGM12   3
#define CS12    2
#define CS11    1
#define CS10    0

#define TCNT1L   (*(volatile unsigned char*)0X4C)
#define TCNT1H   (*(volatile unsigned char*)0X4D)
#define TCNT1   (*(volatile unsigned short*)0X4C)
//compare unit 1 Register
#define OCR1AL   (*(volatile unsigned char*)0X4A)
#define OCR1AH   (*(volatile unsigned char*)0X4B)
#define OCR1A   (*(volatile unsigned short*)0X4A)
//compare unit 2  Register
#define OCR1BL   (*(volatile unsigned char*)0X48)
#define OCR1BH   (*(volatile unsigned char*)0X49)
#define OCR1B   (*(volatile unsigned short*)0X48)

//INPUT CAPATURE REGISTER
#define ICR1L   (*(volatile unsigned char*)0X46)
#define ICR1H   (*(volatile unsigned char*)0X47)
#define ICR1   (*(volatile unsigned short*)0X46)

/***************************************************************************/
/* Timer 2 */
#define TCNT2   (*(volatile unsigned char*)0X44)
#define TCCR2   (*(volatile unsigned char*)0X45)
#define FOC2   7
#define WGM20  6
#define COM21  5
#define COM20  4
#define WGM21  3
#define CS22   2
#define CS21   1
#define CS20   0


#define OCR2    (*(volatile unsigned char*)0X43)
/***************************************************************************/
/*EEprom*/

/*ADDRESS REGISTER*/
#define EEARL   (*(volatile unsigned char*)0X3E)
#define EEARH   (*(volatile unsigned char*)0X3F)
#define EEAR   (*(volatile unsigned short*)0X3E)
/*DATA REGISTER*/
#define EEDR   (*(volatile unsigned char*)0X3D)
/*CONTROL REGISTER*/
#define EECR   (*(volatile unsigned char*)0X3C)
#define EERE   0
#define EEWE   1
#define EEMWE  2
#define EERIE  3

/*****************************************************************************************************/
/* UART */

/* USART I/O Data Register */
#define UDR   (*(volatile unsigned char*)0X2C)

/* USART Control and Status Register A */
#define UCSRA   (*(volatile unsigned char*)0X2B)
#define RXC     7
#define TXC     6
#define UDRE    5
#define FE      4
#define DOR     3
#define PE      2
#define U2X     1
#define MPCM    0

/* USART Control and Status Register B */
#define UCSRB   (*(volatile unsigned char*)0X2A)
#define RXCIE      7
#define TXCIE      6
#define UDRIE      5
#define RXEN       4
#define TXEN       3
#define UCSZ2      2
#define RXB8       1
#define TXB8       0 

/* USART Control and Status Register C */
#define UCSRC   (*(volatile unsigned char*)0X40)
#define URSEL        7
#define UMSEL        6
#define UPM1         5
#define UPM0         4
#define USBS         3
#define UCSZ1        2
#define UCSZ0        1
#define UCPOL        0

/* USART Baud Rate Register High */
#define UBRRH    (*(volatile unsigned char*)0x40)

/* USART Baud Rate Register LOW */
#define UBRRL    (*(volatile unsigned char*)0x29)

/*****************************************************************************************************/
/* SPI*/

/* SPI I/O Data Register */
#define SPDR   (*(volatile unsigned char*)0X2F)

/* SPI Control Register */
#define SPCR   (*(volatile unsigned char*)0X2D)
#define SPIE      7
#define SPE       6
#define DORD      5
#define MSTR      4
#define CPOL      3
#define CPHA      2
#define SPR1      1
#define SPR2      0

/* SPI STATUS REGISTER  */
#define SPSR   (*(volatile unsigned char*)0X2E)
#define SPIF       7
#define WCOL       6
#define SPI2X      0


/************************************************************************************************/

/*I2C Registers  */

/* TWI Bit Rate Register */
#define TWBR (*(volatile unsigned char*)0x20)

/* TWI Control Register*/
#define TWCR (*(volatile unsigned char*)0x56)
#define TWINT 7
#define TWEA  6
#define TWSTA 5
#define TWSTO 4
#define TWWC  3 
#define TWEN  2
#define TWIE  0

/* TWI Status Register*/
#define TWSR (*(volatile unsigned char*)0x21)
#define TWPS1  1
#define TWPS0  0

/* TWI Data Register*/
#define TWDR (*(volatile unsigned char*)0x23)

/* TWI Address Register*/
#define TWAR (*(volatile unsigned char*)0x22)
#define TWGCE   0


/************************************************************************************************************************************/

/* WDT */
#define WDTCR (*(volatile unsigned char*)0x41)
#define WDTOE 4
#define WDE   3


#endif /* MEMMAP_H_ */