/*
 * UART.h
 *
 *  Created on: Jul 10, 2022
 *      Author: bassa
 */

#ifndef MCAL_UART_H_
#define MCAL_UART_H_

#include <avr/io.h>
#include "../utils.h"
#include "../STD_TYPES.h"

//#define UBRRL          *((unsigned char *)0x29)
//#define UCSRB          *((unsigned char *)0x2A)
//#define UCSRA          *((unsigned char *)0x2B)
//#define UDR            *((unsigned char *)0x2C)
//#define UCSRC          *((unsigned char *)0x40)


//#define    TXB8              0
//#define    RXB8              1
//#define    UCSZ2             2
//#define    TXEN              3
//#define    RXEN              4
//#define    UDRIE             5
//#define    TXCIE             6
//#define    RXCIE             7
//
//#define    UCPOL             0
//#define    UCSZ0             1
//#define    UCSZ1             2
//#define    USBS              3
//#define    UPM0              4
//#define    UPM1              5
//#define    UMSEL             6
//#define    URSEL             7

void UART_Init(void);
void UART_SendChar(unsigned char Data);
unsigned char UART_ReceiveChar(void);
void UART_SendString(u8 *ptr);
void UART_Send32(u32 data);
u32 UART_Receive32(void);
void UART_ReceiveString(u8 *ptr, u8 MAX);

#endif /* MCAL_UART_H_ */


