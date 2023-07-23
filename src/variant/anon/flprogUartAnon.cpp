#include "flprogUartAnon.h"

#ifdef FLPROG_ANON_SELECT_UART

FLProgUart::FLProgUart(uint8_t portNumber, int16_t newRxPin, int16_t newTxPin)
{
    number = portNumber;
}

void FLProgUart::restartPort()
{
    end();
    begin();
}

void FLProgUart::end()
{
    if (number != 0)
    {
        return;
    }
    Serial.end();
}

void FLProgUart::begin(int32_t speed, int mode, int16_t newRxPin, int16_t newTxPin)
{
    if (number != 0)
    {
        return;
    }
    Serial.begin();
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