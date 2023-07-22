#pragma once
#include <Arduino.h>
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_ESP32
#if CONFIG_IDF_TARGET_ESP32C3 || CONFIG_IDF_TARGET_ESP32S3
#define FLPROG_USE_ESP32_USB_SERIAL
#endif

#include "flprogUartBluetoothSerial.h"

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart();
    FLProgUart(uint8_t portNumber);
    FLProgUart(uint8_t portNumber, uint8_t newRxPin, uint8_t newTxPin);
    virtual void begin();
    virtual void begin(int32_t speed, int mode);
    virtual void begin(int32_t speed);
    virtual bool hasPort();
    virtual void restartPort();

protected:
    virtual Stream *uartPort();
    virtual void resetPort();
    HardwareSerial *port;
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
    virtual void setPort();
    virtual void stopPort();
    virtual void startPort();
};

namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

#endif
