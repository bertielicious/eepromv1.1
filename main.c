#include "config.h"
//#include "putch.h"
#include <stdio.h>
#include "init.h"
#include "initEusart.h"
#include "serialByte.h"
#include "latchClock.h"
#include "setAddress.h"
#include "readEEProm.h"
#include "writeEEProm.h"
#include "picEEPromOutputs.h"
uchar counter, index, result = 0;
//uchar num[16]={0x77,0x44,0x3d,0x6d,0x1e,0x6b,0x7b,0x45,0x7f,0x6f,0x5f,0x7a,0x33,0x7c,0x3b,0x1b};
//uchar num[16]={0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff,0xff};
uchar num[16]={119,68,61,109,30,107,123,69,127,111,95,122,51,124,59,27};
int main(void)
{
    init();
    initEusart();
    for(index = 0; index <16; index++)
    {
        WE = 1;     // write enable bit is high
        picEEPromOutputs(); // clear TRIS reg of all PIC I/O connected to EEProm D0-D7
        writeEEProm(index, num[index]);
        result = readEEProm(index);
        printf("index = %d     result = %d\n", index,  result);
    }
    while(1)
    {
     
    }
    return 0;
}
