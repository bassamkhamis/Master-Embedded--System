/*
 * STM32F103x8.h
 *
 *  Created on: Apr 28, 2022
 *      Author: bassa
 */

#ifndef INC_STM32F103X8_H_
#define INC_STM32F103X8_H_

//-----------------------------
//Includes
//-----------------------------
#include <stdint.h>
#include<stdlib.h>

//-----------------------------
//Base addresses for Memories
//-----------------------------


#define FLASH_MEMORY_BASE_ADRRESS                  0x08000000UL
#define SRAM_MEMORY_BASE_ADDRESS                   0x20000000UL
#define PERIPHRALS_BASE_ADDRESS                    0x40000000UL
#define CORTEX_M3_PERIPHRALS_BASE_ADDRESS          0xE0000000UL
#define SYSTEM_MEMORY_BASE_ADDRESS                 0x1FFFF000UL
#define NVIC_BASE_ADDRESS                          0xE000E100UL




//-----------------------------
//Base addresses for BUS Peripherals

//-----------------------------
// Base address of AHB peripherals
//-----------------------------
#define RCC_BASE_ADDRESS                          0x40021000UL
//-----------------------------
// Base address of APB1 peripherals
//-----------------------------
#define UART2_BASE_ADDRESS                       0x40004400UL
#define UART3_BASE_ADDRESS                       0x40004800UL
#define SPI2_BASE_ADDRESS                        0x40003800UL
#define I2C1_BASE_ADDRESS                         0x40005400UL
#define I2C2_BASE_ADDRESS                         0x40005800UL

//-----------------------------
// Base address of APB2 peripherals
//-----------------------------
#define GPIOA_BASE_ADDRESS                       0x40010800UL
#define GPIOB_BASE_ADDRESS                       0x40010C00UL
#define GPIOC_BASE_ADDRESS                       0x40011000UL
#define GPIOD_BASE_ADDRESS                       0x40011400UL
#define GPIOE_BASE_ADDRESS                       0x40011800UL
#define GPIOF_BASE_ADDRESS                       0x40011C00UL
#define EXTI_BASE_ADDRESS                        0x40010400UL
#define AFIO_BASE_ADDRESS                        0x40010000UL
#define UART1_BASE_ADDRESS                       0x40013800UL
#define SPI1_BASE_ADDRESS                        0x40013000UL



/*Notes: PORT A and B are fully pins included
 *        C and B partially pins included
 *        E and F Not included
 *        (in package LQFP 48)
 */
//-------------------------------------------
//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:GPIO
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct{


	volatile uint32_t CRL;
	volatile uint32_t CRH;
	volatile uint32_t IDR;
	volatile uint32_t ODR;
	volatile uint32_t BSRR;
	volatile uint32_t BRR;
	volatile uint32_t LCKR;


}GPIOx_typeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:AFIO
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t EVCR;
	volatile uint32_t MAPR;
	volatile uint32_t EXTICR[4];
//	volatile uint32_t EXTICR2;
//	volatile uint32_t EXTICR3;
//	volatile uint32_t EXTICR4;
	volatile uint32_t RESERVED0;
	volatile uint32_t MAPR2;


}AFIO_typeDef;


//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:EXTI
//-*-*-*-*-*-*-*-*-*-*-*

typedef struct {

	volatile uint32_t IMR;
	volatile uint32_t EMR;
	volatile uint32_t RTSR;
	volatile uint32_t FTSR;
	volatile uint32_t SWIER;
	volatile uint32_t PR;

}EXTI_typeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:RCC
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t CR;
	volatile uint32_t CFGR;
	volatile uint32_t CIR;
    volatile uint32_t APB2RSTR;
    volatile uint32_t APB1RSTR;
    volatile uint32_t AHBENR;
    volatile uint32_t APB2ENR;
    volatile uint32_t APB1ENR;
    volatile uint32_t BDCR;
    volatile uint32_t CSR;
    volatile uint32_t AHBSTR;
    volatile uint32_t CFGR2;


}RCC_typeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:USART
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t BRR;
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t CR3;
	volatile uint32_t GTPR;

}USART_typeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:SPI
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t SR;
	volatile uint32_t DR;
	volatile uint32_t CRCPR;
	volatile uint32_t RXCRCR;
	volatile uint32_t TXCRCR;
	volatile uint32_t I2SCFGR;

}SPI_typeDef;

