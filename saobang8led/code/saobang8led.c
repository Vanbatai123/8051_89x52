#include <REGX51.H>
#define setbb(thanhghi,bit)	thanhghi=thanhghi|(1<<bit)
#define clrb(thanhghi,bit)  thanhghi=thanhghi&(~(1<<bit))
#define inbit(thanhghi,bit) (thanhghi&(1<<bit))>>bit
int i,x,dat;
void delay(int x)
{
	int i,j;
	for(i=0;i<x;i++)
	{
		for(j=0;j<125;j++)
		{
				
		}
	}
}
void sip(dat)
{
	for (i=16;i>0;i--)
	{
		
		if((dat&0x80)==0x80)
		setbb(P0,0);
		else
		clrb(P0,0);	
		dat=dat<<1;
		//xung clk cua thanh ghi dich
		clrb(P0,1);
		setbb(P0,1);
	}
		//xung chot
		clrb(P0,2);
		setbb(P0,2);
		
	
}
void saobang()
{
		int i=0,a=0xfFFf,b=0xff;
		for(;i<12;i++)
		{	
			if (i<3)
			{
				sip(a);
				delay(100);
				a=a<<1;
			}
			else	
			{
				sip(a);
				delay(100);
				a=(a<<1)+1;
			}
		}
		delay(1000);
	}
int main(void)
{
	while(1)
	{
		saobang();
	}
}		  
