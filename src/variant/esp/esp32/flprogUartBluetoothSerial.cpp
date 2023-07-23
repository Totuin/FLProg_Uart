#include "flprogUartBluetoothSerial.h"

FLProgBluetoothUart::FLProgBluetoothUart(String name)
{
#ifdef FLPROG_USE_ESP32_ON_BOARD_BLUETOOTH
    bluetoothPort = new BluetoothSerial();
#endif
    deviceName = name;
}

Stream *FLProgBluetoothUart::uartPort()
{
#ifdef FLPROG_USE_ESP32_ON_BOARD_BLUETOOTH
    return bluetoothPort;
#else
    return 0;
#endif
}

void FLProgBluetoothUart::beBluetoothMaster()
{
    if (isMaster)
    {
        return;
    }
    isMaster = true;
    restartPort();
}

void FLProgBluetoothUart::beBluetoothSlave()
{
    if (!isMaster)
    {
        return;
    }
    isMaster = false;
    restartPort();
}

void FLProgBluetoothUart::setDeviceName(String name)
{
    if (deviceName.equals(name))
    {
        return;
    }
    deviceName = name;
    restartPort();
}

void FLProgBluetoothUart::setPartnerName(String name)
{
    if (partnerName.equals(name))
    {
        return;
    }
    partnerName = name;
    restartPort();
}

bool FLProgBluetoothUart::hasPort()
{
#ifdef FLPROG_USE_ESP32_ON_BOARD_BLUETOOTH
    return !(bluetoothPort == 0);
#else
    return false;
#endif
}

void FLProgBluetoothUart::restartPort()
{
    if (hasPort())
    {
#ifdef FLPROG_USE_ESP32_ON_BOARD_BLUETOOTH
        bluetoothPort->end();
#endif
        begin();
    }
}

void FLProgBluetoothUart::begin()
{
#ifdef FLPROG_USE_ESP32_ON_BOARD_BLUETOOTH
    if (hasPort())
    {
        bluetoothPort->begin(deviceName);
        if (isMaster)
        {
            bluetoothPort->connect(partnerName);
        }
        return;
    }
#endif
}
