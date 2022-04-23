/*
 * utils.h
 *
 *  Created on: Apr 23, 2022
 *      Author: bassa
 */

#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(REG,PIT_NUM)       (REG |= (1<<PIT_NUM))
#define CLEAR_BIT(REG,PIT_NUM)     (REG &= ~(1<<PIT_NUM))
#define TOGGLE_BIT(REG,PIT_NUM)    (REG ^= (1<<PIT_NUM))
#define READ_BIT(REG,PIT_NUM)      ((REG>>PIT_NUM) & 1)

#endif /* UTILS_H_ */
