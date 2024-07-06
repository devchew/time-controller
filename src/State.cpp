#include "State.h"

State state;

void setupState() {
  state.scheduleFrom = (int) EEPROM.read(0);
  state.scheduleTo = (int) EEPROM.read(1);
  state.currentTime = (int) EEPROM.read(2);
  state.isOn = (int) EEPROM.read(3) == 1;
  state.isAuto = (int) EEPROM.read(4) == 1;
}

void saveState() {
  // save state to EEPROM

  EEPROM.write(0, (unsigned int) state.scheduleFrom);
  EEPROM.write(1, (unsigned int) state.scheduleTo);
  EEPROM.write(2, (unsigned int) state.currentTime);
  EEPROM.write(3, state.isOn ? (unsigned int) 1 : (unsigned int) 0);
  EEPROM.write(4, state.isAuto ? (unsigned int) 1 : (unsigned int) 0);
}
