#ifndef INCLUDE_LED_CONTROLLER_H_
#define INCLUDE_LED_CONTROLLER_H_

#include <functional>
#include "led.h"

enum LCState {
    LC_UNINITIALIZED,
    LC_NORMAL,
    LC_CONFIGURE
};

class LedController {
 public:
    LedController(const Led& led1,
                  const Led& led2,
                  const Led& led3,
                  const Led& led4,
                  const Led& led5,
                  const Led& led6,
                  const Led& led7,
                  const Led& led8,
                  const uint8_t loop_period)
        : leds_{led1, led2, led3, led4, led5, led6, led7, led8},
          state_(LCState::LC_UNINITIALIZED),
          initialized_(false),
          pulse_count_(0),
          leds_toggled_(false),
          loop_period_(loop_period),
          blink_ticks_(500/loop_period_) {}

    void Initialize() const;
    void Run() const;
    uint8_t SendEvent() const;
    bool InitSequenceRan() const {return initialized_;}
    void RunLedInitSequence() const;

 private:
    static constexpr uint8_t MaxLedCount = 8;

    mutable std::reference_wrapper<const Led> leds_[MaxLedCount];
    mutable LCState state_;
    mutable bool initialized_;
    mutable uint8_t pulse_count_;
    mutable bool leds_toggled_;
    const uint8_t loop_period_;
    const uint16_t blink_ticks_;

    static constexpr uint8_t MaxPulseCount = 2 * (255 / Led::PulseSpeed);
   
};


#endif  // INCLUDE_LED_CONTROLLER_H_