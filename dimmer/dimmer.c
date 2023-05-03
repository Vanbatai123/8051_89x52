				  /*Thach anh su dung f=24Mhz*/
#include <REGX51.H>
sbit led = P2^0;
void delay (unsigned int i)
{
while(i--);
}
 void delay_ms(int x)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<125;j++)
		{
				
		}
	}
}
void main()
{
	while(1)
	{
			led = 0;
			delay(350);	
			led = 1;
			delay(350);	
	}
}