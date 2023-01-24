#include "Arduino.h"
#include "../include/switch.h"

void Switch::Initialize() const {
    pin_.Initialize();

    Serial.print(name_);
    Serial.println(" Initialized");
}

void Switch::Debounce() const {
    uint8_t pin_state = pin_.Read();
    if (previous_switch_state_ != pin_state) {

        // first transition
        if (debounce_count_ == 0) {
            previous_switch_state_ = pin_state;
            debounce_count_++;
        } else {
            // this wasn't the transition, it's not stable
            debounce_count_ = 0;
        }
    } else if (debounce_count_ != 0) {
        debounce_count_++;
    }

    if(debounce_count_ >= MaxDebounceCount) {
        if (pin_state == 0) {
            state_ = SwitchState::SW_PRESSED;
        } else {
            state_ = SwitchState::SW_RELEASED;
        }
        debounce_count_ = 0;
    } 
}

const SwitchState Switch::GetState() const {
    SwitchState state = SwitchState::SW_UNINITIALIZED;
    
    noInterrupts();
    state = state_;
    interrupts();

    return state;
}