//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral register:I2C
//-*-*-*-*-*-*-*-*-*-*-*
typedef struct {
	volatile uint32_t CR1;
	volatile uint32_t CR2;
	volatile uint32_t OAR1;
	volatile uint32_t OAR2;
	volatile uint32_t DR;
	volatile uint32_t SR1;
	volatile uint32_t SR2;
	volatile uint32_t CCR;
	volatile uint32_t TRISE;


}I2C_typeDef;

//-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-



//-*-*-*-*-*-*-*-*-*-*-*-
//Peripheral Instants:
//-*-*-*-*-*-*-*-*-*-*-*
#define GPIOA         ((GPIOx_typeDef*)GPIOA_BASE_ADDRESS)
#define GPIOB         ((GPIOx_typeDef*)GPIOB_BASE_ADDRESS)
#define GPIOC         ((GPIOx_typeDef*)GPIOC_BASE_ADDRESS)
#define GPIOD         ((GPIOx_typeDef*)GPIOD_BASE_ADDRESS)
#define GPIOE         ((GPIOx_typeDef*)GPIOE_BASE_ADDRESS)
#define RCC           ((RCC_typeDef*)RCC_BASE_ADDRESS)
#define EXTI          ((EXTI_typeDef*)EXTI_BASE_ADDRESS)
#define AFIO          ((AFIO_typeDef*)AFIO_BASE_ADDRESS)
#define USART1        ((USART_typeDef*)UART1_BASE_ADDRESS)
#define USART2        ((USART_typeDef*)UART2_BASE_ADDRESS)
#define USART3        ((USART_typeDef*)UART3_BASE_ADDRESS)
#define SPI1          ((SPI_typeDef*)SPI1_BASE_ADDRESS)
#define SPI2          ((SPI_typeDef*)SPI2_BASE_ADDRESS)
#define I2C1          ((I2C_typeDef*)I2C1_BASE_ADDRESS)
#define I2C2          ((I2C_typeDef*)I2C2_BASE_ADDRESS)
//-----------------------
// Internal Peripherals
//----------------------

//NVIC
#define NVIC_ISER0              *((volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x00))
#define NVIC_ISER1              *((volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x04))
#define NVIC_ISER2              *((volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x08))
#define NVIC_ISER3              *((volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x0c))

#define NVIC_ICER0              *((volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x80))
#define NVIC_ICER1              *((volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x84))
#define NVIC_ICER2              *((volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x88))
#define NVIC_ICER3              *((volatile uint32_t *)(NVIC_BASE_ADDRESS + 0x8c))



//-*-*-*-*-*-*-*-*-*-*-*-
//clock enable Macros:
//-*-*-*-*-*-*-*-*-*-*-*
#define RCC_GPIOA_CLK_EN()    (RCC->APB2ENR |= 1<<2)
#define RCC_GPIOB_CLK_EN()    (RCC->APB2ENR |= 1<<3)
#define RCC_GPIOC_CLK_EN()    (RCC->APB2ENR |= 1<<4)
#define RCC_GPIOD_CLK_EN()    (RCC->APB2ENR |= 1<<5)
#define RCC_GPIOE_CLK_EN()    (RCC->APB2ENR |= 1<<6)

// enable clock USART

#define RCC_USART1_CLK_EN()    (RCC->APB2ENR |= 1<<14)
#define RCC_USART2_CLK_EN()    (RCC->APB1ENR |= 1<<17)
#define RCC_USART3_CLK_EN()    (RCC->APB1ENR |= 1<<18)
//disable clock USART
#define RCC_USART1_Reset()    (RCC->APB2RSTR |= 1<<14)
#define RCC_USART2_Reset()    (RCC->APB1RSTR  |= 1<<17)
#define RCC_USART3_Reset()    (RCC->APB1RSTR  |= 1<<18)

// Enable clock SPI
#define RCC_SPI1_CLK_EN()     (RCC->APB2ENR |= 1<<12)
#define RCC_SPI2_CLK_EN()     (RCC->APB1ENR |= 1<<14)

