#include "gpio.h"

void change_led_state(uint8_t state)
{
	LED_PORT = (state << LED_PIN);
}