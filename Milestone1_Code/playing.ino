void playingSetup() {
  tuneStartTime = millis();
  state = playing;
}

void playingLoop() {
  bool done = false;
  unsigned long currentTime = millis();
  // Check buttons
  // Delays button check to avoid accidental double press
  if ((currentTime - tuneStartTime) > 500) {
    if (digitalRead(buttonPin1) == HIGH) {
      tunePending = 1;
      pendingSetup();
    }
    if (digitalRead(buttonPin2) == HIGH) {
      tunePending = 2;
      pendingSetup();
    }
  }
  // Plays current tune
  if (tunePlaying == 1) {
    done = playTune1();
  }
  if (tunePlaying == 2) {
    done = playTune2();
  }
  if (done) {
    if (tunePending == 0) {
      waitingSetup();
    } else {
      tunePlaying = tunePending;
      tunePending = 0;
      playingSetup;
    }
  }
}