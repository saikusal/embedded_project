#ifndef __GPIO_H_
#define __GPIO_H_
/**
 * @file gpio.h
 * @author Shubham Santosh
 * @brief Turn on LED status when the passenger is seated and turns on the heater
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */

/**
 * Include files
 */ 
#include "project_config.h"


/**
 * @brief Change the state of the LED Pin according to the status of switch
 * 
 * @param state Pin level to which the LED Pin should be set
 */
void change_led_state(uint8_t state);


#endif /** __GPIO_H_ */