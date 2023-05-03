#include <REGX51.H>
#include <DELAY.H>
#define setb(thanhghi,bit)	thanhghi=thanhghi|(1<<bit)
#define clrb(thanhghi,bit)  thanhghi=thanhghi&(~(1<<bit))
char count;
char codee[]={0xFE,0xaa,255,255,255,255,255,255};
int main(void)
{
	
	while(1)
	{
		/*for(count = 0;count < 8;count++)
		{
			setb(P3, count);
			P1 = codee[count];
			_delay_us(1);
			clrb(P3, count);
		}*/
		P2=0xff;P1 = 0;
	}
}