#ifndef SCREENS_H
#define SCREENS_H

#include <Arduino.h>
#include <U8g2lib.h>
#include "Buttons.h"
#include "SettingsScreen.h"
#include "MainScreen.h"
#include "ScheduleScreen.h"
#include "IntervalScreen.h"
#include "TimeScreen.h"
#include "ManualScreen.h"

#define FONT_NORMAL u8g2_font_6x10_tr
#define FONT_LARGE u8g2_font_timR14_tr

// sreens
enum Screen {
  MAIN = 0,
  SETTINGS = 1,
  SCHEDULE = 2,
  INTERVAL = 3,
  MANUAL = 4,
  TIME = 5,
};

void setScreen(Screen screen);

void drawScreen();

void setupScreens();

void drawBottomBar();


// menu bar
// @param title - title in the center of the bar
// @param type - arrows, plusminus, none

void drawMenuBar(String title, int type);
void drawTimeSelector(int x, int y, int time, int underlined, String title);
void drawButton(int x, int y, String title, int underlined);
void drawIntSelector(int x, int y, int value, int underlined, String title);

#endif