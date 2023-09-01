#pragma once
#include "flprogUart.h"

#ifdef ARDUINO_ARCH_STM32

// ---------- Анализ UART0---------------------------------------------
#if defined(USBCON) && defined(USBD_USE_CDC)
#define FLPROG_STM32_HAS_UART0 FLPROG_USB_UART
#endif

// ---------- Анализ UART1---------------------------------------------
#if defined(UART1) || defined(USART1)
#ifndef HAVE_HWSERIAL1
#define FLPROGSTM32NEED_CREATE_UART1
#endif
#if defined(HAVE_HWSERIAL1) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART1)
#ifdef USART1
#define FLPROG_STM32_HAS_UART1 FLPROG_USART_UART
#endif
#ifdef UART1
#define FLPROG_STM32_HAS_UART1 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART2---------------------------------------------
#if defined(UART2) || defined(USART2)
#ifndef HAVE_HWSERIAL2
#define FLPROG_STM32_NEED_CREATE_UART2
#endif
#if defined(HAVE_HWSERIAL2) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART2)
#ifdef USART2
#define FLPROG_STM32_HAS_UART2 FLPROG_USART_UART
#endif
#ifdef UART2
#define FLPROG_STM32_HAS_UART2 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART3---------------------------------------------

#if defined(UART3) || defined(USART3)
#ifndef HAVE_HWSERIAL3
#define FLPROG_STM32_NEED_CREATE_UART3
#endif
#if defined(HAVE_HWSERIAL3) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART3)
#ifdef USART3
#define FLPROG_STM32_HAS_UART3 FLPROG_USART_UART
#endif
#ifdef UART3
#define FLPROG_STM32_HAS_UART3 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART4---------------------------------------------
#if defined(UART4) || defined(USART4)
#ifndef HAVE_HWSERIAL4
#define FLPROG_STM32_NEED_CREATE_UART4
#endif
#if defined(HAVE_HWSERIAL4) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART4)
#ifdef USART4
#define FLPROG_STM32_HAS_UART4 FLPROG_USART_UART
#endif
#ifdef UART4
#define FLPROG_STM32_HAS_UART4 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART5---------------------------------------------
#if defined(UART5) || defined(USART5)
#ifndef HAVE_HWSERIAL5
#define FLPROG_STM32_NEED_CREATE_UART5
#endif
#if defined(HAVE_HWSERIAL5) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART5)
#ifdef USART5
#define FLPROG_STM32_HAS_UART5 FLPROG_USART_UART
#endif
#ifdef UART5
#define FLPROG_STM32_HAS_UART5 FLPROG_UART_UART
#endif
#endif
#endif
// ---------- Анализ UART6---------------------------------------------
#if defined(UART6) || defined(USART6)
#ifndef HAVE_HWSERIAL6
#define FLPROG_STM32_NEED_CREATE_UART6
#endif
#if defined(HAVE_HWSERIAL6) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART6)
#ifdef USART6
#define FLPROG_STM32_HAS_UART6 FLPROG_USART_UART
#endif
#ifdef UART6
#define FLPROG_STM32_HAS_UART6 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART7---------------------------------------------
#if defined(UART7) || defined(USART7)
#ifndef HAVE_HWSERIAL7
#define FLPROG_STM32_NEED_CREATE_UART7
#endif
#if defined(HAVE_HWSERIAL7) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART7)
#ifdef USART7
#define FLPROG_STM32_HAS_UART7 FLPROG_USART_UART
#endif
#ifdef UART7
#define FLPROG_STM32_HAS_UART7 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART8---------------------------------------------
#if defined(UART8) || defined(USART8)
#ifndef HAVE_HWSERIAL8
#define FLPROG_STM32_NEED_CREATE_UART8
#endif
#if defined(HAVE_HWSERIAL8) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART8)
#ifdef USART8
#define FLPROG_STM32_HAS_UART8 FLPROG_USART_UART
#endif
#ifdef UART8
#define FLPROG_STM32_HAS_UART8 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART9---------------------------------------------
#if defined(UART9) || defined(USART9)
#ifndef HAVE_HWSERIAL9
#define FLPROG_STM32_NEED_CREATE_UART9
#endif
#if defined(HAVE_HWSERIAL9) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART9)
#ifdef USART9
#define FLPROG_STM32_HAS_UART9 FLPROG_USART_UART
#endif
#ifdef UART9
#define FLPROG_STM32_HAS_UART9 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART10---------------------------------------------
#if defined(UART10) || defined(USART10)
#ifndef HAVE_HWSERIAL10
#define FLPROG_STM32_NEED_CREATE_UART10
#endif
#if defined(HAVE_HWSERIAL10) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART10)
#ifdef USART10
#define FLPROG_STM32_HAS_UART10 FLPROG_USART_UART
#endif
#ifdef UART10
#define FLPROG_STM32_HAS_UART10 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART11---------------------------------------------
#if defined(LPUART1) || defined(LPUSART1)
#ifndef HAVE_HWSERIALLP1
#define FLPROG_STM32_NEED_CREATE_UART11
#endif
#if defined(HAVE_HWSERIALLP1) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART11)
#ifdef LPUSART1
#define FLPROG_STM32_HAS_UART11 FLPROG_USART_UART
#endif
#ifdef LPUART1
#define FLPROG_STM32_HAS_UART11 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Анализ UART12---------------------------------------------
#if defined(LPUART2) || defined(LPUSART2)
#ifndef HAVE_HWSERIALLP2
#define FLPROG_STM32_NEED_CREATE_UART12
#endif
#if defined(HAVE_HWSERIALLP2) || defined(FLPROG_CREATE_ALL_UART) || defined(FLPROG_CREATE_UART12)
#ifdef LPUSART2
#define FLPROG_STM32_HAS_UART12 FLPROG_USART_UART
#endif
#ifdef LPUART2
#define FLPROG_STM32_HAS_UART12 FLPROG_UART_UART
#endif
#endif
#endif

