const unsigned int switch0 = 14;
const unsigned int switch1 = 15;
const unsigned int switch2 = 16;
const unsigned int switch3 = 17;
const unsigned int motor = 28;

bool motorState = false;
unsigned int speed = 1;

#define DEBUG 1

#if DEBUG
#define print(x) Serial.print(x);
#define println(x) Serial.println(x);
#else
#define print(x)
#define println(x)
#endif

void setup() {
  Serial.begin(9600);
  pinMode(switch0, INPUT);
  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
}

void loop() {
  // Check if motor needs is to be turned on
  if(digitalRead(switch0))
    motorState = true;
  // Check if motor needs is to be turned off
  else if(digitalRead(switch1))
    motorState = false;
  // Check if motor speed is to be increased
  else if(digitalRead(switch2)) {
    // Check that speed hasnt been maxed
    if(speed < 5000)
      speed++;
  }
  // Check if motor speed is to be decreased
  else if(digitalRead(switch3)) {
    // Check that speed hasnt been limited
    if(speed > 0)
      speed--;
  }

  // Debug print statements
  print("Motor: ");
  print(motorState ? "ON" : "OFF");
  print(",   Speed: ");
  println(speed);
  
  // PWM mapping
  unsigned int PWM = map(speed, 0, 5000, 0, 255);
  analogWrite(motor, motorState ? speed : 0);
}