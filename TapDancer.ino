#include <stdint.h>
#include "include/hardware.h"
#include "include/led_controller.h"

// constants
static constexpr uint16_t DebounceTimerInterval = 10 * 1000;    // 10 ms
static constexpr uint8_t LoopPeriod = 50;      // 50 ms

elapsedMillis run_interval = 0;

Hardware hw;
LedController led_controller(hw.GetStatusLed(),
                             hw.GetLed1(), 
                             hw.GetLed2(), 
                             hw.GetLed3(), 
                             hw.GetLed4(),
                             hw.GetLed5(), 
                             hw.GetLed6(), 
                             hw.GetLed7(), 
                             hw.GetLed8(), 
                             LoopPeriod);


IntervalTimer debouncer;

SwitchState previous_switch_state = SwitchState::SW_RELEASED;
uint32_t switch_pressed_ticks = 0;

void setup() {
    Serial.begin(115200);
    while(!Serial) {}
    
    // HW setup
    hw.Initialize();

    debouncer.priority(128);    // default priority
    debouncer.begin(debounce_callback, DebounceTimerInterval);

    led_controller.Initialize();
    while (!led_controller.InitSequenceRan()) {
        led_controller.RunLedInitSequence();
        delay(LoopPeriod);
    }
}

void debounce_callback() {
    hw.GetSwitch1().Debounce();
}

void loop() {
    if(run_interval >= LoopPeriod) {
        run_interval = 0;
       
        process_events();
        led_controller.Run();
    }
}

void process_events() {
    SwitchEvent event = get_switch_events();

    if (event != SwitchEvent::NO_EVENT) {
        if (event == SwitchEvent::CONFIGURE) {
            Serial.println("process_events: SendSwitchEvent: SwitchEvent::CONFIGURE");
        } else {
            Serial.println("process_events: SendSwitchEvent: SwitchEvent::PRESSED");
        }
        led_controller.SendSwitchEvent(SwitchId::FS1, event);
    }
    
}

SwitchEvent get_switch_events() {
    SwitchState switch_state = hw.GetSwitch1().GetState();
    SwitchEvent event = SwitchEvent::NO_EVENT;

    if (previous_switch_state != switch_state) {
        if(switch_state == SwitchState::SW_PRESSED) {
            switch_pressed_ticks = millis();
        } else if (switch_state == SwitchState::SW_RELEASED) {
            if ((millis() - switch_pressed_ticks) >= 3000) {
                event = SwitchEvent::CONFIGURE;
            } else if (previous_switch_state == SwitchState::SW_PRESSED) {
                event = SwitchEvent::PRESSED;
            }
        }
        previous_switch_state = switch_state;
    }
    return event;
}
