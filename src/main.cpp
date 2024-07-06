#include <Arduino.h>
#include "Relay.h"
#include "Buttons.h"
#include "Screen.h"
#include "Screens.h"
#include "SettingsScreen.h"
#include "MainScreen.h"

extern Screen currentScreen;

void setup(void) {
  u8g2.begin(); 
  setupButtons();
  setupRelay();

  setupSettingsScreen();
  setupMainScreen();
}


void loop(void) {
  switch (currentScreen) {
    case MAIN:
      drawMainScreen(getButton());
      break;
    case SETTINGS:
      drawSettingsScreen(getButton());
      break;
  }
}