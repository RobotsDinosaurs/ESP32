/*
    Servo with Pot
    
    Mapping the servo sweep to the potentiometer's movement. 
*/

// remove this line if using Arduino IDE
#include <Arduino.h>

#include <ESP32Servo.h>

int potPin = 34;
int servoPin = 12;
int angle = 0;

Servo servo;

void setup() {
  servo.attach(servoPin);
  Serial.begin(9600);
}

void loop() {
  // reading range: 0 to 4095 (ESP32 has a 12-bit analog to digital converter)
  int reading = analogRead(potPin);      
  
  angle = map(reading, 0, 4095, 0, 180);  // map 'reading' 
                                          // from current range 0-4095
                                          // to target range 0-180 degrees
  Serial.println(angle);

  servo.write(angle);
  delay(15);
}