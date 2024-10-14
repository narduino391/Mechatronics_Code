// Set pins for buttons and buzzer
const int buttonPin1 = 2;  // the number of the first pushbutton pin
const int buttonPin2 = 3;  // the number of the second pushbutton pin
const int tonePin = 8;     // the number of the buzzer

// Variables
int tunePending;
int tunePlaying;
unsigned long tuneStartTime;

enum states {waiting, playing, pending};
enum states state;

void setup() {
  // initialize the buzzer as output:
  pinMode(tonePin, OUTPUT);
  // initialize the pushbutton pins as inputs:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);

  waitingSetup();
}

void loop() {

  switch (state) {
    case waiting:
      waitingLoop();
      break;
    case playing:
      playingLoop();
      break;
    case pending:
      pendingLoop();
      break;
  }
}
