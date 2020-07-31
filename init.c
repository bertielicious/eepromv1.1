#include <xc.h>
#include "config.h"
#include "picEEPromOutputs.h"
void init(void)
{
    /* turn off adc module and comparators*/
    ANSEL = 0x00;
    ANSELH = 0x00;  // ADC module off
    CM1CON0 = 0x00;
    CM2CON0 = 0x00; // comparators off
    
    /* internal clock setup*/
    OSCCONbits.IRCF2 = 1;           // 4 MHz clock configuration
    OSCCONbits.IRCF1 = 1;
    OSCCONbits.IRCF0 = 0;
    
    /* setup PORTA an PORTC pins as outputs*/
    
    TRISCbits.TRISC4 = 0;            // RC4 = SERIAL DATA OUT   pin 6
    TRISCbits.TRISC5 = 0;            // RC5 = SHIFT CLOCK OUT   pin 5
    TRISCbits.TRISC6 = 0;            // RC6 = LATCH CLOCK       pin 8
    TRISCbits.TRISC7 = 0;            // RC7 = WE active low     pin 9
    
    TRISAbits.TRISA2 = 0;            // RA2 = DIAGNOSTIC LED    pin 17
    
    /* PICEEProm Outputs */
    picEEPromOutputs();
}
