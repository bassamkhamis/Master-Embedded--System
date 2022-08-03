/*
 * I2C.c
 *
 *  Created on: Jul 31, 2022
 *      Author: bassa
 */


//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8_I2C_driver.h"
#include "STM32F103x8_RCC_driver.h"
#include "STM32F103x8_gpio_driver.h"


/*============================================
 * ============== Generic Variables==========
=========================================== */
I2C_configtypeDef GVI2Cconfig[2] = {0};

/*============================================
 * ============== Macros ==========
=========================================== */
#define I2C1_INDEX                    0
#define I2C2_INDEX                    1



void MCAL_I2C_Init(I2C_typeDef *I2Cx , I2C_configtypeDef *I2Cconfig)
{
	//Enable Clock
	uint16_t Temp = 0 ,Frequency = 0;
	uint32_t Pclk1 = 8000000;
	uint16_t Result = 0 ;
	if (I2Cx == I2C1)
	{
		GVI2Cconfig[I2C1_INDEX] = *I2Cconfig ;
		RCC_I2C1_CLK_EN();
	}
	else if (I2Cx == I2C2)
	{
		GVI2Cconfig[I2C2_INDEX] = *I2Cconfig ;
		RCC_I2C2_CLK_EN();
	}


	if(I2Cconfig->I2C_Mode == I2C_Mode_I2C)
	{

		/*************** init Timing*********************/


		//1• 2 MHz in Sm mode
		//Bits 5:0 FREQ[5:0]: Peripheral clock frequency //I2C_CR2 Register
		Temp = I2Cx->CR2    ;

		Temp &= ~(I2C_CR2_FREQ);

		Pclk1 = MCAL_RCC_GetPCLK1Freq();

		Frequency = (uint16_t) ( Pclk1/1000000 )  ;

		Temp |= Frequency  ;

		I2Cx->CR2 = Temp ;

		//2• Configure the clock control //registers CCR[11:0]
		// Thigh = CCR*Tpclk1
		// Must preipherals Disable
		// RCC = Fplk1/(2*Fclk)
		I2Cx->CR1 &= ~(I2C_CR1_PE);

		Temp = 0;

		if(I2Cconfig->I2C_CLOCK == I2C_SCLK_SM_50K || I2Cconfig->I2C_CLOCK == I2C_SCLK_SM_100K )
		{
			// RCC = Fplk1/(2*Fclk)
			Result = ( Pclk1/( (I2Cconfig->I2C_CLOCK) <<1 ) );  //MUL by 2


			Temp = I2Cx->CCR ;

			Temp |= Result;

			I2Cx->CCR =  Temp ;

			//3• Configure the rise time registerr (I2C_TRISE) TRISE[5:0]

			//			 For instance: in Sm mode, the maximum allowed SCL rise time is 1000 ns.
			//			 If, in the I2C_CR2 register, the value of FREQ[5:0] bits is equal to 0x08 and TPCLK1 = 125 ns
			//			 therefore the TRISE[5:0] bits must be programmed with 09h.
			//			 (1000 ns / 125 ns = 8 + 1)

			I2Cx->TRISE = Frequency + 1 ;

		}
		else
		{
			// Not supported YET

		}


		// Config CR1

		Temp  = 0 ;

		Temp = I2Cx->CR1 ;

		Temp |= (uint16_t)(I2Cconfig->I2C_ACK_Control | I2Cconfig->General_Call_Adrress_Detection | I2Cconfig->stretchClok | I2Cconfig->I2C_Mode);

		I2Cx->CR1 |= Temp ;


		Temp = 0;

		if(I2Cconfig->I2C_Slave_Addres.Enable_DualADD == 1)
		{
			Temp = I2C_OAR2_ENDUAL;
			Temp |= I2Cconfig->I2C_Slave_Addres.Secondary_Slave_Address << I2C_OAR2_ADD2_Pos ;
			I2Cx->OAR2 = Temp ;
		}

		Temp = 0;
		Temp |= I2Cconfig->I2C_Slave_Addres.Primary_Slave_Address <<1 ;
		Temp |= I2Cconfig->I2C_Slave_Addres.I2C_Slave_Address_mode ;
		I2Cx->OAR1 = Temp ;


	}
	else
	{
		// Not supported (SMBus)
	}


	// Slave mode check if Callback Function  not equal Null!
	if(I2Cconfig->P_Slave_EV_CallBack != NULL)
    {
		I2Cx->CR2 |= I2C_CR2_ITBUFEN ;
		I2Cx->CR2 |= I2C_CR2_ITERREN ;
		I2Cx->CR2 |= I2C_CR2_ITEVTEN ;


		// Enable NVIC
		if(I2Cx == I2C1)
		{
			NVIC_IQR32_ER_I2C1_Enable();
			NVIC_IQR31_EV_I2C1_Enable();

		}
		else if(I2Cx == I2C2)
		{

			NVIC_IQR33_EV_I2C2_Enable();
			NVIC_IQR34_ER_I2C2_Enable();
		}

		//Clear Status Register
		I2Cx->SR1 = 0 ;
		I2Cx->SR2 = 0 ;

    }

// Enable Peripherals
I2Cx->CR1 |= (I2C_CR1_PE);

}
void MCAL_I2C_Deinit(I2C_typeDef *I2Cx)
{

	if(I2Cx == I2C1)
	{
		NVIC_IQR32_ER_I2C1_Disable();
		NVIC_IQR31_EV_I2C1_Disable();
		RCC_I2C1_Reset();


	}
	else if(I2Cx == I2C2)
	{

		NVIC_IQR33_EV_I2C2_Disable();
		NVIC_IQR34_ER_I2C2_Disable();
		RCC_I2C2_Reset();
	}


}
void MACL_I2C_GPIO_Set_PINs(I2C_typeDef *I2Cx)
{

	GPIO_configPin_t Pin_Config;


	if(I2Cx == I2C1)
	{
		// Port B Pin 6 SCLK
		// Port B pin 7 SDA
		Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD;
		Pin_Config.GPIO_PinNumber = GPIO_PIN6 ;
		Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &Pin_Config);

		Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD;
		Pin_Config.GPIO_PinNumber = GPIO_PIN7 ;
		Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &Pin_Config);



	}
	else if(I2Cx == I2C2)
	{

		// Port B Pin 10 SCLK
		// Port B pin 11 SDA
		Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD;
		Pin_Config.GPIO_PinNumber = GPIO_PIN10 ;
		Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &Pin_Config);

		Pin_Config.GPIO_Mode = GPIO_MODE_OUTPUT_AF_OD;
		Pin_Config.GPIO_PinNumber = GPIO_PIN11 ;
		Pin_Config.GPIO_Output_Speed = GPIO_SPEED_10M;
		MCAL_GPIO_Init(GPIOB, &Pin_Config);

	}

}

