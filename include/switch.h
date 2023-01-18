#ifndef INCLUDE_SWITCH_H_
#define INCLUDE_SWITCH_H_

#include <stdint.h>
#include "Arduino.h"
#include "gpio.h"

enum SwitchState {
    UNINITIALIZED,
    PRESSED,
    RELEASED
};

class Switch {
 public:
    Switch (const char* name, const Gpio& pin, const bool debug)
    : name_(name)
    , pin_(pin)
    , state_(SwitchState::UNINITIALIZED)
    , debug_(debug)
    , debounce_count_(0)
    , previous_switch_state_(LOW) {}

    void Initialize() const;
    void Debounce() const;
    SwitchState GetState() const;

 private:
    const char* name_;
    const Gpio& pin_;
    mutable volatile SwitchState state_;
    const bool debug_;

    //debounce info
    mutable uint8_t debounce_count_;
    mutable uint8_t previous_switch_state_;

    static constexpr uint8_t MaxDebounceCount = 2;      // results in a 20 ms debounce

};

#endif  // INCLUDE_SWITCH_H_