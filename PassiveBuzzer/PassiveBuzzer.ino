/*
    Passive Buzzer
    
    Plays a tune on a passive buzzer.
*/

// remove this line if using Arduino IDE
#include <Arduino.h>

int buzzerPin = 12;
 
int numTones = 8;
int tones[] = {523,    587, 659, 698, 784, 880, 988, 1047 };
//            Alto Do  Re    Mi   Fa   So  La   Si  Treble Do
 
// setting PWM properties
//channel 0-15, resolution 1-16bits, freq limits depend on resolution
const int freq = 5000;
const int chnl = 0;
const int res = 8;

void setup()
{
  // configure LED PWM functionalitites
  ledcSetup(chnl, freq, res);
  
  // attach the channel to the GPIO to be controlled
  ledcAttachPin(buzzerPin, chnl);
}
 
void loop()
{
  for (int i = 0; i < numTones; i++) 
  {
    // generates a square wave of the specified frequency on buzzerPin 
    ledcWriteTone(chnl, tones[i]);
    delay(500); // wait for 500 ms between subsequent sounds
  }
  delay(1000); // wait for 1 second before playing sounds backwards

  for (int j = numTones - 1; j >= 0; j--) 
  {
    // generates a square wave of the specified frequency on buzzerPin
     ledcWriteTone(chnl, tones[j]); 
     delay(500); // wait for 500 ms between subsequent sounds
  }
  delay(2000); // wait for 2 seconds before the next loop
}