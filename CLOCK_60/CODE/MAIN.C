#include <REGX51.H>
#include "delay.h"
#include "myLCD_HP.h"
#include "my595.h"
#include "myDS1307.h"

unsigned int a=0xa5aa55;

void main()
{
	//_delay_ms(1000);
	//init_LCD();
	P1=0xFF;
	while(1)
	{
		Ship_595(0x112233);
		_delay_ms(400);
	}		
}