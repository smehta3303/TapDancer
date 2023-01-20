#include <stdint.h>
#include "include/hardware.h"

// constants
static constexpr uint16_t DebounceTimerInterval = 10 * 1000;    // 10 ms
static constexpr uint8_t LedUpdateInterval = 20;
static constexpr uint8_t LoopPeriod = 100;      // 100 ms

elapsedMillis led_interval = 0;
elapsedMillis run_interval = 0;

Hardware hw;
IntervalTimer debouncer;
bool led_pulse = false;

uint8_t pulse_count = 0;
uint8_t max_pulse_count = 0;
bool leds_toggled = false;
bool initialized = false;

void init_sequence() {
    if (initialized) {
        return;
    }
    if (!leds_toggled) {
        hw.GetLed1().On();
        delay(100);
        hw.GetLed1().Off();
        hw.GetLed2().On();
        delay(100);
        hw.GetLed2().Off();
        hw.GetLed3().On();
        delay(100);
        hw.GetLed3().Off();
        hw.GetLed4().On();
        delay(100);
        hw.GetLed4().Off();
        hw.GetLed5().On();
        delay(100);
        hw.GetLed5().Off();
        hw.GetLed6().On();
        delay(100);
        hw.GetLed6().Off();
        hw.GetLed7().On();
        delay(100);
        hw.GetLed7().Off();
        hw.GetLed8().On();
        delay(100);
        hw.GetLed8().Off();
        leds_toggled = true;
    }
    
    max_pulse_count = 2 * (255 / hw.GetLed1().GetPulseSpeed());

    if (pulse_count != max_pulse_count) {
        pulse_count++;
        hw.GetLed1().Pulse();
        hw.GetLed2().Pulse();
        hw.GetLed3().Pulse();
        hw.GetLed4().Pulse();
        hw.GetLed5().Pulse();
        hw.GetLed6().Pulse();
        hw.GetLed7().Pulse();
        hw.GetLed8().Pulse();
    } else {
        initialized = true;
    }
}

void setup() {
    Serial.begin(115200);
    
    // HW setup
    hw.Initialize();

    debouncer.priority(128);    // default priority
    debouncer.begin(debounce_callback, DebounceTimerInterval);
}

void debounce_callback() {
    hw.GetSwitch1().Debounce();
}

void loop() {
    if (!initialized) {
        if (led_interval >= LedUpdateInterval) {
            led_interval = 0;

            init_sequence();
        }
        return;
    } 

    if (led_interval >= LedUpdateInterval) {
        led_interval = 0;
        if (led_pulse) {
            hw.GetLed1().Pulse();
        } else {
            hw.GetLed1().Off();
        }
    }
    
    if(run_interval >= LoopPeriod) {
        run_interval = 0;

        process_events();
    }
}

void process_events() {
    SwitchState switch_state = hw.GetSwitch1().GetState();

    if(switch_state == SwitchState::PRESSED) {
        if (!led_pulse) {
            led_pulse = true;
        } else {
            led_pulse = false;
        }
    } 
}
