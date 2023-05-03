#include <REGX51.H>
#include "F:\8051\Header\delay.h"
void main(void)
{
	while(1)
	{
		P0=P1=P2=P3=0xAA;
		_delay_ms(500);
		P0=P1=P2=P3=0x55;
		_delay_ms(500);
	}
}