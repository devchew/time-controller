#include <Arduino.h>
#include "Relay.h"
#include "Buttons.h"
#include "Screen.h"

// sreens
enum Screen {
  MAIN = 0,
  SETTINGS = 1
};

Screen currentScreen = MAIN;

void setScreen(Screen screen) {
  currentScreen = screen;
}

void drawMainScreen() {
  Button button = getButton();

  if ( button == OK ) {
    setScreen(SETTINGS);
  }

  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0, 24, "Main");

    u8g2.setFont(u8g2_font_ncenB24_tr);
    u8g2.setCursor(0, 48);
    u8g2.print(getRelay() ? "ON" : "OFF");
    
  } while ( u8g2.nextPage() );
}

void drawSettingsScreen() {
  Button button = getButton();

  if ( button == OK ) {
    setScreen(MAIN);
  }
  if ( button == UP ) {
    setRelay(true);
  }

  if ( button == DOWN ) {
    setRelay(false);
  }
  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_ncenB10_tr);
    u8g2.drawStr(0, 24, "Settings");
  } while ( u8g2.nextPage() );
}


// setup

void setup(void) {
  u8g2.begin(); 
  setupButtons();
  setupRelay();
}


void loop(void) {
  switch (currentScreen) {
    case MAIN:
      drawMainScreen();
      break;
    case SETTINGS:
      drawSettingsScreen();
      break;
  }
}