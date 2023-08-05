#pragma once
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_RP2040

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(uint8_t portNumber = 0, int16_t newRxPin = -1, int16_t newTxPin = -1);
    virtual void begin() { begin(0); };
    void begin(int32_t speed, int mode = 0, int16_t newRxPin = -2, int16_t newTxPin = -2);
    virtual bool hasPort();
    virtual void restartPort();
    void end();

protected:
    virtual Stream *uartPort();
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
};

namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

#endif