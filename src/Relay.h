#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>
#include "State.h"

#define RELAY A3


void setupRelay();
void relayLoop();

#endif