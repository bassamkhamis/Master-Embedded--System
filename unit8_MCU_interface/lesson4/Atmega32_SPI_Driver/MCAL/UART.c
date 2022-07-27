/*
 * UART.c
 *
 *  Created on: Jul 10, 2022
 *      Author: bassam
 *
 *
 */
#include "UART.h"
void (*GP_IRQ_CallBack)(void);

void UART_Init(void)
{

	UBRRL = 51;    // 9600 buad rate

   CLEAR_BIT(UCSRA, U2X);
  // CLEAR_BIT(UCSRC, UMSEL); // Asynchronous
  /* 1 stop bit
   * 1 start bit
   * 8 bit data
   * all by default we wantn't  to config it
   *
   * */

	//Enable UART Receive and Transmit
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);


}
void UART_SendChar(u8 Data)
{
	while (!READ_BIT(UCSRA,UDRE));
	UDR = Data;


}
u8 UART_ReceiveChar(void)
{

	while (!READ_BIT(UCSRA,RXC));
	u8 temp = UDR;
	return temp;
}

void UART_SendString(u8 *ptr){


	while(*ptr){
		UART_SendChar(*ptr);
		ptr++;
	}
	UART_SendChar(STOPCHAR);
}

void UART_Send32(u32 data){
	u32 *ptr = &data;
	UART_SendChar(ptr[0]);
	UART_SendChar(ptr[1]);
	UART_SendChar(ptr[2]);
	UART_SendChar(ptr[3]);
}

u32 UART_Receive32(void){
   u32 *ptr, data;
   ptr = &data;
   ptr[0] = UART_ReceiveChar();
   ptr[1] = UART_ReceiveChar();
   ptr[2] = UART_ReceiveChar();
   ptr[3] = UART_ReceiveChar();

   return data;
}

void UART_ReceiveString(u8 *ptr, u8 MAX){
	u8 i = 0, temp;
	temp = UART_ReceiveChar();
	while( i<MAX && temp != STOPCHAR ){
		ptr[i] = temp;
		temp = UART_ReceiveChar();
		i++;
	}
	ptr[i] = '\0';
}

u8 UART_Receive_periodChech(u8 *ptr){

	if(READ_BIT(UCSRA,RXC))
	{
		*ptr = UDR;
		return 1;

	}
	else
	{
		return 0;
	}

}

void UART_RX_Interrupt_Enable(void)
{
	SET_BIT(UCSRA,RXCIE);
}
void UART_RX_Interrupt_Disable(void)
{
	CLEAR_BIT(UCSRA,RXCIE);
}
void UART_TX_Interrupt_Enable(void)
{
	SET_BIT(UCSRA,TXCIE);
}
void UART_TX_Interrupt_Disable(void)
{
	CLEAR_BIT(UCSRA,TXCIE);
}


void UART_SendNoblock(u8 data){
	UDR = data;
}
u8 UART_ReceiveNoblock(void){


	return UDR;
}


ISR(USART_RXC_vect)
{
	GP_IRQ_CallBack();
}

ISR(USART_TXC_vect)
{
	GP_IRQ_CallBack();
}
