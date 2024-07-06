#include "MainScreen.h"
extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;
extern State state;

// time
int currentTimeBar = 0;
int startTimeBar = 0;
int endTimeBar = 0;

String getTime() {
  String time = "";
  int hours = state.currentTime / 60;
  int minutes = state.currentTime % 60;
  if (hours < 10) {
    time += "0";
  }
  time += hours;
  time += ":";
  if (minutes < 10) {
    time += "0";
  }
  time += minutes;
  return time;
}

void drawMainScreen(Button button) {
  if (button == CENTER) {
    setScreen(SETTINGS);
  }

  currentTimeBar = map(state.currentTime, 0, 24 * 60, 4, 79);
  startTimeBar = map(state.scheduleFrom, 0, 24 * 60, 4, 79);
  endTimeBar = map((state.scheduleTo - state.scheduleFrom), 0, 24 * 60, 4, 79);

  u8g2.firstPage();
  do {
    //bottom bar
    u8g2.setFont(u8g2_font_4x6_tr);
    u8g2.drawStr(26, 46, "Settings");
    u8g2.drawLine(0, 38, 83, 38);

    // time
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

    // clock
    u8g2.setFont(u8g2_font_6x13_tr);
    u8g2.drawStr(27, 14, getTime().c_str());

    // state
    u8g2.setFont(u8g2_font_4x6_tr);
    if (state.isAuto) {
      u8g2.drawStr(66, 6, "AUTO");
    } else {
      u8g2.drawStr(state.isOn ? 72 : 69, 6, state.isOn ? "ON" : "OFF");
    }
  } while (u8g2.nextPage());
}

void setupMainScreen(){};