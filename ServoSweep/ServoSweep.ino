/*
    Servo Sweep
    
    Sweeping the servo in two directions.
*/

// remove this line if using Arduino IDE
#include <Arduino.h>

#include <ESP32Servo.h>

int servoPin = 12;
int angle = 0;

Servo servo;

void setup() {
  servo.attach(servoPin);
}

void loop() {
  for (angle = 0; angle <= 180; angle += 5) { 
    servo.write(angle);
    delay(150);
  }
  
  for (angle = 180; angle >= 0; angle -= 5) { 
    servo.write(angle);
    delay(150);
  }
}