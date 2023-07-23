#pragma once
#include "Arduino.h"
#include "flprogUart.h"

#if defined(CONFIG_BT_ENABLED) && defined(CONFIG_BLUEDROID_ENABLED)
#include "BluetoothSerial.h"
#define FLPROG_USE_ESP32_ON_BOARD_BLUETOOTH
#endif

class FLProgBluetoothUart : public FLProgUartBasic
{
public:
    FLProgBluetoothUart(String name);
    virtual void setDeviceName(String name);
    void setPartnerName(String name);
    void beBluetoothMaster();
    void beBluetoothSlave();
    virtual bool hasPort();
    virtual void restartPort();
    virtual void begin();

protected:
#ifdef FLPROG_USE_ESP32_ON_BOARD_BLUETOOTH
    BluetoothSerial *bluetoothPort;
#endif
    String deviceName;
    String partnerName;
    bool isMaster = false;
    virtual Stream *uartPort();
};
