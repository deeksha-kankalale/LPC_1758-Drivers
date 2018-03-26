/*
 *  LABGPIO_1.hpp
 *
 *  Created on: Feb 18, 2018
 *      Author: deeksha
 */

#ifndef LABGPIO_1_HPP_
#define LABGPIO_1_HPP_
#include "LPC17xx.h"

class LabGPIO_1
{
private:

    uint8_t pinnum;

public:

    LabGPIO_1(uint8_t pin);

    void setAsInput();
    void setAsOutput();
    void setDirection(bool output);

    void setHigh();
    void setLow();

    void set(bool high);


    bool getLevel();



   // ~LabGPIO_1();
};






#endif /* LABGPIO_1_HPP_ */
