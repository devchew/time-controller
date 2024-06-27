#ifndef BUTTONS_H
#define BUTTONS_H

#include <Arduino.h>

#define BUTTON_UP 4
#define BUTTON_DOWN 2
#define BUTTON_OK 3

enum Button {
  UP = 0,
  DOWN = 1,
  OK = 2
};

Button getButton();

void setupButtons();

#endif