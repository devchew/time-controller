#ifndef SCHEDULE_SCREEN_H
#define SCHEDULE_SCREEN_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Buttons.h"
#include "Screens.h"
#include "State.h"

static const unsigned char time_dots[] U8X8_PROGMEM = {0x01,0x00,0x00,0x00,0x01};

void drawScheduleScreen(Button button);
void setupScheduleScreen();

#endif