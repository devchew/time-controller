#include "IntervalScreen.h"
extern U8G2_KS0108_128X64_1 u8g2;
extern State state;

extern int highlighted;

void drawManualScreen(Button button) {
  if (button == CENTER) {
    highlighted++;
    if (highlighted >= 3) {
      highlighted = 0;
    }
  }

  if (button == RIGHT) {
    if (highlighted == 1) {
      state.isAuto = true;
    }
    if (highlighted == 2) {
      state.isOn = true;
    }
    if (highlighted == 0) {
      //exit
      setScreen(MAIN);
      state.isAuto = true;
    }
  }

  if (button == LEFT) {
    if (highlighted == 1) {
      state.isAuto = false;
    }
    if (highlighted == 2) {
      state.isOn = false;   
    }
  }

  u8g2.firstPage();
  do {
    //bottom bar

    if (highlighted == 0) {
      drawMenuBar("next", 5);
    } else {
      drawMenuBar("next", 4);
    }

    u8g2.drawStr(45, 27, state.isOn ? "on" : "off");
    u8g2.drawStr(45, 13, state.isAuto ? "auto" : "manual");

    u8g2.drawLine(40, 1, 40, 49);    

    drawButton(5, 13, "Mode", highlighted - 1);
    drawButton(5, 26, "Pump", highlighted - 2);
    drawButton(5, 45, "Exit", highlighted);

    // state
    drawPumpAnimation(87, 2, state.isOn);


  } while (u8g2.nextPage());
}

void setupManualScreen(){
  highlighted = 1;
}