// disable clock SPI
#define RCC_SPI1_Reset()      (RCC->APB2RSTR |= 1<<12)
#define RCC_SPI2_Reset()      (RCC->APB1RSTR  |= 1<<14)


// Enable clock I2C
#define RCC_I2C1_CLK_EN()     (RCC->APB1ENR |= 1<<21)
#define RCC_I2C2_CLK_EN()     (RCC->APB1ENR |= 1<<22)

// disable clock SPI
#define RCC_I2C1_Reset()      (RCC->APB1RSTR |= 1<<21)
#define RCC_I2C2_Reset()      (RCC->APB1RSTR |= 1<<22)


//-*-*-*-*-*-*-*-*-*-*-*-
//Generic Macros:
//-*-*-*-*-*-*-*-*-*-*-*

//---------------------
//@refEXTI%_IQR_define
//---------------------

#define EXTI0_IQR            6
#define EXTI1_IQR            7
#define EXTI2_IQR            8
#define EXTI3_IQR            9
#define EXTI4_IQR            10
#define EXTI5_IQR            23
#define EXTI6_IQR            23
#define EXTI7_IQR            23
#define EXTI8_IQR            23
#define EXTI9_IQR            23
#define EXTI10_IQR           40
#define EXTI11_IQR           40
#define EXTI12_IQR           40
#define EXTI13_IQR           40
#define EXTI14_IQR           40
#define EXTI15_IQR           40
#define USART1_IQR           37
#define USART2_IQR           38
#define USART3_IQR           39

#define SPI1_IQR             35
#define SPI2_IQR             36

#define I2C1_EV_IQR             31
#define I2C1_ER_IQR             32
#define I2C2_EV_IQR             33
#define I2C2_ER_IQR             34

//----------------------
// NVIC IQR Enable
//----------------------

//Enable macros
#define NVIC_IQR6_EXTI0_Enable()                  NVIC_ISER0|= 1<6;
#define NVIC_IQR7_EXTI1_Enable()                  NVIC_ISER0|= 1<<7;
#define NVIC_IQR8_EXTI2_Enable()                  NVIC_ISER0|= 1<<8;
#define NVIC_IQR9_EXTI3_Enable()                  NVIC_ISER0|= 1<<9;
#define NVIC_IQR10_EXTI4_Enable()                 NVIC_ISER0|= 1<<10;

#define NVIC_IQR23_EXTI5_9_Enable()               NVIC_ISER0|= 1<<23;
#define NVIC_IQR40_EXTI10_15_Enable()             NVIC_ISER1|= 1<<8; //40-32

//USART
#define NVIC_IQR37_USART1_Enable()             NVIC_ISER1|= 1<<(USART1_IQR -32); //37-32 = 5
#define NVIC_IQR38_USART2_Enable()             NVIC_ISER1|= 1<<(USART2_IQR -32); //38-32 = 6
#define NVIC_IQR39_USART3_Enable()             NVIC_ISER1|= 1<<(USART3_IQR -32); //39-32 = 7

//SPI
#define NVIC_IQR35_SPI1_Enable()             NVIC_ISER1|= 1<<(SPI1_IQR -32); //35-32 = 3
#define NVIC_IQR36_SPI2_Enable()             NVIC_ISER1|= 1<<(SPI2_IQR -32); //36-32 = 4
//I2C
#define NVIC_IQR31_EV_I2C1_Enable()             NVIC_ISER0|= 1<<(I2C1_EV_IQR); //31
#define NVIC_IQR32_ER_I2C1_Enable()             NVIC_ISER1|= 1<<(I2C1_ER_IQR -32); //32-32 = 0
#define NVIC_IQR33_EV_I2C2_Enable()             NVIC_ISER1|= 1<<(I2C2_EV_IQR -32); //33-32 = 1
#define NVIC_IQR34_ER_I2C2_Enable()             NVIC_ISER1|= 1<<(I2C2_ER_IQR -32); //34-32 = 2


//Disable Macros

#define NVIC_IQR6_EXTI0_Disable()                  NVIC_ICER0|= 1<6;
#define NVIC_IQR7_EXTI1_Disable()                  NVIC_ICER0|= 1<<7;
#define NVIC_IQR8_EXTI2_Disable()                  NVIC_ICER0|= 1<<8;
#define NVIC_IQR9_EXTI3_Disable()                  NVIC_ICER0|= 1<<9;
#define NVIC_IQR10_EXTI4_Disable()                 NVIC_ICER0|= 1<<10;

