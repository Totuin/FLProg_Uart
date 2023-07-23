#pragma once
#include <Arduino.h>
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_SAM

namespace flprog
{
  UARTClass::UARTModes serialModeFromInt(int16_t code);
  UARTClass::UARTModes serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

class FLProgUart : public FLProgUartBasic
{
public:
  FLProgUart(uint8_t portNumber = 0, int16_t newRxPin = -1, int16_t newTxPin = -1);
  virtual void begin();
  void begin(int32_t speed, UARTClass::UARTModes mode = SERIAL_8N1, int16_t newRxPin = -2, int16_t newTxPin = -2);
  virtual bool hasPort();
  virtual void restartPort();

protected:
  virtual Stream *uartPort();
  UARTClass::UARTModes serialModeFromParametrs();
  void setSerialMode(UARTClass::UARTModes mode);
  bool portIsInit = false;
  void stopPort();
};

#endif