
// Initiates right after hitting wall 7

// Robot turns right to become parallel with wall
void wall7BackSetup() {
  platformBackward();
  Serial.println("spin back");
  startTime = millis();
  interval = 700;
  state = 14;
}

// Stops turning when straight
void wall7Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(500);
    wall7ForwardSetup();
  }
}