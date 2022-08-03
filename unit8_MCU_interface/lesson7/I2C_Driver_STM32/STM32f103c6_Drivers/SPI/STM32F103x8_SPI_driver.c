/*
 * STM32F103x8_SPI_driver.c
 *
 *  Created on: Jul 13, 2022
 *      Author: bassa
 */



//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8_SPI_driver.h"



/*============================================
 * ============== Generic Variables==========
=========================================== */
SPI_config* Global_SPI_Config[2] = {NULL};

SPI_config SPI1Config;
SPI_config SPI2Config;


/*============================================
 * ============== Generic Functions==========
=========================================== */



/*============================================
 * ============== Macros ==========
=========================================== */

#define TXE_MASK    (uint16_t)(1<<1)
#define RXNE_MASK   (uint16_t)(1<<0)

#define SPI1_INDEX      0
#define SPI2_INDEX      1

/*============================================
 * ============== APIs ==========
=========================================== */

/* ================================================================
 * @Fn				- MCAL_SPI_Init
 * @brief			- Initialize SPI instant
 * @param [in] 		- SPIx: where x can be (1..2 depending on device used)
 * @param [in] 		- SPI_Config: All SPI configuration
 * @retval 			- none
 * Note				- Support full Duplex Master/Salve
 *                  - MUST set RCC peripherals and MUST Know bus clock (APB2 or APB1 according to SPI1 orSPI2)
 */

void MCAL_SPI_Init(SPI_typeDef* SPIx, SPI_config* SPI_Config){

	//Safety for register
	uint16_t Temp_RC1=0;
	uint16_t Temp_RC2=0;
	if(SPIx == SPI1){

		SPI1Config = *SPI_Config;
		Global_SPI_Config[SPI1_INDEX] =  &SPI1Config;
		RCC_SPI1_CLK_EN();
	}
	else if(SPIx == SPI2)
	{
		SPI2Config = *SPI_Config;
		Global_SPI_Config[SPI2_INDEX] =  &SPI2Config;
		RCC_SPI2_CLK_EN();

	}

	//CR1, Bit 6 SPE: SPI enable
	Temp_RC1 |= (1U<<6);

	//Master or Salve
	Temp_RC1 |= SPI_Config->Device_Mode;

	//SPI_communication mode
	Temp_RC1 |= SPI_Config->communication_Mode;

	//SPI_Frame_Format
	Temp_RC1 |= SPI_Config->frame_format;

	//SPI_Data_size
	Temp_RC1 |= SPI_Config->DataSize;

	//SPI_CLKpolarity
	Temp_RC1 |= SPI_Config->CLKpolarity;

	//SPI_CLKphase
	Temp_RC1 |= SPI_Config->CLKphase;
	//--------------SPI_NSS-------------------
	if(SPI_Config->NSS == SPI_NSS_Hardware_Master_SS_OUTPUT_ENABLE)
	{
		Temp_RC2 |= SPI_NSS_Hardware_Master_SS_OUTPUT_ENABLE;
	}
	else if(SPI_Config->NSS == SPI_NSS_Hardware_Master_SS_OUTPUT_Disable)
	{
		Temp_RC2 &= SPI_NSS_Hardware_Master_SS_OUTPUT_Disable;
	}
	else
	{
		Temp_RC1 |= SPI_Config->NSS;
	}

	//SPI_BAUDRATE_PRESCALERS
	Temp_RC1 |= SPI_Config->SPI_BAUDRATE_PRESCALERS;

	//SPI_IRQ_config
	if(SPI_Config->IRQ_Enable != SPI_IRQ_Enable_NONE)
	{
		Temp_RC2 |= SPI_Config->IRQ_Enable;
		if(SPIx == SPI1){

			NVIC_IQR35_SPI1_Enable();
		}
		else if(SPIx == SPI2)
		{

			NVIC_IQR36_SPI2_Enable();
		}


	}



	// Update value in Reg
	// to Avoid any problem during Init
	//
	SPIx->CR1 = Temp_RC1;
	SPIx->CR2 = Temp_RC2;





}
void MCAL_SPI_DeInit(SPI_typeDef* SPIx)
{

	if(SPIx == SPI1){

		NVIC_IQR35_SPI1_Disable();
		RCC_SPI1_Reset();

	}
	else if(SPIx == SPI2)
	{

		NVIC_IQR36_SPI2_Disable();
		RCC_SPI2_Reset();
	}

}

void MCAL_SPI_SendData(SPI_typeDef* SPIx, uint16_t* pTxBuffer, enum Polling_Mechanism_SPI PollingEn)
{
	if(PollingEn == enablePOLLING_SPI)
	{
		while(!(SPIx->SR & TXE_MASK));
	}

	SPIx->DR = * pTxBuffer;
}
void MCAL_SPI_ReceiveData(SPI_typeDef* SPIx, uint16_t* pRxBuffer, enum Polling_Mechanism_SPI PollingEn)
{
	if(PollingEn == enablePOLLING_SPI)
	{
		while(!(SPIx->SR & RXNE_MASK));
	}

	*pRxBuffer = SPIx->DR;
}
void MCAL_SPI_TX_RX(SPI_typeDef* SPIx, uint16_t* pRxTXBuffer, enum Polling_Mechanism_SPI PollingEn)
{
	// Write first
	if(PollingEn == enablePOLLING_SPI)
	{
		while(!(SPIx->SR & TXE_MASK));
	}
	SPIx->DR = * pRxTXBuffer;
	//then Receive
	if(PollingEn == enablePOLLING_SPI)
	{
		while(!(SPIx->SR & RXNE_MASK));
	}
	*pRxTXBuffer = SPIx->DR;


}

