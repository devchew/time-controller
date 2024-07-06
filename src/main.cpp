#include <Arduino.h>

#include "Relay.h"
#include "Buttons.h"
#include "State.h"

#include "Screen.h"
#include "Screens.h"
#include "SettingsScreen.h"
#include "MainScreen.h"

extern Screen currentScreen;
extern State state;

unsigned long lastTimeUpdate = 0;

void setup(void) {
  u8g2.begin(); 
  setupButtons();
  setupRelay();
  setupState();

  setupSettingsScreen();
  setupMainScreen();
}


void loop(void) {

  // tick current time every minute
  if (millis() - lastTimeUpdate > 60000) {
    lastTimeUpdate = millis();
    state.currentTime++;
    if (state.currentTime >= 1440) {
      state.currentTime = 0;
    }
  }

  switch (currentScreen) {
    case MAIN:
      drawMainScreen(getButton());
      break;
    case SETTINGS:
      drawSettingsScreen(getButton());
      break;
  }
}