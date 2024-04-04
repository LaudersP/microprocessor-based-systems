const unsigned int SPEAKER = 0;

const unsigned int switch0 = 14;
const unsigned int switch1 = 15;
const unsigned int switch2 = 16;
const unsigned int switch3 = 17;

const unsigned int noteFreq[] = {262, 294, 330, 349};

const unsigned long debounceDelay = 20;
unsigned long lastDebounceTime = 0;

void setup() {
  pinMode(SPEAKER, OUTPUT);

  pinMode(switch0, INPUT);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
}

void loop() {
  const long currentTime = millis();

  if(currentTime - lastDebounceTime > debounceDelay) {
    if(digitalRead(switch0) == HIGH) {
      tone(SPEAKER, noteFreq[0]);
      lastDebounceTime = currentTime;
    }
    else if(digitalRead(switch1) == HIGH) {
      tone(SPEAKER, noteFreq[1]);
      lastDebounceTime = currentTime;
    }
    else if(digitalRead(switch2) == HIGH) {
      tone(SPEAKER, noteFreq[2]);
      lastDebounceTime = currentTime;
    }
    else if(digitalRead(switch3) == HIGH) {
      tone(SPEAKER, noteFreq[3]);
      lastDebounceTime = currentTime;
    }
    else {
      noTone(SPEAKER);
    }
  }
}