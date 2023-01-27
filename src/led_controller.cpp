#include "../include/led_controller.h"

void LedController::Initialize() const {
    for (uint8_t i = 0; i < MaxLedCount; i++) {
        leds_[i].get().Initialize();
    }
}

void LedController::Run() const {

}

uint8_t LedController::SendEvent() const {
    return 0;
}

void LedController::RunLedInitSequence() const {
    if (initialized_) {
        return;
    }

    if (!leds_toggled_) {
        leds_[0].get().On();
        delay(100);
        leds_[0].get().Off();
        leds_[1].get().On();
        delay(100);
        leds_[1].get().Off();
        leds_[2].get().On();
        delay(100);
        leds_[2].get().Off();
        leds_[3].get().On();
        delay(100);
        leds_[3].get().Off();
        leds_[4].get().On();
        delay(100);
        leds_[4].get().Off();
        leds_[5].get().On();
        delay(100);
        leds_[5].get().Off();
        leds_[6].get().On();
        delay(100);
        leds_[6].get().Off();
        leds_[7].get().On();
        delay(100);
        leds_[7].get().Off();
        leds_toggled_ = true;
    }
    
    if (pulse_count_ != MaxPulseCount) {
        pulse_count_++;
        
        for (uint8_t i = 0; i < MaxLedCount; i++) {
            leds_[i].get().Pulse();
        }
    } else {
        initialized_ = true;
    }
}