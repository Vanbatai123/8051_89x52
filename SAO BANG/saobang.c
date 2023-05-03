#include <REGX51.H>

unsigned char led[16]={255,250,150,90,30,15,12,8,6,4,4,1,1,0,0,0};

void delay_ms(unsigned int ms,ttt){
//65535ms 9000MHz
while(ms--){ 
unsigned int xxx = 7*ttt+1;
while(xxx--); 
}
}
/*xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx*/
/*void delay(unsigned long t)
{
unsigned int m;
for(m=0;m<t;m++);
}*/
unsigned char dem=0,nho;
/*xxxxxxxxxxxxxxx*/
void Timer0()interrupt 1 {
TF0=0; TR0=0;
//if(dem==0) {P0=0;P2=0;}
if(dem>=led[0]) P0_0=0; else P0_0=1;
if(dem>=led[1]) P0_1=0; else P0_1=1;
if(dem>=led[2]) P0_2=0; else P0_2=1;
if(dem>=led[3]) P0_3=0; else P0_3=1;
if(dem>=led[4]) P0_4=0; else P0_4=1;
if(dem>=led[5]) P0_5=0; else P0_5=1;
if(dem>=led[6]) P0_6=0; else P0_6=1;
if(dem>=led[7]) P0_7=0; else P0_7=1;

if(dem>=led[8]) P2_7=0; else P2_7=1;
if(dem>=led[9]) P2_6=0; else P2_6=1;
if(dem>=led[10]) P2_5=0; else P2_5=1;
if(dem>=led[11]) P2_4=0; else P2_4=1;
if(dem>=led[12]) P2_3=0; else P2_3=1;
if(dem>=led[13]) P2_2=0; else P2_2=1;
if(dem>=led[14]) P2_1=0; else P2_1=1;
if(dem>=led[15]) P2_0=0; else P2_0=1;
dem++;
TR0=1;
}
/*xxxxxxxxxxxxxxx*/
/*void Timer1()interrupt 3 {
TF1=0; TR1=0;
//if(dem==0) {P0=0;P2=0;}
if(dem>=led[15]) P0_0=0; else P0_0=1;
if(dem>=led[14]) P0_1=0; else P0_1=1;
if(dem>=led[13]) P0_2=0; else P0_2=1;
if(dem>=led[12]) P0_3=0; else P0_3=1;
if(dem>=led[11]) P0_4=0; else P0_4=1;
if(dem>=led[10]) P0_5=0; else P0_5=1;
if(dem>=led[9]) P0_6=0; else P0_6=1;
if(dem>=led[8]) P0_7=0; else P0_7=1;

if(dem>=led[7]) P2_7=0; else P2_7=1;
if(dem>=led[6]) P2_6=0; else P2_6=1;
if(dem>=led[5]) P2_5=0; else P2_5=1;
if(dem>=led[4]) P2_4=0; else P2_4=1;
if(dem>=led[3]) P2_3=0; else P2_3=1;
if(dem>=led[2]) P2_2=0; else P2_2=1;
if(dem>=led[1]) P2_1=0; else P2_1=1;
if(dem>=led[0]) P2_0=0; else P2_0=1;
dem++;
TR1=1;
}*/ 
/*xxxxxxxxxxxxxxxxxxxxx quay phai xxxxxxxxxxxxxxxxxxxxx*/

void main(void)
{

while(1)
{
unsigned int i,j,k;
TH0=180;
TL0=180; 
TMOD=0x02; //timer 0: che do 2: 8 bit tu dong nap lai
EA=1; ET0=1; TR0=1;

for(i=1;i<500;i++)
{
delay_ms(15,10); dem=0;
nho= led[0];
led[0]= led[1]; led[1]= led[2]; led[2]= led[3]; led[3]= led[4];
led[4]= led[5]; led[5]= led[6]; led[6]= led[7]; led[7]= led[8];
led[8]= led[9]; led[9]= led[10]; led[10]=led[11]; led[11]=led[12];
led[12]=led[13]; led[13]=led[14]; led[14]=led[15]; led[15]=nho;
} 
/*xxxxxxxxxxxxxx quay phai xxxxxxxxxxxxxxxxxxx*/
/*TR0=0;
TH1=180;
TL1=180; 
TMOD=0x02; //timer 0: che do 2: 8 bit tu dong nap lai
EA=1; ET1=1; TR1=1;*/
for(j=1;j<500;j++)
{
delay_ms(15,10); dem=0;
nho= led[15];
led[15]= led[14]; led[14]= led[13]; led[13]= led[12]; led[12]= led[11];
led[11]= led[10]; led[10]= led[9]; led[9]= led[8]; led[8]= led[7];
led[7]= led[6]; led[6]= led[5]; led[5]=led[4]; led[4]=led[3];
led[3]=led[2]; led[2]=led[1]; led[1]=led[0]; led[0]=nho;
}
/*xxxxxxx chop tat xxxxxxxxxxxxxxxxxxxxxxx*/
TR0=0; 
for(k=1;k<20;k++)
{
P0_0=0; 
P0_1=0;
P0_2=0; 
P0_3=0;
P0_4=0; 
P0_5=0; 
P0_6=0; 
P0_7=0; 

P2_7=0; 
P2_6=0; 
P2_5=0; 
P2_4=0; 
P2_3=0; 
P2_2=0; 
P2_1=0; 
P2_0=0; 
delay_ms(60,30);
P0_0=1; 
P0_1=1;
P0_2=1; 
P0_3=1;
P0_4=1; 
P0_5=1; 
P0_6=1; 
P0_7=1; 

P2_7=1; 
P2_6=1; 
P2_5=1; 
P2_4=1; 
P2_3=1; 
P2_2=1; 
P2_1=1; 
P2_0=1; 
delay_ms(60,30);
} 

}}