void MCAL_I2C_Master_RX( I2C_typeDef *I2Cx,uint16_t DecADD, uint8_t *DataOut, uint32_t DataLen, Stop_condition stop, Repeate_Start start   )
{
	uint8_t index =  I2Cx == I2C1 ? I2C1_INDEX : I2C2_INDEX ;
	int i = 0 ;
	         //Generate Start bit
		    I2C_GenerateStart(I2Cx,EnableState, start);

		    // wait EV5
		    // EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
			while( !GetFlag_Status (I2Cx, EV5 ) );

			//Send address
			I2C_SendAddrss(I2Cx, DecADD, I2C_Direction_Receive);

			//wait EV6
			//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
			while( !GetFlag_Status (I2Cx, EV6 ) );
            //Enable ACK
			 I2C_ACKConfig(I2Cx, EnableState);
			if(DataLen)
			{
				for(i = DataLen; i>1; i--)
				{
					while( !GetFlag_Status (I2Cx, EV7 ) );

					*DataOut = I2Cx->DR ;

					DataOut ++ ;

				}

				//NACK
				I2C_ACKConfig(I2Cx, DisableState);
			}



			if(stop == withStop)
			{
				I2C_GenerateStopConditon(I2Cx, EnableState);
			}

			//re-enable ACK
			if(GVI2Cconfig[index].I2C_ACK_Control == I2C_ACK_Control_Enable)
				I2C_ACKConfig(I2Cx, EnableState);
			else
				I2C_ACKConfig(I2Cx, DisableState);


}

