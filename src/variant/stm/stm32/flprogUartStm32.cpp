#include "flprogUartStm32.h"
#ifdef ARDUINO_ARCH_STM32

FLProgUart::FLProgUart(uint8_t portNumber, int16_t newRxPin, int16_t newTxPin)
{
    rxPin = newRxPin;
    txPin = newTxPin;
    number = portNumber;
}

Stream *FLProgUart::uartPort()
{
#ifdef FLPROG_STM32_HAS_UART0
    if (number == 0)
    {
        return &Serial;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART1
    if (number == 1)
    {
        return &Serial1;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART2
    if (number == 2)
    {
        return &Serial2;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART3
    if (number == 3)
    {
        return &Serial3;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART4
    if (number == 4)
    {
        return &Serial4;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART5
    if (number == 5)
    {
        return &Serial5;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART6
    if (number == 6)
    {
        return &Serial6;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART7
    if (number == 7)
    {
        return &Serial7;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART8
    if (number == 8)
    {
        return &Serial8;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART9
    if (number == 9)
    {
        return &Serial9;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART10
    if (number == 10)
    {
        return &Serial10;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART11
    if (number == 11)
    {
        return &SerialLP1;
    }
#endif
#ifdef FLPROG_STM32_HAS_UART12
    if (number == 12)
    {
        return &SerialLP2;
    }
#endif
    return 0;
}

bool FLProgUart::hasPort()
{
    return uartPort() != 0;
}

void FLProgUart::restartPort()
{
    end();
    begin();
}

void FLProgUart::end()
{
#ifdef FLPROG_STM32_HAS_UART0
    if (number == 0)
    {
        Serial.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART1
    if (number == 1)
    {
        Serial1.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART2
    if (number == 2)
    {
        Serial2.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART3
    if (number == 3)
    {
        Serial3.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART4
    if (number == 4)
    {
        Serial4.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART5
    if (number == 5)
    {
        Serial5.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART6
    if (number == 6)
    {
        Serial6.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART7
    if (number == 7)
    {
        Serial7.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART8
    if (number == 8)
    {
        Serial8.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART9
    if (number == 9)
    {
        Serial9.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART10
    if (number == 10)
    {
        Serial10.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART11
    if (number == 11)
    {
        SerialLP1.end();
    }
#endif
#ifdef FLPROG_STM32_HAS_UART12
    if (number == 12)
    {
        SerialLP2.end();
    }
#endif
}

void FLProgUart::begin(int32_t speed, int mode, int16_t newRxPin, int16_t newTxPin)
{
    if (speed > 0)
    {
        setCodeFromSpeed(speed);
    }
    if (mode > 0)
    {
        setSerialMode(mode);
    }
    if (newRxPin > -2)
    {
        rxPin = newRxPin;
    }
    if (newTxPin > -2)
    {
        txPin = newTxPin;
    }
#ifdef FLPROG_STM32_HAS_UART0
    if (number == 0)
    {
        Serial.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART1
    if (number == 1)
    {
        if (rxPin > -1)
        {
            Serial1.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial1.setTx(txPin);
        }
        Serial1.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART2
    if (number == 2)
    {
        if (rxPin > -1)
        {
            Serial2.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial2.setTx(txPin);
        }
        Serial2.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART3
    if (number == 3)
    {
        if (rxPin > -1)
        {
            Serial3.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial3.setTx(txPin);
        }
        Serial3.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART4
    if (number == 4)
    {
        if (rxPin > -1)
        {
            Serial4.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial4.setTx(txPin);
        }
        Serial4.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART5
    if (number == 5)
    {
        if (rxPin > -1)
        {
            Serial5.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial5.setTx(txPin);
        }
        Serial5.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART6
    if (number == 6)
    {
        if (rxPin > -1)
        {
            Serial6.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial6.setTx(txPin);
        }
        Serial6.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART7
    if (number == 7)
    {
        if (rxPin > -1)
        {
            Serial7.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial7.setTx(txPin);
        }
        Serial7.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART8
    if (number == 8)
    {
        if (rxPin > -1)
        {
            Serial8.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial8.setTx(txPin);
        }
        Serial8.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART9
    if (number == 9)
    {
        if (rxPin > -1)
        {
            Serial9.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial9.setTx(txPin);
        }
        Serial9.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART10
    if (number == 10)
    {
        if (rxPin > -1)
        {
            Serial10.setRx(rxPin);
        }
        if (txPin > -1)
        {
            Serial10.setTx(txPin);
        }
        Serial1.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART11
    if (number == 11)
    {
        if (rxPin > -1)
        {
            SerialLP1.setRx(rxPin);
        }
        if (txPin > -1)
        {
            SerialLP1.setTx(txPin);
        }
        SerialLP1.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
#ifdef FLPROG_STM32_HAS_UART12
    if (number == 12)
    {
        if (rxPin > -1)
        {
            SerialLP2.setRx(rxPin);
        }
        if (txPin > -1)
        {
            SerialLP2.setTx(txPin);
        }
        SerialLP2.begin(speedFromCode(), serialModeFromParametrs());
    }
#endif
}

int FLProgUart::serialModeFromParametrs()
{
    return flprog::serialModeFromInt(serialCodeForParametrs());
}

void FLProgUart::setSerialMode(int16_t mode)
{
    switch (mode)
    {
    case 0x00:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x02:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x04:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x06:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x08:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x0A:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x0C:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x0E:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_NONE;
        return;
        break;
    case 0x20:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x22:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x24:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x26:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x28:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x2A:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x2C:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x2E:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_EVEN;
        return;
        break;
    case 0x30:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x32:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x34:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x36:
        portDataBits = FLPROG_PORT_DATA_BITS_8;
        portStopBits = FLPROG_PORT_STOP_BITS_1;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x38:
        portDataBits = FLPROG_PORT_DATA_BITS_5;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x3A:
        portDataBits = FLPROG_PORT_DATA_BITS_6;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x3C:
        portDataBits = FLPROG_PORT_DATA_BITS_7;
        portStopBits = FLPROG_PORT_STOP_BITS_2;
        portParity = FLPROG_PORT_PARITY_ODD;
        return;
        break;
    case 0x3E:
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

int flprog::serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity)
{
    return serialModeFromInt(serialCodeForParametrs(portDataBits, portStopBits, portParity));
}

int flprog::serialModeFromInt(int16_t code)
{
    switch (code)
    {
#ifdef UART_WORDLENGTH_7B
    case 0x04:
        return SERIAL_7N1;
        break;
    case 0x0C:
        return SERIAL_7N2;
        break;
    case 0x22:
        return SERIAL_6E1;
        break;
    case 0x2A:
        return SERIAL_6E2;
        break;
    case 0x32:
        return SERIAL_6O1;
        break;
    case 0x3A:
        return SERIAL_6O2;
        break;
#endif
    case 0x06:
        return SERIAL_8N1;
        break;
    case 0x0E:
        return SERIAL_8N2;
        break;
    case 0x24:
        return SERIAL_7E1;
        break;
    case 0x26:
        return SERIAL_8E1;
        break;
    case 0x2C:
        return SERIAL_7E2;
        break;
    case 0x2E:
        return SERIAL_8E2;
        break;
    case 0x34:
        return SERIAL_7O1;
        break;
    case 0x36:
        return SERIAL_8O1;
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
#endif