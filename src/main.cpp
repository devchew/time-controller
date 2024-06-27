#include <Arduino.h>
#include <U8g2lib.h>
#include <RotaryEncoder.h>

// display setup
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif
U8G2_PCD8544_84X48_1_4W_HW_SPI u8g2(U8G2_R0, /* cs=*/ 10, /* dc=*/ 9, /* reset=*/ 8);						// Nokia 5110 Display

// buttons setup
#define BUTTON_UP 4
#define BUTTON_DOWN 2
#define BUTTON_OK 3

// relay setup
#define RELAY 5
bool relayState = false;

void setup(void) {
  u8g2.begin(); 
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_OK, INPUT_PULLUP);
  pinMode(RELAY, OUTPUT);
}

void loop(void) {

  // read buttons
  if (digitalRead(BUTTON_UP) == LOW) {
    relayState = true;
    digitalWrite(RELAY, HIGH);
  }

  if (digitalRead(BUTTON_DOWN) == LOW) {
    relayState = false;
    digitalWrite(RELAY, LOW);
  }

  if (digitalRead(BUTTON_OK) == LOW) {
    relayState = !relayState;
    digitalWrite(RELAY, relayState ? HIGH : LOW);
    delay(100);
  }


  u8g2.firstPage();
  do {
    u8g2.drawHLine(0,0,10);
    u8g2.drawHLine(0,51,10);
  
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0,24,relayState ? "ON" : "OFF");
  } while ( u8g2.nextPage() );
  //delay(1000);
}