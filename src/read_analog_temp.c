#include "read_analog_temp.h"

void InitADC()
{
    ADMUX|=(1<<REFS0);   /* select 5v reference voltage */
    ADCSRA|=(1<<ADEN)|(7<<ADPS0); /* enable ADC and select the prescalar*/
}
uint16_t readADC(uint16_t ch)
{
    ADMUX&=0xf8;  /* clearing last 3 bits */
    ch&=0b00000111;
    ADMUX|=ch;
    ADCSRA|=(1<<ADSC);  /* start conversion */
    while(!(ADCSRA&(1<<ADIF))); /* wait for conversion to complete */
    ADCSRA|=(1<<ADIF);
    return(ADC);

}