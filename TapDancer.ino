#include <stdint.h>
#include "include/hardware.h"


// constants
static constexpr uint16_t DebounceTimerInterval = 10 * 1000;    // 10 ms
static constexpr uint8_t LoopPeriod = 100;      // 100 ms
elapsedMillis run_interval = 0;

Hardware hw;
IntervalTimer debouncer;

void setup() {
    Serial.begin(115200);
    
    // HW setup
    hw.Initialize();

    debouncer.begin(debounce_callback, DebounceTimerInterval);

}

void debounce_callback() {
    hw.GetSwitch1().Debounce();
}

void process_events() {
    SwitchState switch_state = hw.GetSwitch1().GetState();

    if(switch_state == SwitchState::PRESSED) {
        hw.GetLed1().On();
    } else {
        hw.GetLed1().Off();
    }
}

void loop() {
    if(run_interval >= LoopPeriod) {
        run_interval = 0;

        process_events();
        
    }
}
