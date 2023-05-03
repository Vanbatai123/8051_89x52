#include <REGX51.H>
#include "F:\8051\Header\myUART.h"
//#include "F:\8051\Header\delay.h"

int main(void)
{
	P2 = 0xFF;
	init_UART();
	while(1)
	{
		if(P2_0==0)
			print_UART("Button is pressed");		
	}
}