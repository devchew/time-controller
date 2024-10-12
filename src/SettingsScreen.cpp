#include "SettingsScreen.h"
extern U8G2_KS0108_128X64_1 u8g2;
extern State state;

extern int highlighted;
int previousHighlighted;
int nextHighlighted;

#define OPTIONSLIST_SIZE 5

static String options[OPTIONSLIST_SIZE] = {
  "Time", 
  "Schedule", 
  "Interval",
  "Manual", 
  "Exit"
};

void selectScreen() {
  switch (highlighted) {
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
  previousHighlighted = highlighted - 1;
  nextHighlighted = highlighted + 1;

  if (highlighted >= OPTIONSLIST_SIZE) {
    highlighted = 0;
  }
  if (highlighted < 0) {
    highlighted = OPTIONSLIST_SIZE - 1;
  }
  if (previousHighlighted <= 0) {
    previousHighlighted = OPTIONSLIST_SIZE - 1;
  }
  if (nextHighlighted >= OPTIONSLIST_SIZE) {
    nextHighlighted = 0;
  }
}

void setupSettingsScreen() {
  updateSelected();
}

void drawSettingsScreen(Button button) {
  if (button == RIGHT) {
    highlighted++;
    updateSelected();
  }

  if (button == LEFT) {
    highlighted--;
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
    u8g2.drawStr(2, 11, options[previousHighlighted].c_str());

    //current
    u8g2.drawStr(2, 29, options[highlighted].c_str());

    //next
    u8g2.drawStr(2, 46, options[nextHighlighted].c_str());


    u8g2.drawXBMP(126, 1, 1, 49, scrollBar);
    // draw scrollbar handle
    u8g2.drawBox(125, 44/OPTIONSLIST_SIZE * highlighted, 3, 64/OPTIONSLIST_SIZE); 

  } while (u8g2.nextPage());
}
