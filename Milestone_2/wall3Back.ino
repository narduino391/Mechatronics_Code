
// Initiates right after hitting wall 3

// Robot turns left to become parallel with wall
void wall3BackSetup() {
  Serial.println("back");
  platformBackward();
  startTime = millis();
  interval = 700;
  state = 6;
}

// Stops turning when straight
void wall3Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(500);
    wall3ForwardSetup();
  }
}