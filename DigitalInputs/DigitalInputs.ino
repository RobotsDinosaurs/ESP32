/*
    Digital Inputs
    
    Setting two push buttons as On/Off switches for an LED.
*/

// remove this line if using Arduino IDE
#include <Arduino.h>

int ledPin = 14;
int buttonONpin = 12;
int buttonOFFpin = 13;

void setup() 
{
  pinMode(ledPin, OUTPUT);
  
  //the default value for the input_pullup is HIGH
  //unless pulled LOW by the action of pressing button
  pinMode(buttonONpin, INPUT_PULLUP);  
  pinMode(buttonOFFpin, INPUT_PULLUP);  
}
 
void loop() 
{
  // pressed the ON button
  if (digitalRead(buttonONpin) == LOW)
  {
    digitalWrite(ledPin, HIGH);
  }
  // pressed the OFF button
  if (digitalRead(buttonOFFpin) == LOW)
  {
    digitalWrite(ledPin, LOW);
  }
}