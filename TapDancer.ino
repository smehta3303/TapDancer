#include <stdint.h>
#include "include/hardware.h"


// constants
static constexpr uint32_t SchedulerInterval = 1000 * 1000;     // 1 s
static constexpr uint32_t DebounceTimerInterval = 10 * 1000;   // 10 ms

Hardware hw;
IntervalTimer scheduler;
volatile bool toggle = false;
bool previous_toggle_val = toggle;

void setup() {
    Serial.begin(115200);
    
    // HW setup
    hw.Initialize();

    scheduler.begin(scheduler_callback, SchedulerInterval);
}

void scheduler_callback() {
    if (toggle == false) {
        toggle = true;
    } else {
        toggle = false;
    }
}

void process_events() {

    bool toggle_copy = false;
    noInterrupts();
    toggle_copy = toggle;
    interrupts();

    if( previous_toggle_val != toggle_copy) {
        previous_toggle_val = toggle_copy;

        if(toggle_copy) {
            hw.TestOn();
        } else {
            hw.TestOff();
        }
    }
}

void loop() {
    process_events();
}
