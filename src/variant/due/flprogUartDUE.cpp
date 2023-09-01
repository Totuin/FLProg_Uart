#include "flprogUartDUE.h"

#ifdef ARDUINO_ARCH_SAM

UARTClass::UARTModes flprog::serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity)
{
    return serialModeFromInt(serialCodeForParametrs(portDataBits, portStopBits, portParity));
}

UARTClass::UARTModes flprog::serialModeFromInt(int16_t code)
{
    switch (code)
    {
    case 0x06:
        return SERIAL_8N1;
        break;
    case 0x26:
        return SERIAL_8E1;
        break;
    case 0x36:
        return SERIAL_8O1;
        break;
    }
    return SERIAL_8N1;
}

FLProgUart::FLProgUart(uint8_t portNumber, int16_t newRxPin, int16_t newTxPin)
{
    number = portNumber;
    (void)newRxPin;
    (void)newTxPin;
}

void FLProgUart::end()
{
    if (!portIsInit)
    {
        return;
    }
    if (number == 0)
    {
        Serial.end();
    }
    if (number == 1)
    {
        Serial1.end();
    }
    if (number == 2)
    {
        Serial2.end();
    }
    if (number == 3)
    {
        Serial3.end();
    }
}

void FLProgUart::restartPort()
{
    stopPort();
    begin();
}

Stream *FLProgUart::uartPort()
{
    if (number == 0)
    {
        return &Serial;
    }
    if (number == 1)
    {
        return &Serial1;
    }
    if (number == 2)
    {
        return &Serial2;
    }
    if (number == 3)
    {
        return &Serial3;
    }
    return 0;
}

bool FLProgUart::hasPort()
{
    return number < 4;
}

void FLProgUart::begin()
{
    portIsInit = true;

    if (number == 0)
    {
        Serial.begin(speedFromCode(), serialModeFromParametrs());
        return;
    }
    if (number == 1)
    {
        Serial1.begin(speedFromCode(), serialModeFromParametrs());
        return;
    }
    if (number == 2)
    {
        Serial2.begin(speedFromCode(), serialModeFromParametrs());
        return;
    }
    if (number == 3)
    {
        Serial3.begin(speedFromCode(), serialModeFromParametrs());
        return;
    }
}

void FLProgUart::begin(int32_t speed, UARTClass::UARTModes mode, int16_t newRxPin, int16_t newTxPin)
{
    setCodeFromSpeed(speed);
    setSerialMode(mode);
    begin();
    (void)newRxPin;
    (void)newTxPin;
}

UARTClass::UARTModes FLProgUart::serialModeFromParametrs()
{
    return flprog::serialModeFromInt(serialCodeForParametrs());
}

void FLProgUart::setSerialMode(UARTClass::UARTModes mode)
{
    switch (mode)
    {
    case SERIAL_8N1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_8E1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_8O1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    default:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        break;
    }
}

FLProgSoftwareUart::FLProgSoftwareUart(uint8_t receivePin, uint8_t transmitPin)
{
    (void)receivePin;
    (void)transmitPin;
}

#endif