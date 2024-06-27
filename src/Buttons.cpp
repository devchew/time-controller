#include "Buttons.h"

#define DEBOUNCE_DELAY 100

Button getState() {
    if (digitalRead(BUTTON_UP) == LOW) {
        return UP;
    }
    if (digitalRead(BUTTON_DOWN) == LOW) {
        return DOWN;
    }
    if (digitalRead(BUTTON_OK) == LOW) {
        return OK;
    }
    return (Button) -1;
}

Button getButton() {
    Button newState = getState();
    delay(DEBOUNCE_DELAY);

    return newState;
}

void setupButtons() {
  pinMode(BUTTON_UP, INPUT_PULLUP);
  pinMode(BUTTON_DOWN, INPUT_PULLUP);
  pinMode(BUTTON_OK, INPUT_PULLUP);

}