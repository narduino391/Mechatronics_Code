
// Initiates right after hitting wall 5

// Robot turns right to become parallel with wall
void wall5BackSetup() {
  Serial.println("back");
  platformBackward();
  startTime = millis();
  interval = 700;
  state = 10;
}

// Stops turning when straight
void wall5Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(500);
    wall5ForwardSetup();
  }
}