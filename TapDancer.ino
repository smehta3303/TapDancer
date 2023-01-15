#include "include/hardware.h"
#include "include/relay.h"

Hardware hw;

void setup() {
    Serial.begin(115200);
    
    // HW setup
    hw.Initialize();

    // Turn on status led
    hw.SetStatusLed(true);
}

void loop() {
    hw.TestOn();
    delay(2000);
    
    hw.TestOff();
    delay(2000);
}
