#include "config.h"
void latchClock(void)
{
    LATCH_CLOCK = 0; 
    LATCH_CLOCK = 1;
    LATCH_CLOCK = 0;   
}
