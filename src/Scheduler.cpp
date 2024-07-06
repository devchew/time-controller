#include "Scheduler.h"

extern State state;

void setupScheduler() {}

void scheduleLoop() {
    if (state.isAuto) {
        state.isOn = (state.currentTime >= state.scheduleFrom && state.currentTime < state.scheduleTo);
    }
}