#pragma once
#include "Arduino.h"
#include "flprogUtilites.h"


class FLProgUartBasic : public FLProgStream
{
public:
    virtual void begin(){};
    virtual void begin(int32_t speed);
    uint8_t getPortSpeed() { return portSpeed; };
    uint8_t getPortDataBits() { return portDataBits; };
    uint8_t getPortStopBits() { return portStopBits; };
    uint8_t getPortParity() { return portParity; };
    virtual bool hasPort() { return false; };
    virtual void restartPort(){};
    void setPortSpeed(uint8_t speed);
    void setPortDataBits(uint8_t dataBits);
    void setPortStopBits(uint8_t stopBits);
    void setPortParity(uint8_t parity);
    virtual void setDeviceName(String name);
    virtual void changePins(int16_t newRxPin, int16_t newTxPin);
    virtual void changePort(uint16_t newPort);
    virtual void changePinsAndPort(int16_t newPort, int16_t newRxPin, int16_t newTxPin);

protected:
    virtual Stream *stream() { return uartPort(); };
    virtual Stream *uartPort() { return 0; };
    uint32_t speedFromCode();
    int serialCodeForParametrs();
    void setCodeFromSpeed(int32_t speed);
    virtual void setPort(){};
    virtual void resetPort(){};
    virtual void stopPort(){};
    virtual void startPort(){};

    uint8_t portSpeed = FLPROG_SPEED_9600;
    uint8_t portDataBits = FLPROG_PORT_DATA_BITS_8;
    uint8_t portStopBits = FLPROG_PORT_STOP_BITS_1;
    uint8_t portParity = FLPROG_PORT_PARITY_NONE;
    int16_t rxPin = -1;
    int16_t txPin = -1;
    uint8_t number = 0;
};

#ifdef ARDUINO_ARCH_AVR
#define FLPROG_EXISTS_SELECT_UART
#include "variant/avr/flprogUartAvr.h"
#endif

#ifdef ARDUINO_ARCH_SAM
#define FLPROG_EXISTS_SELECT_UART
#include "variant/due/flprogUartDUE.h"
#endif

#ifdef ARDUINO_ARCH_ESP8266
#define FLPROG_EXISTS_SELECT_UART
#include "variant/esp/esp8266/flprogUatrEsp8266.h"
#endif

#ifdef ARDUINO_ARCH_ESP32
#define FLPROG_EXISTS_SELECT_UART
#include "variant/esp/esp32/flprogUartEsp32.h"
#endif

#ifdef ARDUINO_ARCH_STM32
#define FLPROG_EXISTS_SELECT_UART
#include "variant/stm/stm32/flprogUartStm32.h"
#endif


#ifdef ARDUINO_ARCH_RP2040
#define FLPROG_EXISTS_SELECT_UART
#include "variant/rp2040/flprogRP2040.h"
#endif



#ifndef FLPROG_EXISTS_SELECT_UART
#define FLPROG_EXISTS_SELECT_UART
#define FLPROG_ANON_SELECT_UART
#include "variant/anon/flprogUartAnon.h"
#endif
