#include "project_config.h"

void peripheral_init(void)
{
	/* Configure LED Pin, heater pin and seat pin*/
	DDRB |= (1 << LED_PIN);
	DDRD &=~(1<<SEAT_PIN);
	DDRD &=~(1<<HEATER_PIN);
	/* Turn on by default*/
	SEAT_PORT|=(1<<SEAT_PIN);
	HEATER_PORT|=(1<<HEATER_PIN);
	DDRD|=(1<<PWM_PIN);
    PWM_PORT|=(1<<PWM_PIN);
}