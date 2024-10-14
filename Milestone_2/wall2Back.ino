
// Initiates right after hitting wall 2

// Robot turns left to become parallel with wall
void wall2BackSetup() {
  Serial.println("back");
  platformBackward();
  startTime = millis();
  interval = 700;
  state = 4;
}

// Stops turning when straight
void wall2Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(500);
    wall2ForwardSetup();
  }
}