#include <REGX51.H>
#include "F:\8051\Header\delay.h"
#include "F:\8051\Header\myLCD_HP.h"
int a=0;
void main()
{
	init_LCD();
	while(1)
	{
		a++;
		move_LCD(1,1);
		vietso_LCD(a); 
		_delay_ms(100);
	}
}