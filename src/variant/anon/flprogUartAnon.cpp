#include "flprogUartAnon.h"

#ifdef FLPROG_ANON_SELECT_UART

FLProgUart::FLProgUart(uint8_t portNumber, int16_t newRxPin, int16_t newTxPin)
{
    number = portNumber;
}

void FLProgUart::restartPort()
{
    if (number == 0)
    {
        Serial.end();
        begin();
    }
}

void FLProgUart::begin(int32_t speed, int mode, int16_t newRxPin, int16_t newTxPin)
{
    if (number == 0)
    {
        Serial.begin();
    }
}

Stream *FLProgUart::uartPort()
{
    if (number == 0)
    {
        return &Serial;
    }
    return 0;
};

#endif