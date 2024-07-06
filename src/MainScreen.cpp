#include "MainScreen.h"
extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;

// time
int currentHour = 21;
int currentMinute = 37;

long startTimeInMin = 6 * 60;
long endTimeInMin = 18 * 60;

int currentTimeBar = 0;
int startTimeBar = 0;
int endTimeBar = 0;

extern bool relayState;

void drawMainScreen(Button button) {
  
  if ( button == OK ) {
    setScreen(SETTINGS);
  }

  if ( button == UP ) {
    startTimeInMin -= 30;
  }

  if ( button == DOWN ) {
    startTimeInMin += 30;
  }

  currentTimeBar = map((currentHour * 60 + currentMinute), 0, 24 * 60, 4, 79);
  startTimeBar = map(startTimeInMin, 0, 24 * 60, 4, 79);
  endTimeBar = map((endTimeInMin - startTimeInMin), 0, 24 * 60, 4, 79);

  u8g2.firstPage();
  do {
    u8g2.setFont(u8g2_font_4x6_tr);
    u8g2.drawStr(26, 46, "Settings");
    u8g2.drawLine(0, 38, 83, 38);
    u8g2.drawLine(4, 28, 79, 28);
    u8g2.drawLine(4, 21, 79, 21);
    u8g2.drawStr(2, 35, "0");
    u8g2.drawStr(75, 35, "24");
    u8g2.drawStr(37, 35, "12");
    u8g2.drawStr(17, 35, "6");
    u8g2.drawStr(57, 35, "18");
    // timetable line
    u8g2.drawBox(startTimeBar, 23, endTimeBar, 4);

    u8g2.drawLine(0, 0, 0, 0);

    // current time
    u8g2.drawLine(currentTimeBar, 19, currentTimeBar, 17);

    u8g2.setFont(u8g2_font_6x13_tr);
    u8g2.drawStr(27, 14, "21:37");
    u8g2.setFont(u8g2_font_4x6_tr);
    u8g2.drawStr(71, 6, relayState ? "ON" : "OFF");    
  } while ( u8g2.nextPage() );
}

void setupMainScreen() {

};