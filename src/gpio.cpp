#include <string>
#include "Arduino.h"
#include "../include/gpio.h"

void Gpio::Initialize() const {

    if (type_ == GpioType::OUTPUT_PIN) {
        pinMode(pin_, OUTPUT);
    } else if (type_ == GpioType::INPUT_PIN) {
        pinMode(pin_, INPUT);
    } else {
        Serial.println("Gpio: Unknown type!");
    }
}

void Gpio::On() const {

    if (type_ == GpioType::OUTPUT_PIN) {
        digitalWrite(pin_, HIGH);

        if(debug_) {
            String dbg = "Gpio: " + String(pin_) + ": HIGH";
            Serial.println(dbg);
        }
    } else {
        String dbg = "Gpio: Pin " + String(pin_) + ": Not an output pin";
        Serial.println(dbg);
    }
}

void Gpio::Off() const {
    if (type_ == GpioType::OUTPUT_PIN) {
        digitalWrite(pin_, LOW);

        if(debug_) {
            String dbg = "Gpio: " + String(pin_) + ": LOW";
            Serial.println(dbg);
        }
    } else {
        String dbg = "Gpio: Pin " + String(pin_) + ": Not an output pin";
        Serial.println(dbg);
    }
}

uint8_t Gpio::Read() const {
    uint8_t status = digitalRead(pin_);

    if(debug_) {
        String status_str = "";
        if(status == HIGH) {
            status_str = "HIGH";
        } else {
            status_str = "LOW";
        }

        String dbg = "Gpio: " + String(pin_) + ": " + status_str;
        Serial.println(dbg);
    }

    return status;
}

void Gpio::Toggle() const {
    uint8_t status = Read();

    if (status == HIGH) {
        Off();
    } else {
        On();
    }
}