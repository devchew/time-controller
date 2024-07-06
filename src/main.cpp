#include <Arduino.h>

#include "Relay.h"
#include "Buttons.h"
#include "State.h"
#include "Scheduler.h"
#include "Time.h"
#include "Remote.h"

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
  setupRemote();
}


void loop(void) {
  timeLoop();
  scheduleLoop();
  relayLoop();
  remoteLoop();
  drawScreen();
}