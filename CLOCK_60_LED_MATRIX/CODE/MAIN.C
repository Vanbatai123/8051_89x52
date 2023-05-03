#include <REGX51.H>
#include <delay.H>
#include <myDS1307.H>
// MARCO
#define setb(thanhghi,bit)	thanhghi=thanhghi|(1<<bit)
#define clrb(thanhghi,bit)  thanhghi=thanhghi&(~(1<<bit))
// KHAI BAO PORT
#define MINUS 				P1
#define MATR_P 				P0
#define LED7_PORT 		P2
#define NUTNHAN_PORT 	P3
// KHAI BAO CHAN LED 7 DOAN
#define DONVI 				P2_7
#define CHUC 					P2_6
#define TRAM 					P2_5
#define NGHIN 				P2_4
// KHAI BAO NUT NHAN	
#define MODE					P3_0
#define CONG					P3_1

// KHAI BAO CHAN COMON LED 7 DOAN
char led7_pin[]={7,6,5,4};
// KHAI BAO BIEN NGAY THANG NAM
char ngay, thang, nam, gio, phut, giay;
//KHAI BAO BIEN HIEN THI LED 7 DOAN
char nghin, tram, chuc, donvi;  thuong, sodu;
// KHAI BAO BIEN SETUP
char setup = 1;
// KHAI BAO BIEN DEM
int i, count;
// MANG CHO MA TRAN VIEN 1
char matrix[]={0x00,0x01,0x03,0x07,0x0F,0x1F,0x3F, 0x7F,0xFF};
// MANG SO 0-9 CHO LED 7 DOAN
char sev[]={0x3F,0X06,0X5B,0X4F,0X66,0X6D,0X7D,0X07,0X7F,0X6F};
//-----------------------------------------------------------------
void cai_ngay_gio(int sec, int min,int hour,int day,int month,int year)
{
     //Ghi du lieu ngay gio vao DS1307
     DS1307_Write(DS1307_SEC,sec);
     DS1307_Write(DS1307_MIN,min); 
     DS1307_Write(DS1307_HOUR,hour); 
     DS1307_Write(DS1307_DATE,day); 
     DS1307_Write(DS1307_MONTH,month); 
     DS1307_Write(DS1307_YEAR,year); 
}
//-----------------------------------------------------------------
void doc_gio()
{
	giay = DS1307_Read(DS1307_SEC);
	phut = DS1307_Read(DS1307_MIN);
	gio  = DS1307_Read(DS1307_HOUR);
	if (giay%2)
		P2_3 = 1;
	else 
		P2_3 = 0;
}	
//-----------------------------------------------------------------
void doc_ngay()
{
	ngay = DS1307_Read(DS1307_DATE);
	thang = DS1307_Read(DS1307_MONTH);
	nam  = DS1307_Read(DS1307_YEAR);
}	
//-----------------------------------------------------------------
void led7(char first_2, char last_2)
{
	nghin = first_2/10;
	tram = first_2%10;
	chuc = last_2/10;
	donvi = last_2%10;
	
	DONVI = 0;
	MATR_P = sev[donvi];
	if(last_2 != 99)
		_delay_us(100);
	DONVI = 1;
	MATR_P = 0x00;
	_delay_us(1);
	
	CHUC = 0;
	MATR_P = sev[chuc];
	if(last_2 != 99)
		_delay_us(100);
	CHUC = 1;
	MATR_P = 0x00;
	_delay_us(1);
	
	TRAM = 0;
	MATR_P = sev[tram];
	if(first_2 != 99)
		_delay_us(100);
	TRAM = 1;
	MATR_P = 0x00;
	_delay_us(1);
	
	NGHIN = 0;
	MATR_P = sev[nghin];
	if(first_2 != 99)
		_delay_us(100);
	NGHIN = 1;
	MATR_P = 0x00;
	_delay_us(1);
	
}
//-----------------------------------------------------------------
void vien_1()
{
	giay = DS1307_Read(DS1307_SEC)+1;
	thuong = giay/8 + 1;
	sodu = giay%8;
	
	for(count = 0;count < 8;count++)
	{
		clrb(MINUS, 7-count);
		if(count<(thuong-1))
			MATR_P = 0xFF;
		else if (count>(thuong-1))
			MATR_P = 0x00;
		else
			MATR_P = matrix[sodu];
		_delay_us(100);
		setb(MINUS, 7-count);
		MATR_P = 0x00;
		_delay_us(1);
	}	
}
//-----------------------------------------------------------------
void hien_thi()
{
	for(i = 0;i <2000;i++)
	{
		doc_gio();
		led7(gio,phut);
		vien_1();
	}
	doc_ngay();
	for(i = 0;i <1000;i++)
	{	
		P2_3 = 0;
		led7(ngay, thang);	
		vien_1();
	}
	/*for(i = 0;i <1000;i++)
	{	
		led7(20, nam);	
		vien_1();
	}*/
}
//-----------------------------------------------------------------
int main(void)
{
	MATR_P = 0;
	MINUS = 0xFF;
	MODE = CONG = 1;
	IE=0x81;                    //cho phép ngat ngoài 0
	while(1)
	{
		hien_thi();
	}// END WHILE(1)
}// END MAIN
//-----------------------------------------------------------------
void  cai_dat(void) interrupt 0
{
	MINUS = 0xFF;
	setup = 1;
	while(P3_2 == 0)
	{
		cai_ngay_gio(giay,phut, gio, ngay, thang, nam);
		if(MODE == 0)
		{
			setup++;
			_delay_ms(300);
			if(setup > 7)
				setup = 1;
		}
		switch(setup)
		{
			// CAI GIO
			case 1:	led7(gio,99);
							if(CONG == 0)
							{
								gio++;
								_delay_ms(200);
								if(gio > 23)
									gio = 0;
							}
							break;
			// CAI PHUT
			case 2:	led7(99,phut);
							if(CONG == 0)
							{
								phut++;
								_delay_ms(200);
								if(phut > 59)
									phut = 0;
							}
							break;
			// CAI DAT NGAY
			case 3:	led7(ngay, 99);
							if(CONG == 0)
							{
								ngay++;
								_delay_ms(200);
								if(ngay > 23)
									ngay = 0;
							}
							break;
			// CAI DAT THANG
			case 4:	led7(99, thang);
							if(CONG == 0)
							{
								thang++;
								_delay_ms(200);
								if(thang > 12)
									thang = 0;
							}
							break;
			// CAI DAT NAM
			case 5:	led7(20, nam);
							if(CONG == 0)
							{
								nam++;
								_delay_ms(200);
								if(nam > 20)
									nam = 16;
							}
							break;
			case 6:	giay = 1;
							break;				
		}// END SWITCH
	}// END WHILE()
}// END INTERRUPT