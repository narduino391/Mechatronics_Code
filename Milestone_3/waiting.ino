
// To be run on start-up
// Initiates movement states upon button press

void waiting() {
  Serial.println("waiting");
  if (digitalRead(buttonPin) == HIGH) {
    tone(buzzer, 200, 1000);
    delay(500);
    firstApproachSetup();
  }
}