#define NVIC_IQR23_EXTI5_9_Disable()               NVIC_ICER0|= 1<<23;
#define NVIC_IQR40_EXTI10_15_Disable()             NVIC_ICER1|= 1<<8; //40-32
//USART
#define NVIC_IQR37_USART1_Disable()                NVIC_ICER1|= 1<<(USART1_IQR -32); //37-32 = 5
#define NVIC_IQR38_USART2_Disable()                NVIC_ICER1|= 1<<(USART2_IQR -32); //38-32 = 6
#define NVIC_IQR39_USART3_Disable()                NVIC_ICER1|= 1<<(USART3_IQR -32); //39-32 = 7
// SPI

#define NVIC_IQR35_SPI1_Disable()                  NVIC_ICER1|= 1<<(SPI1_IQR -32); //37-32 = 3
#define NVIC_IQR36_SPI2_Disable()                  NVIC_ICER1|= 1<<(SPI2_IQR -32); //37-32 = 4

#define NVIC_IQR31_EV_I2C1_Disable()               NVIC_ICER0|= 1<<(I2C1_EV_IQR); //31
#define NVIC_IQR32_ER_I2C1_Disable()               NVIC_ICER1|= 1<<(SPI2_IQR -32); //32-32 = 0
#define NVIC_IQR33_EV_I2C2_Disable()               NVIC_ICER1|= 1<<(SPI1_IQR -32); //33-32 = 1
#define NVIC_IQR34_ER_I2C2_Disable()               NVIC_ICER1|= 1<<(SPI2_IQR -32); //34-32 = 2


/********************************************************/
/********************************************************/
/********************************************************/
/*******************  Bit definition  ********************/
/********************************************************/
/********************************************************/



