#include "ScheduleScreen.h"
extern U8G2_KS0108_128X64_1 u8g2;
extern State state;

extern int highlighted;

int newScheduleFrom = 0;
int newScheduleTo = 0;

void drawScheduleScreen(Button button) {
  if (button == CENTER) {
    highlighted++;
    if (highlighted >= 5) {
      highlighted = 0;
    }
  }

  if (button == RIGHT) {
    if (highlighted == 0) {
      newScheduleFrom += 60;
      if (newScheduleFrom >= 1440) {
        newScheduleFrom = 0;
      }
    }
    if (highlighted == 1) {
      newScheduleFrom++;
      if (newScheduleFrom >= 1440) {
        newScheduleFrom = 0;
      }
    }
    if (highlighted == 2) {
      newScheduleTo += 60;
      if (newScheduleTo >= 1440) {
        newScheduleTo = 0;
      }
    }
    if (highlighted == 3) {
      newScheduleTo++;
      if (newScheduleTo >= 1440) {
        newScheduleTo = 0;
      }
    }
    if (highlighted == 4) {
      //save
      setScreen(MAIN);
      state.scheduleFrom = newScheduleFrom;
      state.scheduleTo = newScheduleTo;
      saveState();
    }
  }

  if (button == LEFT) {
    if (highlighted == 0) {
      newScheduleFrom -= 60;
      if (newScheduleFrom < 0) {
        newScheduleFrom = 1439;
      }
    }
    if (highlighted == 1) {
      newScheduleFrom--;
      if (newScheduleFrom < 0) {
        newScheduleFrom = 1439;
      }
    }
    if (highlighted == 2) {
      newScheduleTo -= 60;
      if (newScheduleTo < 0) {
        newScheduleTo = 1439;
      }
    }
    if (highlighted == 3) {
      newScheduleTo--;
      if (newScheduleTo < 0) {
        newScheduleTo = 1439;
      }
    }
    if (highlighted == 4) {
      //cancel
      setScreen(MAIN);
      newScheduleFrom = state.scheduleFrom;
      newScheduleTo = state.scheduleTo;
    }
  }

  u8g2.firstPage();
  do {
    //bottom bar

    if (highlighted < 4) {
      drawMenuBar("next", 2);
    } else {
      drawMenuBar("next", 3);
    }

    drawTimeSelector(2, 9, newScheduleFrom, highlighted, "On");
    drawTimeSelector(83, 9, newScheduleTo, highlighted -2, "Off"); 
    drawButton(54, 46, "OK", highlighted - 4);

  } while (u8g2.nextPage());
}

void setupScheduleScreen(){
  highlighted = 0;
  newScheduleFrom = state.scheduleFrom;
  newScheduleTo = state.scheduleTo;
}

