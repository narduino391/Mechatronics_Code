
// Backs away from wall
void wall1BackSetup() {
  Serial.println("first back");
  platformBackward();
  startTime = millis();
  interval = 550;
  state = 2;
}

// Turns toward block
void wall1Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(1000);
    platformSpinLeft();
    delay(550);
    platformStop();
    delay(1000);
    platformBackward();
    delay(1000);
    platformStop();
    delay(1000);
    blockApproachSetup();
  }
}