#include "Arduino.h"
#include "../include/led.h"


void Led::Initialize() const {
    pin_.Initialize();

    Serial.print(name_);
    Serial.println(" Initialized");
}

void Led::On() const {
    pin_.On();
}

void Led::Off() const {
    pin_.Off();
}

void Led::Toggle() const {
    pin_.Toggle();
}