#ifndef STATE_H
#define STATE_H

#include <Arduino.h>
#include <EEPROM.h>

struct State {
    // schedule starting time in minutes
    int scheduleFrom;
    // schedule ending time in minutes
    int scheduleTo;
    // current time in minutes
    int currentTime;
    // interval window in minutes
    int intervalWindow;
    // interval duration in minutes
    int intervalDuration;
    
    bool isOn;
    bool isAuto;
};

void setupState();
void saveState();

#endif