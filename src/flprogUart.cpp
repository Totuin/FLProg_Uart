#include "flprogUart.h"

void FLProgUartBasic::setDeviceName(String name)
{
    (void)name;
}

void FLProgUartBasic::setPortSpeed(uint8_t speed)
{
    if (portSpeed == speed)
    {
        return;
    }
    portSpeed = speed;
    if (!hasPort())
    {
        return;
    }
    restartPort();
}

void FLProgUartBasic::setPortDataBits(uint8_t dataBits)
{
    if ((dataBits < 5) || (dataBits > 8))
    {
        return;
    }
    if (portDataBits == dataBits)
    {
        return;
    }
    portDataBits = dataBits;
    if (!hasPort())
    {
        return;
    }
    restartPort();
}

void FLProgUartBasic::setPortStopBits(uint8_t stopBits)
{
    if ((stopBits < 1) || (stopBits > 2))
    {
        return;
    }

    if (portStopBits == stopBits)
    {
        return;
    }
    portStopBits = stopBits;
    if (!hasPort())
    {
        return;
    }
    restartPort();
}

void FLProgUartBasic::setPortParity(uint8_t parity)
{
    if (parity > 2)
    {
        return;
    }

    if (portParity == parity)
    {
        return;
    }
    portParity = parity;
    if (!hasPort())
    {
        return;
    }
    restartPort();
}

int FLProgUartBasic::serialCodeForParametrs()
{
    int code = 0;
    if (portStopBits == 2)
    {
        code = code + 8;
    }
    if (portDataBits == 6)
    {
        code = code + 2;
    }
    if (portDataBits == 7)
    {
        code = code + 4;
    }
    if (portDataBits == 8)
    {
        code = code + 6;
    }
    if (portParity == 1)
    {
        code = code + 32;
    }
    if (portParity == 2)
    {
        code = code + 48;
    }
    return code;
}

uint32_t FLProgUartBasic::speedFromCode()
{
    return flprog::speedFromCode(portSpeed);
}

void FLProgUartBasic::setCodeFromSpeed(int32_t speed)
{
    portSpeed = flprog::codeFromSpeed(speed);
}

void FLProgUartBasic::changePins(int16_t newRxPin, int16_t newTxPin)
{
    if ((rxPin != newRxPin) || (txPin != newTxPin))
    {
        rxPin = newRxPin;
        txPin = newTxPin;
        restartPort();
    }
}

void FLProgUartBasic::changePort(uint8_t newPort)
{
    if (newPort != number)
    {
        if (hasPort())
        {
            stopPort();
        }
        newPort = number;
        resetPort();
        setPort();
        startPort();
    }
}

void FLProgUartBasic::changePinsAndPort(uint8_t newPort, int16_t newRxPin, int16_t newTxPin)
{
    if ((rxPin != newRxPin) || (txPin != newTxPin) || (newPort != number))
    {
        stopPort();
        rxPin = newRxPin;
        txPin = newTxPin;
        newPort = number;
        resetPort();
        setPort();
        startPort();
    }
}
