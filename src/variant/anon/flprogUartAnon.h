#pragma once
#include <Arduino.h>
#include "flprogUart.h"

#ifdef FLPROG_ANON_SELECT_UART

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(uint8_t portNumber = 0, int16_t newRxPin = -1, int16_t newTxPin = -1);
    void begin(int32_t speed = 0, int mode = 0, int16_t newRxPin = -2, int16_t newTxPin = -2);
    virtual bool hasPort() { return number == 0; };
    virtual void restartPort();

protected:
    virtual Stream *uartPort();
};

#endif