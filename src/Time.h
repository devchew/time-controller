#ifndef TIME_H
#define TIME_H

#include <Arduino.h>
#include <TimeLib.h>
#include <Wire.h>
#include <DS1307RTC.h>  // a basic DS1307 library that returns time as a time_t
#include "State.h"

void setupTime();
void timeLoop();
void setTime(int hour, int minute);

#endif // TIME_H