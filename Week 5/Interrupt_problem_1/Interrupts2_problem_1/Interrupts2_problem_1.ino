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
      digitalWrite(LED, 0x1);
      delay(250);
      digitalWrite(LED, 0x0);
      delay(250);
    }
  }
}