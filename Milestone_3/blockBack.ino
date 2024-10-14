
// Initiates right after hitting block

// 
void blockBackSetup() {
  // Serial print for debugging purposes
  Serial.println("arm swing");
  // Sets positions of both servos for disk collection
  myServoB.write(80);
  delay(1000);
  myServoA.write(45);
  delay(1000);
  // Swings push arm from 45 to 10
  for (posA = 45; posA >= 10; posA -= 1) {
    myServoA.write(posA);
    delay(10);
  }
  // Sets push arm back to starting position
  delay(500);
  myServoA.write(180);
  // Swings basket arm from 80 back to 140
  for (posB = 80; posB <= 140; posB += 1) {
    myServoB.write(posB);
    delay(20);
  }
  // Advances to next state
  delay(3000);
  state = 4;
}

void blockBack() {
  // Begins backing up from block
  Serial.println("block backup");
  platformBackward();
  delay(4000);
  platformStop();
  delay(500);
  wall2ApproachSetup();
}