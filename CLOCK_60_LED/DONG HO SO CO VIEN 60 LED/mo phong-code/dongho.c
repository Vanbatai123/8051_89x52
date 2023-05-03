   #include<reg52.h>
sbit  DATA1 = P2^7;
sbit  SCK1 = P2^6;
sbit  LACH1 = P2^5;
sbit   set=P3^5;
sbit   up=P3^6;
sbit   down=P3^7;

sbit sdi1 = P3^1;
sbit str1 = P3^2;
sbit clk1 = P3^0;
unsigned char m1[]={0xfe,0xfc,0xf8,0xf0,0xe0,0xc0,0x80,0x00};
unsigned char m2[]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
unsigned char m3[]={0x00,0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff};
 

unsigned char hour, minute, second,c;
unsigned char ma[]={0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90};
unsigned char kt=0,a=0,i,k,x=0;
bit set0=1,set1=1,up1=1,up0=1,down0=1,down1=1;
sbit SCL = P1^0;
sbit SDA = P1^1;
void delay(){
unsigned char i;
for (i = 0; i < 4; i++){};
}

//-----------------------------------------
void SCL_high(){
SCL = 1;
delay();
}

//------------------------------------------
void SCL_low(){
SCL = 0;
delay();
}

//-------------------------------------------
void I2C_Start(){
SDA = 1;
SCL = 1;
SDA = 0;
delay();
SCL = 0;
SDA = 1;
}

//--------------------------------------------
void I2C_Stop(){
SDA = 0;
SCL_high();
SDA = 1;
}

//----------------------------------------------
bit I2C_Write(unsigned char dat){
unsigned char i;
bit outbit;
for (i = 1; i <= 8; i++){
outbit=dat&0x80;
SDA = outbit;
dat = dat << 1;
SCL_high();
SCL_low();
}
SDA = 1; 
SCL_high();
outbit = SDA; 
SCL_low();
return(outbit); 
}

//----------------------------------------------------
unsigned char I2C_Read(bit ack){
unsigned char i, dat;
bit inbit;

dat = 0;
for(i=1;i<=8;i++) {
SCL_high();
inbit = SDA;
dat = dat << 1;
dat = dat | inbit;
SCL_low();
}
if (ack) SDA = 0; 
else SDA = 1;
SCL_high();
SCL = 0;
SDA = 1; 
delay();
return(dat);
} 

//-------------------------------------------------------------
void rtc_write(unsigned char add, unsigned char dat){
I2C_Start();
I2C_Write(0xd0);
I2C_Write(add); 
I2C_Write(((dat/10)<<4)|(dat%10)); 
I2C_Stop();
}

unsigned char rtc_read(unsigned char add){
unsigned char dat;
I2C_Start();
I2C_Write(0xd0); 
I2C_Write(add);
I2C_Start(); 
I2C_Write(0xd1); 
dat = I2C_Read(0);
I2C_Stop();
dat = (dat & 0x0f) + (dat>>4)*10;
return (dat);
}
void writeds(){
rtc_write(0x00, second);
rtc_write(0x01, minute);
rtc_write(0x02, hour);
}

void readds()
{
if(kt==0)
{
if(a==1)
{writeds();a=0;
}
second = rtc_read(0x00);
minute = rtc_read(0x01);
hour = rtc_read(0x02);
}
}

