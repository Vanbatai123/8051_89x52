#include <REGX51.H>
#include "delay.h"

#define DATA 	P2_0
#define CLK  	P2_1

char i,x;

void Ship_164(int value)
{
	for (i=0;i<8;i++)
	{
		if(value & 1)
			DATA = 1;
		else
			DATA = 0;
		value=value>>1;
		CLK = 0;//xung clk cua thanh ghi dich
		_delay_us(100);
		CLK = 1;
	}
}
int main(void)
{
	while(1)
	{
		Ship_164(0xaa);
		_delay_ms(1000);
	}
}