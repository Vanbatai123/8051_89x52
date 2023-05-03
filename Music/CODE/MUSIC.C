#include<reg51.h>
unsigned char preloadTH=0xFF,preloadTL=0xFF;
unsigned int pointer=0,ii=0,jj;
sbit out=P2^0;
//octa: 0
//key : C C# D D# E F F# G G# A A# B 
code float key_octa0[]={16.35,17.32,18.35,19.45,20.6,21.83,23.12,24.5,25.96,27.5,29.14,30.87};
code unsigned int chuan=1000;
//code float crystal=11.0592;
code float crystal=12;
//music
code unsigned char music[]=
{
"4d~,4d~,3g~,3a~,4d.,4d~,4g~,4a~,4b~,4a=,4g=,4d.,4 e~,3a~,4c~,3g~,3a~,4d~,4d ,4d=,4c=,3a~,4c~,3g~,3a~,4do"
"4g~,4g~,4d~,3a~,4g.,4g~,4a~,4g~,4b=,4a=,4g~,4d.,4 g~,4e ,4e~,4d~,4c ,4d~,4d~,3a~,4d~,3b~,3a~,3go,4d ,4go"
"4go,4a ,4b~,4a~,4F~,4g.,4d~,4g~,4a~,4a=,4b=,4a~,4g.,4d~,3 a ,3a ,3a~,4d ,4d~,4d ,3a=,3b=,3a~,3g.,4b=,4a="
"4g~,4d~,4g~,4d~,3a.,4g~,4g ,4F~,4a~,5d.,4a=,4b=,4d ,3a ,4go,4d~,4d~,3g~,3a~,4do,4g~,4g~,4d~,3a~,4go,4g~"
"4d~,4g~,4a~,4A ,4a~,5d~,4b~,4a~,4g~,4F~,4g ,4d ,4d ,4g~,4a~,4A ,4a~,5d~,4b~,4a~,4g~,4F~,4go,s"
};
void doitanso(float tanso)
{
	unsigned int giatrinap;
	giatrinap=65536-(unsigned int)((1000000*crystal)/(24*tanso));
	preloadTL=(unsigned char)giatrinap;
	preloadTH=(unsigned char)(giatrinap>>8);	
}
void key(unsigned char octa,unsigned char k)
{
	float tanso;
	switch (k)
	{
		case 'c' : tanso=key_octa0[0]; break;
		case 'C' : tanso=key_octa0[1]; break;
		case 'd' : tanso=key_octa0[2]; break;
		case 'D' : tanso=key_octa0[3]; break;
		case 'e' : tanso=key_octa0[4]; break;
		case 'f' : tanso=key_octa0[5]; break;
		case 'F' : tanso=key_octa0[6]; break;
		case 'g' : tanso=key_octa0[7]; break;
		case 'G' : tanso=key_octa0[8]; break;
		case 'a' : tanso=key_octa0[9]; break;
		case 'A' : tanso=key_octa0[10]; break;
		case 'b' : tanso=key_octa0[11]; break;
	}
	switch (octa)
	{
		case '1' : tanso*=2; break;	
		case '2' : tanso*=4; break;
		case '3' : tanso*=8; break;
		case '4' : tanso*=16; break;
		case '5' : tanso*=32; break;
		case '6' : tanso*=64; break;
		case '7' : tanso*=128; break;
		case '8' : tanso*=256; break;
	}
	doitanso(tanso);
}
unsigned int trave(unsigned int ms)
{
	unsigned int a;
	a=preloadTH;
	a=a<<8|preloadTL;
	return (ms*crystal*1000)/12/(65536-a);
}
unsigned int tempo(unsigned char tem)
{
	switch (tem)
	{
		case '=' : return trave(chuan); break;
		case '~' : return trave(chuan*2); break;
		case ' ' : return trave(chuan*4); break;
		case '.' : return trave(chuan*6); break;
		case 'o' : return trave(chuan*8);	break;
	}
}
void ngattimer_0(void) interrupt 1
{
	out=~out;
	TL0=preloadTL;
	TH0=preloadTH;
	if(ii==0)
	{
		if(music[pointer]=='s')
		TR0=0;
		key(music[pointer],music[pointer+1]);
		jj=tempo(music[pointer+2]);
	}
	ii++;
	if(ii==jj)
	{
		ii=0;
		pointer+=4;
	}	
}
void main(void)
{
P0=P1=P2=P3=0;
/*TMOD=17;
TL0=0xff;
TH0=0xff;
ET0=1;
EA=1;
TR0=1;*/
EA=0;
TMOD=0x02;// 8 BIT AUTO RELOAD
TL0=0xff;
TH0=0xff;
ET0=1;
EA=1;
TR0=1;
while(1);
}