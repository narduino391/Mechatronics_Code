void pendingSetup() {
  state = pending;
}

void pendingLoop() {
  bool done = false;
  //  Plays tunes
  if (tunePlaying == 1) {
    done = playTune1();
  }
  if (tunePlaying == 2) {
    done = playTune2();
  }

  if (done) {
    tunePlaying = tunePending; //Transitions to queued song
    tunePending = 0; //Resets queue

    // Two beeps before queued song
    tone(tonePin,1319,250);
    delay(500);
    tone(tonePin,1319,250);
    delay(500);
    playingSetup(); //Begins playing
  }
}