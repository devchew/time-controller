#include "ScheduleScreen.h"
extern U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2;
extern State state;

int highlighted;

char fromMinutes[3] = "--";
char fromHours[3] = "--";

char toMinutes[3] = "--";
char toHours[3] = "--";

int newFrom = 0;
int newTo = 0;

void convert() {

  sprintf(fromHours, "%02d", newFrom / 60);
  sprintf(fromMinutes, "%02d", newFrom % 60);

  sprintf(toHours, "%02d", newTo / 60);
  sprintf(toMinutes, "%02d", newTo % 60);
}


void drawScheduleScreen(Button button) {
  if (button == CENTER) {
    highlighted++;
    if (highlighted >= 6) {
      highlighted = 0;
    }
  }

  if (button == RIGHT) {
    if (highlighted == 0) {
      newFrom += 60;
      if (newFrom >= 1440) {
        newFrom = 0;
      }
    }
    if (highlighted == 1) {
      newFrom++;
      if (newFrom >= 1440) {
        newFrom = 0;
      }
    }
    if (highlighted == 2) {
      newTo += 60;
      if (newTo >= 1440) {
        newTo = 0;
      }
    }
    if (highlighted == 3) {
      newTo++;
      if (newTo >= 1440) {
        newTo = 0;
      }
    }
    if (highlighted == 4) {
      //save
      setScreen(MAIN);
      state.scheduleFrom = newFrom;
      state.scheduleTo = newTo;
    }
    if (highlighted == 5) {
      //cancel
      setScreen(MAIN);
      newFrom = state.scheduleFrom;
      newTo = state.scheduleTo;
    }
  }

  if (button == LEFT) {
    if (highlighted == 0) {
      newFrom -= 60;
      if (newFrom < 0) {
        newFrom = 1439;
      }
    }
    if (highlighted == 1) {
      newFrom--;
      if (newFrom < 0) {
        newFrom = 1439;
      }
    }
    if (highlighted == 2) {
      newTo -= 60;
      if (newTo < 0) {
        newTo = 1439;
      }
    }
    if (highlighted == 3) {
      newTo--;
      if (newTo < 0) {
        newTo = 1439;
      }
    }
  }

  if (button != (button) -1 ) {
    convert();
  }

  u8g2.firstPage();
  do {
    //bottom bar
    u8g2.setFont(u8g2_font_4x6_tr);
    u8g2.drawLine(0, 38, 83, 38);
    u8g2.drawStr(32, 46, "next");
    if (highlighted < 4) {
      u8g2.drawStr(68, 46, "+");
      u8g2.drawStr(10, 46, "-");
    } else {
      u8g2.drawStr(71, 46, "OK");
    }

    //labels
    u8g2.drawStr(3, 8, "On");
    u8g2.drawStr(51, 8, "Off");


    u8g2.setFont(u8g2_font_6x13_tr);
    //on timer
    u8g2.drawStr(3, 19, fromHours);
    if (highlighted == 0) { u8g2.drawLine(3, 20, 13, 20); }
    u8g2.drawXBMP(16, 12, 1, 5, time_dots);
    u8g2.drawStr(19, 19, fromMinutes);
    if (highlighted == 1) { u8g2.drawLine(19, 20, 29, 20); }

    //off timer    
    u8g2.drawStr(51, 19, toHours);
    if (highlighted == 2) { u8g2.drawLine(51, 20, 61, 20); }
    u8g2.drawXBMP(64, 12, 1, 5, time_dots);
    u8g2.drawStr(67, 19, toMinutes);
    if (highlighted == 3) { u8g2.drawLine(67, 20, 77, 20); }
    
    u8g2.setFont(u8g2_font_5x7_tr);
    u8g2.drawStr(51, 33, "Cancel");
    if (highlighted == 4) { u8g2.drawLine(3, 34, 21, 34); }
    u8g2.drawStr(3, 33, "Save");
    if (highlighted == 5) { u8g2.drawLine(51, 34, 79, 34); }

  } while (u8g2.nextPage());
}

void setupScheduleScreen(){
  highlighted = 0;
  newFrom = state.scheduleFrom;
  newTo = state.scheduleTo;
  convert();
};