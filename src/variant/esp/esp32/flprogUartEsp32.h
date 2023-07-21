#pragma once
#include <Arduino.h>
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_ESP32

#include "flprogUartBluetoothSerial.h"

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart();
    FLProgUart(uint8_t portNumber);
    FLProgUart(uint8_t portNumber, uint8_t newRxPin, uint8_t newTxPin);
    virtual void begin();
    void begin(int32_t speed, int mode);
    virtual bool hasPort() { return !(port == 0); };
    virtual void restartPort();

protected:
    virtual Stream *uartPort() { return port; };
    HardwareSerial *port;
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);

private:
    void setPort(uint8_t portNumber);
};

namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

#endif
