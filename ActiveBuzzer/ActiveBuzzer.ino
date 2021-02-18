/*
    Active Buzzer
    
    Sets the buzzer On/Off for a defined time interval.
*/

// remove this line if using Arduino IDE
#include <Arduino.h>

int buzzerPin = 12; 

void setup() {
  pinMode(buzzerPin, OUTPUT);  // sets the digital pin 12 as output
}
 
void loop() { 
   digitalWrite(buzzerPin, HIGH); // sets the digital pin 12 on
   delay(3000); // waits for 3 seconds

   digitalWrite(buzzerPin, LOW); // sets the digital pin 12 off
   delay(1000); // waits for a second
}