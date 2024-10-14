
void button1WaitingSetup() {
  // Serial.print("button1WaitingSetup");
  previousMillisWaiting = millis();
  state = 3;
}

void button1Waiting() {
  if ((millis() - previousMillis) >= 10000) {
    waitingSetup();
  } else {
    
    /*
    if (digitalRead(b1) == HIGH) {
      button1Setup();
    }
    */

    if (digitalRead(b2) == HIGH) {
      both1Setup();
    }

  }
}