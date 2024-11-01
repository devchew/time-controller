#include "Scheduler.h"

extern State state;

bool isTimeBetween(int from, int to, int time) {
    if (from < to) {
        return time >= from && time < to;
    } else {
        return time >= from || time < to;
    }
}

bool shouldBeOn(int currentTime, int intervalWindow, int intervalDuration) {
    int interval = currentTime % intervalWindow;
    return interval < intervalDuration;
}


void setupScheduler() {}

void scheduleLoop() {
    if (!state.isAuto) {
        return;
    }

    if (!isTimeBetween(state.scheduleFrom, state.scheduleTo, state.currentTime)) {
        state.isOn = false;
        return;
    }

    state.isOn = shouldBeOn(state.currentTime, state.intervalWindow, state.intervalDuration);

    
}