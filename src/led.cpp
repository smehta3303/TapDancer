#include "Arduino.h"
#include "../include/led.h"


void Led::Initialize() const {
    if (initialized_) {
        return;
    }

    pin_.Initialize();
    Off();

    Serial.print(name_);
    Serial.println(" Initialized");
    initialized_ = true;
}

void Led::On() const {
    duty_cycle_ = 255;
    pin_.SetDutyCycle(duty_cycle_);
    state_ = LedState::LED_ON;
}

void Led::Off() const {
    duty_cycle_ = 0;
    pin_.SetDutyCycle(duty_cycle_);
  
    state_ = LedState::LED_OFF;
}

void Led::Toggle() const {
    pin_.Toggle();
    uint8_t pin_state = pin_.Read();
    if(pin_state == HIGH) {
        state_ = LedState::LED_ON;
    } else {
        state_ = LedState::LED_OFF;
    }
}

void Led::Pulse() const {
    if (duty_cycle_ <= 0) {
        pulse_up_ = true;
    } else if (duty_cycle_ >= MaxPulseValue) {
        pulse_up_ = false;
    }

    if (pulse_up_) {
        duty_cycle_ += PulseSpeed;
    } else {
        duty_cycle_ -= PulseSpeed;
    }
    pin_.SetDutyCycle(duty_cycle_);
    state_ = LedState::LED_PULSE;
}