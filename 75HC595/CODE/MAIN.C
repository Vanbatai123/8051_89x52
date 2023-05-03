#include <REGX51.H>
#include "delay.h"
#include "my595.h"

int a=0;
int main(void)
{
	while(1)
	{
		Ship_595(0xAAFE5512);
		_delay_ms(1000);
	}
}