void MCAL_SPI_GPIO_Set_Pins(SPI_typeDef* SPIx)
{

	GPIO_configPin_t Pin_Config;
	if(SPIx == SPI1){
		// PA4 SPI1 NSS
		//  PA5 SPI1 CLK
		// PA6 SPI1 MISO
		// PA7 SPI1 MOSI


		if(Global_SPI_Config[SPI1_INDEX]->Device_Mode == SPI_Device_Mode_Master )//Master
		{
			switch(Global_SPI_Config[SPI1_INDEX]->NSS){

			case SPI_NSS_Hardware_Master_SS_OUTPUT_Disable:
				//Input floating (Default)
				break;

			case SPI_NSS_Hardware_Master_SS_OUTPUT_ENABLE:

				Pin_Config.GPIO_PinNumber = GPIO_PIN4;
				Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
				Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOA, &Pin_Config);

				break;

			}
			//  PA5 SPI1 CLK OUTPUT_AF_PP
			Pin_Config.GPIO_PinNumber = GPIO_PIN5;
			Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);


			// PA6 SPI1 MISO Input floating (Default)

			// PA7 SPI1 MOSI OUTPUT_AF_PP
			Pin_Config.GPIO_PinNumber = GPIO_PIN7;
			Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);



		}
		//slave
		else{

			if(Global_SPI_Config[SPI1_INDEX]->NSS == SPI_NSS_Hardware_Salve)
			{
				// PA4 SPI1 NSS Input floating (Default)
			}

			//  PA5 SPI1 CLK Input floating (Default)

			// PA6 SPI1 MISO OUTPUT_AF_PP
			Pin_Config.GPIO_PinNumber = GPIO_PIN7;
			Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOA, &Pin_Config);


			// PA7 SPI1 MOSI Input floating (Default)
		}
	}
	else if(SPIx == SPI2)
	{

		// PB12 SPI1 NSS
		// PB13 SPI1 CLK
		// PB14 SPI1 MISO
		// PB15 SPI1 MOSI


		if(Global_SPI_Config[SPI2_INDEX]->Device_Mode == SPI_Device_Mode_Master )//Master
		{
			switch(Global_SPI_Config[SPI2_INDEX]->NSS){

			case SPI_NSS_Hardware_Master_SS_OUTPUT_Disable:
				//Input floating (Default)
				break;

			case SPI_NSS_Hardware_Master_SS_OUTPUT_ENABLE:

				Pin_Config.GPIO_PinNumber = GPIO_PIN4;
				Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
				Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
				MCAL_GPIO_Init(GPIOB, &Pin_Config);

				break;

			}
			//  PA5 SPI1 CLK OUTPUT_AF_PP
			Pin_Config.GPIO_PinNumber = GPIO_PIN5;
			Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &Pin_Config);


			// PA6 SPI1 MISO Input floating (Default)

			// PA7 SPI1 MOSI OUTPUT_AF_PP
			Pin_Config.GPIO_PinNumber = GPIO_PIN7;
			Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &Pin_Config);



		}
		//slave
		else{

			if(Global_SPI_Config[SPI2_INDEX]->NSS == SPI_NSS_Hardware_Salve)
			{
				// PA4 SPI1 NSS Input floating (Default)
			}

			//  PA5 SPI1 CLK Input floating (Default)

			// PA6 SPI1 MISO OUTPUT_AF_PP
			Pin_Config.GPIO_PinNumber = GPIO_PIN7;
			Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_PP;
			Pin_Config.GPIO_Output_Speed= GPIO_SPEED_10M;
			MCAL_GPIO_Init(GPIOB, &Pin_Config);


			// PA7 SPI1 MOSI Input floating (Default)
		}
	}


}




/*============================================
 * ============== IQR ==========
=========================================== */


void SPI1_IRQHandler(void)
{
	struct S_IRQ_SRC iqr_SRC;
	iqr_SRC.TXE  = ( ( SPI1->SR & (1<<1) ) >> 1);
	iqr_SRC.RXNE = ( ( SPI1->SR & (1<<0) ) >> 0);
	iqr_SRC.ERR  = ( ( SPI1->SR & (1<<4) ) >> 4);

	Global_SPI_Config[SPI1_INDEX]->P_IRQ_CallBack(iqr_SRC);
}

void SPI2_IRQHandler(void)
{
	struct S_IRQ_SRC iqr_SRC;
	iqr_SRC.TXE  = ( ( SPI2->SR & (1<<1) ) >> 1);
	iqr_SRC.RXNE = ( ( SPI2->SR & (1<<0) ) >> 0);
	iqr_SRC.ERR  = ( ( SPI2->SR & (1<<4) ) >> 4);

	Global_SPI_Config[SPI2_INDEX]->P_IRQ_CallBack(iqr_SRC);

}

