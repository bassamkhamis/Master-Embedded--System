/*
 * STM32F103x8_SPI_driver.h
 *
 *  Created on: Jul 13, 2022
 *      Author: bassam
 */

#ifndef INC_STM32F103X8_SPI_DRIVER_H_
#define INC_STM32F103X8_SPI_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"
#include "STM32F103x8_gpio_driver.h"

//-----------------------------
//User type definitions (structures)
//-----------------------------


struct S_IRQ_SRC{
	uint8_t TXE      :1;      //TX buffer empty interrupt
	uint8_t RXNE     :1;     //RXNE buffer Not empty interrupt
	uint8_t ERR      :1;    // Error Interrupt
	uint8_t RESERVED5:5;

};

typedef struct {
	uint16_t Device_Mode ;                   //specifies operation mode @ref SPI_Device_Mode_define

	uint16_t communication_Mode;             //specifies the SPI bidirectional mode @ref SPI_communication mode

	uint16_t frame_format;                  // specifies LSB / MSB first @ref SPI_Frame_Format


	uint16_t DataSize;                      //specifies 8 /16 bits data @ref SPI_Data_size


	uint16_t CLKpolarity;                  //specifies clock polarity ideal high / low @ref SPI_CLKpolarity

	uint16_t CLKphase;                     //specifies Clock phase first edge / second edge @ref SPI_CLKphase


	uint16_t NSS;                          //specifies NSS management bit software / hardware @ref SPI_NSS

	uint16_t SPI_BAUDRATE_PRESCALERS;      // specifies the pre scaler value which will be used
	                                       // to configure SCLK
	                                       // This parameters must take value @ref SPI_BAUDRATE_PRESCALERS
	                                       // Take care MUST RCC to be configure APB2 for SPI1, APB1 for SPI2


	 uint16_t		IRQ_Enable;			   // enable or disable the interrupt
	    								   // This parameters must be set based on @Ref SPI_IRQ_define

  void (* P_IRQ_CallBack)(struct S_IRQ_SRC iqr_SRC );	       // Set the C Function() which will be called once the IRQ Happen


}SPI_config;


//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref SPI_Device_Mode_define
#define SPI_Device_Mode_Slave            (0x000U)      //0: Slave configuration
#define SPI_Device_Mode_Master           (1U<<2U)       //1: Master configuration


//@ref SPI_communication mode
#define SPI_2Lines_2fullDuplex           (0x00U)       // CR1:15// 0: 2-line unidirectional data mode selected
                                                       // CR1:10// 0: Full duplex (Transmit and receive)

#define SPI_2Lines_Receive                (1<<10U)     // CR1:15 // 0: 2-line unidirectional data mode selected
                                                       //CR1:10 //1: Output disabled (Receive-only mode)

#define SPI_1Line_Receive                 (1<<15U)     //CR1:15 //1: 1-line bidirectional data mode selected
                                                       //Cr1:14  //0: Output disabled (receive-only mode)

#define SPI_1Line_Transmit               (uint16_t)(1<<15U | 1<<14U)  //CR1:15 //1: 1-line bidirectional data mode selected
                                                                  //Cr1:14  //1: Output enabled (transmit-only mode)


//@ref SPI_Frame_Format//1: LSB transmitted first

#define SPI_Frame_Format_LSB_Frist         (uint16_t)(1<<7)          //CR1:7  //1: LSB transmitted first
#define SPI_Frame_Format_MSB_Frist         (0x00)         //0: MSB transmitted first


//@ref SPI_Data_size //Bit 11 DFF: Data frame format
#define SPI_Data_Size_8Bits                (0x00U)      //CR1:11//0: 8-bit data frame format is selected for transmission/reception
#define SPI_Data_Size_16Bits               (uint16_t)(1<<11U)      //CR1:11//1: 16-bit data frame format is selected for transmission/reception


//@ref SPI_CLKpolarity
#define SPI_CLKpolarity_Ideal_LOW           (0x00U)     //CR1:1 CPOL: Clock polarity //0: CK to 0 when idle
#define SPI_CLKpolarity_Ideal_High          (uint16_t)(1<<1U)                            //1: CK to 1 when idle

