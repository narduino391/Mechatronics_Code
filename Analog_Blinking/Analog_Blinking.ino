/*
  Analog Input

  Demonstrates analog input by reading an analog sensor on analog pin 0 and
  turning on and off a light emitting diode(LED) connected to digital pin 13.
  The amount of time the LED will be on and off depends on the value obtained
  by analogRead().

  - potentiometer
    center pin of the potentiometer to the analog input 0
    one side pin (either one) to ground
    the other side pin to +5V
*/

int sensorPin = A0;   // select the input pin for the potentiometer
int ledPin = 13;      // select the pin for the LED
int sensorValue = 0;  // variable to store the value coming from the sensor
unsigned long previousMillis = 0;

void setup() {
  // declare the ledPin as an OUTPUT:
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}

void loop() {
  // read the value from the sensor:
  sensorValue = analogRead(sensorPin);
  int mapValue = map(sensorValue, 0, 1023, 0, 4);
  if (mapValue == 1 || mapValue == 3 || mapValue == 4) {
    if (millis() - previousMillis >= 500) {
      previousMillis = millis();
      if (digitalRead(ledPin) == HIGH) {
        digitalWrite(ledPin, LOW);
      } else {
        digitalWrite(ledPin, HIGH);
      }
    }
  } else {
    if (mapValue == 0) {
      digitalWrite(ledPin, HIGH);
    }
    if (mapValue == 2) {
      digitalWrite(ledPin, LOW);
    }
    previousMillis = millis();
  }

  //analogWrite(sensorValue, mapValue);
  Serial.print("Analog: ");
  Serial.print(sensorValue);
  Serial.print("      Map: ");
  Serial.println(mapValue);
}
