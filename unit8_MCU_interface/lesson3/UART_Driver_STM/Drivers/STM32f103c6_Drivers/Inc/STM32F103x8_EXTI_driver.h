/*
 * STM32F103x8_EXTI_driver.h
 *
 *  Created on: May 2, 2022
 *      Author: bassam
 */

#ifndef INC_STM32F103X8_EXTI_DRIVER_H_
#define INC_STM32F103X8_EXTI_DRIVER_H_


//-----------------------------
//Includes
//-----------------------------
#include "STM32F103x8.h"
#include "STM32F103x8_gpio_driver.h"
//-----------------------------



//User type definitions (structures)
//-----------------------------


typedef struct {
	uint8_t         EXTR_InputLineNumber ;   //specifies line number of interrupt
										    //@ref EXTI_Number_define

	GPIOx_typeDef * GPIO_PORT            ;  //specifies GPIO PORTx(A,B,C,D)

    uint16_t        GPIO_pin             ;  // specifies the pin number
                                           // the value of this parameter can be find at @ref GPIO_pinNumber_define

    uint8_t         IVT_IQR_number       ;  // specifies IQR number
                                           // the value of this parameter can be find at @refEXTI%_IQR_define

}EXTI_GPIO_Mapping;

typedef struct{

	EXTI_GPIO_Mapping EXTI_pin      ;  //specifies the EXTI line and GPIOx and pin number
	                                  // this parameters can set as @ref EXTI_define

	uint8_t           Trigger       ;  //specifies the interrupt trigger Raising, Falling and Raising or falling
	                                  // This parameters can be set as the @ref Trigger_define

	uint8_t           IQR_Enable    ;  //specifies the Enable or Disable EXTI
                                   	  // This parameters can be set as the @ref IQR_define

    void (* p_EXTIcallback)(void)   ;  //Specifies the function call back
                                      //The parameter can be assign by any function in application layer

}EXTI_pinCofig_t;

//-----------------------------
//Macros Configuration References
//-----------------------------

//---------------------
//@ref EXTI_Number_define
//---------------------

#define EXTI0           0
#define EXTI1           1
#define EXTI2           2
#define EXTI3           3
#define EXTI4           4
#define EXTI5           5
#define EXTI6           6
#define EXTI7           7
#define EXTI8           8
#define EXTI9           9
#define EXTI10          10
#define EXTI11          11
#define EXTI12          12
#define EXTI13          13
#define EXTI14          14
#define EXTI15          15


//---------------------
//@ref EXTI_define
//---------------------

//EXTI0
#define EXTI0PA0                           (EXTI_GPIO_Mapping){EXTI0, GPIOA, GPIO_PIN0, EXTI0_IQR}
#define EXTI0PB0                           (EXTI_GPIO_Mapping){EXTI0, GPIOB, GPIO_PIN0, EXTI0_IQR}
#define EXTI0PC0                           (EXTI_GPIO_Mapping){EXTI0, GPIOC, GPIO_PIN0, EXTI0_IQR}
#define EXTI0PD0                           (EXTI_GPIO_Mapping){EXTI0, GPIOD, GPIO_PIN0, EXTI0_IQR}


//EXTI1
#define EXTI1PA1                           (EXTI_GPIO_Mapping){EXTI1, GPIOA, GPIO_PIN1, EXTI1_IQR}
#define EXTI1PB1                           (EXTI_GPIO_Mapping){EXTI1, GPIOB, GPIO_PIN1, EXTI1_IQR}
#define EXTI1PC1                           (EXTI_GPIO_Mapping){EXTI1, GPIOC, GPIO_PIN1, EXTI1_IQR}
#define EXTI1PD1                           (EXTI_GPIO_Mapping){EXTI1, GPIOD, GPIO_PIN1, EXTI1_IQR}


//EXTI2
#define EXTI2PA2                           (EXTI_GPIO_Mapping){EXTI2, GPIOA, GPIO_PIN2, EXTI2_IQR}
#define EXTI2PB2                           (EXTI_GPIO_Mapping){EXTI2, GPIOB, GPIO_PIN2, EXTI2_IQR}
#define EXTI2PC2                           (EXTI_GPIO_Mapping){EXTI2, GPIOC, GPIO_PIN2, EXTI2_IQR}
#define EXTI2PD2                           (EXTI_GPIO_Mapping){EXTI2, GPIOD, GPIO_PIN2, EXTI2_IQR}


