void waitingSetup() {
  tunePending = 0;
  tunePlaying = 0;
  state = waiting;
}

void waitingLoop(){
  delay(2);
  // Checks for button input
  if(digitalRead(buttonPin1) == HIGH){
    tunePlaying = 1;
    playingSetup();
  }
  if(digitalRead(buttonPin2) == HIGH){
    tunePlaying = 2;
    playingSetup();
  }
}