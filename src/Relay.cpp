#include "Relay.h"

bool relayState = false;

void setRelay(bool state) {
  relayState = state;
  digitalWrite(RELAY, relayState ? HIGH : LOW);
}

void setupRelay() {
  pinMode(RELAY, OUTPUT);
  setRelay(false);
}