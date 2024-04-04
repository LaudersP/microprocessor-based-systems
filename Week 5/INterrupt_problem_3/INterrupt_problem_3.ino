#include <IntervalTimer.h>

const unsigned int SPEAKER = 0;  // 330 HZ

unsigned int counter0 = 0;

bool state0 = false;

IntervalTimer timer;

void timerCallback() {
  counter0++;

  if(counter0 >= 1) {
    state0 = !state0;
    digitalWrite(SPEAKER, state0);
    counter0 = 0;
  }
}

void setup() {
  pinMode(SPEAKER, OUTPUT);

  timer.begin(timerCallback, 1515);
}

void loop() {

}