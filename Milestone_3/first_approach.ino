
// Robot begins to move towards first wall
void firstApproachSetup() {
  Serial.println("first approach");
  delay(1500);
  Serial.println("Forward");
  platformForward();
  state = 1;
}

// Stops moving forward once robot hits wall
void firstApproach() {
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("hit wall");
    tone(buzzer, 300, 1000);
    platformStop();
    delay(1500);
    wall1BackSetup();
  }
}