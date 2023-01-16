#include "Arduino.h"
#include "../include/relay.h"

void Relay::Initialize() const {
   pin_.Initialize();

   Serial.print(name_);
   Serial.println(" Initialized");
}

void Relay::On() const {
    pin_.On();
}

void Relay::Off() const {
    pin_.Off();
}