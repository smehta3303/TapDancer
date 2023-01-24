#ifndef INCLUDE_SWITCH_H_
#define INCLUDE_SWITCH_H_

#include <stdint.h>
#include "Arduino.h"
#include "gpio.h"

enum SwitchEvent {
    NO_EVENT,
    FS1_PRESSED,
    FS2_PRESSED,
    FS3_PRESSED,
    FS4_PRESSED,
    FS5_PRESSED,
    FS6_PRESSED,
    FS7_PRESSED,
    FS8_PRESSED,
    FS1_RELEASED,
    FS2_RELEASED,
    FS3_RELEASED,
    FS4_RELEASED,
    FS5_RELEASED,
    FS6_RELEASED,
    FS7_RELEASED,
    FS8_RELEASED,
    FS1_CONFIGURE,
    FS2_CONFIGURE,
    FS3_CONFIGURE,
    FS4_CONFIGURE,
    FS5_CONFIGURE,
    FS6_CONFIGURE,
    FS7_CONFIGURE,
    FS8_CONFIGURE,
};

enum SwitchState {
    SW_UNINITIALIZED,
    SW_PRESSED,
    SW_RELEASED
};

class Switch {
 public:
    Switch (const char* name, const Gpio& pin, const bool debug)
    : name_(name),
      pin_(pin),
      debug_(debug),
      state_(SwitchState::SW_UNINITIALIZED),
      debounce_count_(0),
      previous_switch_state_(LOW) {}

    void Initialize() const;
    void Debounce() const;
    const SwitchState GetState() const;

 private:
    const char* name_;
    const Gpio& pin_;
    const bool debug_;
    mutable volatile SwitchState state_;

    //debounce info
    mutable uint8_t debounce_count_;
    mutable uint8_t previous_switch_state_;

    static constexpr uint8_t MaxDebounceCount = 2;      // results in a 20 ms debounce

};

#endif  // INCLUDE_SWITCH_H_