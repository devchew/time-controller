#ifndef SETTINHS_SCREEN_H
#define SETTINHS_SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Buttons.h"
#include "Relay.h"
#include "Screens.h"
#include "State.h"


void drawSettingsScreen(Button button);
void setupSettingsScreen();

#endif