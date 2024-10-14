
// Initiates to become parallel with wall 1

// Robot turns and moves forward
void wall1ForwardSetup() {
  Serial.println("1");  // Displays current wall (for debugging)
  platformSpinLeft();
  delay(510);
  platformForward();
  startTime = millis();
  state = 3;
}

// Stops moving forward once robot hits next wall
void wall1Forward() {
  if (digitalRead(buttonPin) == HIGH) {
    platformStop();
    // Beeps once
    tone(buzzer,600,1500);
    delay(1500);
    wall2BackSetup();
  }
}