
// Initiates right after hitting wall 1

// Robot turns left to become parallel with wall
void wall1BackSetup() {
  Serial.println("back");
  platformBackward();
  startTime = millis();
  interval = 700;
  state = 2;
}

// Stops turning when straight
void wall1Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(500);
    wall1ForwardSetup();
  }
}