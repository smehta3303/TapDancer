#ifndef INCLUDE_HARDWARE_H_
#define INCLUDE_HARDWARE_H_

#include "relay.h"

class Hardware {
  public:
    Hardware() 
    : relay_1_(Pin_Relay_1),
    relay_2_(Pin_Relay_2),
    relay_3_(Pin_Relay_3),
    relay_4_(Pin_Relay_4),
    relay_5_(Pin_Relay_5),
    relay_6_(Pin_Relay_6),
    relay_7_(Pin_Relay_7),
    relay_8_(Pin_Relay_8) {}

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
    const uint8_t Pin_Relay_1 = 2;
    const uint8_t Pin_Relay_2 = 3;
    const uint8_t Pin_Relay_3 = 4;
    const uint8_t Pin_Relay_4 = 5;
    const uint8_t Pin_Relay_5 = 6;
    const uint8_t Pin_Relay_6 = 7;
    const uint8_t Pin_Relay_7 = 8;
    const uint8_t Pin_Relay_8 = 9;
    
    mutable Relay relay_1_;
    mutable Relay relay_2_;
    mutable Relay relay_3_;
    mutable Relay relay_4_;
    mutable Relay relay_5_;
    mutable Relay relay_6_;
    mutable Relay relay_7_;
    mutable Relay relay_8_;

    
   

    const uint8_t Status_Led = 13;
};

#endif
