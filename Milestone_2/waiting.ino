
// To be run on start-up
// Initiates movement states upon button press

void waiting() {
  if (digitalRead(buttonPin) == HIGH) {
    firstApproachSetup();
    delay(500);
  }
}