
#define DS 		P0_5			//DATA
#define SH_CP P0_7			//SRC
#define ST_CP P0_6			//RCL
void Ship_595(unsigned int data)
{
	for (int i=8;i>0;i--)
	{
		if((data&0x80)==0x80)
			DS=1;
		else
			DS=0;
		data=data<<1;
		SH_CP=0;//xung clk cua thanh ghi dich
		SH_CP=1;
	}
	ST_CP=0;//xung clk cua thanh ghi dich
	ST_CP=1;
}