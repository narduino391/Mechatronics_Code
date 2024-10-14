
// Sets pin numbers
const int leftA = 2;      // Left Motor A pin
const int leftB = 3;      // Left Motor B pin
const int rightA = 6;     // Right Motor A pin
const int rightB = 7;     // Right Motor B pin
const int buttonPin = 9;  // Button Pin
const int buzzer = 11;    // Buzzer Pin

unsigned long startTime;  // Variable used for timing
long interval;  // Set variable to be used for turning

int state = 0;  // Initializes variable for storing the current state (Begins at 0)

void setup() {
  // Assigns pins for motors and button
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(buttonPin, INPUT);

  // Enables serial output for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // Calls functions based on state of run
  switch (state) {
    case 0:
      waiting();
      break;
    case 1:
      firstApproach();
      break;
    case 2:
      wall1Back();
      break;
    case 3:
      wall1Forward();
      break;
    case 4:
      wall2Back();
      break;
    case 5:
      wall2Forward();
      break;
    case 6:
      wall3Back();
      break;
    case 7:
      wall3Forward();
      break;
    case 8:
      wall4Back();
      break;
    case 9:
      wall4Forward();
      break;
    case 10:
      wall5Back();
      break;
    case 11:
      wall5Forward();
      break;
    case 12:
      wall6Back();
      break;
    case 13:
      wall6Forward();
      break;
    case 14:
      wall7Back();
      break;
    case 15:
      wall7Forward();
      break;
  }
}
