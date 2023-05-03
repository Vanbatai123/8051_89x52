/****************Khai báo chân giao tiep I2C***************************/

#define SCL    						P2_0
#define SDA    						P2_1

#define DS1307_SEC      	0x00 //Giay
#define DS1307_MIN       	0x01 //Phut
#define DS1307_HOUR     	0x02 //Gio
#define DS1307_DAY        0x03 //Thu
#define DS1307_DATE      	0x04 //Ngay
#define DS1307_MONTH    	0x05 //Thang
#define DS1307_YEAR       0x06 //Nam


char date,month,year,hour,minute,second,day;
int  set;

/****************Cac ham giao tiep I2C***************************/
void I2C_time_start()
{
     SCL = 1; 
     SDA = 1;
     SDA = 0; 
     SCL = 0; 
}
void I2C_time_stop()
{
     SCL = 1; 
     SDA = 0; 
     SDA=1;
     SCL=1; 
}
unsigned char I2C_write(unsigned char dat)
{
     unsigned char i;
     for (i=0;i<8;i++)
		 {
          SDA = (dat & 0x80); ///? 1:0;
          SCL=1;
          SCL=0;
          dat<<=1;
     }
     SCL = 1; 
     SCL = 0;
     return dat;
}
unsigned char I2C_read(void)
{
     bit rd_bit;
     unsigned char i, dat;
     dat = 0x00;
     for(i=0;i<8;i++)/* For loop read dataa 1 byte */
	   { 
          SCL = 1;
          rd_bit = SDA; /* Keep for check acknowledge */
          dat = dat<<1;
          dat = dat | rd_bit; /* Keep biit daata in dat */
          SCL = 0; /* Clear SCL */
     }
     return dat;
}
/***************Dia chi giao tiep DS1307*********************/


void DS1307_Write(unsigned char addr,unsigned char dat)
{
     unsigned int temp;
     temp = dat ; /*HEX to BCD*/
     dat = (((dat/10)*16)|(temp %10)); /*for Led 7seg*/
     I2C_time_start(); /* time_start i2c bus */
     I2C_write(0XD0); /* Connect to DS1307 */
     I2C_write(addr); /* Requetime_5 RAM address on DS1307 */
     I2C_write(dat); 
     I2C_time_stop();
}
unsigned char DS1307_Read(unsigned char addr)
{
     unsigned int tm,ret;
     I2C_time_start(); /* time_start i2c bus */
     I2C_write(0xD0); /* Connect to DS1307 */
     I2C_write(addr); /* Requetime_5 RAM address on DS1307 */
     I2C_time_start(); /* time_start i2c bus */
     I2C_write(0XD1); /* Connect to DS1307 for Read */
     ret = I2C_read(); /* Receive data */
     I2C_time_stop();
     tm = ret; /*BCD to HEX*/
     ret = (((ret/16)*10)+ (tm & 0x0f)); /*for Led 7seg*/
     return ret;
}
void DS1307_Set(int sec,int min,int hour,int date,int month,int year,int day)
{
          //Ghi du lieu ngay gio vao DS1307
     DS1307_Write(DS1307_SEC,sec);
     DS1307_Write(DS1307_MIN,min); 
     DS1307_Write(DS1307_HOUR,hour); 
     DS1307_Write(DS1307_DATE,date); 
     DS1307_Write(DS1307_MONTH,month); 
     DS1307_Write(DS1307_YEAR,year);
		 DS1307_Write(DS1307_DAY,day);	
}
void DS1307_GetTime(int sec,int min,int hour)
{
     //Doc du lieu gio tu DS1307
     hour=DS1307_Read(DS1307_HOUR);
     min=DS1307_Read(DS1307_MIN);
     sec=DS1307_Read(DS1307_SEC);
}
void DS1307_GetDate(int day,int month,int year)
{
     //Doc du lieu ngay tu DS1307
     day=DS1307_Read(DS1307_DATE);
     month=DS1307_Read(DS1307_MONTH);
     year=DS1307_Read(DS1307_YEAR);
}//end codee DS1307
/*void display()
{
		 vietso_UART(DS1307_Read(DS1307_DATE));
		 print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_MONTH));print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_YEAR));print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_HOUR));print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_MIN));print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_SEC));
	
}	*/
void update()
{
	date=DS1307_Read(DS1307_DATE);
	month=DS1307_Read(DS1307_MONTH);
	year=DS1307_Read(DS1307_YEAR);
	hour=DS1307_Read(DS1307_HOUR);
	minute=DS1307_Read(DS1307_MIN);
	second=DS1307_Read(DS1307_SEC);
	day=DS1307_Read(DS1307_DAY);
}
void display()
{
		move_LCD(1,1);
		vietso_LCD(date);
		print_LCD("-");
		vietso_LCD(month);
		print_LCD("-");
		vietso_LCD(year);
		print_LCD("    ");
		move_LCD(2,1);
		vietso_LCD(hour);
		print_LCD("-");
		vietso_LCD(minute);
		print_LCD("-");
		vietso_LCD(second);
		print_LCD("    ");
		move_LCD(3,1);
		vietso_LCD(day);
}	

