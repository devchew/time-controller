#include "Relay.h"

extern State state;

void setRelay(bool state) {
  digitalWrite(RELAY, state ? LOW : HIGH);
}

void setupRelay() {
  pinMode(RELAY, OUTPUT);
  setRelay(false);
}

void relayLoop() {
  setRelay(state.isOn);
}