
// 8051 Serial Port communication : Data from PC to 8051 and its interfaced LCD

/* Program for Serial receiving of data from PC(through Hyperterminal) to 8051
microcontroller and to display received data on 16X2 LCD display
NOTE: The following code is meant to transmitt only one letter or number or symbol
 at time i.e word or sentence cannot be sent at a single unit time.  */

// Code by CH. Raghavendra Vamsi Teja

// Code format: Embedded C language | RS 232 DB9 cable interface


#include <reg51.h>

sbit rs=P2^0;                //Register select initialization of LCD Module at Port2-pin0
sbit rw=P2^1;               // Read/Write initialization of LCD Module at Port2-pin1
sbit en=P2^2;              //Enable initialization of LCD Module at Port2-pin2
sfr ldata = 0x90;         // Port 1 initialization

void msDelay(unsigned int time);   // function to create delay in milliseconds
void LCD_Cmd(unsigned char command);  //function for LCD commands
void LCD_Data(unsigned char value); //function for displaying data on LCD
void LCD_init();   //Initializing LCD Module
unsigned int i,j;
void main()
{
  unsigned char info;
  LCD_init();
  TMOD=0x20;       // Timer 1 8 bit auto reload mode
  TH1=0xFD;       // Baud Rate set to 9600
  SCON=0X50;
  TR1=1;          // Begin timer
  while(1)
  {
    while(RI==0);  // wait for receive interrupt
    info=SBUF;    // Transfer Incomming Data fro PC stored in Serial Buffer into variable info
    LCD_Data(info); // Display Data on LCD
    msDelay(5);
    RI=0;
    msDelay(5);
    TF1=0;
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
