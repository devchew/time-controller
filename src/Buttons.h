#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

#define BUTTON_RIGHT 4
#define BUTTON_LEFT 6
#define BUTTON_CENTER 7

enum Button {
  RIGHT = 0,
  LEFT = 1,
  CENTER = 2
};

Button getButton();

void setupButtons();

#endif