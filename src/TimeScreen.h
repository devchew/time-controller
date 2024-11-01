#ifndef TIME_SCREEN_H
#define TIME_SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Buttons.h"
#include "Screens.h"
#include "State.h"
#include "Time.h"
#include "Intl.h"

void drawTimeScreen(Button button);
void setupTimeScreen();

#endif