
// Initiates to become parallel with wall 2

// Robot turns and moves forward
void wall2ApproachSetup() {
  // Serial print for debugging purposes
  Serial.println("second approach");
  // Turns toward and moves to deposit wall
  platformForward();
  delay(500);
  platformSpinLeft();
  delay(600);
  platformBackward();
  delay(2000);
  platformForward();
  startTime = millis();
  // Advances state
  state = 5;
}

// Stops moving forward once robot hits next wall
void wall2Approach() {
  // Stops robot when it hits deposit wall
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("hit second");
    tone(buzzer, 500, 1000);
    platformStop();
    delay(1500);
    wall2ReleaseSetup();
  }
}