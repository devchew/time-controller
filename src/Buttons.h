#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

#define BUTTON_LEFT A0
#define BUTTON_CENTER A1
#define BUTTON_RIGHT A2

enum Button {
  RIGHT = 0,
  LEFT = 1,
  CENTER = 2
};

Button getButton();

void setupButtons();

#endif