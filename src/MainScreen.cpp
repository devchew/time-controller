#include "MainScreen.h"
extern U8G2_KS0108_128X64_1 u8g2;
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

  currentTimeBar = map(state.currentTime, 0, 24 * 60, 4, 123);
  startTimeBar = map(state.scheduleFrom, 0, 24 * 60, 4, 123);
  endTimeBar = map((state.scheduleTo - state.scheduleFrom), 0, 24 * 60, 2, 122);

  u8g2.firstPage();
  do {
    // clock
    u8g2.setFont(FONT_LARGE);
    u8g2.drawStr(42, 19, getTime().c_str());

    //bottom bar
    drawMenuBar("Menu", 0);

    // time
    u8g2.drawLine(3, 39, 124, 39);
    u8g2.drawLine(3, 28, 124, 28);
    u8g2.drawStr(3, 48, "0");
    u8g2.drawStr(113, 48, "24");
    u8g2.drawStr(28, 48, "6");
    u8g2.drawStr(86, 48, "18");
    u8g2.drawStr(57, 48, "12");

    // timetable line
    u8g2.drawBox(startTimeBar, 30, endTimeBar, 8);


    // current time
    u8g2.drawLine(currentTimeBar, 22, currentTimeBar, 26);

    // state
    u8g2.drawStr(110, 8, state.isOn ? "On" : "OFF");
    
  } while (u8g2.nextPage());
}

void setupMainScreen(){};