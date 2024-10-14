
void waitingSetup() {
  // Serial.println("waitingSetup");
  Serial.println("Please press both buttons.");
  state = 0;
}

void waiting() {
  previousMillis = millis();
  if (digitalRead(b1) == HIGH) {
    // Serial.println("B1 Pressed");
    button1Setup();
  }
  if (digitalRead(b2) == HIGH) {
    // Serial.println("B2 Pressed");
    button2Setup();
  }
}