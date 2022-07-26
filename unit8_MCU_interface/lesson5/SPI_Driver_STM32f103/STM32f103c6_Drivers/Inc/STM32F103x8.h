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
#define RCC_SPI1_CLK_EN()    (RCC->APB2ENR |= 1<<12)
#define RCC_SPI2_CLK_EN()    (RCC->APB1ENR |= 1<<14)

// disable clock SPI
#define RCC_SPI1_Reset()    (RCC->APB2RSTR |= 1<<12)
#define RCC_SPI2_Reset()    (RCC->APB1RSTR  |= 1<<14)
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

//Disable Macros

#define NVIC_IQR6_EXTI0_Disable()                  NVIC_ICER0|= 1<6;
#define NVIC_IQR7_EXTI1_Disable()                  NVIC_ICER0|= 1<<7;
#define NVIC_IQR8_EXTI2_Disable()                  NVIC_ICER0|= 1<<8;
#define NVIC_IQR9_EXTI3_Disable()                  NVIC_ICER0|= 1<<9;
#define NVIC_IQR10_EXTI4_Disable()                 NVIC_ICER0|= 1<<10;

#define NVIC_IQR23_EXTI5_9_Disable()               NVIC_ICER0|= 1<<23;
#define NVIC_IQR40_EXTI10_15_Disable()             NVIC_ICER1|= 1<<8; //40-32
//USART
#define NVIC_IQR37_USART1_Disable()             NVIC_ICER1|= 1<<(USART1_IQR -32); //37-32 = 5
#define NVIC_IQR38_USART2_Disable()             NVIC_ICER1|= 1<<(USART2_IQR -32); //38-32 = 6
#define NVIC_IQR39_USART3_Disable()             NVIC_ICER1|= 1<<(USART3_IQR -32); //39-32 = 7
// SPI

#define NVIC_IQR35_SPI1_Disable()             NVIC_ICER1|= 1<<(SPI1_IQR -32); //37-32 = 3
#define NVIC_IQR36_SPI2_Disable()             NVIC_ICER1|= 1<<(SPI2_IQR -32); //37-32 = 4

#endif /* INC_STM32F103X8_H_ */
