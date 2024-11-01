#include "Screens.h"
extern U8G2_KS0108_128X64_1 u8g2;
extern State state;

int highlighted;

void drawMenuBar(int type) {
  u8g2.setFont(FONT_NORMAL);

  // write title in center
  if (type == 0) {
    u8g2.drawStr(64 - sizeof(TEXT_MENU) * 3, 62, TEXT_MENU);
  } else {
    u8g2.drawStr(64 - sizeof(TEXT_NEXT) * 3, 62, TEXT_NEXT);
  }

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
    u8g2.drawStr(1, 62, TEXT_NO);
    u8g2.drawStr(132 - sizeof(TEXT_YES) * 6, 62, TEXT_YES);
  }

  // type 4: on off
  if (type == 4) {
    u8g2.drawStr(1, 62, TEXT_OFF);
    u8g2.drawStr(132 - sizeof(TEXT_ON) * 6, 62, TEXT_ON);
  }

  // type 5: ok
  if (type == 5) {
    u8g2.drawStr(132 - sizeof(TEXT_OK) * 6, 62, TEXT_OK);
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

void drawSaveOnCenterButton(int y, int underlined) {
  u8g2.setFont(FONT_NORMAL);
  u8g2.drawStr(64 - sizeof(TEXT_SAVE) * 3, y, TEXT_SAVE);
  if (underlined == 0) { u8g2.drawLine(64 - sizeof(TEXT_SAVE) * 3, y+1, 64 + sizeof(TEXT_SAVE) * 3, y+1); }
}

void drawPumpAnimation(int x, int y, bool text) {
  u8g2.drawXBM(x + 18, y, 20, 19, pump);
  if (state.isOn) {
    u8g2.drawXBM(x + 26, y + 5, 9, 9, now() % 2 == 0 ? rotor1 : rotor2);
    if (text) {
      u8g2.drawStr(x + 6, y + 13, TEXT_ON);
    }
  } else {
    u8g2.drawEllipse(x + 30, y + 9, 2, 2);
    if (text) {
      u8g2.drawStr(x, y + 13, TEXT_OFF);
    }
  }
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
  u8g2.drawStr(51, 60, TEXT_MENU);
  u8g2.drawLine(0, 52, 128, 52);
}