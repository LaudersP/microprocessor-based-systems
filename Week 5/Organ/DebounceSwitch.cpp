#include "DebounceSwitch.hpp"

// Constructor
DebounceSwitch::DebounceSwitch(const unsigned int pin) : _pin(pin) {
  _debounceInterval = 20;
  _lastDebounceTime = 0;
  _lastButtonState = 0x0;
  _buttonState = 0x0;
  _liftFlag = 0x0;
}

// Method to intitialize the class
void DebounceSwitch::begin() {
  pinMode(_pin, 0x0);
}

// Method to read the switch and cancel the debug
bool DebounceSwitch::read() {
  bool current = digitalRead(_pin);

  if(current != _lastButtonState) {
    _lastDebounceTime = millis();
  }

  if((millis() - _lastDebounceTime) > _debounceInterval) {
    if(current != _buttonState) {
      _buttonState = current;

      if(_buttonState == 0x0) {
        _lastButtonState = current;

        return true;
      }
    }
  }

  _lastButtonState = current;

  return false;
}