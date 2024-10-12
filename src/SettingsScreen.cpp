#include "SettingsScreen.h"
extern U8G2_KS0108_128X64_1 u8g2;
extern State state;

int selected = 0;
int previousSelected = 0;
int nextSelected = 0;

#define OPTIONSLIST_SIZE 5

static String options[OPTIONSLIST_SIZE] = {
  "Time", 
  "Schedule", 
  "Interval",
  "Manual", 
  "Exit"
};

void selectScreen() {
  switch (selected) {
    case 0:
      setScreen(TIME);
      break;
    case 1:
      setScreen(SCHEDULE);
      break;
    case 2:
      setScreen(INTERVAL);
      break;
    case 3:
      setScreen(MANUAL);
      break;
    case 4:
      setScreen(MAIN);
      break;
  }
}

void updateSelected() {
  previousSelected = selected - 1;
  nextSelected = selected + 1;

  if (selected >= OPTIONSLIST_SIZE) {
    selected = 0;
  }
  if (selected < 0) {
    selected = OPTIONSLIST_SIZE - 1;
  }
  if (previousSelected < 0) {
    previousSelected = OPTIONSLIST_SIZE - 1;
  }
  if (nextSelected >= OPTIONSLIST_SIZE) {
    nextSelected = 0;
  }
}

void setupSettingsScreen() {
  selected = 0;
  updateSelected();
}

void drawSettingsScreen(Button button) {
  if (button == RIGHT) {
    selected++;
    updateSelected();
  }

  if (button == LEFT) {
    selected--;
    updateSelected();
  }

  if (button == CENTER) {
    selectScreen();
  }

  u8g2.firstPage();

  do {
    drawMenuBar("Select", 1);


    //selectedFrame
    u8g2.drawRFrame(0, 18, 122, 16, 2);

    //previous
    u8g2.drawStr(2, 11, options[previousSelected].c_str());

    //current
    u8g2.drawStr(2, 29, options[selected].c_str());

    //next
    u8g2.drawStr(2, 46, options[nextSelected].c_str());


    u8g2.drawXBMP(126, 1, 1, 49, scrollBar);
    // draw scrollbar handle
    u8g2.drawBox(125, 44/OPTIONSLIST_SIZE * selected, 3, 64/OPTIONSLIST_SIZE); 

  } while (u8g2.nextPage());
}
