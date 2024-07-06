#include "SettingsScreen.h"
extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;
extern State state;

int option = 0;

#define OPTIONSLIST_SIZE 3

static String options[OPTIONSLIST_SIZE] = {
  "Time",
  "Schedule",
  "Exit"
};

void setupSettingsScreen() {}

void drawSettingsScreen(Button button) {
  if (button == RIGHT) {
    option++;
    if (option >= OPTIONSLIST_SIZE) {
      option = 0;
    }
  }

  if (button == LEFT) {
    option--;
    if (option < 0) {
      option = OPTIONSLIST_SIZE - 1;
    }
  }

  if (button == CENTER) {
    if (option == 0) {
      state.isAuto = !state.isAuto;
    }
    if (option == 1) {
      state.isOn = !state.isOn;
    }
    if (option == 2) {
      setScreen(MAIN);
    }
  }

  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_4x6_tr);
    u8g2.drawStr(37, 46, "OK");
    u8g2.drawLine(0, 38, 83, 38);
    u8g2.drawLine(69, 44, 72, 41);
    u8g2.drawLine(72, 41, 75, 44);
    u8g2.drawLine(6, 42, 9, 45);
    u8g2.drawLine(9, 45, 12, 42);
    u8g2.setFont(u8g2_font_6x10_tr);

    for(int i = 0; i < OPTIONSLIST_SIZE; i++) {
      u8g2.drawStr(4, 11 + 12 * i, options[i].c_str());
      if (option == i) {
        u8g2.drawLine(4, 12 + 12 * i, 79, 12 + 12 * i);
      }
    }

  } while (u8g2.nextPage());
}
