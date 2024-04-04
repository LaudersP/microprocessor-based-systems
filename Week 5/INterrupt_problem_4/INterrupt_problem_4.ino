#include <IntervalTimer.h>

const unsigned int SPEAKER = 0;

const int notes[] = {262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494};   // Desired Hz's
int noteIndex = 0;
bool noteState = true;

IntervalTimer timer;

void timerCallback() {
  static unsigned long noteDuration = 0;
  static const unsigned long notePlayTime = 2000;
  static const unsigned long pauseTime = 1000;

  if(noteState) {
    if(noteDuration < notePlayTime) {
      if(noteDuration == 0)
        tone(SPEAKER, notes[noteIndex]);
      
      noteDuration++;
    } else {
      noTone(SPEAKER);
      noteDuration = 0;
      noteState = false;
    }
  } else {
    if(noteDuration < pauseTime) {
      noteDuration++;
    } else {
      noteDuration = 0;
      noteState = true;
      noteIndex = (noteIndex + 1) % 12;
    }
  }
}

void setup() {
  pinMode(SPEAKER, OUTPUT);

  timer.begin(timerCallback, 500);
}

void loop() {

}