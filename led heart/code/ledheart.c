#include "REGX51.H"
#include "E:\8051\delay\delay.c"
int n,i,j,k,a=0xff,b=0xfe,c=0x7f,d=0xff,x=0xff,y=0xfe,z=0xfe;
void sangdan(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		int a=0xff,b=0xfe,c=0x7f,d=0xff;
		for(i=8;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				P1=P2=P3=P0=a&b;
				delay_ms(50);
				b=b<<1;
				b=b|0x01;
			}
			b=0xfe;
			a=a>>1;
		}
		for(i=8;i>0;i--)
		{
			for(j=0;j<i;j++)
			{
				P1=P2=P3=P0=d&c;
				delay_ms(50);
				c=(c>>1)+0x80;
				
			}
			c=0x7f;
			d=d<<1;
		}
	}
}
void sang2bentang(int solan)
{		
	for(n=0;n<solan;n++)
	{
		int x=0xff,y=0xfe,z=0xfe;
		for(k=8;k>0;k--)
		{
			for(j=0;j<8;j++)
			{
				P2=y;
				delay_ms(50);
				y=(y<<1)+1;	
			}
			P2=0xff;
			for(i=0;i<k;i++)
			{
				P3=x&z;
				delay_ms(50);
				z=(z<<1)+1;
			}
			
			z=y=0xfe;
			x=x>>1;			
		}
		x=0xff;
		for(k=8;k>0;k--)
		{
			for(i=0;i<k;i++)
			{
				P2=x&z;
				delay_ms(50);
				z=(z<<1)+1;
			}
			
			y=z=0xfe;
			x=x>>1;			
		}
		
		P3=0xff;
	}
}
void sang2bengiam(int solan)
{		
	for(n=0;n<solan;n++)
	{
		int a=0xff,e=0x7f,b=0x7f,c=0x7f,d=0xff;
		for(k=8;k>0;k--)
		{
			for(j=0;j<8;j++)
			{
				P1=e;
				delay_ms(50);
				e=(e>>1)+0x80;	
			}
			P1=0xff;	
			for(i=0;i<k;i++)
			{
				P0=a&b;
				delay_ms(50);
				b=(b>>1)+0x80;
			}
			
			e=b=0x7f;
			a=a<<1;			
		}
		a=0xff;
		for(k=8;k>0;k--)
		{
			for(i=0;i<k;i++)
			{
				P1=a&b;
				delay_ms(50);
				b=(b>>1)+0x80;
			}
			
			e=b=0x7f;
			a=a<<1;			
		} 
		P0=0xff;
	}
}
void lanluot(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		int a=0xff,e=0x7f,b=0x7f,c=0xfe,d=0xff,x=0xff,y=0xfe,z=0xfe;
		for(k=8;k>0;k--)
		{
			for(j=0;j<8;j++)
			{
				P1=e;
				delay_ms(50);
				e=(e>>1)+0x80;	
			}
			P1=0xff;	
			for(i=0;i<k;i++)
			{
				P0=a&b;
				delay_ms(50);
				b=(b>>1)+0x80;
			}
			
			e=b=0x7f;
			a=a<<1;
			for(j=0;j<8;j++)
			{
				P2=y;
				delay_ms(50);
				y=(y<<1)+1;	
			}
			P2=0xff;
			for(i=0;i<k;i++)
			{
				P3=x&z;
				delay_ms(50);
				z=(z<<1)+1;
			}
			
			z=y=0xfe;
			x=x>>1;			
		}
		a=x=0xff;
		for(k=8;k>0;k--)
		{
			for(i=0;i<k;i++)
			{
				P1=a&b;
				delay_ms(50);
				b=(b>>1)+0x80;
			}
			
			e=b=0x7f;
			a=a<<1;	
		for(i=0;i<k;i++)
			{
				P2=x&z;
				delay_ms(50);
				z=(z<<1)+1;
			}
			
			y=z=0xfe;
			x=x>>1;			
		} 
		P0=0xff;
	}
}
void haipha(int solan)
{		 
	for(n=0;n<solan;n++)
	{ 	
		P0=P1=P2=P3=0Xaa;delay_ms(50);
		P0=P1=P2=P3=0X55;delay_ms(50);
	}
}
void fulltraifai(int solan)
{		 
	for(n=0;n<solan;n++)
	{  	
		b=0xfe;
		for(i=0;i<8;i++)
		{
			P0=b;
			delay_ms(50) ;
			b=(b<<1);
		}
		b=0xfe;
		for(i=0;i<8;i++)
		{
			P1=b;
			delay_ms(50) ;
			b=(b<<1);
		}
		b=0xfe;
		for(i=0;i<8;i++)
		{
			P2=b;
			delay_ms(50) ;
			b=(b<<1);
		}
		b=0xfe;
		for(i=0;i<8;i++)
		{
			P3=b;
			delay_ms(50) ;
			b=(b<<1);
		}
	}
}
void xoatraifai(int solan)
{		 
	for(n=0;n<solan;n++)
	{  	

		b=0;
		for(i=0;i<=8;i++)
		{
			P0=b;
			delay_ms(50) ;
			b=(b<<1)+1;
		}
		b=0;
		for(i=0;i<=8;i++)
		{
			P1=b;
			delay_ms(50) ;
			b=(b<<1)+1;
		}
		b=0;
		for(i=0;i<=8;i++)
		{
			P2=b;
			delay_ms(50) ;
			b=(b<<1)+1;
		}
		b=0;
		for(i=0;i<=8;i++)
		{
			P3=b;
			delay_ms(50) ;
			b=(b<<1)+1;
		}
	}
}
void haibongsang(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		c=0x7f;
		for(j=0;j<8;j++)
		{
			P3=P1=c;
			delay_ms(50);
			c=(c>>1)+0x80;	
		}
			c=0x7f;
			for(j=0;j<8;j++)
		{
			P2=P0=c;
			delay_ms(50);
			c=(c>>1)+0x80;	
		}
	}
}
void allbongsang(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		P2=P0=0xff;
		c=0x7f;
		for(j=0;j<8;j++)
		{
			P3=P1=c;
			delay_ms(50);
			c=(c>>1);	
		}
			c=0x7f;
			for(j=0;j<8;j++)
		{
			P2=P0=c;
			delay_ms(50);
			c=(c>>1);	
		}
	}
}
void allbongtat(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		P2=P0=0x00;
		c=0x00;
		for(j=0;j<8;j++)
		{
			P3=P1=c;
			delay_ms(50);
			c=(c>>1)+0x80;	
		}
		P3=P1=0xff;
			c=0x00;
			for(j=0;j<8;j++)
		{
			P2=P0=c;
			delay_ms(50);
			c=(c>>1)+0x80;	
		}
	}
}
void newstyle(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		P2=P0=0xff;
		c=0x00;
		for(j=0;j<8;j++)
		{
			P3=P1=c;
			delay_ms(50);
			c=(c>>1)+0x80;	
		}
		P3=P1=0xff;
			c=0x00;
			for(j=0;j<8;j++)
		{
			P2=P0=c;
			delay_ms(50);
			c=(c>>1)+0x80;	
		}
	}
}
void babonggiam(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		c=0x7f;
		for(j=0;j<9;j++)
		{
			if(j>1)
		   	{
			P2=P0=P3=P1=c;
			delay_ms(50);
			c=(c>>1)+0x80;
			}
		else
		{	P2=P0=P3=P1=c;
			delay_ms(50);
			c=(c>>1);}	
		}
	}
}
void babongtang(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		c=0xfe;
		for(j=0;j<9;j++)
		{
			if(j>1)
		   	{
			P2=P0=P3=P1=c;
			delay_ms(50);
			c=(c<<1)+1;
			}
		else
		{	P2=P0=P3=P1=c;
			delay_ms(50);
			c=(c<<1);}	
		}
	}
}
void haibg2xuong(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		c=0xfe;d=0x7f;
		for(j=0;j<9;j++)
		{
			if(j>0)
		   	{
			P2=c;
		//	delay_ms(30);
			P1=d;
			delay_ms(50);
			d=(d>>1)+0x80;
			c=(c<<1)+1;
			}
			else
			{	P2=c;
			//	delay_ms(50);
				P1=d;
				delay_ms(50);
				c=(c<<1);	
				d=d>>1;
			}
		}
		P0=P1=P2=P3=0XFF;
		c=0xfe;d=0x7f;
		for(j=0;j<9;j++)
		{
			if(j>0)
		   	{
			P3=c;
		//	delay_ms(50);
			P0=d;
			delay_ms(50);
			c=(c<<1)+1;
			d=(d>>1)+0x80;
			}
			else
			{
				P3=c;
			//	delay_ms(30);
				P0=d;
				delay_ms(50);
				c=(c<<1);
				d=d>>1;
			}	
		}
			P0=P1=P2=P3=0XFF;
			delay_ms(50);
	}
}
void haibg2len(int solan)
{		 
	for(n=0;n<solan;n++)
	{
		c=0xfe;d=0x7f;
		for(j=0;j<9;j++)
		{
			if(j>0)
		   	{
			P0=c;
		//	delay_ms(30);
			P3=d;
			delay_ms(50);
			d=(d>>1)+0x80;
			c=(c<<1)+1;
			}
			else
			{	P0=c;
			//	delay_ms(30);
				P3=d;
				delay_ms(50);
				c=(c<<1);	
				d=d>>1;
			}
		}
		P0=P1=P2=P3=0XFF;
		c=0xfe;d=0x7f;
		for(j=0;j<9;j++)
		{
			if(j>0)
		   	{
			P1=c;
		//	delay_ms(30);
			P2=d;
			delay_ms(50);
			c=(c<<1)+1;
			d=(d>>1)+0x80;
			}
			else
			{
				P1=c;
		//		delay_ms(30);
				P2=d;
				delay_ms(50);
				c=(c<<1);
				d=d>>1;
			}	
		}
			P0=P1=P2=P3=0XFF;
			delay_ms(50);
	}
}
void nhay2pha(int solan)
{		 
	for(n=0;n<solan;n++)
	{  
		P3=P1=0X00;
		P2=P0=0XFF;
		delay_ms(100);
		P2=P0=0X00;
		P3=P1=0XFF;
		delay_ms(100);
	}
}
void main (void)
{
	while(1)
	{
		nhay2pha(1);
		
		 
	}
}