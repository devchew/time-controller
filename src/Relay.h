#ifndef RELAY_H
#define RELAY_H

#include <Arduino.h>

#define RELAY 5

void setRelay(bool state);

bool getRelay();

void setupRelay();

#endif