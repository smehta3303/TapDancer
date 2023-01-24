#include <stdint.h>
#include "include/hardware.h"

// constants
static constexpr uint16_t DebounceTimerInterval = 10 * 1000;    // 10 ms
static constexpr uint8_t LedUpdateInterval = 20;
static constexpr uint8_t LoopPeriod = 50;      // 100 ms

elapsedMillis led_interval = 0;
elapsedMillis run_interval = 0;

Hardware hw;
IntervalTimer debouncer;
LedState led_state = LedState::LED_OFF;

uint8_t pulse_count = 0;
uint8_t max_pulse_count = 2 * (255 / hw.GetLed1().GetPulseSpeed());
bool leds_toggled = false;
bool initialized = false;

SwitchState previous_switch_state = SwitchState::SW_UNINITIALIZED;
uint32_t switch_pressed_ticks = 0;

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

        update_leds();
    }
    
    if(run_interval >= LoopPeriod) {
        run_interval = 0;

        process_events();
    }
}

void process_events() {

    SwitchEvent event = get_switch_events();
    LedState current_state = hw.GetLed1().GetState();
    
    switch (event) {
        case SwitchEvent::FS1_PRESSED:
            Serial.println("Got Pressed Event");
            if(current_state == LedState::LED_OFF) {
                led_state = LedState::LED_ON;
                Serial.println("FS1_PRESSED: led_state: On");
                
            } else {
                led_state = LedState::LED_OFF;
                Serial.println("FS1_PRESSED: led_state: Off");
            }
            break;

        case SwitchEvent::FS1_CONFIGURE:
            if(current_state == LedState::LED_OFF) {
                led_state = LedState::LED_PULSE;
                Serial.println("FS1_CONFIGURE: led_state: Pulse");
            } else {
                led_state = LedState::LED_OFF;
                Serial.println("FS1_CONFIGURE: led_state: Off");
            }
            break;
        case SwitchEvent::FS1_RELEASED:
            led_state = LedState::LED_OFF;
            Serial.println("FS1_RELEASED: led_state: Off");
            break;

        case SwitchEvent::NO_EVENT:
            return;
        default:
            led_state = LedState::LED_OFF;
            Serial.println("default: led_state: Off");
    }
}

SwitchEvent get_switch_events() {
    SwitchState switch_state = hw.GetSwitch1().GetState();
    SwitchEvent event = SwitchEvent::NO_EVENT;

    if (previous_switch_state != switch_state) {
        Serial.println("GSE: Inside first if");

        if(switch_state == SwitchState::SW_PRESSED) {
            switch_pressed_ticks = millis();
            Serial.println("GSE: SW_PRESSED: Starting timer");
        } else if (switch_state == SwitchState::SW_RELEASED) {
            if ((millis() - switch_pressed_ticks) >= 3000) {
                event = SwitchEvent::FS1_CONFIGURE;
                Serial.println("GSE: Event: FS1_CONFIGURE");
            } else if (previous_switch_state == SwitchState::SW_PRESSED) {
                event = SwitchEvent::FS1_PRESSED;
                Serial.println("GSE: Event: FS1_PRESSED");
            } else {
                event = SwitchEvent::FS1_RELEASED;
                Serial.println("GSE: Event: FS1_RELEASED");
            }
        }
        previous_switch_state = switch_state;
    }
    return event;
}

void update_leds() {
    switch(led_state) {
        case LedState::LED_ON:
             hw.GetLed1().On();
             break;

        case LedState::LED_PULSE:
            hw.GetLed1().Pulse();
            break;

        case LedState::LED_OFF:
        default:
            hw.GetLed1().Off();
            break;
    }
}