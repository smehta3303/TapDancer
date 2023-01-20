#ifndef INCLUDE_RELAY_H_
#define INCLUDE_RELAY_H_

#include <stdint.h>
#include "gpio.h"

class Relay {
 public:
    Relay(const char* name, const Gpio& pin, const bool debug=false)
    : name_(name),
      pin_(pin),
      debug_(debug) {}

    void Initialize() const;
    void On() const;
    void Off() const;
    
 private:
    const char* name_;
    const Gpio& pin_;
    const bool debug_;

};

#endif  // INCLUDE_RELAY_H_