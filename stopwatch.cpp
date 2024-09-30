#include "stopwatch.h"
void Stopwatch::watch_start() {
  paused = true;
}
void Stopwatch::watch_stop() {
    paused = false;
}

void Stopwatch::watch_clear() {
    seconds = 0;
    seconds_on_diplay = 0;
    minutes = 0;
    counter = 0;
    previous_seconds_value = 0;
    paused = false;
}



bool Stopwatch::get_paused() {
    return paused;
}






short int Stopwatch::get_seconds() {
    return seconds;
}

short int Stopwatch::get_seconds_on_display() {
    return seconds_on_diplay;
}
void Stopwatch::set_seconds_on_display(short int value) {
    seconds_on_diplay = value;
}

short int Stopwatch::increase_seconds() {
    seconds += 1;
    return seconds;
}

short int Stopwatch::increase_seconds_on_display() {
    seconds_on_diplay += 1;
    return seconds_on_diplay;






}
short int Stopwatch::increase_minutes() {
    minutes += 1;
    return minutes;
}

short int Stopwatch::get_minutes() {
    return minutes;
}

void Stopwatch::set_minutes(short int value) {
    minutes = value;
}






short int Stopwatch::increase_counter() {
    counter += 1;
    return counter;
}

int Stopwatch::get_counter() {
    return counter;
}





void Stopwatch::set_previous_second_value(short int value) {
    previous_seconds_value = value;
}

short int Stopwatch::get_previous_seconds_value() {
    return previous_seconds_value;
}

void Stopwatch::set_previous_minutes_value(short int value) {
    previous_minutes_value = value;
}

short int Stopwatch::get_previous_minutes_value() {
    return previous_minutes_value;
}
