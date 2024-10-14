
// Initiates to become parallel with wall 3

// Robot turns and moves forward
void wall3ForwardSetup() {
  Serial.println("3");  // Displays current wall (for debugging)
  platformSpinLeft();
  delay(510);
  platformForward();
  startTime = millis();
  state = 7;
}

// Stops moving forward once robot hits next wall
void wall3Forward() {
  if (digitalRead(buttonPin) == HIGH) {
    platformStop();
    wall4BackSetup();
  }
}