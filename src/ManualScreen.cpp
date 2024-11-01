#include "IntervalScreen.h"
extern U8G2_KS0108_128X64_1 u8g2;
extern State state;

extern int highlighted;

void drawManualScreen(Button button) {
  if (button == CENTER) {
    highlighted++;
    if (highlighted >= 2) {
      highlighted = 0;
    }
  }

  if (button == RIGHT) {
    if (highlighted == 0) {
      state.isOn = true;
    }
    if (highlighted == 1) {
      //exit
      setScreen(MAIN);
      state.isAuto = true;
    }
  }

  if (button == LEFT) {
    if (highlighted == 0) {
      state.isOn = false;   
    }
  }

  u8g2.firstPage();
  do {
    //bottom bar

    if (highlighted == 0) {
      drawMenuBar("next", 4);
    } else {
      drawMenuBar("next", 5);
    }

    u8g2.drawStr(52, 33, state.isOn ? "on" : "off");
    if (state.isAuto) {
      u8g2.drawStr(50, 41, "auto");
    }

    drawButton(43, 9, "Relay", highlighted);
    drawButton(54, 46, "Exit", highlighted - 1);

  } while (u8g2.nextPage());
}

void setupManualScreen(){
  highlighted = 0;
  state.isAuto = false;
}