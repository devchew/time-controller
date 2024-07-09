#ifndef SCREEN_H
#define SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>

// display setup
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_PCD8544_84X48_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 14, /* reset=*/ 15);						// Nokia 5110 Display

#endif