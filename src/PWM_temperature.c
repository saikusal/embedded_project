#include "PWM_temperature.h"

void PWMinit()
{
 /* selecting Fast PWM mode for pin PD6 */
 TCCR0A|=(1<<COM0A1)|(1<<WGM00)|(1<<WGM01);
 TCCR0B|=(1<<CS01)|(1<<CS00); /* 64 bit prescalar */
}

/*
void PWMoutput(uint16_t temperature)
{
if (temperature>=0 && temperature<=200)
OCR0A=51;
else if (temperature>200 && temperature<=500)
OCR0A= 102;
else if (temperature>500 && temperature<=700)
OCR0A =179; 
else if (temperature>700 && temperature<=1023)
OCR0A=243;  
else
OCR0A=0;  
}
*/