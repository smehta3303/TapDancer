#include <stdint.h>
#include "include/hardware.h"


// constants
static constexpr uint16_t DebounceTimerInterval = 10 * 1000;    // 10 ms
static constexpr uint8_t LoopPeriod = 100;      // 100 ms

uint32_t time_since_last_run = 0;

Hardware hw;
IntervalTimer debouncer;
volatile bool toggle = false;
bool previous_toggle_val = toggle;

uint8_t previous_pin_state = 1;
uint8_t debounce_count = 0;

SwitchState previous_switch_state = SwitchState::UNINITIALIZED;
SwitchState switch_state = SwitchState::UNINITIALIZED;


void setup() {
    Serial.begin(115200);
    
    // HW setup
    hw.Initialize();

    debouncer.begin(debounce_callback, DebounceTimerInterval);

}

void scheduler_callback() {
    if (toggle == false) {
        toggle = true;
    } else {
        toggle = false;
    }
}

void debounce_callback() {
    hw.GetSwitch1().Debounce();
}

void process_events() {
    switch_state = hw.GetSwitch1().GetState();
    
    if (previous_switch_state != switch_state) {
        previous_switch_state = switch_state;
        if(switch_state == SwitchState::PRESSED) {
            Serial.println("PRESSED");
        } else if(switch_state == SwitchState::RELEASED) {
            Serial.println("RELEASED");
        }
    }
}

void loop() {
    uint32_t current_ticks_ms = millis();
    if((current_ticks_ms - time_since_last_run) >= LoopPeriod) {
        time_since_last_run = current_ticks_ms;

        process_events();
        
    }
}