/*******************  Bit definition for I2C_CR1 register  ********************/
#define I2C_CR1_PE_Pos                      (0U)
#define I2C_CR1_PE_Msk                      (0x1UL << I2C_CR1_PE_Pos)           /*!< 0x00000001 */
#define I2C_CR1_PE                          I2C_CR1_PE_Msk                     /*!< Peripheral Enable */
#define I2C_CR1_SMBUS_Pos                   (1U)
#define I2C_CR1_SMBUS_Msk                   (0x1UL << I2C_CR1_SMBUS_Pos)        /*!< 0x00000002 */
#define I2C_CR1_SMBUS                       I2C_CR1_SMBUS_Msk                  /*!< SMBus Mode */
#define I2C_CR1_SMBTYPE_Pos                 (3U)
#define I2C_CR1_SMBTYPE_Msk                 (0x1UL << I2C_CR1_SMBTYPE_Pos)      /*!< 0x00000008 */
#define I2C_CR1_SMBTYPE                     I2C_CR1_SMBTYPE_Msk                /*!< SMBus Type */
#define I2C_CR1_ENARP_Pos                   (4U)
#define I2C_CR1_ENARP_Msk                   (0x1UL << I2C_CR1_ENARP_Pos)        /*!< 0x00000010 */
#define I2C_CR1_ENARP                       I2C_CR1_ENARP_Msk                  /*!< ARP Enable */
#define I2C_CR1_ENPEC_Pos                   (5U)
#define I2C_CR1_ENPEC_Msk                   (0x1UL << I2C_CR1_ENPEC_Pos)        /*!< 0x00000020 */
#define I2C_CR1_ENPEC                       I2C_CR1_ENPEC_Msk                  /*!< PEC Enable */
#define I2C_CR1_ENGC_Pos                    (6U)
#define I2C_CR1_ENGC_Msk                    (0x1UL << I2C_CR1_ENGC_Pos)         /*!< 0x00000040 */
#define I2C_CR1_ENGC                        I2C_CR1_ENGC_Msk                   /*!< General Call Enable */
#define I2C_CR1_NOSTRETCH_Pos               (7U)
#define I2C_CR1_NOSTRETCH_Msk               (0x1UL << I2C_CR1_NOSTRETCH_Pos)    /*!< 0x00000080 */
#define I2C_CR1_NOSTRETCH                   I2C_CR1_NOSTRETCH_Msk              /*!< Clock Stretching Disable (Slave mode) */
#define I2C_CR1_START_Pos                   (8U)
#define I2C_CR1_START_Msk                   (0x1UL << I2C_CR1_START_Pos)        /*!< 0x00000100 */
#define I2C_CR1_START                       I2C_CR1_START_Msk                  /*!< Start Generation */
#define I2C_CR1_STOP_Pos                    (9U)
#define I2C_CR1_STOP_Msk                    (0x1UL << I2C_CR1_STOP_Pos)         /*!< 0x00000200 */
#define I2C_CR1_STOP                        I2C_CR1_STOP_Msk                   /*!< Stop Generation */
#define I2C_CR1_ACK_Pos                     (10U)
#define I2C_CR1_ACK_Msk                     (0x1UL << I2C_CR1_ACK_Pos)          /*!< 0x00000400 */
#define I2C_CR1_ACK                         I2C_CR1_ACK_Msk                    /*!< Acknowledge Enable */
#define I2C_CR1_POS_Pos                     (11U)
#define I2C_CR1_POS_Msk                     (0x1UL << I2C_CR1_POS_Pos)          /*!< 0x00000800 */
#define I2C_CR1_POS                         I2C_CR1_POS_Msk                    /*!< Acknowledge/PEC Position (for data reception) */
#define I2C_CR1_PEC_Pos                     (12U)
#define I2C_CR1_PEC_Msk                     (0x1UL << I2C_CR1_PEC_Pos)          /*!< 0x00001000 */
#define I2C_CR1_PEC                         I2C_CR1_PEC_Msk                    /*!< Packet Error Checking */
#define I2C_CR1_ALERT_Pos                   (13U)
#define I2C_CR1_ALERT_Msk                   (0x1UL << I2C_CR1_ALERT_Pos)        /*!< 0x00002000 */
#define I2C_CR1_ALERT                       I2C_CR1_ALERT_Msk                  /*!< SMBus Alert */
#define I2C_CR1_SWRST_Pos                   (15U)
#define I2C_CR1_SWRST_Msk                   (0x1UL << I2C_CR1_SWRST_Pos)        /*!< 0x00008000 */
#define I2C_CR1_SWRST                       I2C_CR1_SWRST_Msk                  /*!< Software Reset */
/*******************  Bit definition for I2C_CR2 register  ********************/
#define I2C_CR2_FREQ_Pos                    (0U)
#define I2C_CR2_FREQ_Msk                    (0x3FUL << I2C_CR2_FREQ_Pos)        /*!< 0x0000003F */
#define I2C_CR2_FREQ                        I2C_CR2_FREQ_Msk                   /*!< FREQ[5:0] bits (Peripheral Clock Frequency) */
#define I2C_CR2_ITERREN_Pos                 (8U)
#define I2C_CR2_ITERREN_Msk                 (0x1UL << I2C_CR2_ITERREN_Pos)      /*!< 0x00000100 */
#define I2C_CR2_ITERREN                     I2C_CR2_ITERREN_Msk                /*!< Error Interrupt Enable */
#define I2C_CR2_ITEVTEN_Pos                 (9U)
#define I2C_CR2_ITEVTEN_Msk                 (0x1UL << I2C_CR2_ITEVTEN_Pos)      /*!< 0x00000200 */
#define I2C_CR2_ITEVTEN                     I2C_CR2_ITEVTEN_Msk                /*!< Event Interrupt Enable */
#define I2C_CR2_ITBUFEN_Pos                 (10U)
#define I2C_CR2_ITBUFEN_Msk                 (0x1UL << I2C_CR2_ITBUFEN_Pos)      /*!< 0x00000400 */
#define I2C_CR2_ITBUFEN                     I2C_CR2_ITBUFEN_Msk                /*!< Buffer Interrupt Enable */
#define I2C_CR2_DMAEN_Pos                   (11U)
#define I2C_CR2_DMAEN_Msk                   (0x1UL << I2C_CR2_DMAEN_Pos)        /*!< 0x00000800 */
#define I2C_CR2_DMAEN                       I2C_CR2_DMAEN_Msk                  /*!< DMA Requests Enable */
#define I2C_CR2_LAST_Pos                    (12U)
#define I2C_CR2_LAST_Msk                    (0x1UL << I2C_CR2_LAST_Pos)         /*!< 0x00001000 */
#define I2C_CR2_LAST                        I2C_CR2_LAST_Msk                   /*!< DMA Last Transfer */
/*******************  Bit definition for I2C_OAR2 register  *******************/
#define I2C_OAR2_ENDUAL_Pos                 (0U)
#define I2C_OAR2_ENDUAL_Msk                 (0x1UL << I2C_OAR2_ENDUAL_Pos)      /*!< 0x00000001 */
#define I2C_OAR2_ENDUAL                     I2C_OAR2_ENDUAL_Msk                /*!< Dual addressing mode enable */
#define I2C_OAR2_ADD2_Pos                   (1U)
/*******************  Bit definition for I2C_SR1 register  ********************/
#define I2C_SR1_SB_Pos                      (0U)
#define I2C_SR1_SB_Msk                      (0x1UL << I2C_SR1_SB_Pos)           /*!< 0x00000001 */
#define I2C_SR1_SB                          I2C_SR1_SB_Msk                     /*!< Start Bit (Master mode) */
#define I2C_SR1_ADDR_Pos                    (1U)
#define I2C_SR1_ADDR_Msk                    (0x1UL << I2C_SR1_ADDR_Pos)         /*!< 0x00000002 */
#define I2C_SR1_ADDR                        I2C_SR1_ADDR_Msk                   /*!< Address sent (master mode)/matched (slave mode) */
#define I2C_SR1_BTF_Pos                     (2U)
#define I2C_SR1_BTF_Msk                     (0x1UL << I2C_SR1_BTF_Pos)          /*!< 0x00000004 */
#define I2C_SR1_BTF                         I2C_SR1_BTF_Msk                    /*!< Byte Transfer Finished */
#define I2C_SR1_ADD10_Pos                   (3U)
#define I2C_SR1_ADD10_Msk                   (0x1UL << I2C_SR1_ADD10_Pos)        /*!< 0x00000008 */
#define I2C_SR1_ADD10                       I2C_SR1_ADD10_Msk                  /*!< 10-bit header sent (Master mode) */
#define I2C_SR1_STOPF_Pos                   (4U)
#define I2C_SR1_STOPF_Msk                   (0x1UL << I2C_SR1_STOPF_Pos)        /*!< 0x00000010 */
#define I2C_SR1_STOPF                       I2C_SR1_STOPF_Msk                  /*!< Stop detection (Slave mode) */
#define I2C_SR1_RXNE_Pos                    (6U)
#define I2C_SR1_RXNE_Msk                    (0x1UL << I2C_SR1_RXNE_Pos)         /*!< 0x00000040 */
#define I2C_SR1_RXNE                        I2C_SR1_RXNE_Msk                   /*!< Data Register not Empty (receivers) */
#define I2C_SR1_TXE_Pos                     (7U)
#define I2C_SR1_TXE_Msk                     (0x1UL << I2C_SR1_TXE_Pos)          /*!< 0x00000080 */
#define I2C_SR1_TXE                         I2C_SR1_TXE_Msk                    /*!< Data Register Empty (transmitters) */
#define I2C_SR1_BERR_Pos                    (8U)
#define I2C_SR1_BERR_Msk                    (0x1UL << I2C_SR1_BERR_Pos)         /*!< 0x00000100 */
#define I2C_SR1_BERR                        I2C_SR1_BERR_Msk                   /*!< Bus Error */
#define I2C_SR1_ARLO_Pos                    (9U)
#define I2C_SR1_ARLO_Msk                    (0x1UL << I2C_SR1_ARLO_Pos)         /*!< 0x00000200 */
#define I2C_SR1_ARLO                        I2C_SR1_ARLO_Msk                   /*!< Arbitration Lost (master mode) */
#define I2C_SR1_AF_Pos                      (10U)
#define I2C_SR1_AF_Msk                      (0x1UL << I2C_SR1_AF_Pos)           /*!< 0x00000400 */
#define I2C_SR1_AF                          I2C_SR1_AF_Msk                     /*!< Acknowledge Failure */
#define I2C_SR1_OVR_Pos                     (11U)
#define I2C_SR1_OVR_Msk                     (0x1UL << I2C_SR1_OVR_Pos)          /*!< 0x00000800 */
#define I2C_SR1_OVR                         I2C_SR1_OVR_Msk                    /*!< Overrun/Underrun */
#define I2C_SR1_PECERR_Pos                  (12U)
#define I2C_SR1_PECERR_Msk                  (0x1UL << I2C_SR1_PECERR_Pos)       /*!< 0x00001000 */
#define I2C_SR1_PECERR                      I2C_SR1_PECERR_Msk                 /*!< PEC Error in reception */
#define I2C_SR1_TIMEOUT_Pos                 (14U)
#define I2C_SR1_TIMEOUT_Msk                 (0x1UL << I2C_SR1_TIMEOUT_Pos)      /*!< 0x00004000 */
#define I2C_SR1_TIMEOUT                     I2C_SR1_TIMEOUT_Msk                /*!< Timeout or Tlow Error */
#define I2C_SR1_SMBALERT_Pos                (15U)
#define I2C_SR1_SMBALERT_Msk                (0x1UL << I2C_SR1_SMBALERT_Pos)     /*!< 0x00008000 */
#define I2C_SR1_SMBALERT                    I2C_SR1_SMBALERT_Msk               /*!< SMBus Alert */

