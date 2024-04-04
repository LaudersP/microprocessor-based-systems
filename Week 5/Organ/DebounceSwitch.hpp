#ifndef DEBOUNCE_SWITCH_HPP
#define DEBOUNCE_SWITCH_HPP

#include <Arduino.h>

class DebounceSwitch {
  private:
    unsigned int _pin;
    unsigned long _lastDebounceTime;
    unsigned long _debounceInterval;
    bool _lastButtonState;
    bool _buttonState;
    bool _liftFlag;

  public:
    DebounceSwitch(const unsigned int pin);
    void begin();
    bool read();
};

#endif