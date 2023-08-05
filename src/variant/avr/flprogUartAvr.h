#pragma once
#include <Arduino.h>
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_AVR
#include "SoftwareSerial.h"
namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

class FLProgSoftwareUart : public FLProgUartBasic
{
public:
    FLProgSoftwareUart(byte receivePin, byte transmitPin);
    virtual void restartPort();
    virtual bool hasPort();
    virtual void begin();
    void end();

protected:
    SoftwareSerial *softwarePort;
    virtual Stream *uartPort() { return softwarePort; };
};

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

#endif