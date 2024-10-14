
// Initiates to become parallel with wall 2

// Robot turns and moves forward
void wall2ForwardSetup() {
  platformSpinLeft();
  Serial.println("2");  // Displays current wall (for debugging)
  delay(510);
  platformForward();
  startTime = millis();
  state = 5;
}

// Stops moving forward once robot hits next wall
void wall2Forward() {
  if (digitalRead(buttonPin) == HIGH) {
    platformStop();
    wall3BackSetup();
  }
}