
// Initiates right after hitting wall 4

// Robot turns left to become parallel with wall
void wall4BackSetup() {
    Serial.println("back");

  platformBackward();
  startTime = millis();
  interval = 700;
  state = 8;
}

// Stops turning when straight
void wall4Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(500);
    wall4ForwardSetup();
  }
}