void hienthi(unsigned char x)
{
unsigned int i,temp;
for(i=0;i<8;i++)
{
temp=x;
temp=temp&0x80;
if(temp==0x80)
DATA1=1;   
else
DATA1=0;    
x*=2;   
SCK1=0;   
SCK1=1;  
}
}
void quetled()
{

if(kt==0)
{
hienthi(ma[second%10]);
hienthi(ma[second/10]);
hienthi(ma[minute%10]);
hienthi(ma[minute/10]);
hienthi(ma[hour%10]);
hienthi(ma[hour/10]);
LACH1=0;   
LACH1=1;
}
if(kt==1)
{
hienthi(0xff);
hienthi(0xff);
hienthi(0xff);
hienthi(0xff);
hienthi(ma[hour%10]);
hienthi(ma[hour/10]);
LACH1=0;   
LACH1=1;
}
if(kt==2)
{
hienthi(0xff);
hienthi(0xff);
hienthi(ma[minute%10]);
hienthi(ma[minute/10]);
hienthi(0xff);
hienthi(0xff);
LACH1=0;   
LACH1=1;
}
if(kt==3)
{
hienthi(ma[second%10]);
hienthi(ma[second/10]);
hienthi(0xff);
hienthi(0xff);
hienthi(0xff);
hienthi(0xff);
LACH1=0;  
LACH1=1;
}
}
void ktphim()
{
set0=set1;set1=set;
if((set0==1)&&(set1==0))
  {
   kt++;
   if(kt>3)kt=0;
  }
switch(kt)
 {
  case 0:break;
  case 1:
    {
      up0=up1;up1=up; a=1;
      if((up0==1)&&(up1==0))
       {
         hour++;
		  if(hour>23)hour=0;
       }
       down0=down1;down1=down;
       if((down0==1)&&(down1==0))
        {
          hour--;
		   if(hour==-1)
		   hour=23;
        }
     break;
   }
  case 2:
    {
     up0=up1;up1=up; a=1;
     if((up0==1)&&(up1==0))
       {
         minute++;
		 if(minute>59)
		 minute=0;
       }
     down0=down1;down1=down;
     if((down0==1)&&(down1==0))
       {
         minute--;
		 if(minute==-1)
		 minute=59;
       }
      break;
    }

  case 3:
    {
     up0=up1;up1=up;a=1;
     if((up0==1)&&(up1==0))
      {
       second++;
		 if(second>59)
		 second++;
      }
      down0=down1;down1=down;
     if((down0==1)&&(down1==0))
      {
      second=0;
      }
     break;
    }
   }
}

void ghi_dich(unsigned char t1,unsigned char t2,unsigned char t3,unsigned char t4,unsigned char t5,unsigned char t6,unsigned char t7,unsigned char t8)
{unsigned char i,Q; 
Q=t8;  for(i=0;i<8;i++){sdi1=(Q&0x01)?1:0;clk1=1;clk1=0;Q>>=1; } 
Q=t7;  for(i=0;i<8;i++){sdi1=(Q&0x01)?1:0;clk1=1;clk1=0;Q>>=1; }
Q=t6;  for(i=0;i<8;i++){sdi1=(Q&0x01)?1:0;clk1=1;clk1=0;Q>>=1; } 
Q=t5;  for(i=0;i<8;i++){sdi1=(Q&0x01)?1:0;clk1=1;clk1=0;Q>>=1; }
Q=t4;  for(i=0;i<8;i++){sdi1=(Q&0x01)?1:0;clk1=1;clk1=0;Q>>=1; } 
Q=t3;  for(i=0;i<8;i++){sdi1=(Q&0x01)?1:0;clk1=1;clk1=0;Q>>=1; }
Q=t2;  for(i=0;i<8;i++){sdi1=(Q&0x01)?1:0;clk1=1;clk1=0;Q>>=1; } 
Q=t1;  for(i=0;i<8;i++){sdi1=(Q&0x01)?1:0;clk1=1;clk1=0;Q>>=1; }
str1=0; str1=1;
}
void sosanh(unsigned char gia_tri)
	{unsigned char k1,k2,k3;
	 k1=0;k2=m1[gia_tri%8];k3=0xff;
	 if((gia_tri>=0)&&(gia_tri<8))  ghi_dich(k2,k3,k3,k3,k3,k3,k3,k3);
	 if((gia_tri>=8)&&(gia_tri<16)) ghi_dich(k1,k2,k3,k3,k3,k3,k3,k3);
	 if((gia_tri>=16)&&(gia_tri<24))ghi_dich(k1,k1,k2,k3,k3,k3,k3,k3);
	 if((gia_tri>=24)&&(gia_tri<32))ghi_dich(k1,k1,k1,k2,k3,k3,k3,k3);
	 if((gia_tri>=32)&&(gia_tri<40))ghi_dich(k1,k1,k1,k1,k2,k3,k3,k3);
	 if((gia_tri>=40)&&(gia_tri<48))ghi_dich(k1,k1,k1,k1,k1,k2,k3,k3);
	 if((gia_tri>=48)&&(gia_tri<56))ghi_dich(k1,k1,k1,k1,k1,k1,k2,k3);
	 if((gia_tri>=56)&&(gia_tri<60))ghi_dich(k1,k1,k1,k1,k1,k1,k1,k2);
	}

void main()
{
    I2C_Start();
    I2C_Write(0xD0);
    I2C_Write(0x07); 
    I2C_Write(0x10); 
    I2C_Stop(); 	   
	while(1)
 {
 ktphim();
 readds();
 quetled();
 sosanh(second);
}
}