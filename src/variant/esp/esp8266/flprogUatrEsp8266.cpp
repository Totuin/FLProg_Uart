#include "flprogUatrEsp8266.h"
#ifdef ARDUINO_ARCH_ESP8266
SerialConfig flprog::serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity)
{
    return serialModeFromInt(serialCodeForParametrs(portDataBits, portStopBits, portParity));
}

SerialConfig flprog::serialModeFromInt(int16_t code)
{
    switch (code)
    {
    case 0x00:
        return SERIAL_5N1;
        break;
    case 0x02:
        return SERIAL_6N1;
        break;
    case 0x04:
        return SERIAL_7N1;
        break;
    case 0x06:
        return SERIAL_8N1;
        break;
    case 0x08:
        return SERIAL_5N2;
        break;
    case 0x0A:
        return SERIAL_6N2;
        break;
    case 0x0C:
        return SERIAL_7N2;
        break;
    case 0x0E:
        return SERIAL_8N2;
        break;
    case 0x20:
        return SERIAL_5E1;
        break;
    case 0x22:
        return SERIAL_6E1;
        break;
    case 0x24:
        return SERIAL_7E1;
        break;
    case 0x26:
        return SERIAL_8E1;
        break;
    case 0x28:
        return SERIAL_5E2;
        break;
    case 0x2A:
        return SERIAL_6E2;
        break;
    case 0x2C:
        return SERIAL_7E2;
        break;
    case 0x2E:
        return SERIAL_8E2;
        break;
    case 0x30:
        return SERIAL_5O1;
        break;
    case 0x32:
        return SERIAL_6O1;
        break;
    case 0x34:
        return SERIAL_7O1;
        break;
    case 0x36:
        return SERIAL_8O1;
        break;
    case 0x38:
        return SERIAL_5O2;
        break;
    case 0x3A:
        return SERIAL_6O2;
        break;
    case 0x3C:
        return SERIAL_7O2;
        break;
    case 0x3E:
        return SERIAL_8O2;
        break;
    }
    return SERIAL_8N1;
}

//--------------------------------------------FLProgSoftwareUart-----------------------

FLProgSoftwareUart::FLProgSoftwareUart(byte receivePin, byte transmitPin)
{
    softwarePort = new SoftwareSerial(receivePin, transmitPin);
}

bool FLProgSoftwareUart::hasPort()
{
    return !(softwarePort == 0);
}

void FLProgSoftwareUart::restartPort()
{
    if (hasPort())
    {
        softwarePort->end();
        begin();
    }
}

void FLProgSoftwareUart::begin()
{
    if (hasPort())
    {
        softwarePort->begin(speedFromCode());
    }
}

//--------------------------------------------FLProgUart-----------------------

FLProgUart::FLProgUart(uint8_t portNumber, int16_t newRxPin, int16_t newTxPin)
{
    number = portNumber;
    (void)newRxPin;
    (void)newTxPin;
}

void FLProgUart::restartPort()
{
    end();
    begin();
}

void FLProgUart::end()
{
#ifdef FLPROG_ESP8266_HAS_UART0
    if (number == 0)
    {
        Serial.end();
    }
#endif
#ifdef FLPROG_ESP8266_HAS_UART1
    if (number == 1)
    {
        Serial1.end();
    }
#endif
}

void FLProgUart::begin()
{
#ifdef FLPROG_ESP8266_HAS_UART0
    if (number == 0)
    {
        Serial.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_ESP8266_HAS_UART1
    if (number == 1)
    {
        Serial1.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
}

void FLProgUart::begin(int32_t speed, SerialConfig mode, int16_t newRxPin, int16_t newTxPin)
{
    setCodeFromSpeed(speed);
    setSerialMode(mode);
    begin();
    (void)newRxPin;
    (void)newTxPin;
}

bool FLProgUart::hasPort()
{
    return uartPort() != 0;
};

Stream *FLProgUart::uartPort()
{
#ifdef FLPROG_ESP8266_HAS_UART0
    if (number == 0)
    {
        return &Serial;
    }
#endif
#ifdef FLPROG_ESP8266_HAS_UART1
    if (number == 1)
    {
        return &Serial1;
    }
#endif
    return 0;
}

SerialConfig FLProgUart::serialModeFromParametrs()
{
    return flprog::serialModeFromInt(serialCodeForParametrs());
}

void FLProgUart::setSerialMode(SerialConfig mode)
{
    switch (mode)
    {
    case SERIAL_5N1:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_6N1:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_7N1:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_8N1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_5N2:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_6N2:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_7N2:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_8N2:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case SERIAL_5E1:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_6E1:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_7E1:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_8E1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_5E2:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_6E2:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_7E2:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_8E2:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case SERIAL_5O1:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_6O1:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_7O1:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_8O1:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_5O2:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_6O2:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_7O2:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case SERIAL_8O2:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    }
    portDataBits = FLPROG_PORT_DATA_BITS_8;
    portStopBits = FLPROG_PORT_STOP_BITS_1;
    portParity = FLPROG_PORT_PARITY_NONE;
}

#endif