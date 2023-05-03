/****************Khai báo chân giao tiep I2C***************************/

#define SCL    P2_0
#define SDA    P2_1

#define DS1307_SEC      0x00 //Giay
#define DS1307_MIN       0x01 //Phut
#define DS1307_HOUR     0x02 //Gio
#define DS1307_DAY        0x03 //Thu
#define DS1307_DATE      0x04 //Ngay
#define DS1307_MONTH    0x05 //Thang
#define DS1307_YEAR       0x06 //Nam

#define PI 3.1416
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
void DS1307_Set(int sec,int min,int hour,int day,int month,int year)
{
          //Ghi du lieu ngay gio vao DS1307
     DS1307_Write(DS1307_SEC,sec);
     DS1307_Write(DS1307_MIN,min); 
     DS1307_Write(DS1307_HOUR,hour); 
     DS1307_Write(DS1307_DATE,day); 
     DS1307_Write(DS1307_MONTH,month); 
     DS1307_Write(DS1307_YEAR,year); 
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
// tinh ngay soc
int getNewMoonDay(int k,int timeZone)
{
	int T, T2, T3, dr, Jd1, M, Mpr, F, C1, deltat, JdNew;
	T = k/1236.85; // Time in Julian centuries from 1900 January 0.5
	T2 = T * T;
	T3 = T2 * T;
	dr = PI/180;
	Jd1 = 2415020.75933 + 29.53058868*k + 0.0001178*T2 - 0.000000155*T3;
	Jd1 = Jd1 + 0.00033*sin((166.56 + 132.87*T - 0.009173*T2)*dr); // Mean new moon
	M = 359.2242 + 29.10535608*k - 0.0000333*T2 - 0.00000347*T3; // Sun's mean anomaly
	Mpr = 306.0253 + 385.81691806*k + 0.0107306*T2 + 0.00001236*T3; // Moon's mean anomaly
	F = 21.2964 + 390.67050646*k - 0.0016528*T2 - 0.00000239*T3; // Moon's argument of latitude
	C1=(0.1734 - 0.000393*T)*sin(M*dr) + 0.0021*sin(2*dr*M);
	C1 = C1 - 0.4068*sin(Mpr*dr) + 0.0161*sin(dr*2*Mpr);
	C1 = C1 - 0.0004*sin(dr*3*Mpr);
	C1 = C1 + 0.0104*sin(dr*2*F) - 0.0051*sin(dr*(M+Mpr));
	C1 = C1 - 0.0074*sin(dr*(M-Mpr)) + 0.0004*sin(dr*(2*F+M));
	C1 = C1 - 0.0004*sin(dr*(2*F-M)) - 0.0006*sin(dr*(2*F+Mpr));
	C1 = C1 + 0.0010*sin(dr*(2*F-Mpr)) + 0.0005*sin(dr*(2*Mpr+M));
	if (T < -11) 
	{
		deltat= 0.001 + 0.000839*T + 0.0002261*T2 - 0.00000845*T3 - 0.000000081*T*T3;
	} 
	else 
	{
		deltat= -0.000278 + 0.000265*T + 0.000262*T2;
	}
	JdNew = Jd1 + C1 - deltat;
	return (JdNew + 0.5 + timeZone/24);
}
// tinh toa do mat troi
char getSunLongitude(int jdn,int timeZone) 
{
	int T, T2, dr, M, L0, DL, L; 
	T = (jdn - 2451545.5 - timeZone/24) / 36525; // Time in Julian centuries from 2000-01-01 12:00:00 GMT 
	T2 = T*T; 
	dr = PI/180; // degree to radian 
	M = 357.52910 + 35999.05030*T - 0.0001559*T2 - 0.00000048*T*T2; // mean anomaly, degree 
	L0 = 280.46645 + 36000.76983*T + 0.0003032*T2; // mean longitude, degree 
	DL = (1.914600 - 0.004817*T - 0.000014*T2)*sin(dr*M); 
	DL = DL + (0.019993 - 0.000101*T)*sin(dr*2*M) + 0.000290*sin(dr*3*M); 
	L = L0 + DL; // true longitude, degree 
	L = L*dr; 
	L = L - PI*2*((int)(L/(PI*2))); // Normalize to (0, 2*PI) 
	return (int)(L / PI * 6);
}
// tinh thang nhuan
int getLeapMonthOffset(int a11,int timeZone) 
{
	int k, last, arc, i; 
	k = (int)((a11 - 2415021.076998695) / 29.530588853 + 0.5); 
	last = 0; 
	i = 1; // We start with the month following lunar month 11 
	arc = getSunLongitude(getNewMoonDay(k+i, timeZone), timeZone); 
	do { 
		last = arc; 
		i++; 
		arc = getSunLongitude(getNewMoonDay(k+i, timeZone), timeZone); 
	} while (arc != last && i < 14); 
	return i-1; 
}

void display()
{
		 vietso_UART(DS1307_Read(DS1307_DATE));
		 print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_MONTH));print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_YEAR));print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_HOUR));print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_MIN));print_UART("-");
		 vietso_UART(DS1307_Read(DS1307_SEC));
	
}	
