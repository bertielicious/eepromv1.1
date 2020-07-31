#include "config.h"
void picEEPromOutputs(void)
{
    TRISCbits.TRISC3 = 0;   //pin 7 //LSB
    TRISCbits.TRISC2 = 0;   //pin 14
    TRISCbits.TRISC1 = 0;   //pin 15
    TRISCbits.TRISC0 = 0;   //pin 16
    TRISBbits.TRISB6 = 0;   //pin 11
    TRISBbits.TRISB5 = 0;   //pin 12
    TRISBbits.TRISB4 = 0;   //pin 13
    TRISAbits.TRISA5 = 0;   //pin 2  //MSB
}
