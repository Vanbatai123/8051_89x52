#include <REGX51.H>
#include "F:\8051\Header\delay.h"
#include "F:\8051\Header\myUART.h"
#include <math.h>
#include "F:\8051\Header\myDS1307.h"


int main(void)
{
		init_UART();
		DS1307_Set(1,2,3,4,5,6);
		while(1)
		{
				display();
				print_UART("\r");
				_delay_ms(11);
		}	
}