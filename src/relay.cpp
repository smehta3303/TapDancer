#include "Arduino.h"
#include "../include/relay.h"

void Relay::Initialize() const {
    pinMode(pin_, OUTPUT);
    String pin_name = String(pin_);
    Serial.println("Relay Pin: " + pin_name + " set to OUTPUT");
}

void Relay::On() const {
    digitalWrite(pin_, HIGH);
    
    if (log_) {
        String pin_name = String(pin_);
        Serial.println("Relay Pin: " + pin_name + " set to ON");
    }
}

void Relay::Off() const {
    digitalWrite(pin_, LOW);
    
    if (log_) {
        String pin_name = String(pin_);
        Serial.println("Relay Pin: " + pin_name + " set to OFF");
    }
}