
void button1Setup() {
  // Serial.println("Button1Setup");
  previousMillis = millis();
  state = 1;
}

void button1() {
  // Serial.println("button1");
  if (digitalRead(b1) == LOW) {
    button1WaitingSetup();
  } else {
    if (digitalRead(b2) == HIGH) {
      both1Setup();
    }
    if (millis() - previousMillis >= 10000) {
      Serial.println(">10000");
      reminderSetup();
    }
  }
}