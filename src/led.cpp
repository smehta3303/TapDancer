#include "Arduino.h"
#include "../include/led.h"


void Led::Initialize() const {
    pinMode(pin_, OUTPUT);
}

void Led::On() const {
    digitalWrite(pin_, HIGH);
}

void Led::Off() const {
    digitalWrite(pin_, LOW);
}