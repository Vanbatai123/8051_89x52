				  /*Thach anh su dung f=24Mhz*/
#include <REGX51.H>
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
	P2=P1=0;
	while(1)
	{
			if(P1_0==1)
			{
				delay_ms(500);
				P2_0=~P2_0;
			}
			if(P2_0==1)
			{
				
				P0_0 = 0;
				delay_ms(250);	
				P0_0 = 1;
				delay_ms(1000);
			}
			else 
			P0_0=1;

			if(P1_1==1)
			{
				delay_ms(500);
				P2_1=~P2_1;
			}
			if(P2_1==1)
			{
				
				//P0_0 = 0;
				//delay_ms(40);	
				P0_1 = 1;
				//delay_ms(100);
			}
			else 
			P0_1=0;
				 
			if(P1_2==1)
			{
				delay_ms(500);
				P2_2=~P2_2;
			}
			if(P2_2==1)
			{
				
				//P0_0 = 0;
				//delay_ms(40);	
				P0_2 = 1;
				//delay_ms(100);
			}
			else 
			P0_2=0;
		
			

		/*	if(P1_1==1)
			{
				delay_ms(600);
				P2_1=~P2_1;
			}
			if(P1_2==1)
			{
				delay_ms(600);
				P2_2=~P2_2;
			}
			if(P1_3==1)
			{
				delay_ms(600);
				P2_3=~P2_3;
			}*/	
	}
}