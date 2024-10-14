
// Initiates to become parallel with wall 5

// Robot turns and backs into back wall before moving forward
void wall5ForwardSetup() {
  platformSpinRight();
  Serial.println("5");  // Displays current wall (for debugging)
  delay(510);
  platformBackward();
  delay(2000);
  platformStop();
  delay(500);
  platformForward();
  startTime = millis();
  state = 11;
}

// Stops moving forward once robot hits next wall
void wall5Forward() {
  if (digitalRead(buttonPin) == HIGH) {
    platformStop();
    // Beeps twice
    for (int i = 0; i <= 1; i++) {
      tone(buzzer, 600, 1000);
      delay(1500);
    }
    wall6BackSetup();
  }
}