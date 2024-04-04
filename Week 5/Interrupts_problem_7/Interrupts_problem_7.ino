#include "DebounceSwitch.hpp"

#define DEBUG 1

#if DEBUG
#define print(x) Serial.print(x)
#define println(x) Serial.println(x)
#else
#define print(x)
#define println(x)
#endif

DebounceSwitch switch0(14);
DebounceSwitch switch1(15);

unsigned int count = 0;
const int LED = 0;
const unsigned int SPEAKER = 0;

void setup() {
  switch0.begin();
  switch1.begin();
  Serial.begin(9600);
}

void loop() {
  if(switch0.read()) {
    count++;
    print("Count: ");
    println(count);
  }
    

  if(switch1.read()) {
    for(unsigned int i = 0; i < count; i++) {
      tone(SPEAKER, 494);
      delay(250);
      noTone(SPEAKER);
      delay(250);
    }

    count = 0;
  }
}