#include "LabADC.hpp"
#include "LPC17xx.h"
#include <stdio.h>
#include <stdint.h>

ADCDriver::ADCDriver()
{
}

void ADCDriver::adcInitBurstMode()
{
    LPC_SC->PCONP |= (1 << 12); // turn on adc
    LPC_ADC->ADCR |= ((1 << 16) | (1 << 21)); // burst mode

    //clock select
    LPC_SC->PCLKSEL0 &= ~(3 << 24); //clear PCLKSEL0[25:24]
    LPC_SC->PCLKSEL0 |= (1 << 24); //set PCLKSEL[25:24] to 01
    puts("ADC clock select");
}

void ADCDriver::adcSelectPin(ADC_PIN adc_pin_arg)
{
    switch (adc_pin_arg) {
        case 0:
            LPC_ADC->ADCR |= (1 << 2); //P0.25 -> ADC2 (light sensor
            LPC_PINCON->PINSEL1 &= ~(3 << 18);
            LPC_PINCON->PINSEL1 |= (1 << 18); //setting to 01
            puts("channel 2");
            break;
        case 1:
            LPC_ADC->ADCR |= (1 << 3); //P0.26 -> ADC3
            LPC_PINCON->PINSEL1 &= ~(3 << 20);
            LPC_PINCON->PINSEL1 |= (1 << 20); //setting to 01
            puts("channel 3");
            break;
        case 2:
            LPC_ADC->ADCR |= (1 << 4); //P1.30 -> ADC4
            LPC_PINCON->PINSEL3 |= (3 << 28);//setting to 11
            puts("channel 4");
            break;
        case 3:
            LPC_ADC->ADCR |= (1 << 5); //P1.31 -> ADC5
            LPC_PINCON->PINSEL3 |= (3 << 30);//setting to 11
            puts("channel 5");
            break;
        default:
            break;
    }
}

float ADCDriver::readADCVoltageByChannel(uint8_t channel_sel)
{
    while (!((LPC_ADC->ADSTAT & (1 << 2))))//wait till the channel 2 register is high (have to come up with a better way to change this
        ;
    uint32_t result=0;
    uint32_t res;
    switch (channel_sel) {
        case 0:
            result = LPC_ADC->ADDR2 & (0xFFF0);
            puts("channel 2");
            break;

        case 1:
            result = LPC_ADC->ADDR3 & (0xFFF0);
            puts("channel 3");
            break;

        case 2:
            result = LPC_ADC->ADDR4 & (0xFFF0);
            puts("channel 4");
            break;

        case 3:
            result = LPC_ADC->ADDR5 & (0xFFF0);
            puts("channel 5");
            break;
        default:
            break;

    }
    res = result >> 4;
    return res;
}
