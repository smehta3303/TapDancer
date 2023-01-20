#ifndef INCLUDE_GPIO_H_
#define INCLUDE_GPIO_H_

#include <stdint.h>

enum GpioType {
    UNKNOWN_PIN,
    INPUT_PIN,
    INPUT_WITH_PULLUP,
    OUTPUT_PIN,
};

enum ActiveLevel {
    UNKNOWN_LEVEL,
    ACTIVE_HIGH,
    ACTIVE_LOW,
};

class Gpio {
 public:
    Gpio(const uint8_t pin, 
         const GpioType type, 
         const bool debug=false, 
         const ActiveLevel active_level=ActiveLevel::UNKNOWN_LEVEL) 
    : pin_(pin),
      type_(type),
      active_level_(active_level),
      debug_(debug) {}

    void Initialize() const;
    void On() const;
    void On(const uint8_t duty_cycle) const;
    void Off() const;
    void Toggle() const;
    uint8_t Read() const;

 private:
    const uint8_t pin_;
    const GpioType type_;
    const ActiveLevel active_level_;
    const bool debug_;
};

#endif  // INCLUDE_GPIO_H_