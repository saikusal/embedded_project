#include "uart.h"

void UARTinit(uint16_t baud_value)
{
    UBRR0H=(baud_value>>8); /* set baud value */
    UBRR0L=baud_value;
    UCSR0B=0b11011000; /* enable RXEN0, TXEN0, RXIE0 and TXIE0 */
    UCSR0C=(1<<UCSZ00)|(1<<UCSZ01); /* set 8 bit character size */
}


void UARTwrite(char data)
{
    while(!(UCSR0A&(1<<UDRE0))) /* check if transmit buffer is empty */
    {/* Do nothing*/}
    UDR0=data;  /*send data to buffer */
}