#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_

#include <stdint.h>
#include "gpio.h"

class Led {
 public:
    Led (const char* name, const Gpio& pin, const bool debug)
    : name_(name)
    , pin_(pin)
    , debug_(debug) {}

    void Initialize() const;
    void On() const;
    void Off() const;
    void Toggle() const;

 private:
    const char* name_;
    const Gpio& pin_;
    const bool debug_;
};

#endif  // INCLUDE_LED_H_