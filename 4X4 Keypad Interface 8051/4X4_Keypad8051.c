/*
8051 Microcontroller : 4X4 Matrix Keypad Interfacing Code
 Description: Button pressed on keypad will be shown on LCD Module.
 NOTE: 1.The value of Button pressed on Keypad can be changed upon developer's requirements. Replace the value within the
 '__' with desired value in RowFinder1,RowFinder2,RowFinder3,RowFinder4 functions.
       2. If your Keypad is of 4X3 matrix avoid sbit "C4=P2^3", "if (c4==0)" block and "RowFinder4()" function wherever mentioned.
*/
// Code by: Raghavendra Vamsi Teja
// Code Format: Embeddded C

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include<reg51.h>
sfr ldata=0x90;               // Port 1 used for 16X2 LCD display pin D0-D7
sbit rs=P3^0;                 // Register select of LCD Module
sbit rw=P3^1;                // Read/Write
sbit en=P3^2;                // Enable

sbit c1 =P2^0;   //column 1 pin to port2-pin0
sbit c2 =P2^1;   //column 2 pin to port2-pin1
sbit c3 =P2^2;   //column 3 pin to port2-pin2
sbit c4 =P2^3;   //column 4 pin to port2-pin3
sbit r1 =P2^4;    //row 1 pin to port2-pin4
sbit r2 =P2^5;    //row 1 pin to port2-pin5
sbit r3 =P2^6;    //row 1 pin to port2-pin6
sbit r4 =P2^7;    //row 1 pin to port2-pin7

void msDelay(unsigned int time);   // function to create delay in milliseconds
void LCD_Cmd(unsigned char command);  //function for LCD commands
void LCD_Data(unsigned char value); //function for displaying data on LCD
void LCD_init();   //Function for initializing LCD Module
void RowFinder1(); //Function for Checking rows in column 1
void RowFinder2();    //Function for Checking rows in column 2
void RowFinder3();     //Function for Checking rows in column 3
void RowFinder4();     //Function for Checking rows in column 4
unsigned int i,j;

void main()
{
LCD_init();
while (1) {
  msDelay(10);
  c1=c2=c3=c4=1;
  r1=r2=r3=r4=0;
  if(c1==0)          //If column is zero , then the condtion directs to find row number thus knowing which button is pressed in column 1
  {
    RowFinder1();
  }
  else if(c2==0)   //If column is zero , then the condtion directs to find row number thus knowing which button is pressed in column 2
  {
    RowFinder2();
  }
  else if(c3==0)  //If column is zero , then the condtion directs to find row number thus knowing which button is pressed in column 3
  {
    RowFinder3();
  }
  else if(c4==0)   //If column is zero , then the condtion directs to find row number thus knowing which button is pressed in column 4
  {
    RowFinder4();
  }
}
}

void msDelay(unsigned int time)
{
   for(i=0;i<time;i++) //Number of milliseconds
   for(j=0;j<1275;j++);    // Each millisecond with reference to machine cycle
 }


void LCD_Cmd(unsigned char command)
{
  ldata=command;    // commands will initialize LCD Module. Command are given at LCD_init function
  rs=0;
  rw=0;
  en=1;
  msDelay(10);
  en=0;
  return;
}

void LCD_init()
{
  LCD_Cmd(0x38); // enable 2 lines and 5x7 matrix of LCD Module
  msDelay(10);
  LCD_Cmd(0x0F);    //Display ON, cursor blinking
  msDelay(10);
  LCD_Cmd(0x01);   //Clear Display screen
  msDelay(10);
  LCD_Cmd(0x81);   //cursor position at 1st block
  msDelay(10);
  return;
}
void LCD_Data(unsigned char value)
{
   ldata=value; // assign value to port 1
   rs=0;
   rw=0;
   en=1;
   msDelay(10);
   en=0;
   return;
 }

void RowFinder1()  // checking rows of column 1
{
  r1=r2=r3=r4=0;
  c1=c2=c3=c4=0;
  if(r1==0)
  {
    LCD_Data('1');
  }
  if(r2==0)
  {
    LCD_Data('4');
  }
  if(r3==0)
  {
    LCD_Data('7');
  }
  if(r4==0)
  {
    LCD_Data('*');
  }
}

void RowFinder2()    // checking rows of column 2
{
  r1=r2=r3=r4=0;
  c1=c2=c3=c4=0;
  if(r1==0)
  {
    LCD_Data('2');
  }
  if(r2==0)
  {
    LCD_Data('5');
  }
  if(r3==0)
  {
    LCD_Data('8');
  }
  if(r4==0)
  {
    LCD_Data('0');
  }
}

void RowFinder3()     // checking rows of column 3
{
  r1=r2=r3=r4=0;
  c1=c2=c3=c4=0;
  if(r1==0)
  {
    LCD_Data('3');
  }
  if(r2==0)
  {
    LCD_Data('6');
  }
  if(r3==0)
  {
    LCD_Data('9');
  }
  if(r4==0)
  {
    LCD_Data('#');
  }
}

void RowFinder4()      // checking rows of column 4
{
  r1=r2=r3=r4=0;
  c1=c2=c3=c4=0;
  if(r1==0)
  {
    LCD_Data('A');
  }
  if(r2==0)
  {
    LCD_Data('B');
  }
  if(r3==0)
  {
    LCD_Data('C');
  }
  if(r4==0)
  {
    LCD_Data('D');
  }
}
