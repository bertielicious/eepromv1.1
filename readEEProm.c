#include "config.h"
#include "picEEPromOutputs.h"
#include "picEEPromInputs.h"
#include "setAddress.h"
#include <stdio.h>

uchar readEEProm(uint address)
{
    uchar byte = 0;
    WE = 1;             // write enable on EEPROM is disabled
    picEEPromOutputs();
    setAddress(address,OUTPUT_EN); // put address where you want to read from on the address inputs of the EEPROM, then enable EEPROM outputs
    picEEPromInputs();  // set  PIC  I/O pins connected to EEPROM to inputs
    // read each of the 8 bits stored at the EEPROM address and assemble them into a byte
    byte = PORTCbits.RC3|(PORTCbits.RC2<<1)|(PORTCbits.RC1<<2)|(PORTCbits.RC0<<3)|(PORTBbits.RB6<<4)|(PORTBbits.RB5<<5)|(PORTBbits.RB4<<6)|(PORTAbits.RA5<<7);
    __delay_ms(10);
    printf("readEEProm RA5 = %d\n", PORTAbits.RA5);
    printf("readEEProm RB4 = %d\n", PORTBbits.RB4);
    printf("readEEProm RB5 = %d\n", PORTBbits.RB5);
    printf("readEEProm RB6 = %d\n", PORTBbits.RB6);
    printf("readEEProm RC0 = %d\n", PORTCbits.RC0);
    printf("readEEProm RC1 = %d\n", PORTCbits.RC1);
    printf("readEEProm RC2 = %d\n", PORTCbits.RC2);
    printf("readEEProm RC3 = %d\n", PORTCbits.RC3);
    printf("read EEProm byte = %d\n", byte);
    
    return byte;// return value of byte to caller
}
