
// Initiates after starting button press

// Robot begins to move towards first wall
void firstApproachSetup() {
  Serial.println("Forward");
  platformForward();
  startTime = millis();
  state = 1;
}

// Stops moving forward once robot hits wall
void firstApproach() {
  if (digitalRead(buttonPin) == HIGH) {
    platformStop();
    wall1BackSetup();
  }
}