// ---------- Конец анализа ---------------------------------------------

// ---------- Создание UART1 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART1
#ifdef FLPROG_STM32_NEED_CREATE_UART1
#if (FLPROG_STM32_HAS_UART1 == FLPROG_USART_UART)
HardwareSerial Serial1(USART1);
#endif
#if (FLPROG_STM32_HAS_UART1 == FLPROG_UART_UART)
HardwareSerial Serial1(UART1);
#endif
#endif
#endif

// ---------- Создание UART2 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART2
#ifdef FLPROG_STM32_NEED_CREATE_UART2
#if (FLPROG_STM32_HAS_UART2 == FLPROG_USART_UART)
HardwareSerial Serial2(USART2);
#endif
#if (FLPROG_STM32_HAS_UART2 == FLPROG_UART_UART)
HardwareSerial Serial2(UART2);
#endif
#endif
#endif

// ---------- Создание UART3 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART3
#ifdef FLPROG_STM32_NEED_CREATE_UART3
#if (FLPROG_STM32_HAS_UART3 == FLPROG_USART_UART)
HardwareSerial Serial3(USART3);
#endif
#if (FLPROG_STM32_HAS_UART3 == FLPROG_UART_UART)
HardwareSerial Serial3(UART3);
#endif
#endif
#endif

// ---------- Создание UART4 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART4
#ifdef FLPROG_STM32_NEED_CREATE_UART4
#if (FLPROG_STM32_HAS_UART4 == FLPROG_USART_UART)
HardwareSerial Serial4(USART4);
#endif
#if (FLPROG_STM32_HAS_UART4 == FLPROG_UART_UART)
HardwareSerial Serial4(UART4);
#endif
#endif
#endif

// ---------- Создание UART5 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART5
#ifdef FLPROG_STM32_NEED_CREATE_UART5
#if (FLPROG_STM32_HAS_UART5 == FLPROG_USART_UART)
HardwareSerial Serial5(USART5);
#endif
#if (FLPROG_STM32_HAS_UART5 == FLPROG_UART_UART)
HardwareSerial Serial5(UART5);
#endif
#endif
#endif

