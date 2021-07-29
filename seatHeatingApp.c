/**
 * @file project_main.c
 * @author Shubham Santosh
 * @brief Seat Heating Application used in Automobiles
 * @version 0.1
 * @date 2021-04-23
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include "project_config.h"
#include "user_utils.h"
#include "gpio.h"
#include "read_analog_temp.h"
#include "PWM_temperature.h"
#include "uart.h"

/**
 * @brief Prints the temperature in ˚C
 * 
 * @param a points to the temperature in string format
 */
void UARTwrite_string(char *a);

/**
 * @brief Main function where the code execution starts
 * 
 * @return int Return 0 if the program completes successfully
 * @note PORTB0 is in sink config. i.e when pin is Low, the LED will turn OFF
 * @note PORTB0 is in sink config. i.e when pin is High, the LED will turn ON
 */
int main(void)
{
	/* Initialize Peripherals */
	peripheral_init();
    InitADC();
	PWMinit();
    UARTinit(103); /* claculated from formula (fosc/(16*baudrate)-1) for 9600 baud rate */
	while(1)
	{
		/**
		 * @brief checking the status of heater_pin and seat_pin
		 * 
		 */
		 uint8_t heater_on=!(PIND&(1<<HEATER_PIN));  
	     uint8_t seated=!(PIND&(1<<SEAT_PIN));
		 uint16_t temp_reading=0;
		if(heater_on && seated) 
		{
		/* Driver is seated and turned on the heater button */
        change_led_state(LED_ON);
		
        temp_reading=readADC(0); /* Read temperature sensor */
		if (temp_reading<=200)
		{
			PWM_OUT=51; /* 20% of 256 */
			UARTwrite_string("22");
		}
		else if (temp_reading>200 && temp_reading<=500)
		{
			PWM_OUT= 102; /* 40% of 256 */
			UARTwrite_string("25");
		}
		else if (temp_reading>500 && temp_reading<=700)
		{
			PWM_OUT =179; /* 70% of 256 */
			UARTwrite_string("29");
		}
		else
		{
			PWM_OUT=243;  /* 95% of 256 */
			UARTwrite_string("33");
		}
		delay_ms(LED_ON_TIME);
		}
		else
		{
        change_led_state(LED_OFF);
		PWM_OUT=0;     /* No output in PWM */
		delay_ms(LED_OFF_TIME);	
		}
	}
	return 0;
}

void UARTwrite_string(char *a)
{
	uint8_t i=0;
	while(a[i]!='\0') /* runs till end of character */
	{
		UARTwrite(a[i]);
		i++;
	}
	UARTwrite(176); /* ascii value of degree(˚)  */
	UARTwrite('C');
	UARTwrite('\n');
}