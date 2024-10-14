
// Initiates right after hitting wall 6

// Robot turns right to become parallel with wall
void wall6BackSetup() {
  platformBackward();
  startTime = millis();
  interval = 700;
  state = 12;
}

// Stops turning when straight
void wall6Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(500);
    wall6ForwardSetup();
  }
}