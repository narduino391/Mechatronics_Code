// Nathan Arduino
// Individual Programming Assigment #2

// Sets variables for pin numbers
int b1 = 6;
int b2 = 5;
unsigned long previousMillis;
unsigned long previousMillisWaiting;
unsigned long timeDifference;
int state;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  // Sets input pins
  pinMode(b1, INPUT);
  pinMode(b2, INPUT);
  // Sets variables for storing previous button values
  waitingSetup();
}

void loop() {
  switch (state) {
    case 0:
    waiting();
      break;
    case 1:
      button1();
      break;
    case 2:
      button2();
      break;
    case 3:
      button1Waiting();
      break;
    case 4:
      button2Waiting();
      break;
    case 5:
      both1();
      break;
    case 6:
      both2();
      break;
    case 7:
      reminder();
      break;

  }
}