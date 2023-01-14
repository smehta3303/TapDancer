#include "Arduino.h"
#include "hardware.h"

void Hardware::Initialize() const {
    relay_1_.Initialize();
    relay_2_.Initialize();
    relay_3_.Initialize();
    relay_4_.Initialize();
    relay_5_.Initialize();
    relay_6_.Initialize();
    relay_7_.Initialize();
    relay_8_.Initialize();

    pinMode(Status_Led, OUTPUT);
}

Relay& Hardware::GetRelay1() const {
    return relay_1_;
}

Relay& Hardware::GetRelay2() const {
    return relay_2_;
}

Relay& Hardware::GetRelay3() const {
    return relay_3_;
}

Relay& Hardware::GetRelay4() const {
    return relay_4_;
}

Relay& Hardware::GetRelay5() const {
    return relay_5_;
}

Relay& Hardware::GetRelay6() const {
    return relay_6_;
}

Relay& Hardware::GetRelay7() const {
    return relay_7_;
}

Relay& Hardware::GetRelay8() const {
    return relay_8_;
}

void Hardware::SetStatusLed(const bool on) const {
    if (on) {
        digitalWrite(Status_Led, HIGH);
    } else {
        digitalWrite(Status_Led, LOW);
    }
}

// Sanity test, turn everything on
void Hardware::TestOn() const {
    relay_1_.On();
    relay_2_.On();
    relay_3_.On();
    relay_4_.On();
    relay_5_.On();
    relay_6_.On();
    relay_7_.On();
    relay_8_.On();
    
    SetStatusLed(true);
}

// Sanity test, turn everything off
void Hardware::TestOff() const {
    relay_1_.Off();
    relay_2_.Off();
    relay_3_.Off();
    relay_4_.Off();
    relay_5_.Off();
    relay_6_.Off();
    relay_7_.Off();
    relay_8_.Off();
    
    SetStatusLed(false);
}
