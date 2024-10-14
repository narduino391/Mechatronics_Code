
// Initiates to become parallel with wall 4

// Robot turns and moves forward
void wall4ForwardSetup() {
  platformSpinRight();
  Serial.println("4");  // Displays current wall (for debugging)
  delay(510);
  platformForward();
  startTime = millis();
  state = 9;
}

// Stops moving forward once robot hits next wall
void wall4Forward() {
  if (digitalRead(buttonPin) == HIGH) {
    platformStop();
    wall5BackSetup();
  }
}