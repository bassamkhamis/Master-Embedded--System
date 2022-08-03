/*
 * STM32F103x8_I2C_driver.h
 *
 *  Created on: Jul 31, 2022
 *      Author: bassa
 */

#ifndef INC_STM32F103X8_I2C_DRIVER_H_
#define INC_STM32F103X8_I2C_DRIVER_H_

//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"
#include "STM32F103x8_gpio_driver.h"

//--------------------------------------
//User type definitions (structures)
//--------------------------------------


#define I2C_MASTER_BYTE_TRANSMITING                    ((uint32_t)0x00070080)  //TRA, BUSY, TXE,


typedef enum {

	I2C_Direction_Transmit = 0,
	I2C_Direction_Receive
}I2C_Direction;
typedef enum {

	Reset = 0,
	Set
}Flag_Status;

typedef enum {

	I2C_FLAG_Busy = 0,
	EV5 , //EV5: SB=1, cleared by reading SR1 register followed by writing DR register with Address.
    EV6,  // EV6: ADDR=1, cleared by reading SR1 register followed by reading SR2.
	MASTER_BYTE_TRANSMITING =  ((uint32_t)0x00070080) , //TRA, BUSY, TXE,
	EV8 = 3,
	EV8_1,
	EV7,
}Status;



typedef enum {

	DisableState = 0,
	EnableState
}FuntinalState;


typedef enum{
	withStop,
	WithoutStop

}Stop_condition;

typedef enum{
	start,
	repeateStart

}Repeate_Start;

struct I2C_Slave_Device_Address{

	uint16_t    Enable_DualADD             ;  // Enable 1: Disable 0

	uint16_t    Primary_Slave_Address      ;

	uint16_t    Secondary_Slave_Address    ;

	uint16_t    I2C_Slave_Address_mode     ; // @ ref I2C_Slave_Address_define

};


typedef enum{
	I2C_EV_STOP,
	I2C_ERROR_AF,
	I2C_EV_ADD_MACHEd,
	I2C_EV_DATA_REQ,      //Application must send data
	I2C_EV_DATA_RCV       //Application must Read data


}Slave_State;

typedef struct {


	uint32_t                            I2C_CLOCK          ;     //specifies this parameter @ref I2C_CLOCK_define

	uint32_t                            I2C_Mode           ;     //specifies this parameter @ref I2C_Mode_define

	uint32_t                            stretchClok        ;   //@ ref stretchClok

	struct I2C_Slave_Device_Address     I2C_Slave_Addres   ;

	uint32_t                          I2C_ACK_Control       ; //@ ref I2C_ACK_Control_define

	uint32_t                  General_Call_Adrress_Detection; //@ ref  General_Call_Adrress_Detection_define

	void (*P_Slave_EV_CallBack)(Slave_State state);

}I2C_configtypeDef;

//-----------------------------
//Macros Configuration References
//-----------------------------

//@ref I2C_CLOCK_define

//1• 2 MHz in Sm mode
//Bits 5:0 FREQ[5:0]: Peripheral clock frequency //I2C_CR2 Register
//The FREQ bits must be configured with the APB clock frequency value (I2C peripheral
//connected to APB). The FREQ field is used by the peripheral to generate data setup and
//hold times compliant with the I2C specifications. The minimum allowed frequency is 2 MHz,
//the maximum frequency is limited by the maximum APB frequency and cannot exceed
//50 MHz (peripheral intrinsic maximum limit).
//0b000000: Not allowed
//0b000001: Not allowed
//0b000010: 2 MHz
//...
//0b110010: 50 MHz
//Higher than 0b100100: Not allowed
//2• Configure the clock control //registers CCR[11:0]
// Thigh = CCR*Tpclk1
//3• Configure the rise time registerr (I2C_TRISE) TRISE[5:0]

#define I2C_SCLK_SM_50K                50000
#define I2C_SCLK_SM_100K               100000

#define I2C_SCLK_FM_100K               200000    //Fast mode Not supported yet
#define I2C_SCLK_FM_200K               200000


//Bit 1 SMBUS: SMBus mode
//I2C_CR1
//0: I2C mode
//1: SMBus mode
//@ref I2C_Mode_define

#define I2C_Mode_I2C                   0x0U
#define I2C_Mode_SMBus                 I2C_CR1_SMBUS


//stretchClok_define
//Bit 7 NOSTRETCH: Clock stretching disable (Slave mode)
//This bit is used to disable clock stretching in slave mode when ADDR or BTF flag is set, until
//it is reset by software.
//0: Clock stretching enabled
//1: Clock stretching disabled
#define stretchClok_Enable               (0<<7)                //(I2C_CR1)
#define stretchClok_Disable              I2C_CR1_NOSTRETCH     //(I2C_CR1)

// @ ref I2C_Slave_Address_define
// (I2C_OAR1)
//Bit 15 ADDMODE Addressing mode (slave mode)
//0: 7-bit slave address (10-bit address not acknowledged)
//1: 10-bit slave address (7-bit address not acknowledged)

#define I2C_Slave_Address_7Bits                0x0
#define I2C_Slave_Address_10Bits               (uint16_t)(1<<15)

//@ ref I2C_ACK_Control_define
//(I2C_CR1)
//Bit 10 ACK: Acknowledge enable
//0: No acknowledge returned
//1: Acknowledge returned after a byte is received (matched address or data
#define I2C_ACK_Control_Enable         I2C_CR1_ACK
#define I2C_ACK_Control_Disable        0x00

//@ ref  General_Call_Adrress_Detection_define
//(I2C_CR1)
//Bit 6 ENGC: General call enable
//0: General call disabled. Address 00h is NACKed.
//1: General call enabled. Address 00h is ACKed.

#define General_Call_Adrress_Detection_Enable           0x00
#define General_Call_Adrress_Detection_Disable          I2C_CR1_ENGC


//  Macros

/*
* ===============================================
* APIs Supported by "MCAL SPI DRIVER"
* ===============================================
*/



void MCAL_I2C_Init(I2C_typeDef *I2Cx , I2C_configtypeDef *I2Cconfig);
void MCAL_I2C_Deinit(I2C_typeDef *I2Cx);
void MACL_I2C_GPIO_Set_PINs(I2C_typeDef *I2Cx);
void MCAL_I2C_Master_TX(I2C_typeDef *I2Cx,uint16_t DecADD, uint8_t *DataOut, uint32_t DataLen, Stop_condition stop, Repeate_Start start   );
void MCAL_I2C_Master_RX(I2C_typeDef *I2Cx,uint16_t DecADD, uint8_t *DataOut, uint32_t DataLen, Stop_condition stop, Repeate_Start start   );


//-----------------------------
//----- Generic functions -----
//-----------------------------

void I2C_GenerateStart(I2C_typeDef *I2Cx,FuntinalState NEWState, Repeate_Start start );

Flag_Status GetFlag_Status(I2C_typeDef *I2Cx, Status flag);

void I2C_SendAddrss(I2C_typeDef *I2Cx, uint16_t Address, I2C_Direction direct);

void I2C_GenerateStopConditon(I2C_typeDef *I2Cx , FuntinalState NEWState);


//Master polling mechanism
//Slave interrupt mechanism
void MCAL_I2C_SlaveSend(I2C_typeDef *I2Cx, uint8_t data);
uint8_t MCAL_I2C_SlaveReceive(I2C_typeDef *I2Cx);
void I2C_ACKConfig(I2C_typeDef *I2Cx, FuntinalState State);

#endif /* INC_STM32F103X8_I2C_DRIVER_H_ */
