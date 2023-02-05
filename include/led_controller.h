#ifndef INCLUDE_LED_CONTROLLER_H_
#define INCLUDE_LED_CONTROLLER_H_

#include <functional>
#include "led.h"
#include "switch.h"

enum LCState {
    LC_UNINITIALIZED,
    LC_NORMAL,
    LC_CONFIGURE
};

struct LedSwitchEvent {
    SwitchId id = SwitchId::NONE;
    SwitchEvent event = SwitchEvent::NO_EVENT;
    bool dirty = false;
};

class LedController {
 public:
    LedController(const Led& status_led,
                  const Led& led1,
                  const Led& led2,
                  const Led& led3,
                  const Led& led4,
                  const Led& led5,
                  const Led& led6,
                  const Led& led7,
                  const Led& led8,
                  const uint8_t loop_period)
        : status_led_(status_led),
          leds_{led1, led2, led3, led4, led5, led6, led7, led8},
          state_(LCState::LC_UNINITIALIZED),
          init_seq_complete_(false),
          pulse_count_(0),
          leds_toggled_(false),
          loop_period_(loop_period),
          blink_ticks_(500/loop_period),
          switch_event_() {}

    void Initialize() const;
    void Run() const;
    void SendSwitchEvent(const SwitchId id, const SwitchEvent event) const;
    bool InitSequenceRan() const {return init_seq_complete_;}
    void RunLedInitSequence() const;
    const Led& GetLedFromSwitchId(const SwitchId id) const;

 private:
    static constexpr uint8_t MaxLedCount = 8;

    const Led& status_led_;
    const std::reference_wrapper<const Led> leds_[MaxLedCount];
    mutable LCState state_;
    mutable bool init_seq_complete_;
    mutable uint8_t pulse_count_;
    mutable bool leds_toggled_;
    const uint8_t loop_period_;
    const uint16_t blink_ticks_;
    mutable struct LedSwitchEvent switch_event_;

    static constexpr uint8_t MaxPulseCount = 2 * (255 / Led::PulseSpeed);
   
};


#endif  // INCLUDE_LED_CONTROLLER_H_