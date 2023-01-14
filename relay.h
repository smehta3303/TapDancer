#ifndef INCLUDE_RELAY_H_
#define INCLUDE_RELAY_H_

class Relay {
  public:
    Relay(const uint8_t pin, const bool log=false)
    : pin_(pin),
      log_(log) {}

    void Initialize() const;
    void On() const;
    void Off() const;
    
  private:
    const uint8_t pin_;
    const bool log_;

};

#endif  //INCLUDE_RELAY_H_