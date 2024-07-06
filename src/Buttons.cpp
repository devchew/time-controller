#include "Buttons.h"

#define DEBOUNCE_DELAY 200

Button getButtonState() {
    if (digitalRead(BUTTON_CENTER) == LOW) {
        return CENTER;
    }
    if (digitalRead(BUTTON_LEFT) == LOW) {
        return LEFT;
    }
    if (digitalRead(BUTTON_RIGHT) == LOW) {
        return RIGHT;
    }
    return (Button) -1;
}

Button getButton() {
    Button newState = getButtonState();
    if (newState == (Button) -1) {
        return (Button) -1;
    }
    delay(DEBOUNCE_DELAY);

    return newState;
}

void setupButtons() {
  pinMode(BUTTON_RIGHT, INPUT_PULLUP);
  pinMode(BUTTON_CENTER, INPUT_PULLUP);
  pinMode(BUTTON_LEFT, INPUT_PULLUP);

}