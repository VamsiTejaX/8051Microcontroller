// 8051 Microcontroller : 16X2 LCD Interfacing Code
// Code by: Raghavendra Vamsi Teja
// Code Format: Embeddded C




#include<reg51.h>
sfr ldata=0x90; // LCD module data pins D0-D7 interfaced with port 1
sbit rs=P2^0;   // Regester select
sbit rw=P2^1;   // Read/write to LCD
sbit en=P2^2;   // Enable to LCD

void lcdcmd(unsigned char);
void lcddata(unsigned char);
void MSDelay(unsigned int);


void lcdcmd(unsigned char value)
{
ldata=value;
rs=0;
rw=0;
en=1;
MSDelay(25);
en=0;
}


void lcddata(unsigned char value)
{
ldata=value;
rs=1;
rw=0;
en=1;
MSDelay(25);
en=0;
return;
}
void MSDelay(unsigned int itime)
{
unsigned int i,j;
for(i=1;i<itime;i++)
{
for(j=0;j<1257;j++);
}
}
void main(void)
{
lcdcmd(0x38);   //enabling 16X2 matrix i.e both lines of 16 block LCD
MSDelay(25);
lcdcmd(0x0E);   //Blinking cursor
MSDelay(25);
lcdcmd(0x01);  //Clear screen
MSDelay(25);
lcdcmd(0x06);   // Increment cursor to right
MSDelay(25);
lcdcmd(0x86);   //cursor begins at 1st(8) line 6th Block(6).
MSDelay(25);
lcddata('M');  // comment from this line until the next 5th line if you want to display string innstead of each char and uncomment the commented code section below
MSDelay(25);
lcddata('D');
MSDelay(25);
lcddata('E');   //Prints MDE

/*
// Displaying String instead of single character at a time.
unsigned int k;
unsigned char val;
unsigned char info[]="MDE";
for(i=0;i<3;i++)  // i<3 because MDE consits three letters.
{
  val=info[i];
  lcddata(val);
  MSDelay(10);
}
*/
	while(1)
	{
	}
}
