#define DS 		P3_6			//value
#define SH_CP P3_5			//SRC
#define ST_CP P3_7			//RCL

unsigned int i;
void Ship_595(unsigned long int value)
{
	for (i=24;i>0;i--)
	{
		if((value&1)==1)
			DS=1;
		else
			DS=0;
		value=value>>1;
		SH_CP=0;//xung clk cua thanh ghi dich
		SH_CP=1;
	}
	ST_CP=0;//xung clk cua thanh ghi dich
	ST_CP=1;
}