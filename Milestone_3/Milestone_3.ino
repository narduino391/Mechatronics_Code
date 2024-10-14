// Author: Nick Savino
// Date Created: 9/29
// Last Modified: 10/3

#include <Servo.h>

// Creates Servo objects for each servo used
Servo myServoA;
Servo myServoB;

// Sets pin numbers
const int leftA = 2;      // Left Motor A pin
const int leftB = 3;      // Left Motor B pin
const int rightA = 6;     // Right Motor A pin
const int rightB = 7;     // Right Motor B pin
const int buttonPin = 9;  // Button Pin
const int buzzer = 5;     // Buzzer Pin
const int servoA = 10;    // Push arm servo
const int servoB = 11;    // Basket arm servo

unsigned long startTime;  // Variable used for timing
long interval;            // Set variable to be used for turning
int posA = 180;           // Variable for push arm position
int posB = 140;            // Variable for basket arm position
int state = 0;            // Initializes variable for storing the current state (Begins at 0)

void setup() {
  // Assigns inputs and outputs
  pinMode(leftA, OUTPUT);
  pinMode(leftB, OUTPUT);
  pinMode(rightA, OUTPUT);
  pinMode(rightB, OUTPUT);
  pinMode(buttonPin, INPUT);

  myServoA.attach(servoA);
  myServoB.attach(servoB);
  myServoA.write(posA);  // Sets starting position for push arm
  myServoB.write(posB);  // tell servo to go to position in variable 'pos'

  // Enables serial output for debugging purposes
  Serial.begin(9600);
}

void loop() {
  // Calls functions based on state of run
  switch (state) {
    case 0:
      waiting();
      break;
    case 1:
      firstApproach();
      break;
    case 2:
      wall1Back();
      break;
    case 3:
      blockApproach();
      break;
    case 4:
      blockBack();
      break;
    case 5:
      wall2Approach();
      break;
    case 6:
      wall2Release();
      break;
  }
}


// Defines motor functions for various movements

void platformForward()
{
  leftForward();
  rightForward();
}
void platformBackward()
{
  leftBackward();
  rightBackward();
}
void platformStop()
{
  leftStop();
  rightStop();
}
void platformSpinLeft()
{
  leftBackward();
  rightForward();
}
void platformSpinRight()
{
  rightBackward();
  leftForward();
}
//left
void leftForward()
{
      digitalWrite(leftA, HIGH);
      digitalWrite(leftB, LOW); 
}
void leftBackward()
{
      digitalWrite(leftA, LOW);
      digitalWrite(leftB, HIGH); 
}

void leftStop()
{
      digitalWrite(leftA, LOW);
      digitalWrite(leftB, LOW); 
}
//right
void rightForward()
{
      digitalWrite(rightA, HIGH);
      digitalWrite(rightB, LOW); 
}
void rightBackward()
{
      digitalWrite(rightA, LOW);
      digitalWrite(rightB, HIGH); 
}

void rightStop()
{
      digitalWrite(rightA, LOW);
      digitalWrite(rightB, LOW); 
}


// To be run on start-up
// Initiates movement states upon button press

void waiting() {
  Serial.println("waiting");
  if (digitalRead(buttonPin) == HIGH) {
    tone(buzzer, 200, 1000);
    delay(500);
    firstApproachSetup();
  }
}


// Robot begins to move towards first wall
void firstApproachSetup() {
  Serial.println("first approach");
  delay(1500);
  Serial.println("Forward");
  platformForward();
  state = 1;
}

// Stops moving forward once robot hits wall
void firstApproach() {
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("hit wall");
    tone(buzzer, 300, 1000);
    platformStop();
    delay(1500);
    wall1BackSetup();
  }
}


// Backs away from wall
void wall1BackSetup() {
  Serial.println("first back");
  platformBackward();
  startTime = millis();
  interval = 550;
  state = 2;
}

// Turns toward block
void wall1Back() {
  if ((millis() - startTime) > interval) {
    platformStop();
    delay(1000);
    platformSpinLeft();
    delay(550);
    platformStop();
    delay(1000);
    platformBackward();
    delay(1000);
    platformStop();
    delay(1000);
    blockApproachSetup();
  }
}


// Moves toward block
void blockApproachSetup() {
  Serial.println("block approach");
  platformForward();
  startTime = millis();
  state = 3;
}

// Stops when robot hits block
void blockApproach() {
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("hit block");
    tone(buzzer, 400, 1000);
    platformStop();
    // Beeps once
    delay(1500);
    blockBackSetup();
  }
}


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


// Robot turns and moves forward
void wall2ApproachSetup() {
  // Serial print for debugging purposes
  Serial.println("second approach");
  // Turns toward and moves to deposit wall
  platformForward();
  delay(500);
  platformSpinLeft();
  delay(600);
  platformBackward();
  delay(2000);
  platformForward();
  startTime = millis();
  // Advances state
  state = 5;
}

// Stops moving forward once robot hits next wall
void wall2Approach() {
  // Stops robot when it hits deposit wall
  if (digitalRead(buttonPin) == HIGH) {
    Serial.println("hit second");
    tone(buzzer, 500, 1000);
    platformStop();
    delay(1500);
    wall2ReleaseSetup();
  }
}


// Initiates after hitting base wall
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
  for (posB = 140; posB <= 180; posB += 1) {
    // in steps of 1 degree
    myServoB.write(posB);
    delay(5);
  }
  // Returns basket arm to starting position
  delay(2000);
  myServoB.write(140);
  delay(3000);
  // Resets to starting state
  state = 0;
}