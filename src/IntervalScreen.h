#ifndef INTERVAL_SCREEN_H
#define INTERVAL_SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Buttons.h"
#include "Screens.h"
#include "State.h"
#include "Intl.h"

void drawIntervalScreen(Button button);
void setupIntervalScreen();

#endif