//EXTI3
#define EXTI3PA3                           (EXTI_GPIO_Mapping){EXTI3, GPIOA, GPIO_PIN3, EXTI3_IQR}
#define EXTI3PB3                           (EXTI_GPIO_Mapping){EXTI3, GPIOB, GPIO_PIN3, EXTI3_IQR}
#define EXTI3PC3                           (EXTI_GPIO_Mapping){EXTI3, GPIOC, GPIO_PIN3, EXTI3_IQR}
#define EXTI3PD3                           (EXTI_GPIO_Mapping){EXTI3, GPIOD, GPIO_PIN3, EXTI3_IQR}


//EXTI4
#define EXTI4PA4                           (EXTI_GPIO_Mapping){EXTI4, GPIOA, GPIO_PIN4, EXTI4_IQR}
#define EXTI4PB4                           (EXTI_GPIO_Mapping){EXTI4, GPIOB, GPIO_PIN4, EXTI4_IQR}
#define EXTI4PC4                           (EXTI_GPIO_Mapping){EXTI4, GPIOC, GPIO_PIN4, EXTI4_IQR}
#define EXTI4PD4                           (EXTI_GPIO_Mapping){EXTI4, GPIOD, GPIO_PIN4, EXTI4_IQR}


//EXTI5
#define EXTI5PA5                           (EXTI_GPIO_Mapping){EXTI5, GPIOA, GPIO_PIN5, EXTI5_IQR}
#define EXTI5PB5                           (EXTI_GPIO_Mapping){EXTI5, GPIOB, GPIO_PIN5, EXTI5_IQR}
#define EXTI5PC5                           (EXTI_GPIO_Mapping){EXTI5, GPIOC, GPIO_PIN5, EXTI5_IQR}
#define EXTI5PD5                           (EXTI_GPIO_Mapping){EXTI5, GPIOD, GPIO_PIN5, EXTI5_IQR}


//EXTI6
#define EXTI6PA6                           (EXTI_GPIO_Mapping){EXTI6, GPIOA, GPIO_PIN6, EXTI6_IQR}
#define EXTI6PB6                           (EXTI_GPIO_Mapping){EXTI6, GPIOB, GPIO_PIN6, EXTI6_IQR}
#define EXTI6PC6                           (EXTI_GPIO_Mapping){EXTI6, GPIOC, GPIO_PIN6, EXTI6_IQR}
#define EXTI6PD6                           (EXTI_GPIO_Mapping){EXTI6, GPIOD, GPIO_PIN6, EXTI6_IQR}


//EXTI7
#define EXTI7PA7                           (EXTI_GPIO_Mapping){EXTI7, GPIOA, GPIO_PIN7, EXTI7_IQR}
#define EXTI7PB7                           (EXTI_GPIO_Mapping){EXTI7, GPIOB, GPIO_PIN7, EXTI7_IQR}
#define EXTI7PC7                           (EXTI_GPIO_Mapping){EXTI7, GPIOC, GPIO_PIN7, EXTI7_IQR}
#define EXTI7PD7                           (EXTI_GPIO_Mapping){EXTI7, GPIOD, GPIO_PIN7, EXTI7_IQR}


//EXTI8
#define EXTI8PA8                           (EXTI_GPIO_Mapping){EXTI8, GPIOA, GPIO_PIN8, EXTI8_IQR}
#define EXTI8PB8                           (EXTI_GPIO_Mapping){EXTI8, GPIOB, GPIO_PIN8, EXTI8_IQR}
#define EXTI8PC8                           (EXTI_GPIO_Mapping){EXTI8, GPIOC, GPIO_PIN8, EXTI8_IQR}
#define EXTI8PD8                           (EXTI_GPIO_Mapping){EXTI8, GPIOD, GPIO_PIN8, EXTI8_IQR}


//EXTI9
#define EXTI9PA9                           (EXTI_GPIO_Mapping){EXTI9, GPIOA, GPIO_PIN9, EXTI9_IQR}
#define EXTI9PB9                           (EXTI_GPIO_Mapping){EXTI9, GPIOB, GPIO_PIN9, EXTI9_IQR}
#define EXTI9PC9                           (EXTI_GPIO_Mapping){EXTI9, GPIOC, GPIO_PIN9, EXTI9_IQR}
#define EXTI9PD9                           (EXTI_GPIO_Mapping){EXTI9, GPIOD, GPIO_PIN9, EXTI9_IQR}


