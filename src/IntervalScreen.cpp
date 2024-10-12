#include "IntervalScreen.h"
extern U8G2_KS0108_128X64_1 u8g2;
extern State state;

extern int highlighted;

int newIntervalWindow = 0;
int newIntervalDuration = 0;

#define MAX_WINDOW 1440

void drawIntervalScreen(Button button) {
if (button == CENTER) {
    highlighted++;
    if (highlighted >= 3) {
      highlighted = 0;
    }
  }

  if (button == RIGHT) {
    if (highlighted == 0) {
      newIntervalWindow ++;
      if (newIntervalWindow > MAX_WINDOW) {
        newIntervalWindow = 0;
      }
    }
    if (highlighted == 1) {
      newIntervalDuration++;
      if (newIntervalDuration > newIntervalWindow) {
        newIntervalDuration = 0;
      }
    }

    if (highlighted == 2) {
      //save
      setScreen(MAIN);
      state.intervalWindow = newIntervalWindow;
      state.intervalDuration = newIntervalDuration;
      saveState();
    }
  }

  if (button == LEFT) {
    if (highlighted == 0) {
      newIntervalWindow --;
      if (newIntervalWindow < 0) {
        newIntervalWindow = MAX_WINDOW;
      }
    }
    if (highlighted == 1) {
      newIntervalDuration--;
      if (newIntervalDuration < 0) {
        newIntervalDuration = 0;
      }
    }
    if (highlighted == 2) {
      //cancel
      setScreen(MAIN);
      newIntervalWindow = state.intervalWindow;
      newIntervalDuration = state.intervalDuration;
    }
  }

  u8g2.firstPage();
  do {
    //bottom bar

    if (highlighted < 2) {
      drawMenuBar("next", 2);
    } else {
      drawMenuBar("next", 3);
    }

    drawIntSelector(2, 9, newIntervalWindow, highlighted, "Window");
    drawIntSelector(80, 9, newIntervalDuration, highlighted - 1, "Duration"); 
    drawButton(54, 46, "OK", highlighted - 2);

  } while (u8g2.nextPage());
}

void setupIntervalScreen(){
  highlighted = 0;
  newIntervalWindow = state.intervalWindow;
  newIntervalDuration = state.intervalDuration;
};