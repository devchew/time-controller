#include "Screens.h"

Screen currentScreen = MAIN;

void setScreen(Screen screen) {
  currentScreen = screen;
}

void setupScreens() {
  setupMainScreen();
  setupSettingsScreen();
  setupScheduleScreen();
}

void drawScreen() {
  switch (currentScreen) {
    case MAIN:
      drawMainScreen(getButton());
      break;
    case SETTINGS:
      drawSettingsScreen(getButton());
      break;
    case SCHEDULE:
      drawScheduleScreen(getButton());
      break;
  }
}