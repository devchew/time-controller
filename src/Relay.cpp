#include "Relay.h"


bool relayState = false;

void setRelay(bool state) {
  relayState = state;
  digitalWrite(RELAY, relayState ? HIGH : LOW);
}

bool getRelay() {
  return relayState;
}

void setupRelay() {
  pinMode(RELAY, OUTPUT);
  setRelay(false);
}