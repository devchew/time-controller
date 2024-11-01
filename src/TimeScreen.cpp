#include "IntervalScreen.h"
extern U8G2_KS0108_128X64_1 u8g2;
extern State state;

extern int highlighted;

int newCurrentTime = 0;

#define MAX_WINDOW 1440

void drawTimeScreen(Button button) {
  if (button == CENTER) {
    highlighted++;
    if (highlighted >= 3) {
      highlighted = 0;
    }
  }

  if (button == RIGHT) {
    if (highlighted == 0) {
      newCurrentTime += 60;
      if (newCurrentTime >= 1440) {
        newCurrentTime = 0;
      }
    }
    if (highlighted == 1) {
      newCurrentTime++;
      if (newCurrentTime >= 1440) {
        newCurrentTime = 0;
      }
    }
    if (highlighted == 2) {
      //save
      setScreen(MAIN);
      state.currentTime = newCurrentTime;
      saveState();
      setTime(newCurrentTime / 60, newCurrentTime % 60);
    }
  }

  if (button == LEFT) {
    if (highlighted == 0) {
      newCurrentTime -= 60;
      if (newCurrentTime < 0) {
        newCurrentTime = 1439;
      }
    }
    if (highlighted == 1) {
      newCurrentTime--;
      if (newCurrentTime < 0) {
        newCurrentTime = 1439;
      }
    }
    if (highlighted == 2) {
      //cancel
      setScreen(MAIN);
      newCurrentTime = state.currentTime;
    }
  }

  u8g2.firstPage();
  do {
    //bottom bar

    if (highlighted < 2) {
      drawMenuBar(2);
    } else {
      drawMenuBar(3);
    }

    drawTimeSelector(43, 9, newCurrentTime, highlighted, TEXT_TIME);
    drawSaveOnCenterButton(46, highlighted - 2);

  } while (u8g2.nextPage());
}

void setupTimeScreen(){
  highlighted = 0;
  newCurrentTime = state.currentTime;
}