// ---------- Создание UART6 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART6
#ifdef FLPROG_STM32_NEED_CREATE_UART6
#if (FLPROG_STM32_HAS_UART6 == FLPROG_USART_UART)

HardwareSerial Serial6(USART6);
#endif
#if (FLPROG_STM32_HAS_UART6 == FLPROG_UART_UART)

HardwareSerial Serial6(UART6);
#endif
#endif
#endif

// ---------- Создание UART7 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART7
#ifdef FLPROG_STM32_NEED_CREATE_UART7
#if (FLPROG_STM32_HAS_UART7 == FLPROG_USART_UART)

HardwareSerial Serial7(USART7);
#endif
#if (FLPROG_STM32_HAS_UART7 == FLPROG_UART_UART)

HardwareSerial Serial7(UART7);
#endif
#endif
#endif

// ---------- Создание UART8 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART8
#ifdef FLPROG_STM32_NEED_CREATE_UART8
#if (FLPROG_STM32_HAS_UART8 == FLPROG_USART_UART)

HardwareSerial Serial8(USART8);
#endif
#if (FLPROG_STM32_HAS_UART8 == FLPROG_UART_UART)

HardwareSerial Serial8(UART8);
#endif
#endif
#endif

// ---------- Создание UART9 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART9
#ifdef FLPROG_STM32_NEED_CREATE_UART9
#if (FLPROG_STM32_HAS_UART9 == FLPROG_USART_UART)

HardwareSerial Serial9(USART9);
#endif
#if (FLPROG_STM32_HAS_UART9 == FLPROG_UART_UART)

HardwareSerial Serial9(UART9);
#endif
#endif
#endif

// ---------- Создание UART10 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART10
#ifdef FLPROG_STM32_NEED_CREATE_UART10
#if (FLPROG_STM32_HAS_UART10 == FLPROG_USART_UART)

HardwareSerial Serial10(USART10);
#endif
#if (FLPROG_STM32_HAS_UART10 == FLPROG_UART_UART)

HardwareSerial Serial10(UART10);
#endif
#endif
#endif

// ---------- Создание UART11 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART11
#ifdef FLPROG_STM32_NEED_CREATE_UART11
#if (FLPROG_STM32_HAS_UART11 == FLPROG_USART_UART)

HardwareSerial SerialLP1(LPUSART1);
#endif
#if (FLPROG_STM32_HAS_UART11 == FLPROG_UART_UART)

HardwareSerial SerialLP1(LPUART1);
#endif
#endif
#endif

// ---------- Создание UART12 ---------------------------------------------
#ifdef FLPROG_STM32_HAS_UART12
#ifdef FLPROG_STM32_NEED_CREATE_UART12
#if (FLPROG_STM32_HAS_UART12 == FLPROG_USART_UART)

HardwareSerial SerialLP2(LPUSART2);
#endif
#if (FLPROG_STM32_HAS_UART12 == FLPROG_UART_UART)

HardwareSerial SerialLP2(LPUART2);
#endif
#endif
#endif

// ---------- Окончание создания ---------------------------------------------

namespace flprog
{
    int serialModeFromInt(int16_t code);
    int serialModeFromParametrs(byte portDataBits, byte portStopBits, byte portParity);
};

class FLProgUart : public FLProgUartBasic
{
public:
    FLProgUart(uint8_t portNumber = 0, int16_t newRxPin = -1, int16_t newTxPin = -1);
    virtual void begin() { begin(0); };
    void begin(int32_t speed, int mode = 0, int16_t newRxPin = -2, int16_t newTxPin = -2);
    virtual bool hasPort();
    virtual void restartPort();
    virtual void end();

protected:
    virtual Stream *uartPort();
    int serialModeFromParametrs();
    void setSerialMode(int16_t mode);
};

class FLProgSoftwareUart : public FLProgUartBasic
{
public:
    FLProgSoftwareUart(uint8_t receivePin, uint8_t transmitPin);
    virtual void begin(){};
};

#endif