void DS1307()
{
	if(P0_0==0)
		{
			set++;
			_delay_ms(150);
		}
		if(set%8==0)
		{
			move_LCD(4,1);
			print_LCD("         ");
			update();
			display();
		}
		else if(set%8==1)
		{	
			move_LCD(4,1);
			print_LCD("SECOND");
			if(P0_1==0)
			{	
				second++;
				if(second==60)
				second=0;
				_delay_ms(150);
			}
			if(P0_2==0)
			{	
				second--;
				if(second==-1)
				second=59;
				_delay_ms(150);
			}
			DS1307_Write(DS1307_SEC,second);
			display();
		}
		else if(set%8==2)
		{	
			move_LCD(4,1);
			print_LCD("MINUTE   ");
			if(P0_1==0)
			{	
				minute++;
				if(minute==60)
				minute=0;
				_delay_ms(150);
			}
			if(P0_2==0)
			{	
				minute--;
				if(minute==-1)
				minute=59;
				_delay_ms(150);
			}
			DS1307_Write(DS1307_MIN,minute);
			display();
		}
		else if(set%8==3)
		{	
			move_LCD(4,1);
			print_LCD("HOUR   ");
			if(P0_1==0)
			{	
				hour++;
				if(hour==24)
				hour=0;
				_delay_ms(150);
			}
			if(P0_2==0)
			{	
				hour--;
				if(hour==-1)
				hour=23;
				_delay_ms(150);
			}
			DS1307_Write(DS1307_HOUR,hour);
			display();
		}
		else if(set%8==4)
		{	
			move_LCD(4,1);
			print_LCD("DATE   ");
			if(P0_1==0)
			{	
				date++;
				if(date==32)
				date=0;
				_delay_ms(150);
			}
			if(P0_2==0)
			{	
				date--;
				if(date==-1)
				date=31;
				_delay_ms(150);
			}
			DS1307_Write(DS1307_DATE,date);
			display();
		}
		else if(set%8==5)
		{	
			move_LCD(4,1);
			print_LCD("MONTH   ");
			if(P0_1==0)
			{	
				month++;
				if(month==13)
				month=0;
				_delay_ms(150);
			}
			if(P0_2==0)
			{	
				month--;
				if(month==-1)
				month=12;
				_delay_ms(150);
			}
			DS1307_Write(DS1307_MONTH,month);
			display();
		}
		else if(set%8==6)
		{	
			move_LCD(4,1);
			print_LCD("YEAR   ");
			if(P0_1==0)
			{	
				year++;
				if(year==100)
				year=0;
				_delay_ms(150);
			}
			if(P0_2==0)
			{	
				year--;
				if(year==-1)
				year=99;
				_delay_ms(150);
			}
			DS1307_Write(DS1307_YEAR,year);
			display();
		}
		else if(set%8==7)
		{	
			move_LCD(4,1);
			print_LCD("DAY   ");
			if(P0_1==0)
			{	
				day++;
				if(day==9)
				day=2;
				_delay_ms(150);
			}
			if(P0_2==0)
			{	
				day--;
				if(day==1)
				day=8;
				_delay_ms(150);
			}
			DS1307_Write(DS1307_DAY,day);
			display();
		}
}