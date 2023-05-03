/*---------------?????----------------*/
#include <REGX51.H>


#define uint	unsigned int
#define uchar	unsigned char

#define data_ora	P0
#define a0				P0_0
#define wr				P0_1
#define rd				P0_2
#define rst				P0_3
#define cs				P0_4
	
void delay (uint us)
{
  while(us--);
}

void delay1(uint ms)
{
  uint i,j;
  for(i=0;i<ms;i++)
  for(j=0;j<1000;j++);
}

void chk_busy(void)               //???
{
  P0=0xff;
  a0=0;
  wr=1;
  rd=0;
  //while(busy==1);
  rd=1;
}

void wr_comm(uchar comm)     //???
{
  chk_busy ();
  a0=1;
  rd=1;
  data_ora=comm;
  wr=0;
  // delay(2);
  wr=1;
}

void wr_data (uchar dat)        //???
{
  chk_busy ();
  a0=0;
  rd=1;
  data_ora=dat;
  wr=0;
  //  delay(2);
  wr=1;
}
 
uchar rd_data (uchar dat)        //???
{
  P0=0xff;
  a0=1;
  wr=1;
  rd=0;
  dat=data_ora;
  rd=1;
  return dat;
}

void wr_xd (uint dat)       //???16????
{
  uchar datl,dath;
  datl=dat;
  dath=dat>>8;
  wr_data (datl);        //????
  wr_data (dath);        //????
}

//........????..........
void lcd_lattice(uchar dat1,uchar dat2)
{
uchar i,j,k;
//wr_comm(0x4c);     //????????--??
wr_comm(0x46);
wr_xd(0x04b0);
wr_comm(0x42);
 for(i=0;i<120;i++)
 {
   for(j=0;j<40;j++)
      wr_data(dat1);
   for(k=0;k<40;k++)
      wr_data(dat2);
 }
}

//........???..........
void lcd_kuang(void)
{
uint n0,n1;
//wr_comm(0x4c);     //????????--??
wr_comm(0x46);
wr_xd(0x04b0);
wr_comm(0x42);
for(n0=0;n0<40;n0++)
                   wr_data(0xff);
     for(n0=0;n0<(238);n0++)           
    {
            for(n1=0;n1<40;n1++)
            {
                if (n1==0)          wr_data(0x80);
                  else if (n1==39) wr_data(0x01);
                 else                wr_data(0x00);
        }
     }
 
     for(n0=0;n0<40;n0++)
                   wr_data(0xff);
}
 
/*--------------????------------------*/
void disp_eng(uchar code *eng)
{
  uchar i,j;
  wr_comm(0x46);
  wr_data(0x00);
  wr_data(0x00);
  //wr_xd(0x0000);
  wr_comm(0x42);
  for(i=0;i<7;i++)
  for(j=0;j<40;j++) 
  wr_data(eng[40*i+j]);
  for(i=0;i<96;i++)
  { 
    wr_data(0x20+i);
  }
  for(i=0;i<24;i++)
  {
   wr_data(0xa0+i);
  }
}

//..........????...............
void disp_character(uchar x,uchar y,uchar x1,uchar y1,uchar x2,uchar y2,uchar code *chn)
{                               //?x,y?????x1,y1??,??x2?,??y2??    
  uchar i,j,k,l;                //x????,y????
  for(i=0;i<x2;i++)
  for(j=0;j<y2;j++)
  for(k=0;k<y1;k++)
  for(l=0;l<x1;l++)
  {
     wr_comm(0x46);
      wr_xd(0x04b0+x+40*y+l+k*40+j*x1+i*y1*40);
      wr_comm(0x42);
     wr_data(*chn);
     ++chn;
  }
}
 
//............????..........
void disp_photo(uchar x,uchar y,uchar x1,uchar y1,uchar code *pho)
{ 
  uchar i,j;                               //?x,y?????x1,y1???
  wr_comm(0x46);                          
  wr_xd(0x04b0+x+40*y);
  wr_comm(0x42);
  for(i=0;i<y1;i++)
  for(j=0;j<x1;j++)
  {
    wr_data(*pho);
    ++pho;
  }
}

//.......??............
void lcd_clear(void)
{
uint i,j;
wr_comm(0x46);    //??????
//wr_xd(0x0000);
  wr_data(0x00);
  wr_data(0x00);
wr_comm(0x42);
for(i=0;i<135;i++)
for(j=0;j<80;j++)
wr_data(0x00);
}

//.......???...........
void init_lcd (void)
{
 uchar i;
 rst=1;
 cs=0;
 wr_comm(0x40);         //WRITE SYSTEMSET ?????
 for(i=0;i<8;i++)
 //wr_data(systab[i]);
 wr_comm(0x44);         //WRITE SCROLL ?????
 for(i=0;i<10;i++)
 //wr_data(scrtab[i]);
 wr_comm(0x5a);    //?????????:00--07?
 wr_data(0x00);
 wr_comm(0x5b);    //????:DM1(DM2)=0,????;DM1(DM2)=1,????;OV=1,????;OV=0,????
 wr_data(0x08);
 wr_comm(0x5d);
 wr_data(0x07);
 wr_data(0x8f);   
 wr_comm(0x4c);    //????????--??
 wr_comm(0x59);    //DISP    ON
 wr_data(0x56);  
}
 
//...............???...............
void main()
{
 delay(12);
// SP=0x5f;
 
 init_lcd ();
 //lcd_clear();
   while(1)
 {
 lcd_clear();
 //disp_eng(tab2);
 //disp_photo(0,160,40,80,tab1);
 delay1(400);
 lcd_clear();
 lcd_lattice(0xff,0x00);
 delay1(400);
 lcd_lattice(0x00,0xff);
 delay1(400);
 lcd_clear();
 //sp_character(4,19,3,19,4,12,tab);
 //sp_photo(0,120,40,80,tab1);
 delay1(400);
 lcd_clear();
 lcd_lattice(0xaa,0x55);
 delay1(400);
 lcd_lattice(0x55,0xaa);
 delay1(400);
 lcd_kuang();
 delay1(400);
 }
}