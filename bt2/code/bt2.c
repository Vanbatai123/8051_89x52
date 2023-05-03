#include <REGX51.H>
#include "delay.h"
void main (void)
{
	while(1)
	{
		P1=P2=P3=P0=0xAA;
		_delay_ms(500);
		P1=P2=P3=P0=0x55;
		_delay_ms(500);
	}
}