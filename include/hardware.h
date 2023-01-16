#ifndef INCLUDE_HARDWARE_H_
#define INCLUDE_HARDWARE_H_

#include <stdint.h>
#include "Arduino.h"
#include "relay.h" 
#include "led.h"
#include "gpio.h"

class Hardware {
 public:
    Hardware() 
    : relay_1_pin_(0, GpioType::OUTPUT_PIN, debug_)
    , relay_1_("Relay 1", relay_1_pin_, debug_)
    , relay_2_pin_(1, GpioType::OUTPUT_PIN, debug_)
    , relay_2_("Relay 2", relay_2_pin_, debug_)
    , relay_3_pin_(2, GpioType::OUTPUT_PIN, debug_)
    , relay_3_("Relay 3", relay_3_pin_, debug_)
    , relay_4_pin_(3, GpioType::OUTPUT_PIN, debug_)
    , relay_4_("Relay 4", relay_4_pin_, debug_)
    , relay_5_pin_(4, GpioType::OUTPUT_PIN, debug_)
    , relay_5_("Relay 5", relay_5_pin_, debug_)
    , relay_6_pin_(5, GpioType::OUTPUT_PIN, debug_)
    , relay_6_("Relay 6", relay_6_pin_, debug_)
    , relay_7_pin_(6, GpioType::OUTPUT_PIN, debug_)
    , relay_7_("Relay 7", relay_7_pin_, debug_)
    , relay_8_pin_(7, GpioType::OUTPUT_PIN, debug_)
    , relay_8_("Relay 8", relay_8_pin_, debug_)
    , status_led_pin_(LED_BUILTIN, GpioType::OUTPUT_PIN, debug_)
    , status_led_("Status Led", status_led_pin_, debug_)
    , led_1_pin_(8, GpioType::OUTPUT_PIN, debug_)
    , led_1_("Led 1", led_1_pin_, debug_)
    , led_2_pin_(9, GpioType::OUTPUT_PIN, debug_)
    , led_2_("Led 2", led_2_pin_, debug_)
    , led_3_pin_(10, GpioType::OUTPUT_PIN, debug_)
    , led_3_("Led 3", led_3_pin_, debug_)
    , led_4_pin_(11, GpioType::OUTPUT_PIN, debug_)
    , led_4_("Led 4", led_4_pin_, debug_)
    , led_5_pin_(12 , GpioType::OUTPUT_PIN, debug_)
    , led_5_("Led 5", led_5_pin_, debug_)
    , led_6_pin_(23, GpioType::OUTPUT_PIN, debug_)
    , led_6_("Led 6", led_6_pin_, debug_)
    , led_7_pin_(22, GpioType::OUTPUT_PIN, debug_)
    , led_7_("Led 7", led_7_pin_, debug_)
    , led_8_pin_(21, GpioType::OUTPUT_PIN, debug_)
    , led_8_("Led 8", led_8_pin_, debug_) {}

    void Initialize() const;
    
    Relay& GetRelay1() const;
    Relay& GetRelay2() const;
    Relay& GetRelay3() const;
    Relay& GetRelay4() const;
    Relay& GetRelay5() const;
    Relay& GetRelay6() const;
    Relay& GetRelay7() const;
    Relay& GetRelay8() const;

    Led& GetStatusLed() const;
    Led& GetLed1() const;
    Led& GetLed2() const;
    Led& GetLed3() const;
    Led& GetLed4() const;
    Led& GetLed5() const;
    Led& GetLed6() const;
    Led& GetLed7() const;
    Led& GetLed8() const;

    void TestOn() const;
    void TestOff() const;

 private:
    // Misc
    static constexpr bool debug_ = false;
    
    // Relay pins
    
    mutable Gpio relay_1_pin_;
    mutable Relay relay_1_;
    
    // Relays
    mutable Gpio relay_2_pin_;
    mutable Relay relay_2_;
    mutable Gpio relay_3_pin_;
    mutable Relay relay_3_;
    mutable Gpio relay_4_pin_;
    mutable Relay relay_4_;
    mutable Gpio relay_5_pin_;
    mutable Relay relay_5_;
    mutable Gpio relay_6_pin_;
    mutable Relay relay_6_;
    mutable Gpio relay_7_pin_;
    mutable Relay relay_7_;
    mutable Gpio relay_8_pin_;
    mutable Relay relay_8_;
    
    // LEDs
    mutable Gpio status_led_pin_;
    mutable Led status_led_;
    mutable Gpio led_1_pin_;
    mutable Led led_1_;
    mutable Gpio led_2_pin_;
    mutable Led led_2_;
    mutable Gpio led_3_pin_;
    mutable Led led_3_;
    mutable Gpio led_4_pin_;
    mutable Led led_4_;
    mutable Gpio led_5_pin_;
    mutable Led led_5_;
    mutable Gpio led_6_pin_;
    mutable Led led_6_;
    mutable Gpio led_7_pin_;
    mutable Led led_7_;
    mutable Gpio led_8_pin_;
    mutable Led led_8_;

};

#endif  // INCLUDE_HARDWARE_H_
