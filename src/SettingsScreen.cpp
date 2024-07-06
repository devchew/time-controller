#include "SettingsScreen.h"
extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;

int option = 0;

void setupSettingsScreen() {
}

void drawSettingsScreen(Button button) {
  if ( button == UP ) {
    option = (option + 1) % 2;
  }

  if ( button == DOWN ) {
    option = (option - 1) % 2;
  }

    if ( button == OK ) {
        setScreen(MAIN);    
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
    u8g2.drawStr(4, 11, "Time");
    if (option == 0) {
        u8g2.drawLine(4, 12, 79, 12);
    }
    u8g2.drawStr(4, 23, "Schedule");
    if (option == 1) {
        u8g2.drawLine(4, 24, 79, 24);
    }
  } while ( u8g2.nextPage() );
}
