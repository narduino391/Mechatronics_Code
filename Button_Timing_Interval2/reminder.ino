
void reminderSetup() {
  // Serial.print("reminderSetup");
  state = 7;
  previousMillis = millis();
}

void reminder() {
  // Serial.println("reminder");
  if (digitalRead(b1) == LOW && digitalRead(b2) == LOW) {
    delay(1000);
    Serial.println("Please wait. System resetting...");
    delay(9000);
    Serial.println();
    waitingSetup();
  } else {
    if (millis() - previousMillis >= 3000) {
      Serial.println ("Please let go of both buttons.");
      previousMillis = millis();
    }
  }
}