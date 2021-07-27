#ifndef __READ_ANALOG_TEMP_H_
#define __READ_ANALOG_TEMP_H_
/**
 * @file read_analog_temp.h
 * @author Shubham Santosh
 * @brief Read the temperature reading from the temperature sensor
 * @version 0.1
 * @date 2021-04-28
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"

/**
 * @brief initialise the ADC Pin Channel
 * 
 */
void InitADC();

/**
 * @brief 
 * 
 * @param ch specifies the analog channel name
 * @return uint16_t 
 */
uint16_t readADC(uint16_t ch);

#endif
