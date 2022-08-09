/*
 * STD_TYPES.h
 *
 *  Created on: Jul 10, 2022
 *      Author: bassa
 */

#ifndef STD_TYPES_H_
#define STD_TYPES_H_

typedef unsigned char u8;
typedef unsigned int u16;
typedef unsigned long long u32;
#define null ((void*)0)


typedef unsigned char* ptr_uint8_t ;
typedef char* Ptr_sint8_t          ;

typedef void(*Ptr_VoidFunVoid)(void);


typedef unsigned char E_Status_t;

#define E_OK         ((E_Status_t)0)

#define E_NOK         ((E_Status_t)1)

#endif /* STD_TYPES_H_ */
