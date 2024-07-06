#include "ScheduleScreen.h"
extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;
extern State state;


void drawScheduleScreen(Button button) {
  if (button == CENTER) {
    setScreen(SETTINGS);
  }


  u8g2.firstPage();
  do {
    //bottom bar
    u8g2.setFont(u8g2_font_4x6_tr);
    u8g2.drawStr(37, 46, "OK");
    u8g2.drawLine(0, 38, 83, 38);
    u8g2.drawLine(69, 44, 72, 41);
    u8g2.drawLine(72, 41, 75, 44);
    u8g2.drawLine(6, 42, 9, 45);
    u8g2.drawLine(9, 45, 12, 42);

  } while (u8g2.nextPage());
}

void setupScheduleScreen(){};