void MCAL_I2C_Master_TX( I2C_typeDef *I2Cx, uint16_t DecADD, uint8_t *DataOut, uint32_t DataLen, Stop_condition stop, Repeate_Start start    )
{
         int i = 0 ;
         //Generate Start bit
	    I2C_GenerateStart(I2Cx,EnableState, start);

	    // wait EV5
	    // EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
		while( !GetFlag_Status (I2Cx, EV5 ) );

		//Send address
		I2C_SendAddrss(I2Cx, DecADD, I2C_Direction_Transmit);

		//wait EV6
		//EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2
		while( !GetFlag_Status (I2Cx, EV6 ) );

		//wait flag MASTER_BYTE_TRANSMITING
		while( !GetFlag_Status (I2Cx, MASTER_BYTE_TRANSMITING ) );

		for(i = 0; i<DataLen; i++)
		{
			I2Cx->DR = DataOut[i] ;
			//EV8: TxE=1, shift register not empty, d. ata register empty, cleared by writing DR register
			while( !GetFlag_Status (I2Cx, EV8 ) );
		}

		//while( !GetFlag_Status (I2Cx, EV8_2 ) );


		// stop condition
		if(stop == withStop)
		{
			I2C_GenerateStopConditon(I2Cx, EnableState);
		}


}


void I2C_GenerateStart(I2C_typeDef *I2Cx,FuntinalState NEWState, Repeate_Start start )
{
	if(start != repeateStart)
	{
		//Check Busy Bus
		while( GetFlag_Status (I2Cx, I2C_FLAG_Busy ) );

	}

	// check start condition

	if(NEWState != DisableState)
	{

	   I2Cx->CR1 |= I2C_CR1_START ;
	}
	else
	{
		I2Cx->CR1 &= ~(I2C_CR1_START) ;
	}
}




Flag_Status GetFlag_Status(I2C_typeDef *I2Cx, Status flag)
{
	volatile uint32_t dummyData;
	uint32_t flag1 = 0, flag2 = 0, lastEvent = 0;

	Flag_Status bitState = Reset ;
	switch(flag){


	case I2C_FLAG_Busy:
	{
		if( (I2Cx->SR2) & I2C_SR2_BUSY)
			bitState  = Set;
		else
			bitState = Reset ;

		break;
	}


	case EV5:
	{
		if( (I2Cx->SR1) & I2C_SR1_SB)
			bitState  = Set;
		else
			bitState = Reset ;

		break;
	}

	case EV6:
	{
		if( (I2Cx->SR1) & I2C_SR1_ADDR)
			bitState  = Set;
		else
			bitState = Reset ;

		//dummyData = I2Cx->SR2 ;
		break;
	}


	case MASTER_BYTE_TRANSMITING:
	{

		flag1 = I2Cx->SR1;
		flag2 = I2Cx->SR2;
		flag2 = flag2<<16;
		lastEvent = (flag1 | flag2) &((uint32_t)0x000FFFFFF) ;

		if( (lastEvent & flag ) == flag )
		{
			bitState  = Set;
		}
		else
		{
			bitState = Reset ;
		}
		break;

	}
	case EV8_1:
	case EV8:
	{
		if( (I2Cx->SR1) & I2C_SR1_TXE)
			bitState  = Set;
		else
			bitState = Reset ;

		//dummyData = I2Cx->SR2 ;
		break;
	}

	case EV7:
	{
		if( (I2Cx->SR1) & I2C_SR1_RXNE)
			bitState  = Set;
		else
			bitState = Reset ;

		//dummyData = I2Cx->SR2 ;
		break;
	}


	}



	return bitState ;
}

void I2C_SendAddrss(I2C_typeDef *I2Cx, uint16_t Address, I2C_Direction direct)
{
	Address = (Address<<1) ;

	if(direct != I2C_Direction_Transmit)
	{
		Address |= 1<<0 ;

	}
	else
	{
		Address &= ~(1<<0)  ;
	}

	I2Cx->DR = Address ;
}


void I2C_GenerateStopConditon(I2C_typeDef *I2Cx , FuntinalState NEWState)
{
     if( NEWState != DisableState )
     {
         I2Cx->CR1 |= I2C_CR1_STOP  ;
     }
     else
     {
    	 I2Cx->CR1 &= ~(I2C_CR1_STOP)  ;
     }
}


void MCAL_I2C_SlaveSend(I2C_typeDef *I2Cx, uint8_t data)
{
	I2Cx->DR = data  ;
}
uint8_t MCAL_I2C_SlaveReceive(I2C_typeDef *I2Cx)
{
	return (uint8_t) I2Cx->DR ;
}

void I2C_ACKConfig(I2C_typeDef *I2Cx, FuntinalState State)
{
	if(State == EnableState)
	{
		/* Enable Automatic ACK */
		I2Cx->CR1 |= (I2C_CR1_ACK);
	}
	else
	{
		/* Disable Automatic ACK */
		I2Cx->CR1 &= ~(I2C_CR1_ACK);
	}
}
