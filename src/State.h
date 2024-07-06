#ifndef STATE_H
#define STATE_H

#include <Arduino.h>


struct State {
    // schedule starting time in minutes
    int scheduleFrom;
    // schedule ending time in minutes
    int scheduleTo;
    // current time in minutes
    int currentTime;
    
    bool isOn;
    bool isAuto;
};

void setupState();
void saveState();

#endif