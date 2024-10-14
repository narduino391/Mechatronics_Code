
// Initiates to become parallel with wall 6

// Robot turns and moves forward
void wall6ForwardSetup() {
  Serial.println("6");  // Displays current wall (for debugging)
  platformSpinRight();
  delay(510);
  platformForward();
  startTime = millis();
  state = 13;
}

// Stops moving forward once robot hits next wall
void wall6Forward() {
  if (digitalRead(buttonPin) == HIGH) {
    platformStop();
    wall7BackSetup();
  }
}