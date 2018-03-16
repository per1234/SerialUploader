#ifndef ARDUINO_SERIALUPLOADER_H
#define ARDUINO_SERIALUPLOADER_H
#include <Arduino.h>
#include "stk500.h"

// ============= Customization ===================
//
// !! SERIAL_TARGET and SERIAL_UI cannot be identical!!
// If your programmer has only one hardware serial, comment out SERIAL_UI (SD UI will then be used, see main sketch)
//

// What pin to use to slave-select the SD card reader
#define SS_SD SS

// What pin to use on the programmer board (PIN_RESET) to reset the target board (RST pin)
// Comment out if you are using DTR to reset the target board
// #define PIN_RESET 9

// What pin to use on the programmer to send DTR to the target board
// Comment out if you connected the programmer's hardware DTR
#define PIN_DTR 4

// How long to keep the reset pin low to reset the target board
#define DELAY_RESET 100

// How long to wait for replies to Stk500 commands, including receiving 4-5 bytes of response data
#define STK_TIMEOUT 500

// Delay in ms after each flash write to the target. Found in original implementations, uncomment to use
//#define DELAY_FLASH_WRITE 50


// See ifdefs below
#define PROGRAMMER_UNO
//#define PROGRAMMER_MEGA

// Target board on Serial, UI on the SD card
#ifdef PROGRAMMER_UNO

// What HardwareSerial instance to use to communicate with the target board
#define SERIAL_TARGET Serial
// Pins to pull up high to avoid noise on SERIAL_TARGET. Needed for example on ATMega2560's Serial1
//#define SERIAL_RX 19 // USART1_RX
//#define SERIAL_TX 18 // USART1_TX

// What HardwareSerial instance to use if using serial-based UI
//#define SERIAL_UI Serial

#endif // PROGRAMMER_UNO

// Target board on Serial1, UI on Serial
#ifdef PROGRAMMER_MEGA
#define SERIAL_TARGET Serial1
#define SERIAL_RX 19 // USART1_RX
#define SERIAL_TX 18 // USART1_TX
#define SERIAL_UI Serial
#endif // PROGRAMMER_MEGA

// ================================================

#define AUTO_BAUD_RATE 0ul
const uint32_t AUTO_BAUD_RATES[] = { 115200ul, 57600ul, 38400ul, 9600ul, 2400ul, 0ul };

typedef const __FlashStringHelper *FString;
#define printByte(out, b) out.print(F(" 0x")); out.print((uint8_t)b, HEX)

#endif //ARDUINO_SERIALUPLOADER_H
