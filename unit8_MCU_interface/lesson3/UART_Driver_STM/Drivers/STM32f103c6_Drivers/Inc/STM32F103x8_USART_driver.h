/*
 * STM32F103x8_USART_driver.h
 *
 *  Created on: Jul 11, 2022
 *      Author: bassa
 */

#ifndef INC_STM32F103X8_USART_DRIVER_H_
#define INC_STM32F103X8_USART_DRIVER_H_

#include "STM32F103x8.h"
#include "STM32F103x8_gpio_driver.h"
#include "STM32F103x8_RCC_driver.h"



//configuration structure

typedef struct{

	uint8_t USART_Mode;                // specifies TX,RX Enable/Disable
	                                  // This parameter Must set based on @Ref UART_MODE_define

    uint32_t BaudRate;               //specifies The Buad Rate(Bit Rate)
	                                // This parameter Must set based on @Ref USART_Buad_Rate_define

    uint8_t	 Payload_Length;		// Specifies the number of data bits transmitted or received in a frame
    							   // This parameters must be set based on @Ref UART_Payload_Length_define

    uint8_t		Parity;				// Specifies the parity mode
    							   // This parameters must be set based on @Ref UART_Parity_define

    uint8_t		StopBits;			// Specifies the number of stop bits
    							    // This parameters must be set based on @Ref UART_StopBits_define

    uint8_t		HwFlowCtl;			// Specifies whether the hardware flow control mode is enabled or disabled
    								// This parameters must be set based on @Ref UART_HwFlowCtl_define

    uint8_t		IRQ_Enable;			// enable or disable the interrupt
    								// This parameters must be set based on @Ref UART_IRQ_define

    void (* P_IRQ_CallBack)(void);	// Set the C Function() which will be called once the IRQ Happen


}USART_config;

//-----------------------------
//Macros Configuration References
//-----------------------------
//@Ref UART_MODE_define
#define     UART_MODE_RX           (uint32_t)(1<<2)
#define     UART_MODE_TX           (uint32_t)(1<<3)
#define     UART_MODE_RX_TX        (uint32_t)( (1<<3) | (1<<2) )


// @Ref UART_BaudRate_define
#define UART_BaudRate_2400			2400
#define UART_BaudRate_9600			9600
#define UART_BaudRate_19200			19200
#define UART_BaudRate_57600			57600
#define UART_BaudRate_115200		115200
#define UART_BaudRate_230400		230400
#define UART_BaudRate_460800		460800
#define UART_BaudRate_921600		921600
#define UART_BaudRate_225000		2250000
#define UART_BaudRate_4500000		4500000

// @Ref UART_Payload_Legth_define
#define UART_Payload_Length_8B		(uint32_t)(0<<12)    // Bit 12 M: Word length
#define UART_Payload_Length_9B		(uint32_t)(1<<12) 	// Bit 12 M: Word length

// @Ref UART_Parity_define
#define UART_Parity_NONE			(uint32_t)(0)
#define UART_Parity_EVEN			((uint32_t)(1<<10) | 0<<9) 		 // Bit 10 PCE: Parity control enable
#define UART_Parity_ODD				((uint32_t)(1<<10  | 1<<9))     // Bit 9 PS: Parity selection

// @Ref UART_StopBits_define
//0: Even parity
//Bits 13:12 STOP: STOP bits
//These bits are used for programming the stop bits.
//00: 1 Stop bit
//01: 0.5 Stop bit
//10: 2 Stop bits
//11: 1.5 Stop bit
//The 0.5 Stop bit and 1.5 Stop bit are not available for UART4 & UART5.                                                                 //1: Odd parity

#define UART_StopBits_half			(uint32_t)(1<<12) 	// Bits 13:12 STOP: STOP bits
#define UART_StopBits_1				(uint32_t)(0)	  	// Bits 13:12 STOP: STOP bits
#define UART_StopBits_1_half		(uint32_t)(3<<12)	// Bits 13:12 STOP: STOP bits
#define UART_StopBits_2				(uint32_t)(2<<12)	// Bits 13:12 STOP: STOP bits

