#include "REGX51.H"
#include "F:\8051\Header\delay.h"
int n=0;
void main (void)
{
	while(1)
	{	 
		P2_1=~P2_1;
		_delay_ms(90);
	}
}