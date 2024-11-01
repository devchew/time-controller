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

// same as map(position, 0, 24 * 60, 4, 123);
long mapTimeLine(long position)
{
  return (position) * (119) / 1444;
}

void drawMainScreen(Button button) {
  if (button == CENTER) {
    setScreen(SETTINGS);
  }

  currentTimeBar = mapTimeLine(state.currentTime);
  startTimeBar = mapTimeLine(state.scheduleFrom);
  endTimeBar = mapTimeLine(state.scheduleTo - state.scheduleFrom);

  u8g2.firstPage();
  do {
    // clock
    u8g2.setFont(FONT_LARGE);
    u8g2.drawStr(42, 18, getTime().c_str());

    //bottom bar
    drawMenuBar(0);

    // time
    u8g2.drawLine(3, 39, 124, 39);
    u8g2.drawLine(3, 28, 124, 28);
    u8g2.drawStr(3, 48, "0");
    u8g2.drawStr(113, 48, "24");
    u8g2.drawStr(28, 48, "6");
    u8g2.drawStr(86, 48, "18");
    u8g2.drawStr(57, 48, "12");

    // timetable line
    u8g2.drawFrame(startTimeBar, 30, endTimeBar, 8);
    //interval fill

    //loop from startTime to endTime with step of intervalWindow
    for (int i = state.scheduleFrom; i < state.scheduleTo; i += state.intervalWindow) {
      int width = mapTimeLine(i + state.intervalDuration) - mapTimeLine(i);
      u8g2.drawBox(mapTimeLine(i), 30, width, 8);
    }



    // current time
    u8g2.drawLine(currentTimeBar, 22, currentTimeBar, 26);

    // state
    drawPumpAnimation(87, 2, true);

    
  } while (u8g2.nextPage());
}

void setupMainScreen(){
};