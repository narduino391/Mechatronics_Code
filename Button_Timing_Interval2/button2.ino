
void button2Setup() {
  // Serial.println("Button2Setup");
  previousMillis = millis();
  state = 2;
}

void button2() {
  // Serial.println("button2");
  if (digitalRead(b2) == LOW) {
    button2WaitingSetup();
  } else {
    if (digitalRead(b1) == HIGH) {
      both2Setup();
    }
    if (millis() - previousMillis >= 10000) {
      Serial.println(">10000");
      reminderSetup();
    }
  }
}