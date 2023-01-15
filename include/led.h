#ifndef INCLUDE_LED_H_
#define INCLUDE_LED_H_

#include <stdint.h>

class Led {
 public:
    Led (const uint8_t pin)
    : pin_(pin) {}

    void Initialize() const;
    void On() const;
    void Off() const;

 private:
    const uint8_t pin_;

};

#endif  // INCLUDE_LED_H_