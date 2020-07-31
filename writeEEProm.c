#include "config.h"
#include "picEEPromOutputs.h"
#include "setAddress.h"
#include <stdio.h>

void writeEEProm(uint address, uchar data)
{
    
    setAddress(address, INPUT_EN);
    __delay_ms(1);

   
    WE = 0;
    __delay_us(120);
    WE = 1;
    
    PORTAbits.RA5 = (data&0b10000000)>>7;
    PORTBbits.RB4 = (data&0b01000000)>>6;    
    PORTBbits.RB5 = (data&0b00100000)>>5;   
    PORTBbits.RB6 = (data&0b00010000)>>4;   
    PORTCbits.RC0 = (data&0b00001000)>>3;   
    PORTCbits.RC1 = (data&0b00000100)>>2;    
    PORTCbits.RC2 = (data&0b00000010)>>1;   
    PORTCbits.RC3 = (data&0b00000001);
    
     __delay_ms(10);
    
    printf("RA5 = %d\n", PORTAbits.RA5);
    printf("RB4 = %d\n", PORTBbits.RB4);
    printf("RB5 = %d\n", PORTBbits.RB5);
    printf("RB6 = %d\n", PORTBbits.RB6);
    printf("RC0 = %d\n", PORTCbits.RC0);
    printf("RC1 = %d\n", PORTCbits.RC1);
    printf("RC2 = %d\n", PORTCbits.RC2);
    printf("RC3 = %d\n", PORTCbits.RC3);
} 
