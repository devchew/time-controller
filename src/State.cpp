#include "State.h"

State state;

void setupState() {
  state.scheduleFrom = 6 * 60;
  state.scheduleTo = 18 * 60;
  state.currentTime = 20 * 60 + 32;
  state.isOn = false;
  state.isAuto = true;
}

void saveState() {
  // save state to EEPROM
}
