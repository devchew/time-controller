#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

#define BUTTON_RIGHT 2
#define BUTTON_LEFT 4
#define BUTTON_CENTER 3

enum Button {
  RIGHT = 0,
  LEFT = 1,
  CENTER = 2
};

Button getButton();

void setupButtons();

#endif