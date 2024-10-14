
// Moves toward block
void blockApproachSetup() {
  Serial.println("block approach");
  platformForward();
  startTime = millis();
  state = 3;
}

// Stops when robot hits block
void blockApproach() {
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("hit block");
    tone(buzzer, 400, 1000);
    platformStop();
    // Beeps once
    delay(1500);
    blockBackSetup();
  }
}