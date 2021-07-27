#ifndef __PROJECT_CONFIG_H__
#define __PROJECT_CONFIG_H__
/**
 * @file project_config.h
 * @author Shubham Santosh
 * @brief Configuration file to define pins and ports for the interfaced peripherals
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <avr/io.h>

#define F_CPU 16000000UL 	/**< Clock Frequency of MCU is 16 MHz */

#define LED_PORT (PORTB)    /**< LED Port Number */
#define LED_PIN  (PORTB0)   /**< LED Pin number  */
#define SEAT_PORT (PORTD)
#define HEATER_PORT (PORTD)
#define SEAT_PIN (PORTD1)
#define HEATER_PIN (PORTD0)

#define PWM_PORT (PORTD)
#define PWM_PIN (PORTD6)
#define PWM_OUT (OCR0A)

#define LED_ON 	(0x01)			/**< LED state HIGH */
#define LED_OFF	(0x00)			/**< LED state LOW */

#define LED_ON_TIME     (20)  /**< LED ON time in milli seconds  */
#define LED_OFF_TIME    (20)   /**< LED OFF time in milli seconds */



void peripheral_init(void);
#endif /* __PROJECT_CONFIG_H__ */