
void button2WaitingSetup() {
  // Serial.print("button2WaitingSetup");
  previousMillisWaiting = millis();
  state = 4;
}

void button2Waiting() {
  if ((millis() - previousMillis) >= 10000) {
    waitingSetup();
  } else {
    
    /*
    if (digitalRead(b2) == HIGH) {
      button2Setup();
    }
    */

    if (digitalRead(b1) == HIGH) {
      both2Setup();
    }

  }
}