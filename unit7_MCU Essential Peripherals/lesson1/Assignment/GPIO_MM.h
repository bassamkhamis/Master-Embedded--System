/*
 * GPIO_private.h
 *
 *  Created on: Apr 23, 2022
 *      Author: bassa
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_

#define POTRA  *((volatile unsigned char *)(0x3B))
#define DDRA  *((volatile unsigned char *)(0x3A))
#define PINA  *((volatile unsigned char *)(0x39))

#define POTRB  *((volatile unsigned char *)(0x38))
#define DDRB  *((volatile unsigned char *)(0x37))
#define PINB  *((volatile unsigned char *)(0x36))

#define POTRC  *((volatile unsigned char *)(0x35))
#define DDRC  *((volatile unsigned char *)(0x34))
#define PINC  *((volatile unsigned char *)(0x33))

#define POTRD  *((volatile unsigned char *)(0x32))
#define DDRD   *((volatile unsigned char *)(0x31))
#define PIND  *((volatile unsigned char *)(0x30))
#endif /* GPIO_PRIVATE_H_ */
