void _delay_us(unsigned int us)
{    
 while(us--);
}
//----------------------------------------------
void _delay_ms(unsigned int ms)
{
 unsigned int x,y;
 for(x=0;x<ms;x++)
 for(y=0;y<=125;y++);
}