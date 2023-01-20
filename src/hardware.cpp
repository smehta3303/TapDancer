#include "Arduino.h"
#include "../include/hardware.h"

void Hardware::Initialize() const {
    relay_1_.Initialize();
    relay_2_.Initialize();
    relay_3_.Initialize();
    relay_4_.Initialize();
    relay_5_.Initialize();
    relay_6_.Initialize();
    relay_7_.Initialize();
    relay_8_.Initialize();

    status_led_.Initialize();
    led_1_.Initialize();
    led_2_.Initialize();
    led_3_.Initialize();
    led_4_.Initialize();
    led_5_.Initialize();
    led_6_.Initialize();
    led_7_.Initialize();
    led_8_.Initialize();

    led_1_.Off();
    led_2_.Off();
    led_3_.Off();
    led_4_.Off();
    led_5_.Off();
    led_6_.Off();
    led_7_.Off();
    led_8_.Off();


    fs1_.Initialize();
    fs2_.Initialize();
    fs3_.Initialize();
    fs4_.Initialize();
    fs5_.Initialize();
    fs6_.Initialize();
    fs7_.Initialize();
    fs8_.Initialize();
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

Led& Hardware::GetStatusLed() const {
    return status_led_;
}

Led& Hardware::GetLed1() const {
    return led_1_;
}

Led& Hardware::GetLed2() const {
    return led_2_;
}

Led& Hardware::GetLed3() const {
    return led_3_;
}

Led& Hardware::GetLed4() const {
    return led_4_;
}

Led& Hardware::GetLed5() const {
    return led_5_;
}

Led& Hardware::GetLed6() const {
    return led_6_;
}

Led& Hardware::GetLed7() const {
    return led_7_;
}

Led& Hardware::GetLed8() const {
    return led_8_;
}

Switch& Hardware::GetSwitch1() const {
    return fs1_;
}

Switch& Hardware::GetSwitch2() const {
    return fs2_;
}

Switch& Hardware::GetSwitch3() const {
    return fs3_;
}

Switch& Hardware::GetSwitch4() const {
    return fs4_;
}

Switch& Hardware::GetSwitch5() const {
    return fs5_;
}

Switch& Hardware::GetSwitch6() const {
    return fs6_;
}

Switch& Hardware::GetSwitch7() const {
    return fs7_;
}

Switch& Hardware::GetSwitch8() const {
    return fs8_;
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
    
    led_1_.On();
    led_2_.On();
    led_3_.On();
    led_4_.On();
    led_5_.On();
    led_6_.On();
    led_7_.On();
    led_8_.On();
}

// Sanity test, turn everything off except status led
void Hardware::TestOff() const {
    relay_1_.Off();
    relay_2_.Off();
    relay_3_.Off();
    relay_4_.Off();
    relay_5_.Off();
    relay_6_.Off();
    relay_7_.Off();
    relay_8_.Off();

    led_1_.Off();
    led_2_.Off();
    led_3_.Off();
    led_4_.Off();
    led_5_.Off();
    led_6_.Off();
    led_7_.Off();
    led_8_.Off();
}