/*******************  Bit definition for I2C_SR2 register  ********************/
#define I2C_SR2_MSL_Pos                     (0U)
#define I2C_SR2_MSL_Msk                     (0x1UL << I2C_SR2_MSL_Pos)          /*!< 0x00000001 */
#define I2C_SR2_MSL                         I2C_SR2_MSL_Msk                    /*!< Master/Slave */
#define I2C_SR2_BUSY_Pos                    (1U)
#define I2C_SR2_BUSY_Msk                    (0x1UL << I2C_SR2_BUSY_Pos)         /*!< 0x00000002 */
#define I2C_SR2_BUSY                        I2C_SR2_BUSY_Msk                   /*!< Bus Busy */
#define I2C_SR2_TRA_Pos                     (2U)
#define I2C_SR2_TRA_Msk                     (0x1UL << I2C_SR2_TRA_Pos)          /*!< 0x00000004 */
#define I2C_SR2_TRA                         I2C_SR2_TRA_Msk                    /*!< Transmitter/Receiver */
#define I2C_SR2_GENCALL_Pos                 (4U)
#define I2C_SR2_GENCALL_Msk                 (0x1UL << I2C_SR2_GENCALL_Pos)      /*!< 0x00000010 */
#define I2C_SR2_GENCALL                     I2C_SR2_GENCALL_Msk                /*!< General Call Address (Slave mode) */
#define I2C_SR2_SMBDEFAULT_Pos              (5U)
#define I2C_SR2_SMBDEFAULT_Msk              (0x1UL << I2C_SR2_SMBDEFAULT_Pos)   /*!< 0x00000020 */
#define I2C_SR2_SMBDEFAULT                  I2C_SR2_SMBDEFAULT_Msk             /*!< SMBus Device Default Address (Slave mode) */
#define I2C_SR2_SMBHOST_Pos                 (6U)
#define I2C_SR2_SMBHOST_Msk                 (0x1UL << I2C_SR2_SMBHOST_Pos)      /*!< 0x00000040 */
#define I2C_SR2_SMBHOST                     I2C_SR2_SMBHOST_Msk                /*!< SMBus Host Header (Slave mode) */
#define I2C_SR2_DUALF_Pos                   (7U)
#define I2C_SR2_DUALF_Msk                   (0x1UL << I2C_SR2_DUALF_Pos)        /*!< 0x00000080 */
#define I2C_SR2_DUALF                       I2C_SR2_DUALF_Msk                  /*!< Dual Flag (Slave mode) */
#define I2C_SR2_PEC_Pos                     (8U)
#define I2C_SR2_PEC_Msk                     (0xFFUL << I2C_SR2_PEC_Pos)         /*!< 0x0000FF00 */
#define I2C_SR2_PEC                         I2C_SR2_PEC_Msk                    /*!< Packet Error Checking Register */





#endif /* INC_STM32F103X8_H_ */
