#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_

#include <stdint.h>
#include "gpio.h"
#include "Arduino.h"


enum LedState {
    LED_UNINITIALIZED,
    LED_OFF,
    LED_ON,
    LED_PULSE
};

class Led {
 public:
    Led (const char* name, const Gpio& pin, const bool debug)
    : name_(name),
      pin_(pin),
      debug_(debug),
      duty_cycle_(0),
      pulse_up_(false),
      state_(LedState::LED_UNINITIALIZED) {}

    void Initialize() const;
    void On() const;
    void Off() const;
    void Toggle() const;
    void Pulse() const;
    uint8_t GetPulseSpeed() const {
        return PulseSpeed;
    }

    const LedState GetState() const {return state_;}

 private:
    const char* name_;
    const Gpio& pin_;
    const bool debug_;
    
    mutable uint8_t duty_cycle_;
    mutable bool pulse_up_;
    mutable LedState state_;

    static constexpr uint8_t PulseSpeed = 7;
    static constexpr uint8_t MaxPulseValue = (PulseSpeed * (255 / PulseSpeed));
};

#endif  // INCLUDE_LED_H_