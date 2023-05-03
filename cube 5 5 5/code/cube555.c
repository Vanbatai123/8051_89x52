				  /*Thach anh su dung f=24Mhz*/
#include <REGX51.H>
sbit mot = P2^0;
sbit hai = P2^1;
sbit ba = P2^2;
sbit bon = P2^3;
sbit nam = P2^4;
sbit tam = P2^7;
#define ca5 mot=hai=ba=bon=nam				
unsigned int i,a;
unsigned int mang[]={191,119,254,238,251,221,239,187};
unsigned int scan[]={254,253,251,247,239,223,191,127,254,253,251,247,239,223,191,127};
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
void tat()
{
	P0=P1=P2=P3=255;
}
void bat()
{
	P0=P1=P2=P3=0;
}
void ngoaivao()
{
	for(i=0;i<70;i++)
	{
		mot=nam=0;P1=P0=0;delay(2);
		tat();
		hai=ba=bon=0;P1=P0=238;delay(2);
		tat();
	} 
	for(i=0;i<20;i++)
	{
		hai=bon=0;P3=0; delay(2);
		tat();
		ba=0;P3=170; delay(2);
		tat();
	}
	for(i=0;i<70;i++)
	{
		ba=tam=0;
		delay(4);
		//tat();
	} 		
	delay(200);
}
void trongra()
{
	for(i=0;i<70;i++)
	{
		ba=tam=0;
		delay(4);
		//tat();
	} 		
	delay(400); 
	for(i=0;i<20;i++)
	{
		hai=bon=0;P3=0; delay(2);
		tat();
		ba=0;P3=170; delay(2);
		tat();
	}
	for(i=0;i<150;i++)
	{
		mot=nam=0;P1=P0=0;delay(2);
		tat();
		hai=ba=bon=0;P1=P0=238;delay(2);
		tat();
	}
	
}
void nhapnhay()
{
	for(i=150;i>0;i--)
	{
		bat();
		delay(i);
		tat();	 
		delay(i);
	}
}
void goc1(int tocdo)
{
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		for(i=0;i<tocdo;i++)
		{
			mot=bon=0;P1=255;P3=14;P0=1;delay(2);
			tat();
			hai=ba=0;P0=109;P3=191;delay(2);
			tat();
		} 
		for(i=0;i<tocdo;i++)
		{
			mot=ba=0;P0=131;tam=0;P3=245;delay(2);
			tat();
			hai=0;P0=171;tam=0;delay(2);
			tat(); 
		}  
		for(i=0;i<tocdo;i++)
		{
			mot=hai=0;P0=199;P3=251;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=0;P0=239;delay(4);
			tat(); 
		}
		delay(6*tocdo);
		for(i=0;i<tocdo;i++)
		{
			mot=0;P0=239;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=hai=0;P0=199;P3=251;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=ba=0;P0=131;tam=0;P3=245;delay(2);
			tat();
			hai=0;P0=171;tam=0;delay(2);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=bon=0;P1=255;P3=14;P0=1;delay(2);
			tat();
			hai=ba=0;P0=109;P3=191;delay(2);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		 
}
void goc3(int tocdo)
{
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		for(i=0;i<tocdo;i++)
		{
			mot=bon=0;P0=255;P1=1;P3=224;delay(2);
			tat();
			hai=ba=0;P0=255;P1=109;P3=251;delay(2);
			tat();
		} 
		for(i=0;i<tocdo;i++)
		{
			mot=ba=0;P0=255;tam=0;P1=131;P3=95;delay(2);
			tat();
			hai=0;P1=171;tam=0;delay(2);
			tat(); 
		}  
		for(i=0;i<tocdo;i++)
		{
			mot=hai=0;P1=199;P3=191;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=0;P1=239;delay(4);
			tat(); 
		}
		delay(6*tocdo);
		for(i=0;i<tocdo;i++)
		{
			mot=0;P1=239;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=hai=0;P1=199;P3=191;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=ba=0;P0=255;tam=0;P1=131;P3=95;delay(2);
			tat();
			hai=0;P1=171;tam=0;delay(2);
			tat(); 
		}
		 
		for(i=0;i<tocdo;i++)
		{
			mot=bon=0;P0=255;P1=1;P3=224;delay(2);
			tat();
			hai=ba=0;P0=255;P1=109;P3=251;delay(2);
			tat();
		}  
		 for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		} 
}
void goc4(int tocdo)
{
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		for(i=0;i<tocdo;i++)
		{
			mot=bon=0;P1=31;P3=131;P0=240;delay(2);
			tat();
			hai=ba=0;P0=246;P1=223;P3=239;delay(2);
			tat();
		} 
		for(i=0;i<tocdo;i++)
		{
			mot=ba=0;P0=248;tam=0;P1=63;P3=125;delay(2);
			tat();
			hai=0;P1=191;P0=250;tam=0;delay(2);
			tat(); 
		}  
		for(i=0;i<tocdo;i++)
		{
			mot=hai=0;P1=127;P0=252;P3=254;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=0;P0=254;delay(4);
			tat(); 
		}
		delay(6*tocdo);
		for(i=0;i<tocdo;i++)
		{
			mot=0;P0=254;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=hai=0;P1=127;P0=252;P3=254;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=ba=0;P0=248;tam=0;P1=63;P3=125;delay(2);
			tat();
			hai=0;P1=191;P0=250;tam=0;delay(2);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			mot=bon=0;P1=31;P3=131;P0=240;delay(2);
			tat();
			hai=ba=0;P0=246;P1=223;P3=239;delay(2);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		 
}	
void goc5(int tocdo)
{
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		for(i=0;i<tocdo;i++)
		{
			hai=nam=0;P1=255;P3=14;P0=1;delay(2);
			tat();
			bon=ba=0;P0=109;P3=191;delay(2);
			tat();
		} 
		for(i=0;i<tocdo;i++)
		{
			nam=ba=0;P0=131;tam=0;P3=245;delay(2);
			tat();
			bon=0;P0=171;tam=0;delay(2);
			tat(); 
		}  
		for(i=0;i<tocdo;i++)
		{
			bon=nam=0;P0=199;P3=251;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=0;P0=239;delay(4);
			tat(); 
		}
		delay(6*tocdo);
		for(i=0;i<tocdo;i++)
		{
			nam=0;P0=239;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=bon=0;P0=199;P3=251;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			ba=nam=0;P0=131;tam=0;P3=245;delay(2);
			tat();
			bon=0;P0=171;tam=0;delay(2);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			hai=nam=0;P1=255;P3=14;P0=1;delay(2);
			tat();
			bon=ba=0;P0=109;P3=191;delay(2);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		 
}
void goc6(int tocdo)
{
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		for(i=0;i<tocdo;i++)
		{
			hai=nam=0;P1=240;P3=56;P0=31;delay(2);
			tat();
			bon=ba=0;P0=223;P1=246;P3=254;delay(2);
			tat();
		} 
		for(i=0;i<tocdo;i++)
		{
			nam=ba=0;P0=63;tam=0;P1=248;P3=215;delay(2);
			tat();
			bon=0;P0=191;P1=250;tam=0;delay(2);
			tat(); 
		}  
		for(i=0;i<tocdo;i++)
		{
			bon=nam=0;P0=127;P1=252;P3=239;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=0;P1=254;delay(4);
			tat(); 
		}
		delay(6*tocdo);
		for(i=0;i<tocdo;i++)
		{
			nam=0;P1=254;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=bon=0;P0=127;P1=252;P3=239;delay(4);
			tat(); 
		}

		for(i=0;i<tocdo;i++)
		{
			nam=ba=0;P0=63;tam=0;P1=248;P3=215;delay(2);
			tat();
			bon=0;P0=191;P1=250;tam=0;delay(2);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			hai=nam=0;P1=240;P3=56;P0=31;delay(2);
			tat();
			bon=ba=0;P0=223;P1=246;P3=254;delay(2);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		 
}	 
 void goc7(int tocdo)
{
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		for(i=0;i<tocdo;i++)
		{
			hai=nam=0;P0=255;P1=1;P3=224;delay(2);
			tat();
			bon=ba=0;P0=255;P1=109;P3=251;delay(2);
			tat();
		} 
		for(i=0;i<tocdo;i++)
		{
			nam=ba=0;P0=255;tam=0;P1=131;P3=95;delay(2);
			tat();
			bon=0;P1=171;tam=0;delay(2);
			tat(); 
		}  
		for(i=0;i<tocdo;i++)
		{
			bon=nam=0;P1=199;P3=191;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=0;P1=239;delay(4);
			tat(); 
		}
		delay(6*tocdo);
		for(i=0;i<tocdo;i++)
		{
			nam=0;P1=239;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=bon=0;P1=199;P3=191;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			ba=nam=0;P0=255;tam=0;P1=131;P3=95;delay(2);
			tat();
			bon=0;P1=171;tam=0;delay(2);
			tat(); 
		}
		 
		for(i=0;i<tocdo;i++)
		{
			hai=nam=0;P0=255;P1=1;P3=224;delay(2);
			tat();
			bon=ba=0;P0=255;P1=109;P3=251;delay(2);
			tat();
		}  
		 for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		} 
}
void goc8(int tocdo)
{
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		for(i=0;i<tocdo;i++)
		{
			hai=nam=0;P1=31;P3=131;P0=240;delay(2);
			tat();
			bon=ba=0;P0=246;P1=223;P3=239;delay(2);
			tat();
		} 
		for(i=0;i<tocdo;i++)
		{
			nam=ba=0;P0=248;tam=0;P1=63;P3=125;delay(2);
			tat();
			bon=0;P1=191;P0=250;tam=0;delay(2);
			tat(); 
		}  
		for(i=0;i<tocdo;i++)
		{
			bon=nam=0;P1=127;P0=252;P3=254;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=0;P0=254;delay(4);
			tat(); 
		}
		delay(6*tocdo);
		for(i=0;i<tocdo;i++)
		{
			nam=0;P0=254;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			bon=nam=0;P1=127;P0=252;P3=254;delay(4);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=ba=0;P0=248;tam=0;P1=63;P3=125;delay(2);
			tat();
			bon=0;P1=191;P0=250;tam=0;delay(2);
			tat(); 
		}
		for(i=0;i<tocdo;i++)
		{
			nam=hai=0;P1=31;P3=131;P0=240;delay(2);
			tat();
			ba=bon=0;P0=246;P1=223;P3=239;delay(2);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			mot=nam=0;P1=P0=0;delay(2);
			tat();
			hai=ba=bon=0;P1=P0=238;delay(2);
			tat();
		}  
		 
}

void phaohoa(int tocdo)
{
	a=255;
	for(i=0;i<5;i++)
	{
		P2=a<<i;tam=0;delay(tocdo);
	}
	tat();
	//P1=254;
	P2=225-128;delay(tocdo);
	P2=227-128;delay(tocdo);
	P2=231-128;delay(tocdo);
	P2=239-128;delay(tocdo);
	tat();
	nam=0;tam=0;delay(tocdo);
	tam=1;P3=170;delay(tocdo);
	P1=P0=238;P3=255;delay(tocdo);
	bon=0;delay(tocdo);
	ba=0;delay(tocdo);
	hai=0;delay(tocdo);
	mot=0;delay(tocdo);
	nam=1;delay(tocdo);
	bon=1;delay(tocdo);
	ba=1;delay(tocdo);
	hai=1;delay(tocdo);
	tat();delay(tocdo);

}
void motmat()
{
	int i=0,a=0xff;
	ba=0;
	P1=P0=P3=a=255;
	tam=0;
	delay(100);
	a=0XFF;
	for(i=0;i<8;i++)
	{
		a=a>>1;
		P3=a;
		delay(100);
	}
	a=0XFF;
	for(i=0;i<8;i++)
	{
		a=a>>1;
		P1=a;
		delay(100);
	}
	a=0XFF;
	for(i=0;i<8;i++)
	{
		a=a>>1;
		P0=a;
		delay(100);
	}
}
void quayngang(int tocdo)
{
	 for(i=0;i<tocdo;i++)
	{
		ba=tam=P1=P0=P3=0;delay(1);
		tat();			delay(4);
	}
	for(i=0;i<tocdo;i++)
	{
		mot=0;P0=15;P1=254;delay(1);
		tat();
		hai=0;P0=247;P1=253;P3=227;delay(1);
		tat();
		ba=0;P0=251;P1=251;P3=221;tam=0;delay(1);
		tat();
		bon=0;P0=253;P1=247;P3=62;	 delay(1);
		tat();
		nam=0;P0=254;P1=15;P3=255;	delay(1);
		tat();	   
	}
	for(i=0;i<tocdo;i++)
	{
		ca5=0;P0=251;P1=251;P3=221;tam=0;	 delay(4);
		tat();		   delay(1);
			}
	for(i=0;i<tocdo;i++)
	{
		nam=0;P0=15;P1=254;delay(1);
		tat();
		bon=0;P0=247;P1=253;P3=227;delay(1);
		tat();
		ba=0;P0=251;P1=251;P3=221;tam=0;delay(1);
		tat();
		hai=0;P0=253;P1=247;P3=62;	 delay(1);
		tat();
		mot=0;P0=254;P1=15;P3=255;	delay(1);
		tat();
	}
}
void song(int tocdo)
{
	for(i=0;i<tocdo;i++)
	{
		nam=0;P0=15;P1=254;delay(1);
		tat();
		bon=0;P0=247;P1=253;P3=227;delay(1);
		tat();
		ba=0;P0=251;P1=251;P3=221;tam=0;delay(1);
		tat();
		hai=0;P0=253;P1=247;P3=62;	 delay(1);
		tat();
		mot=0;P0=254;P1=15;P3=255;	delay(1);
		tat();
	}	
	for(i=0;i<tocdo;i++)
	{
		bon=0;P0=15;P1=254;delay(1);
		tat();
		nam=0;P0=247;P1=253;P3=227;delay(1);
		tat();
		bon=0;P0=251;P1=251;P3=221;tam=0;delay(1);
		tat();
		ba=0;P0=253;P1=247;P3=62;	 delay(1);
		tat();
		hai=0;P0=254;P1=15;P3=255;	delay(1);
		tat();
	}

		for(i=0;i<tocdo;i++)
		{
			ba=0;P0=15;P1=254;delay(1);
			tat();
			bon=0;P0=247;P1=253;P3=227;delay(1);
			tat();
			nam=0;P0=251;P1=251;P3=221;tam=0;delay(1);
			tat();
			bon=0;P0=253;P1=247;P3=62;	 delay(1);
			tat();
			ba=0;P0=254;P1=15;P3=255;	delay(1);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			hai=0;P0=15;P1=254;delay(1);
			tat();
			ba=0;P0=247;P1=253;P3=227;delay(1);
			tat();
			bon=0;P0=251;P1=251;P3=221;tam=0;delay(1);
			tat();
			nam=0;P0=253;P1=247;P3=62;	 delay(1);
			tat();
			bon=0;P0=254;P1=15;P3=255;	delay(1);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			mot=0;P0=15;P1=254;delay(1);
			tat();
			hai=0;P0=247;P1=253;P3=227;delay(1);
			tat();
			ba=0;P0=251;P1=251;P3=221;tam=0;delay(1);
			tat();
			bon=0;P0=253;P1=247;P3=62;	 delay(1);
			tat();
			nam=0;P0=254;P1=15;P3=255;	delay(1);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			hai=0;P0=15;P1=254;delay(1);
			tat();
			mot=0;P0=247;P1=253;P3=227;delay(1);
			tat();
			hai=0;P0=251;P1=251;P3=221;tam=0;delay(1);
			tat();
			ba=0;P0=253;P1=247;P3=62;	 delay(1);
			tat();
			bon=0;P0=254;P1=15;P3=255;	delay(1);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			ba=0;P0=15;P1=254;delay(1);
			tat();
			hai=0;P0=247;P1=253;P3=227;delay(1);
			tat();
			mot=0;P0=251;P1=251;P3=221;tam=0;delay(1);
			tat();
			hai=0;P0=253;P1=247;P3=62;	 delay(1);
			tat();
			ba=0;P0=254;P1=15;P3=255;	delay(1);
			tat();
		}
		for(i=0;i<tocdo;i++)
		{
			bon=0;P0=15;P1=254;delay(1);
			tat();
			ba=0;P0=247;P1=253;P3=227;delay(1);
			tat();
			hai=0;P0=251;P1=251;P3=221;tam=0;delay(1);
			tat();
			mot=0;P0=253;P1=247;P3=62;	 delay(1);
			tat();
			hai=0;P0=254;P1=15;P3=255;	delay(1);
			tat();
		}
}
void quet(int i)
{
	mot=0;P0=P1=scan[i];delay(1);tat();
	hai=0;P0=P1=scan[i+1];delay(1);tat();
	ba=0;P0=P1=scan[i+2];delay(1);	tat();
	bon=0;P0=P1=scan[i+3];delay(1);tat();
	nam=0;P0=P1=scan[i+4];delay(1);tat();
}
void bondiem(int tocdo,int solan)
{
	for(i=0;i<solan;i++)
	{
		 ba=tam=0;delay(tocdo);
		 tat();
		 hai=bon=0;P3=170;delay(tocdo);
		 tat();
		 mot=nam=0;P0=P1=238;delay(tocdo*4);
		 tat();
		 hai=bon=0;P3=170;delay(tocdo);
		 tat();
	}
}
void cheo(int tocdo)
{
	 mot=0;
	 P0=254;delay(tocdo);
	 P3=254;delay(tocdo);
	 tam=0;delay(tocdo);
	 P3=238;delay(tocdo);
	 P1=254;delay(tocdo);
	 P0=255;delay(tocdo);
	 P3=239;delay(tocdo);
	 tam=1;delay(tocdo);
	 P3=255;delay(tocdo);
	 tat();delay(tocdo);

	 nam=0;
	 P1=239;delay(tocdo);
	 P3=191;delay(tocdo);
	 tam=0;delay(tocdo);
	 P3=187;delay(tocdo);
	 P0=239;delay(tocdo);
	 P1=255;delay(tocdo);
	 P3=251;delay(tocdo);
	 tam=1;delay(tocdo);
	 P3=255;delay(tocdo);
	 tat();delay(tocdo);
	 P1=254;
	 a=255;
	for(i=0;i<5;i++)
	{
		P2=a<<i;tam=1;delay(tocdo);
	}
	tat();
	P1=254;
	P2=225;delay(tocdo);
	P2=227;delay(tocdo);
	P2=231;delay(tocdo);
	P2=239;delay(tocdo);
	tat();delay(tocdo);
	bon=0;
		P1=247;delay(tocdo);
		P3=191;delay(tocdo);
		P3=63;delay(tocdo);
		P3=62;delay(tocdo);
		P0=253;delay(tocdo);
		P1=255;delay(tocdo);
		P3=126;delay(tocdo);
		P3=254;delay(tocdo);
		P3=255;delay(tocdo);
		tat();delay(tocdo);
		hai=0;
	 P0=254;delay(tocdo);
	 P3=254;delay(tocdo);
	 tam=0;delay(tocdo);
	 P3=238;delay(tocdo);
	 P1=254;delay(tocdo);
	 P0=255;delay(tocdo);
	 P3=239;delay(tocdo);
	 tam=1;delay(tocdo);
	 P3=255;delay(tocdo);
	 tat();delay(tocdo);
 ba=0;
	 P1=239;delay(tocdo);
	 P3=191;delay(tocdo);
	 tam=0;delay(tocdo);
	 P3=187;delay(tocdo);
	 P0=239;delay(tocdo);
	 P1=255;delay(tocdo);
	 P3=251;delay(tocdo);
	 tam=1;delay(tocdo);
	 P3=255;delay(tocdo);
	 tat();delay(tocdo);
}
void ilu()
{
		for(i=0;i<200;i++)
		{
		 	 mot=nam=P0=P1=P3=tam=0;delay(2);
			 tat();
			 hai=bon=ba=0;P0=251;P1=251;P3=221;tam=0;delay(2);
			 tat();	 
		}
		delay(1000);
		for(i=0;i<200;i++)
		{
		 	 mot=nam=P0=P1=P3=tam=0;delay(2);
			 tat();
			 hai=bon=ba=0;P0=251;P1=251;P3=221;tam=0;delay(2);
			 tat();	 
		}
		delay(1000);
		for(i=0;i<200;i++)
		{
		 	 mot=nam=P0=P1=P3=tam=0;delay(2);
			 tat();
			 hai=bon=ba=0;P0=251;P1=251;P3=221;tam=0;delay(2);
			 tat();	 
		}
		delay(1000);
		for(i=0;i<200;i++)
			{
		 mot=0;P0=251;P1=251;P3=221;tam=0;delay(1); tat();
		 hai=0;P0=241;P1=241;P3=0;tam=0;delay(1);tat();
		 ba=bon=P0=P1=P3=tam=0;delay(1);tat();
		 nam=0;P0=245;P1=245;P3=34;delay(1); tat();
		 }
		 delay(1000);
		 for(i=0;i<200;i++)
			{
		 mot=0;P0=251;P1=251;P3=221;tam=0;delay(1); tat();
		 hai=0;P0=241;P1=241;P3=0;tam=0;delay(1);tat();
		 ba=bon=P0=P1=P3=tam=0;delay(1);tat();
		 nam=0;P0=245;P1=245;P3=34;delay(1); tat();
		 }
		 delay(1000);
		 for(i=0;i<200;i++)
			{
		 mot=0;P0=251;P1=251;P3=221;tam=0;delay(1); tat();
		 hai=0;P0=241;P1=241;P3=0;tam=0;delay(1);tat();
		 ba=bon=P0=P1=P3=tam=0;delay(1);tat();
		 nam=0;P0=245;P1=245;P3=34;delay(1); tat();
		 }
		 delay(1000);
		 for(i=0;i<200;i++)
			{	
		 mot=0;P0=241;P1=241;P3=0;tam=0;delay(2);tat();
		 hai=ba=bon=nam=0;P0=14;P1=14;P3=255; delay(2); tat();
		 }
		 delay(1000);
		 for(i=0;i<200;i++)
			{	
		 mot=0;P0=241;P1=241;P3=0;tam=0;delay(2);tat();
		 hai=ba=bon=nam=0;P0=14;P1=14;P3=255; delay(2); tat();
		 }
		 delay(1000);
		 for(i=0;i<200;i++)
			{	
		 mot=0;P0=241;P1=241;P3=0;tam=0;delay(2);tat();
		 hai=ba=bon=nam=0;P0=14;P1=14;P3=255; delay(2); tat();
		 }
		 delay(1000);
}
void taohop(int tocdo)
{
tat();
		 mot=0;
		 for(i=0;i<8;i++)
		{
			P0=a<<i;delay(tocdo);
		}
		for(i=0;i<8;i++)
		{
			P1=a<<i;delay(tocdo);
		} //delay(3000);
		for(i=0;i<1;i++)
		{
		mot=1;hai=0;delay(100);
		hai=1;ba=0;delay(100); 
		ba=1;bon=0;delay(100);
		bon=1;nam=0;delay(100);

		nam=1;bon=0;delay(100);
		bon=1;ba=0;delay(100); 
		ba=1;hai=0;delay(100);
		hai=1;mot=0;delay(100);

		}
		mot=1;hai=0;delay(100);
		hai=1;ba=0;delay(100); 
		ba=1;bon=0;delay(100);
		bon=1;nam=0;delay(100);

		bon=0;delay(100);
		ba=0;delay(100); 
		hai=0;delay(100);
		mot=0;delay(100);
		delay(1000);
}
void main()
{
	int i=0,j,k;
	while(1)
	{
		nhapnhay();
		ilu();
		trongra();ngoaivao();
		trongra();ngoaivao();
		trongra();ngoaivao();
		motmat();
		for(i=150;i>0;i--)
		{
			quayngang(i);
			if(i>30) i=i-15;
		}
		for(i=0;i<100;i++)
		{
			quayngang(i);
			if(i>30) i=i+15;
		}
		for(i=20;i<40;i++)
		{	  
			song(i);
		}
		tat();
		bondiem(80,5);	
		for(k=0;k<17;k++)
			for(i=0;i<8;i++)
			{
				for(j=0;j<20;j++)
				quet(i);
			}
		 
		bondiem(100,7);
		cheo(100);cheo(100);cheo(100);		
		phaohoa(140);
		phaohoa(90); 
		phaohoa(100);
		phaohoa(70);
		phaohoa(200);
						
		
		ilu();
		delay(5000);
		taohop(100);
		bondiem(100,7);
		goc1(20); 
		goc6(20);
		goc3(20);
		goc8(20);
	//	goc2(20); 
		goc4(20);
		goc5(20);
		goc7(20);
		goc3(20);
		goc1(20);
	//	goc2(20); 
		goc6(20);
		goc5(20);
		for(k=0;k<15;k++)
			for(i=0;i<8;i++)
			{
				for(j=0;j<20;j++)
				quet(i);
			} 
	}
}







