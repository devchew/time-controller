#include "State.h"

State state;

// eeprom map
// 0-1: scheduleFrom
// 2-3: scheduleTo
// 4: isAuto

void storeInt(int value, int address) {
  EEPROM.write(address, value & 0xFF);
  EEPROM.write(address + 1, (value >> 8) & 0xFF);
}

int readInt(int address) {
  return (int) EEPROM.read(address) + ((int) EEPROM.read(address + 1) << 8);
}

void storeBool(bool value, int address) {
  EEPROM.write(address, value ? (unsigned int) 1 : (unsigned int) 0);
}

bool readBool(int address) {
  return (int) EEPROM.read(address) == 1;
}

void setupState() {
  state.scheduleFrom = readInt(0);
  state.scheduleTo = readInt(2);
  state.currentTime = 0;
  state.isOn = false;
  state.isAuto = readBool(4);
}

void saveState() {
  // save state to EEPROM

  storeInt(state.scheduleFrom, 0);
  storeInt(state.scheduleTo, 2);
  storeBool(state.isAuto, 4);
}
