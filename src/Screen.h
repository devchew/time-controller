#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Intl.h"

// display setup
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif


#ifdef WOKWI // Wokwi simulator

U8G2_SSD1306_128X64_NONAME_2_HW_I2C u8g2 (U8G2_R0);
#else
// U8G2_KS0108_128X64_1( rotation, d0, d1, d2, d3, d4, d5, d6, d7, enable, dc, cs0, cs1, cs2 [, reset])
U8G2_KS0108_128X64_1 u8g2(U8G2_R2, 6, 7, 8, 9, 10, 11, 12, 13,     5, 4,  2,  3,  U8X8_PIN_NONE, U8X8_PIN_NONE); 	// Set R/W to low!
#endif

#endif