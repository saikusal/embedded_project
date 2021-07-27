#ifndef __UART_H_
#define __UART_H_
/**
 * @file uart.h
 * @author Shubham Santosh
 * @brief Display temperature value(in degree celcius) on the Serial Monitor
 * @version 0.1
 * @date 2021-04-29
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"

/**
 * @brief Initialise UART with the specified baud rate
 * 
 * @param value decimal value for the initializing the baud rate calculated using fosc/(16*baud rate)-1
 */
void UARTinit(uint16_t baud_value);

/**
 * @brief Write the character data on the serial monitor
 * 
 * @param data the character to be printed on the serial monitor
 */
void UARTwrite(char data);

#endif