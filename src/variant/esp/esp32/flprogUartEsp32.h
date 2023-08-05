#pragma once
#include <Arduino.h>
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_ESP32
#include "flprogUartBluetoothSerial.h"

#if (CONFIG_IDF_TARGET_ESP32C3 || CONFIG_IDF_TARGET_ESP32S3)
#if ARDUINO_USB_CDC_ON_BOOT
#define FLPROG_USE_ESP32_SERIAL_FOR_USB
#else
#define FLPROG_USE_ESP32_USBSERIAL
#endif
#else
#if CONFIG_TINYUSB_CDC_ENABLED
#define FLPROG_USE_ESP32_SERIAL_FOR_USB
#endif
#endif

#if SOC_UART_NUM > 1
#define FLPROG_USE_ESP32_SERIAL1
#endif

#if SOC_UART_NUM > 2
#define FLPROG_USE_ESP32_SERIAL2
#endif

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
