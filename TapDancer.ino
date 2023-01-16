#include <stdint.h>
#include "include/hardware.h"


// constants
static constexpr uint32_t EventTimerInterval = 100 * 1000;     // 100 ms
static constexpr uint32_t DebounceTimerInterval = 10 * 1000;   // 10 ms

Hardware hw;


void setup() {
    Serial.begin(115200);
    
    // HW setup
    hw.Initialize();
}

void hardware_test() {
    // Turn on status led
    hw.GetStatusLed().On();

    hw.TestOn();
    delay(2000);
    
    hw.TestOff();
    delay(2000);
}

void loop() {
    hardware_test();
}
