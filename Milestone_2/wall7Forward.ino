
// Initiates to become parallel with wall 7

// Robot turns and moves forward
void wall7ForwardSetup() {
  platformSpinRight();
  Serial.println("7");  // Displays current wall (for debugging)
  delay(510);
  platformForward();
  startTime = millis();
  state = 15;
}

// Stops moving forward once robot hits wall
void wall7Forward() {
  if (digitalRead(buttonPin) == HIGH) {
    platformStop();
    delay(500);
    // Turns towards finish
    leftBackward();
    delay(1000);
    // Pulls back into starting square
    platformForward();
    delay(1000);
    platformStop();
    // Beeps three times
    for (int i = 0; i <= 2; i++) {
      tone(buzzer, 600, 1000);
      delay(1500);
    }
    // Resets to starting state
    state = 0;
  }
}