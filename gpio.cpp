#include "GPIO_1.hpp"
    LabGPIO_1::LabGPIO_1(uint8_t pin)
    {
      pinnum=pin;

    //LPC_PINCON ->PINSEL2 &= ~ (0xF<<pinnum);
    //LPC_PINCON ->PINSEL2 &= ~(0xF<<pinnum);
    }

    void LabGPIO_1:: setAsInput()
    {
    LPC_GPIO1 ->FIODIR &= ~(1<<pinnum);
    }

    void LabGPIO_1:: setAsOutput()
    {
    LPC_GPIO1->FIODIR |= (1<<pinnum);
    }

    void LabGPIO_1:: setDirection(bool output)
    {
    if (output)
        setAsOutput();
    else
        setAsInput();
    }

    void LabGPIO_1:: setHigh()
    {
        //LPC_GPIO1->FIOPIN |= (1<<pinnum);
        LPC_GPIO1->FIOSET |= (1<<pinnum);
    }
    void LabGPIO_1:: setLow()
    {
         //LPC_GPIO1->FIOPIN &= ~(1<<pinnum);
        LPC_GPIO1->FIOCLR |= (1<<pinnum);
    }

    void LabGPIO_1:: set(bool high)
    {
        if (high)
            setHigh();
        else
            setLow();
     }


    bool LabGPIO_1::getLevel()
    {
        bool flag;
        flag = (LPC_GPIO1 -> FIOPIN & (1<<pinnum));
        return flag;
    }
