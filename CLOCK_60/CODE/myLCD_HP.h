#include <stdio.h>
#define CS		P1_4 //Chon chip	  ss
#define SDAT	P1_5 //Data SPI
#define AO		P1_6 //Chot du lieu Command va Data (C/D)
#define SCK		P1_7 //Clock SPI	   ck
int h,w,u,v;
//-------------------------------------------------------------
unsigned char  code font[][6] =
{	//Font 5x7
	{0x00, 0x00, 0x00, 0x00, 0x00, 0x00} // 20
	,{0x00, 0x00, 0x00, 0x5f, 0x00, 0x00} // 21 !
	,{0x00, 0x00, 0x07, 0x00, 0x07, 0x00} // 22 "
	,{0x00, 0x14, 0x7f, 0x14, 0x7f, 0x14} // 23 #
	,{0x00, 0x24, 0x2a, 0x7f, 0x2a, 0x12} // 24 $
	,{0x00, 0x23, 0x13, 0x08, 0x64, 0x62} // 25 %
	,{0x00, 0x36, 0x49, 0x55, 0x22, 0x50} // 26 &
	,{0x00, 0x00, 0x05, 0x03, 0x00, 0x00} // 27 '
	,{0x00, 0x00, 0x1c, 0x22, 0x41, 0x00} // 28 (
	,{0x00, 0x00, 0x41, 0x22, 0x1c, 0x00} // 29 )
	,{0x00, 0x14, 0x08, 0x3e, 0x08, 0x14} // 2a *
	,{0x00, 0x08, 0x08, 0x3e, 0x08, 0x08} // 2b +
	,{0x00, 0x00, 0x50, 0x30, 0x00, 0x00} // 2c ,
	,{0x00, 0x08, 0x08, 0x08, 0x08, 0x08} // 2d -
	,{0x00, 0x00, 0x60, 0x60, 0x00, 0x00} // 2e .
	,{0x00, 0x20, 0x10, 0x08, 0x04, 0x02} // 2f /
	,{0x00, 0x3e, 0x51, 0x49, 0x45, 0x3e} // 30 0
	,{0x00, 0x00, 0x42, 0x7f, 0x40, 0x00} // 31 1
	,{0x00, 0x42, 0x61, 0x51, 0x49, 0x46} // 32 2
	,{0x00, 0x21, 0x41, 0x45, 0x4b, 0x31} // 33 3
	,{0x00, 0x18, 0x14, 0x12, 0x7f, 0x10} // 34 4
	,{0x00, 0x27, 0x45, 0x45, 0x45, 0x39} // 35 5
	,{0x00, 0x3c, 0x4a, 0x49, 0x49, 0x30} // 36 6
	,{0x00, 0x01, 0x71, 0x09, 0x05, 0x03} // 37 7
	,{0x00, 0x36, 0x49, 0x49, 0x49, 0x36} // 38 8
	,{0x00, 0x06, 0x49, 0x49, 0x29, 0x1e} // 39 9
	,{0x00, 0x00, 0x36, 0x36, 0x00, 0x00} // 3a :
	,{0x00, 0x00, 0x56, 0x36, 0x00, 0x00} // 3b ;
	,{0x00, 0x08, 0x14, 0x22, 0x41, 0x00} // 3c <
	,{0x00, 0x14, 0x14, 0x14, 0x14, 0x14} // 3d =
	,{0x00, 0x00, 0x41, 0x22, 0x14, 0x08} // 3e >
	,{0x00, 0x02, 0x01, 0x51, 0x09, 0x06} // 3f ?
	,{0x00, 0x32, 0x49, 0x79, 0x41, 0x3e} // 40 @
	,{0x00, 0x7e, 0x11, 0x11, 0x11, 0x7e} // 41 A
	,{0x00, 0x7f, 0x49, 0x49, 0x49, 0x36} // 42 B
	,{0x00, 0x3e, 0x41, 0x41, 0x41, 0x22} // 43 C
	,{0x00, 0x7f, 0x41, 0x41, 0x22, 0x1c} // 44 D
	,{0x00, 0x7f, 0x49, 0x49, 0x49, 0x41} // 45 E
	,{0x00, 0x7f, 0x09, 0x09, 0x09, 0x01} // 46 F
	,{0x00, 0x3e, 0x41, 0x49, 0x49, 0x7a} // 47 G
	,{0x00, 0x7f, 0x08, 0x08, 0x08, 0x7f} // 48 H
	,{0x00, 0x00, 0x41, 0x7f, 0x41, 0x00} // 49 I
	,{0x00, 0x20, 0x40, 0x41, 0x3f, 0x01} // 4a J
	,{0x00, 0x7f, 0x08, 0x14, 0x22, 0x41} // 4b K
	,{0x00, 0x7f, 0x40, 0x40, 0x40, 0x40} // 4c L
	,{0x00, 0x7f, 0x02, 0x0c, 0x02, 0x7f} // 4d M
	,{0x00, 0x7f, 0x04, 0x08, 0x10, 0x7f} // 4e N
	,{0x00, 0x3e, 0x41, 0x41, 0x41, 0x3e} // 4f O
	,{0x00, 0x7f, 0x09, 0x09, 0x09, 0x06} // 50 P
	,{0x00, 0x3e, 0x41, 0x51, 0x21, 0x5e} // 51 Q
	,{0x00, 0x7f, 0x09, 0x19, 0x29, 0x46} // 52 R
	,{0x00, 0x46, 0x49, 0x49, 0x49, 0x31} // 53 S
	,{0x00, 0x01, 0x01, 0x7f, 0x01, 0x01} // 54 T
	,{0x00, 0x3f, 0x40, 0x40, 0x40, 0x3f} // 55 U
	,{0x00, 0x1f, 0x20, 0x40, 0x20, 0x1f} // 56 V
	,{0x00, 0x3f, 0x40, 0x38, 0x40, 0x3f} // 57 W
	,{0x00, 0x63, 0x14, 0x08, 0x14, 0x63} // 58 X
	,{0x00, 0x07, 0x08, 0x70, 0x08, 0x07} // 59 Y
	,{0x00, 0x61, 0x51, 0x49, 0x45, 0x43} // 5a Z
	,{0x00, 0x00, 0x7f, 0x41, 0x41, 0x00} // 5b [
	,{0x00, 0x02, 0x04, 0x08, 0x10, 0x20} // 5c ¥
	,{0x00, 0x00, 0x41, 0x41, 0x7f, 0x00} // 5d ]
	,{0x00, 0x04, 0x02, 0x01, 0x02, 0x04} // 5e ^
	,{0x00, 0x40, 0x40, 0x40, 0x40, 0x40} // 5f _
	,{0x00, 0x00, 0x01, 0x02, 0x04, 0x00} // 60 `
	,{0x00, 0x20, 0x54, 0x54, 0x54, 0x78} // 61 a
	,{0x00, 0x7f, 0x48, 0x44, 0x44, 0x38} // 62 b
	,{0x00, 0x38, 0x44, 0x44, 0x44, 0x20} // 63 c
	,{0x00, 0x38, 0x44, 0x44, 0x48, 0x7f} // 64 d
	,{0x00, 0x38, 0x54, 0x54, 0x54, 0x18} // 65 e
	,{0x00, 0x08, 0x7e, 0x09, 0x01, 0x02} // 66 f
	,{0x00, 0x0c, 0x52, 0x52, 0x52, 0x3e} // 67 g
	,{0x00, 0x7f, 0x08, 0x04, 0x04, 0x78} // 68 h
	,{0x00, 0x00, 0x44, 0x7d, 0x40, 0x00} // 69 i
	,{0x00, 0x20, 0x40, 0x44, 0x3d, 0x00} // 6a j
	,{0x00, 0x7f, 0x10, 0x28, 0x44, 0x00} // 6b k
	,{0x00, 0x00, 0x41, 0x7f, 0x40, 0x00} // 6c l
	,{0x00, 0x7c, 0x04, 0x18, 0x04, 0x78} // 6d m
	,{0x00, 0x7c, 0x08, 0x04, 0x04, 0x78} // 6e n
	,{0x00, 0x38, 0x44, 0x44, 0x44, 0x38} // 6f o
	,{0x00, 0x7c, 0x14, 0x14, 0x14, 0x08} // 70 p
	,{0x00, 0x08, 0x14, 0x14, 0x18, 0x7c} // 71 q
	,{0x00, 0x7c, 0x08, 0x04, 0x04, 0x08} // 72 r
	,{0x00, 0x48, 0x54, 0x54, 0x54, 0x20} // 73 s
	,{0x00, 0x04, 0x3f, 0x44, 0x40, 0x20} // 74 t
	,{0x00, 0x3c, 0x40, 0x40, 0x20, 0x7c} // 75 u
	,{0x00, 0x1c, 0x20, 0x40, 0x20, 0x1c} // 76 v
	,{0x00, 0x3c, 0x40, 0x30, 0x40, 0x3c} // 77 w
	,{0x00, 0x44, 0x28, 0x10, 0x28, 0x44} // 78 x
	,{0x00, 0x0c, 0x50, 0x50, 0x50, 0x3c} // 79 y
	,{0x00, 0x44, 0x64, 0x54, 0x4c, 0x44} // 7a z
	,{0x00, 0x00, 0x08, 0x36, 0x41, 0x00} // 7b {
	,{0x00, 0x00, 0x00, 0x7f, 0x00, 0x00} // 7c |
	,{0x00, 0x00, 0x41, 0x36, 0x08, 0x00} // 7d }
	,{0x00, 0x10, 0x08, 0x08, 0x10, 0x08} // 7e ->
	,{0x00, 0x78, 0x46, 0x41, 0x46, 0x78} // 7f <-
};
//-------------------------------------------------------------
void lcd_write(int cd, char byte)//SPI 4Line
{
	CS=0;
	if(cd)
		AO=1;
	else
		AO=0;
	for(h=0;h<8;h++)
	{
			if(!(byte&0x80))
					SDAT=0;
			else
					SDAT=1;
			SCK=0;
			SCK=1;
			byte<<=1;
	}
	AO=~AO;
	CS=0;
}
//-------------------------------------------------------------
void move_LCD(unsigned char x, unsigned char y)
{
	y--;
	x--;
	y=y*6;//Graphic Mode thi xoa dong nay di, Text thi de lai
	lcd_write(0,(y&0x0f));
	lcd_write(0,((y>>4)&0x07)|0x10);
	lcd_write(0,(x&0x0f)|0xb0);
}
//-------------------------------------------------------------
void clr_LCD()
{
	for(u=0;u<8;u++)
	{
		move_LCD(u+1,1);
		for(w=0;w<130;w++)
		{
			lcd_write(1,0);
		}
	}
	move_LCD(1,1);
}
//-------------------------------------------------------------
void lcd_putchar(int dat)
{
	if((dat >= 0x20) && (dat <= 0x7f))
	{
		dat=dat-32;
		for(v=0;v<6;v++)
		lcd_write(1, font[dat][v]);
	}
}
//-------------------------------------------------------------
void print_LCD(char *s)
{
	while(*s)
	lcd_putchar(*s++);
}
//-------------------------------------------------------------
void init_LCD()//Khoi tao GLCD
{
	lcd_write(0,0xE2); //Reset
	_delay_ms(100);	   //Delay 100ms
	lcd_write(0,0xAF); //Display ON, 0xAE - OFF
	lcd_write(0,0x2F); //Power control
	clr_LCD(); //Xoa man hinh
}
//-------------------------------------------------------------
void vietso_LCD(int num)
{
	char dis[5];
	sprintf(dis, "%i", num);
	print_LCD(dis);
}
//-------------------------------------------------------------
/*void picture(nt dat)
{
	//if((dat >= 0x20) && (dat <= 0x7f))
	//{
		//dat=dat+8;
		for(v=0;v<128;v++)
		lcd_write(1, anh[dat][v]);
	//}
}	 */