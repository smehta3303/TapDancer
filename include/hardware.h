#ifndef INCLUDE_HARDWARE_H_
#define INCLUDE_HARDWARE_H_

#include <stdint.h>
#include "relay.h" 
#include "led.h"

class Hardware {
 public:
    Hardware() 
    : relay_1_(Relay_1_Pin)
    , relay_2_(Relay_2_Pin)
    , relay_3_(Relay_3_Pin)
    , relay_4_(Relay_4_Pin)
    , relay_5_(Relay_5_Pin)
    , relay_6_(Relay_6_Pin)
    , relay_7_(Relay_7_Pin)
    , relay_8_(Relay_8_Pin) {}

    void Initialize() const;
    
    Relay& GetRelay1() const;
    Relay& GetRelay2() const;
    Relay& GetRelay3() const;
    Relay& GetRelay4() const;
    Relay& GetRelay5() const;
    Relay& GetRelay6() const;
    Relay& GetRelay7() const;
    Relay& GetRelay8() const;

    void SetStatusLed(const bool on) const;
    void TestOn() const;
    void TestOff() const;

 private:
    // Relay pins
    static constexpr uint8_t Relay_1_Pin = 0;
    static constexpr uint8_t Relay_2_Pin = 1;
    static constexpr uint8_t Relay_3_Pin = 2;
    static constexpr uint8_t Relay_4_Pin = 3;
    static constexpr uint8_t Relay_5_Pin = 4;
    static constexpr uint8_t Relay_6_Pin = 5;
    static constexpr uint8_t Relay_7_Pin = 6;
    static constexpr uint8_t Relay_8_Pin = 7;
    
    // LEDs
    static constexpr uint8_t Status_Led_Pin = LED_BUILTIN;   // pin 13
    static constexpr uint8_t Led_1_Pin = 8;
    static constexpr uint8_t Led_2_Pin = 9;
    static constexpr uint8_t Led_3_Pin = 10;
    static constexpr uint8_t Led_4_Pin = 11;
    static constexpr uint8_t Led_5_Pin = 12;
    static constexpr uint8_t Led_6_Pin = 23;
    static constexpr uint8_t Led_7_Pin = 22;
    static constexpr uint8_t Led_8_Pin = 21;

    
    mutable Relay relay_1_;
    mutable Relay relay_2_;
    mutable Relay relay_3_;
    mutable Relay relay_4_;
    mutable Relay relay_5_;
    mutable Relay relay_6_;
    mutable Relay relay_7_;
    mutable Relay relay_8_;

    
   

};

#endif  // INCLUDE_HARDWARE_H_
