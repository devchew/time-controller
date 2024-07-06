#ifndef SCREENS_H
#define SCREENS_H

#include <Arduino.h>
#include "Buttons.h"
#include "SettingsScreen.h"
#include "MainScreen.h"
#include "ScheduleScreen.h"

// sreens
enum Screen {
  MAIN = 0,
  SETTINGS = 1,
  SCHEDULE = 2
};

void setScreen(Screen screen);

void drawScreen();

void setupScreens();

#endif