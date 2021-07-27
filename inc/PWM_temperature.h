#ifndef __PWM_TEMPERATURE_H_
#define __PWM_TEMPERATURE_H_
/**
 * @file PWM_temperature.h
 * @author Shubham Santosh
 * @brief To display PWM output based on temperature reading
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include "project_config.h"

/**
 * @brief Initialise PWM functionality for PORTD6 
 * 
 */
void PWMinit();

/**
 * @brief Outputs PWM wave with duty cycle depending on the temperaure sensor
 * 
 * @param temp_reading temperature reading from sensor
 */
//void PWMoutput(uint16_t temperature);

#endif