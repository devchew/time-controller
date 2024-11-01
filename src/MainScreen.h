#ifndef MAIN_SCREEN_H
#define MAIN_SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Buttons.h"
#include "Screens.h"
#include "State.h"


void drawMainScreen(Button button);
void setupMainScreen();

#endif