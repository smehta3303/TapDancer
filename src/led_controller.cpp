#include "../include/led_controller.h"

void LedController::Initialize() const {
    for (uint8_t i = 0; i < MaxLedCount; i++) {
        leds_[i].get().Initialize();
        leds_[i].get().Off();
    }
}

const Led& LedController::GetLedFromSwitchId(const SwitchId id) const {
    switch (id) {
        case SwitchId::FS1: return leds_[0].get();
        case SwitchId::FS2: return leds_[1].get();
        case SwitchId::FS3: return leds_[2].get();
        case SwitchId::FS4: return leds_[3].get();
        case SwitchId::FS5: return leds_[4].get();
        case SwitchId::FS6: return leds_[5].get();
        case SwitchId::FS7: return leds_[6].get();
        case SwitchId::FS8: return leds_[7].get();
        case SwitchId::NONE:
        default:
            return status_led_;
    }
}

void LedController::Run() const {

    // process events
    if (switch_event_.dirty) {
        Serial.println("LedController::Run: Got event!");
        const Led& led = GetLedFromSwitchId(switch_event_.id);
        LedState led_state = led.GetState();

        switch (switch_event_.event) {
            case SwitchEvent::PRESSED:
                Serial.println("LedController::Run: event: SwitchEvent::PRESSED");
                if ((led_state == LedState::LED_OFF) || 
                    (led_state == LedState::LED_PULSE)) {
                    led.On();
                    Serial.println("LedController::Run: event: SwitchEvent::PRESSED: ON");
                } else {
                    led.Off();
                    Serial.println("LedController::Run: event: SwitchEvent::PRESSED: OFF");
                }
                break;
            case SwitchEvent::CONFIGURE:
                Serial.println("LedController::Run: event: SwitchEvent::CONFIGURE");
                if (led_state == LedState::LED_OFF) {
                    led.Pulse();
                    Serial.println("LedController::Run: event: SwitchEvent::CONFIGURE: PULSE");
                } else {
                    led.Off();
                    Serial.println("LedController::Run: event: SwitchEvent::CONFIGURE: OFF");
                }
                break;
            case SwitchEvent::NO_EVENT:
            default:
                break;
        }
        switch_event_.dirty = false;
    } else {
        for (uint8_t i = 0; i < MaxLedCount; i++) {
            const Led& led = leds_[i].get();
            LedState led_state = led.GetState();

            switch(led_state) {
                case LedState::LED_ON:
                    led.On();
                    break;

                case LedState::LED_PULSE:
                    led.Pulse();
                    break;

                case LedState::LED_OFF:
                    led.Off();
                    break;
                default:
                    break;
            }
        }
    }
}

void LedController::SendSwitchEvent(const SwitchId id, const SwitchEvent event) const {
    switch_event_.dirty = true;
    switch_event_.id = id;
    switch_event_.event = event;
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
        for (uint8_t i = 0; i < MaxLedCount; i++) {
            leds_[i].get().Off();
        }
        initialized_ = true;
    }
}