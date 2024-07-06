#ifndef SCHEDULE_SCREEN_H
#define SCHEDULE_SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Buttons.h"
#include "Screens.h"
#include "State.h"

void drawScheduleScreen(Button button);
void setupScheduleScreen();

#endif