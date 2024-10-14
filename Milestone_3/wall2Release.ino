
// Initiates right after hitting wall 3

// Robot turns left to become parallel with wall
void wall2ReleaseSetup() {
  // Serial print for debugging purposes
  Serial.println("second backup");
  // Turns away from deposit wall
  platformBackward();
  delay(700);
  platformStop();
  delay(500);
  platformSpinRight();
  delay(1100);
  startTime = millis();
  state = 6;
}

// Stops turning when straight
void wall2Release() {
  // Serial print for debugging purposes
  Serial.println("release");
  // Backs into wall
  platformBackward();
  delay(2000);
  platformStop();
  delay(500);
  // Swings backet arm from 140 to 180 to deposit disks
  for (posB = 140; posB <= 180; posB += 1) {  // goes from 0 degrees to 30 degrees
    // in steps of 1 degree
    myServoB.write(posB);  // tell servo to go to position in variable 'pos'
    delay(5);              // waits 50 ms for the servo to reach the position
  }
  // Returns basket arm to starting position
  delay(2000);
  myServoB.write(140);
  delay(3000);
  // Resets to starting state
  state = 0;
}