//EXTI10
#define EXTI10PA10                          (EXTI_GPIO_Mapping){EXTI10, GPIOA, GPIO_PIN10, EXTI10_IQR}
#define EXTI10PB10                          (EXTI_GPIO_Mapping){EXTI10, GPIOB, GPIO_PIN10, EXTI10_IQR}
#define EXTI10PC10                          (EXTI_GPIO_Mapping){EXTI10, GPIOC, GPIO_PIN10, EXTI10_IQR}
#define EXTI10PD10                          (EXTI_GPIO_Mapping){EXTI10, GPIOD, GPIO_PIN10, EXTI10_IQR}


//EXTI11
#define EXTI11PA11                          (EXTI_GPIO_Mapping){EXTI11, GPIOA, GPIO_PIN11, EXTI11_IQR}
#define EXTI11PB11                          (EXTI_GPIO_Mapping){EXTI11, GPIOB, GPIO_PIN11, EXTI11_IQR}
#define EXTI11PC11                          (EXTI_GPIO_Mapping){EXTI11, GPIOC, GPIO_PIN11, EXTI11_IQR}
#define EXTI11PD11                          (EXTI_GPIO_Mapping){EXTI11, GPIOD, GPIO_PIN11, EXTI11_IQR}


//EXTI12
#define EXTI12PA12                          (EXTI_GPIO_Mapping){EXTI12, GPIOA, GPIO_PIN12, EXTI12_IQR}
#define EXTI12PB12                          (EXTI_GPIO_Mapping){EXTI12, GPIOB, GPIO_PIN12, EXTI12_IQR}
#define EXTI12PC12                          (EXTI_GPIO_Mapping){EXTI12, GPIOC, GPIO_PIN12, EXTI12_IQR}
#define EXTI12PD12                          (EXTI_GPIO_Mapping){EXTI12, GPIOD, GPIO_PIN12, EXTI12_IQR}


//EXTI13
#define EXTI13PA13                          (EXTI_GPIO_Mapping){EXTI13, GPIOA, GPIO_PIN13, EXTI13_IQR}
#define EXTI13PB13                          (EXTI_GPIO_Mapping){EXTI13, GPIOB, GPIO_PIN13, EXTI13_IQR}
#define EXTI13PC13                          (EXTI_GPIO_Mapping){EXTI13, GPIOC, GPIO_PIN13, EXTI13_IQR}
#define EXTI13PD13                          (EXTI_GPIO_Mapping){EXTI13, GPIOD, GPIO_PIN13, EXTI13_IQR}


//EXTI14
#define EXTI14PA14                          (EXTI_GPIO_Mapping){EXTI14, GPIOA, GPIO_PIN14, EXTI14_IQR}
#define EXTI14PB14                          (EXTI_GPIO_Mapping){EXTI14, GPIOB, GPIO_PIN14, EXTI14_IQR}
#define EXTI14PC14                          (EXTI_GPIO_Mapping){EXTI14, GPIOC, GPIO_PIN14, EXTI14_IQR}
#define EXTI14PD14                          (EXTI_GPIO_Mapping){EXTI14, GPIOD, GPIO_PIN14, EXTI14_IQR}


//EXTI15
#define EXTI15PA15                          (EXTI_GPIO_Mapping){EXTI15, GPIOA, GPIO_PIN15, EXTI15_IQR}
#define EXTI15PB15                          (EXTI_GPIO_Mapping){EXTI15, GPIOB, GPIO_PIN15, EXTI15_IQR}
#define EXTI15PC15                          (EXTI_GPIO_Mapping){EXTI15, GPIOC, GPIO_PIN15, EXTI15_IQR}
#define EXTI15PD15                          (EXTI_GPIO_Mapping){EXTI15, GPIOD, GPIO_PIN15, EXTI15_IQR}


//---------------------
//@ref Trigger_define
//--------------------

#define EXTR_RAISING                           0
#define EXTR_FALLING                           1
#define EXTR_FALLING_AND_RAISING               2

//--------------------
//@ref IQR_define
//--------------------

#define EXTI_ENABLE                             0
#define EXTI_DISABLE                            1

//-------------------

/*
* ===============================================
* APIs Supported by "MCAL GPIO DRIVER"
* ===============================================
*/

void MCAL_EXTI_GPIO_Init(EXTI_pinCofig_t *EXTI_con);
void MCAL_EXTI_GPIO_Denit();
void MCAL_EXTI_GPIO_Update(EXTI_pinCofig_t *EXTI_con);



#endif /* INC_STM32F103X8_EXTI_DRIVER_H_ */
