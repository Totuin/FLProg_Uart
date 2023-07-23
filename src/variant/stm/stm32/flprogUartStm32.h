#pragma once
#include <Arduino.h>
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_STM32

#if defined(USBCON) && defined(USBD_USE_CDC)
#define FLPROG_STM32_USB_COM0
#endif

#ifdef HAVE_HWSERIAL1
#define FLPROG_STM32_SERIAL1
#endif

#ifdef HAVE_HWSERIAL2
#define FLPROG_STM32_SERIAL2
#endif

#ifdef HAVE_HWSERIAL3
#define FLPROG_STM32_SERIAL3
#endif

#ifdef HAVE_HWSERIAL4
#define FLPROG_STM32_SERIAL4
#endif

#ifdef HAVE_HWSERIAL5
#define FLPROG_STM32_SERIAL5
#endif

#ifdef HAVE_HWSERIAL6
#define FLPROG_STM32_SERIAL6
#endif

#ifdef HAVE_HWSERIAL7
#define FLPROG_STM32_SERIAL7
#endif

#ifdef HAVE_HWSERIAL8
#define FLPROG_STM32_SERIAL8
#endif

#ifdef HAVE_HWSERIAL9
#define FLPROG_STM32_SERIAL9
#endif

#ifdef HAVE_HWSERIAL10
#define FLPROG_STM32_SERIAL10
#endif

#ifdef HAVE_HWSERIALLP1
#define FLPROG_STM32_SERIAL_LP1
#endif

#ifdef HAVE_HWSERIALLP2
#define FLPROG_STM32_SERIAL_LP1
#endif

namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(uint8_t portNumber = 0, int16_t newRxPin = -1, int16_t newTxPin = -1);
    virtual void begin(int32_t speed = 0, int mode = 0, int16_t newRxPin = -2, int16_t newTxPin = -2);
    virtual bool hasPort();
    virtual void restartPort();
    virtual void end();

protected:
    virtual Stream *uartPort();
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
};

#endif