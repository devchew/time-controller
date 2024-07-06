#include <Arduino.h>

#include "Relay.h"
#include "Buttons.h"
#include "State.h"
#include "Scheduler.h"
#include "Time.h"

#include "Screen.h"
#include "Screens.h"

extern State state;

unsigned long lastTimeUpdate = 0;

void setup(void) {
  u8g2.begin(); 
  setupButtons();
  setupRelay();
  setupState();
  setupScreens();
  setupScheduler();
  setupTime();
}


void loop(void) {

  // tick current time every minute
  if (millis() - lastTimeUpdate > 60000) {
    lastTimeUpdate = millis();
    state.currentTime++;
    if (state.currentTime >= 1440) {
      state.currentTime = 0;
    }
  }

  scheduleLoop();
  drawScreen();
  relayLoop();
  timeLoop();
}