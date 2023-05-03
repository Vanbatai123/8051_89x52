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