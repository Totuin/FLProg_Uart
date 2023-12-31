#pragma once
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_ESP8266
#include "SoftwareSerial.h"

#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL)
#define FLPROG_ESP8266_HAS_UART0
#endif
#if !defined(NO_GLOBAL_INSTANCES) && !defined(NO_GLOBAL_SERIAL1)
#define FLPROG_ESP8266_HAS_UART1
#endif

namespace flprog
{
    SerialConfig serialModeFromInt(int16_t code);
    SerialConfig serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

class FLProgSoftwareUart : public FLProgUartBasic
{
public:
    FLProgSoftwareUart(byte receivePin, byte transmitPin);
    virtual void restartPort();
    virtual bool hasPort();
    virtual void begin();

protected:
    SoftwareSerial *softwarePort;
    virtual Stream *uartPort() { return softwarePort; };
};

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(uint8_t portNumber = 0, int16_t newRxPin = -1, int16_t newTxPin = -1);
    virtual void begin();
    void begin(int32_t speed, SerialConfig mode = SERIAL_8N1, int16_t newRxPin = -2, int16_t newTxPin = -2);
    virtual bool hasPort();
    virtual void restartPort();
    void end();

protected:
    virtual Stream *uartPort();
    SerialConfig serialModeFromParametrs();
    void setSerialMode(SerialConfig mode);
};

#endif