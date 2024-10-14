
void both2Setup() {
  timeDifference = (millis() - previousMillis)*1000;
  previousMillis = millis();
  Serial.print("Button2 was pressed first by ");
  Serial.print(timeDifference);
  Serial.println(" microseconds.");
  state = 6;
}

void both2() {
  // Serial.println("both");
  if (digitalRead(b1) == LOW && digitalRead(b2) == LOW) {
    delay(1000);
    Serial.println("Please wait. System resetting...");
    delay(9000);
    Serial.println();
    waitingSetup();
  } else {
    if (millis() - previousMillis >= 10000) {
      reminderSetup();
    }
  }
}