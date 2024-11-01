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

static const unsigned char pump[] = {0xc7,0x01,0x00,0x44,0x00,0x00,0x44,0x7c,0x00,0x44,0x83,0x01,0xc4,0x00,0x02,0x04,0x00,0x04,0x04,0x00,0x04,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x08,0x04,0x00,0x04,0x04,0x00,0x04,0xc4,0x00,0x02,0x44,0x83,0x01,0x44,0x7c,0x00,0x44,0x00,0x00,0xc7,0x01,0x00};
static const unsigned char rotor1[] = {0x48,0x00,0x50,0x00,0x7f,0x00,0x44,0x01,0xc6,0x00,0x45,0x00,0xfc,0x01,0x14,0x00,0x24,0x00};
static const unsigned char rotor2[] = {0x10,0x00,0x92,0x00,0x7c,0x00,0x44,0x00,0xc7,0x01,0x44,0x00,0x7c,0x00,0x92,0x00,0x10,0x00};

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
void drawPumpAnimation(int x, int y, bool state);
#endif