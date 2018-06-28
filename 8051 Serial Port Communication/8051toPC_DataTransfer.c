// 8051 Serial Port communication : Data from 8051 to PC

/* Program for Serial recieving of data for PC(through Hyperterminal) from 8051
microcontroller.
*/

// Code by CH. Raghavendra Vamsi Teja

// Code format: Embedded C language | RS 232 DB9 cable interface


#include <reg51.h>
unsigned char dataTransfer[]="Greetings from 8051";   //ENTER YOUR MESSAGE INSIDE DOUBLE QUOTES
unsigned int i;
void main()
{
  TMOD=0x20; // Using Timer 1 in autoreload mode
  TH1=0xFD;     // baudrate set to 9600
  SCON=0x50;
  TR1=1;           //begin Timer
  while(1)
  {
    for(i=0;i<18;i++)
    {
      SBUF=dataTransfer[i];   // transfer data into SBUF
      while(TI==0);        // Wait for transmit interrupt
      TI=0;
    }
  }
}
