#include <string.h>
#include <stdio.h>
/*void delay(unsigned int t)
{//Ctr delay 50ms dung timer0
	unsigned int i;
	for(i=0;i<t;i++){	
		TH0=0x3c; //-50000us
		TL0=0xb0;
		TR0=1;
		while(!TF0); //cho timer0 tran
		TF0=TR0=0;
	}
}*/
void init_UART()
{
		TMOD=0x21; //Timer 1 che do 8bit nap lai tu dong, timer0 cho delay che do 16bit
		SCON=0x50;//01010000 che do 1, cho phep nhan
		TH1=TL1=0xf3;//Nap 253 tao baud 2400 ko nhan doi baud
		TR1=1; //khoi dong timer1
		ES=1; //Ngat UART
		EA=1; //Cho phep ngat
}
void print_UART(unsigned char *s)
{//Ham gui chuoi ki tu qua UART
	 unsigned char n,i;
	 n=strlen(s); //Dem xem co bao nhieu ky tu
	 for(i=0;i<n;i++){//Vong lap gui tung ky tu 1
	 SBUF=s[i];//Gui 1 byte
	 while(!TI); TI=0;//xoa co truyen
	 }
}
void ngat_uart()interrupt 4 //Ngat nhan du lieu tu uart 
{ 	 
	if(RI)
	{	
		//P1=SBUF; //Xuat du lieu ra Port 1
		char ledState = SBUF;
    if(ledState == '1')
      P2_0=1;
    if(ledState == '0')
      P2_0=0;
	}
	RI = 0;	//Xoa co nhan
			
}
void vietso_UART(int num)
{
	char dis[5];
	sprintf(dis, "%i", num);
	print_UART(dis);
}