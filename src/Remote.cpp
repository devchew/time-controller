#include "Remote.h"

/**
 * Commands:
 * 
 * set
 *  - time [hh:mm]
 *    example: set time 21:30
 *  - state [on|off]
 *    example: set state on
 *  - schedule [hh:mm hh:mm]
 *    example: set schedule 06:30 22:30
 *  - auto [on|off]
 *    example: set auto mode on
 * 
 * get
 * - time
 *   returns: hh:mm
 * - state
 *   returns: on|off
 * - schedule
 *   returns: hh:mm hh:mm
 * - auto
 *   returns: on|off
 * 
 */

extern State state;

void cmdHelp() {
    Serial.println("Commands:");
    Serial.println("help");
    Serial.println("set time [hh:mm]");
    Serial.println("set state [on|off]");
    Serial.println("set schedule [hh:mm hh:mm]");
    Serial.println("set auto [on|off]");
    Serial.println("get time");
    Serial.println("get state");
    Serial.println("get schedule");
    Serial.println("get auto");    
}

void cmdSetTime(String input) {
    int hour = input.substring(0, 2).toInt();
    int minute = input.substring(3, 5).toInt();
    setTime(hour, minute);
    saveState();
}

void cmdSetState(String input) {
    if (input == "on") {
        state.isOn = true;
        saveState();
    } else if (input == "off") {
        state.isOn = false;
        saveState();
    } else {
        Serial.println("Invalid state");
    }
}

void cmdSetSchedule(String input) {
    int startHour = input.substring(0, 2).toInt();
    int startMinute = input.substring(3, 5).toInt();
    int endHour = input.substring(6, 8).toInt();
    int endMinute = input.substring(9, 11).toInt();
    state.scheduleFrom = startHour * 60 + startMinute;
    state.scheduleTo = endHour * 60 + endMinute;
    saveState();
}

void cmdSetAutoMode(String input) {
    if (input == "on") {
        state.isAuto = true;
        saveState();
    } else if (input == "off") {
        state.isAuto = false;
        saveState();
    } else {
        Serial.println("Invalid auto mode");
    }
}

void cmdGetTime() {
    int hours = state.currentTime / 60;
    int minutes = state.currentTime % 60;
    Serial.println(String(hours) + ":" + String(minutes));
}

void cmdGetState() {
    Serial.println(state.isOn ? "on" : "off");
}

void cmdGetSchedule() {
    int startHour = state.scheduleFrom / 60;
    int startMinute = state.scheduleFrom % 60;
    int endHour = state.scheduleTo / 60;
    int endMinute = state.scheduleTo % 60;
    Serial.println(String(startHour) + ":" + String(startMinute) + " " + String(endHour) + ":" + String(endMinute));
}

void cmdGetAutoMode() {
    Serial.println(state.isAuto ? "on" : "off");
}

void setupRemote() {
    Serial.begin(9600);
}

void remoteLoop() {
    if (Serial.available()) {
        String input = Serial.readStringUntil('\n');
        Serial.println("# " + input);

        if (input == "help") {
            cmdHelp();
        } else if (input.startsWith("set time")) {
            cmdSetTime(input.substring(9));
        } else if (input.startsWith("set state")) {
            cmdSetState(input.substring(10));
        } else if (input.startsWith("set schedule")) {
            cmdSetSchedule(input.substring(13));
        } else if (input.startsWith("set auto")) {
            cmdSetAutoMode(input.substring(9));
        } else if (input == "get time") {
            cmdGetTime();
        } else if (input == "get state") {
            cmdGetState();
        } else if (input == "get schedule") {
            cmdGetSchedule();
        } else if (input == "get auto") {
            cmdGetAutoMode();
        } else {
          Serial.println("Unknown command");
        }

    }
}