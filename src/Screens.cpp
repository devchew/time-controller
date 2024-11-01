#include "Screens.h"
extern U8G2_KS0108_128X64_1 u8g2;

int highlighted;

void drawMenuBar(String title, int type) {
  u8g2.setFont(FONT_NORMAL);

  // write title in center
  int titleWidth = u8g2.getStrWidth(title.c_str());
  u8g2.drawStr(64 - titleWidth / 2, 62, title.c_str());

  u8g2.drawLine(0, 52, 128, 52);

  // type 1: arrows
  if (type == 1) {
    u8g2.drawStr(16, 63, "^");
    u8g2.drawStr(103, 63, "v");
  }

  // type 2: plusminus
  if (type == 2) {
    u8g2.drawStr(16, 63, "-");
    u8g2.drawStr(103, 63, "+");
  }

  // type 3: save
  if (type == 3) {
    u8g2.drawStr(1, 62, "Cancel");
    u8g2.drawStr(91, 62, "Save");
  }

  // type 4: on off
  if (type == 4) {
    u8g2.drawStr(1, 62, "Off");
    u8g2.drawStr(91, 62, "On");
  }

  // type 5: ok
  if (type == 5) {
    u8g2.drawStr(91, 62, "Ok");
  }
}

void drawTimeSelector(int x, int y, int time, int underlined, String title) {
  char hours[3];
  char minutes[3];

  sprintf(hours, "%02d", time / 60);
  sprintf(minutes, "%02d", time % 60);

  u8g2.setFont(FONT_NORMAL);
  u8g2.drawStr(x, y, title.c_str());

  u8g2.setFont(FONT_LARGE);
  u8g2.drawStr(x-1, y + 18, hours);
  if (underlined == 0) { u8g2.drawLine(x, y+19, x+16, y+19); }
  u8g2.drawStr(x + 19, y + 16, ":");
  u8g2.drawStr(x + 24, y + 18, minutes);
  if (underlined == 1) { u8g2.drawLine(x+25, y+19, x+41, y+19); }
}

void drawIntSelector(int x, int y, int value, int underlined, String title) {
  char buffer[5];
  sprintf(buffer, "%d", value);

  u8g2.setFont(FONT_NORMAL);
  u8g2.drawStr(x, y, title.c_str());

  u8g2.setFont(FONT_LARGE);
  u8g2.drawStr(x-1, y + 18, buffer);
  int width = u8g2.getStrWidth(buffer);
  if (underlined == 0) { u8g2.drawLine(x, y+19, x+width, y+19); }
}

void drawButton(int x, int y, String title, int underlined) {
  u8g2.setFont(FONT_NORMAL);
  u8g2.drawStr(x, y, title.c_str());
  if (underlined == 0) { u8g2.drawLine(x, y+1, x+10, y+1); }
}

Screen currentScreen = MAIN;

void setScreen(Screen screen) {
  currentScreen = screen;
  highlighted = 0;
  switch (screen) {
    case MAIN:
      setupMainScreen();
      break;
    case SETTINGS:
      setupSettingsScreen();
      break;
    case SCHEDULE:
      setupScheduleScreen();
      break;
    case INTERVAL:
      setupIntervalScreen();
      break;
    case MANUAL:
      break;
    case TIME:
      setupTimeScreen();
      break;
    default:
      break;
  }
}

void setupScreens() {
  setScreen(currentScreen);
}

void drawScreen() {
  switch (currentScreen) {
    case MAIN:
      drawMainScreen(getButton());
      break;
    case SETTINGS:
      drawSettingsScreen(getButton());
      break;
    case SCHEDULE:
      drawScheduleScreen(getButton());
      break;
    case INTERVAL:
      drawIntervalScreen(getButton());
      break;
    case MANUAL:
      drawManualScreen(getButton());
      break;
    case TIME:
      drawTimeScreen(getButton());
      break;
    default:
      drawMainScreen(getButton());
      break;
  }
}

void drawBottomBar() {
  u8g2.setFont(u8g2_font_6x10_tr);
  u8g2.drawStr(51, 60, "menu");
  u8g2.drawLine(0, 52, 128, 52);
}