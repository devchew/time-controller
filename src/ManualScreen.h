#ifndef MANUAL_SCREEN_H
#define MANUAL_SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Buttons.h"
#include "Screens.h"
#include "State.h"
#include "Intl.h"

void drawManualScreen(Button button);
void setupManualScreen();

#endif