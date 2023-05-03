
#define DS 		P3_0			//14
#define SH_CP P3_1			//11
#define ST_CP P3_1			//12

int i;
void Ship_595(unsigned long int value)
{
	for (i=32;i>0;i--)
	{
		if((value&0x80000000)==0x80000000)
			DS=1;
		else
			DS=0;
		value=value<<1;
		SH_CP=0;//xung clk cua thanh ghi dich
		SH_CP=1;
	}
	ST_CP=0;//xung clk cua thanh ghi dich
	ST_CP=1;
}