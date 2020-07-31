#include "config.h"
#include "stdbool.h"
#include "serialByte.h"
#include <stdio.h>
/*Converts decimal value (range 0 to 255) to a byte of binary data which is 
 * transmitted serially to 74HC595 shift register
 * Only 3 pins are used from the microcontroller to achieve an
 * I/O expansion of 8/16/24/32/64 bits.
 */
void serialByte(uchar value)        
{
    signed char index;
    bool bit[8];
    for(index = 7; index >= 0; index--)
    {   
        bit[index] = value/(0b00000001<<index);
    
        value = value%(0b00000001<<index);
      
        SERIAL_DATA = bit[index];
        SHIFT_CLOCK = 0;
     
        SHIFT_CLOCK = 1;
      
        SHIFT_CLOCK = 0;            
    }
}
