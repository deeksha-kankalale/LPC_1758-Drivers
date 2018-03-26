
#include "LABGPIO_1.hpp"
#include <stdio.h>

int main()
{
    LabGPIO_1 LEDex(19);
    LabGPIO_1 SWITCHex(22);

    LEDex.setAsOutput();
    SWITCHex.setAsInput();
    while(1)
    {
        if (SWITCHex.getLevel())
        LEDex.set(1);
        else
        LEDex.set(0);
    }
}



