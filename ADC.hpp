#ifndef ADC_DRIVER_H_
#define ADC_DRIVER_H_

#include <stdio.h>
#include "LPC17xx.h"
#include "FreeRTOS.h"
#include "io.hpp"

class ADCDriver
{
public:
    enum ADC_PIN
    {
        ADC_PIN_0_25,       // AD0.2 <-- Light Sensor --> 0
        ADC_PIN_0_26,       // AD0.3 1
        ADC_PIN_1_30,       // AD0.4 2
        ADC_PIN_1_31,       // AD0.5 3

    };

    // Nothing needs to be done within the default constructor
    ADCDriver();

    /**
    * 1) Powers up ADC peripheral
    * 2) Set peripheral clock
    * 2) Enable ADC
    * 3) Select ADC channels
    * 4) Enable burst mode
    */
    void adcInitBurstMode();

    /**
    * 1) Selects ADC functionality of any of the ADC pins that are ADC capable
    *
    * @param adc_pin_arg is the ADC_PIN enumeration of the desired pin.
    *
    * WARNING: For proper operation of the SJOne board, do NOT configure any pins
    *           as ADC except for 0.26, 1.31, 1.30
    */
    void adcSelectPin(ADC_PIN adc_pin_arg);

    /**
    * 1) Returns the voltage reading of the 12bit register of a given ADC channel
    *
    * @param adc_channel_arg is the number (0 through 7) of the desired ADC channel.
    */
    float readADCVoltageByChannel(uint8_t adc_channel_arg);
};

#endif