// @Ref UART_HwFlowCtl_define
#define UART_HwFlowCtl_NONE			(uint32_t)(0)
#define UART_HwFlowCtl_RTS			(uint32_t)(1<<8)	  // Bit 8 RTSE: RTS enable
#define UART_HwFlowCtl_CTS			(uint32_t)(1<<9) 	  // Bit 9 CTSE: CTS enable
#define UART_HwFlowCtl_RTS_CTS		(uint32_t)(1<<8 | 1<<9)


// @Ref UART_IRQ_Enable_define
#define UART_IRQ_Enable_NONE		(uint32_t)(0)
#define UART_IRQ_Enable_TXE			(uint32_t)(1<<7)	// Bit 7 TXEIE: TXE interrupt enable (Transmit data register empty)
#define UART_IRQ_Enable_TC			(uint32_t)(1<<6)	// Bit 6 TCIE: Transmission complete interrupt enable (Transmission complete)
#define UART_IRQ_Enable_RXNEIE		(uint32_t)(1<<5)	// Bit 5 RXNEIE: RXNE interrupt enable (Received data ready to be read)
#define UART_IRQ_Enable_PE			(uint32_t)(1<<8)	// Bit 8 PEIE: PE interrupt enable (Parity error)


/*
* ===============================================
* Baud Rate calculation
* ===============================================
*/

// USARTDIV = fclk / (16 * Baudrate)
// USARTDIV_MUL100 = uint32((100 * fclk ) / ( 16 * Baudrate) == (25 * fclk) / (4 * Baudrate))
// DIV_Mantissa_MUL100 = Integer Part (USARTDIV) * 100
// DIV_Mantissa = Integer Part (USARTDIV)
// DIV_Fraction = (( USARTDIV_MUL100 - DIV_Mantissa_MUL100 ) *16) / 100

#define USARTDIV(_PCLK_, _BAUD_)				(uint32_t) (_PCLK_/(16 * _BAUD_ ))
#define USARTDIV_MUL100(_PCLK_, _BAUD_)			(uint32_t) ((25 * _PCLK_ ) / (4 * _BAUD_))
#define Mantissa_MUL100(_PCLK_, _BAUD_)			(uint32_t) (USARTDIV(_PCLK_, _BAUD_) * 100)
#define Mantissa(_PCLK_, _BAUD_)				(uint32_t) (USARTDIV(_PCLK_, _BAUD_ ))
#define DIV_Fraction(_PCLK_, _BAUD_)			(uint32_t) (((USARTDIV_MUL100(_PCLK_, _BAUD_) - Mantissa_MUL100(_PCLK_, _BAUD_) )*16) / 100)
#define UART_BRR_Register(_PCLK_, _BAUD_)		(( Mantissa (_PCLK_, _BAUD_ ) ) << 4 )|((DIV_Fraction(_PCLK_, _BAUD_)) & 0xF )


enum Polling_Mechanism
{
	disable,
	enable
};


/*
* ===============================================
* APIs Supported by "MCAL USART DRIVER"
* ===============================================
*/

void MCAL_UART_Init(USART_typeDef* USARTx, USART_config* UART_Config);
void MCAL_UART_DeInit(USART_typeDef* USARTx);

void MCAL_UART_GPIO_Set_Pins(USART_typeDef* USARTx);

void MCAL_UART_SendData(USART_typeDef* USARTx, uint16_t* pTxBuffer, enum Polling_Mechanism PollingEn);
void MCAL_UART_ReceiveData(USART_typeDef* USARTx, uint16_t* pRxBuffer, enum Polling_Mechanism PollingEn);

void MCAL_UART_WAIT_TC(USART_typeDef* USARTx);

// TODO MCAL_USART_LIN_Init()	// LIN
// TODO MCAL_USART_Init()		// Synchronous
// TODO MCAL_USART_DMA_Init()	// Multi-buffer communication

#endif /* INC_STM32F103X8_USART_DRIVER_H_ */
