#include "Time.h"

extern State state;

void setupTime() {
  setSyncProvider(RTC.get);
  if (timeStatus() != timeSet) {
    setTime(5, 5);
  }
}

void timeLoop() {
  if (timeStatus() != timeNotSet) {
    state.currentTime = hour() * 60 + minute();
  }
}

void setTime(int hour, int minute) { 
  setTime(hour, minute, 0, 1, 1, 2019);
  RTC.set(now());
}