//@ref SPI_CLKphase
#define SPI_CLKphase_1thEDG_DATA_Sample   (0x00U)      //Bit 0 CPHA: Clock phase
                                                       //0: The first clock transition is the first data capture edge
#define SPI_CLKphase_2ndEDG_DATA_Sample   (uint16_t)(1<<0U)      //1: The second clock transition is the first data capture edge

//@ref SPI_NSS
//HW
#define SPI_NSS_Hardware_Salve                      (0x000)
#define SPI_NSS_Hardware_Master_SS_OUTPUT_Disable  (uint16_t)~(0x1U<<2)     //RC2:2//0: SS output is disabled in master mode and the cell can work in multimaster configuration

#define SPI_NSS_Hardware_Master_SS_OUTPUT_ENABLE   (uint16_t)(1<<2)    //RC2:2//1: SS output is enabled in master mode
                                                             //and when the cell is enabled. The cell cannot work in a multimaster environment
//SW
#define SPI_NSS_internal_SOFT_Reset                (uint16_t)(1<<9U)     //RC1//Bit 9 SSM: Software slave management
#define SPI_NSS_internal_SOFT_Set                  (uint16_t)((1U<<9U) | (1U<<8U)) //RC1 //Bit 8 SSI: Internal slave select


//@ref SPI_BAUDRATE_PRESCALERS

//Bits 5:3 BR[2:0]: Baud rate control
//000: fPCLK/2
//001: fPCLK/4
//010: fPCLK/8
//011: fPCLK/16
//100: fPCLK/32
//101: fPCLK/64
//110: fPCLK/128
//111: fPCLK/256
#define SPI_BAUDRATE_PRESCALERS_DIV2          (0b000U << 3U)
#define SPI_BAUDRATE_PRESCALERS_DIV4          (0b001U << 3U)
#define SPI_BAUDRATE_PRESCALERS_DIV8          (0b010U << 3U)
#define SPI_BAUDRATE_PRESCALERS_DIV16         (0b011U << 3U)
#define SPI_BAUDRATE_PRESCALERS_DIV32         (0b100U << 3U)
#define SPI_BAUDRATE_PRESCALERS_DIV64         (0b101U << 3U)
#define SPI_BAUDRATE_PRESCALERS_DIV128        (0b110U << 3U)
#define SPI_BAUDRATE_PRESCALERS_DIV256        (0b111U << 3U)

//@Ref SPI_IRQ_define

#define SPI_IRQ_Enable_NONE                    (0x00U)
#define SPI_IRQ_Enable_TXEI                    (uint16_t)(0x1U<<7U)//CR2//Bit 7 TXEIE: Tx buffer empty interrupt enable
#define SPI_IRQ_Enable_RXNEIE                  (uint16_t)(0x1U<<6U)//RC2//Bit 6 RXNEIE: RX buffer not empty interrupt enable
#define SPI_IRQ_Enable_ERRIE                   (uint16_t)(0x1U<<5U)//CR2//Bit 5 ERRIE: Error interrupt enable


enum Polling_Mechanism_SPI
{
	disablePOLLING_SPI,
	enablePOLLING_SPI
};



/*
* ===============================================
* APIs Supported by "MCAL SPI DRIVER"
* ===============================================
*/

void MCAL_SPI_Init(SPI_typeDef* SPIx, SPI_config* SPI_Config);
void MCAL_SPI_DeInit(SPI_typeDef* SPIx);

void MCAL_SPI_GPIO_Set_Pins(SPI_typeDef* SPIx);
void MCAL_SPI_SendData(SPI_typeDef* SPIx, uint16_t* pTxBuffer, enum Polling_Mechanism_SPI PollingEn);
void MCAL_SPI_ReceiveData(SPI_typeDef* SPIx, uint16_t* pRxBuffer, enum Polling_Mechanism_SPI PollingEn);
void MCAL_SPI_TX_RX(SPI_typeDef* SPIx, uint16_t* pRxTXBuffer, enum Polling_Mechanism_SPI PollingEn);

#endif /* INC_STM32F103X8_SPI_DRIVER_H_ */
