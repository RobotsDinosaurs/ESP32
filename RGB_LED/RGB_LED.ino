/*
    RGB LED
    
    Fading colors of the spectrum on a single RGB LED. 
*/

// remove this line if using Arduino IDE
#include <Arduino.h>

// define channels 0-7
#define chBLUE 1
#define chGREEN 2
#define chRED 3

// define frequency 1220 - 312500
#define freq 12000

// define pin names
uint8_t ledR = 13;
uint8_t ledG = 12;
uint8_t ledB = 14;

void setup()
{
  // setup channel chBLUE with frequency freq
  sigmaDeltaSetup (chBLUE, freq);
  // attach pin ledB to channel chBLUE
  sigmaDeltaAttachPin(ledB, chBLUE);
  // initialize channel chBLUE to off
  sigmaDeltaWrite(chBLUE, 0);

  // setup channel chRED with frequency freq
  sigmaDeltaSetup (chRED, freq);
  // attach pin ledR to channel chRED
  sigmaDeltaAttachPin(ledR, chRED);
  // initialize channel chRED to ON
  sigmaDeltaWrite(chRED, 255);

   // setup channel chGREEN with frequency freq
  sigmaDeltaSetup (chGREEN, freq);
  // attach pin ledG to channel chGREEN
  sigmaDeltaAttachPin(ledG, chGREEN);
  // initialize channel chGREEN to off
  sigmaDeltaWrite(chGREEN, 0);
}

// define variables
int redValue;
int greenValue;
int blueValue;

// main loop
void loop()
{
  #define delayTime 20 // fading time between colors

  redValue = 255; // choose a value between 1 and 255 to change the color.
  greenValue = 0;
  blueValue = 0;

  for(int i = 0; i < 255; i += 1) // fades out red bring green full when i=255
  {
    redValue -= 1;
    greenValue += 1;
    sigmaDeltaWrite(chRED, redValue);
    sigmaDeltaWrite(chGREEN, greenValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 255;
  blueValue = 0;

  for(int i = 0; i < 255; i += 1) // fades out green bring blue full when i=255
  {
    greenValue -= 1;
    blueValue += 1;
    sigmaDeltaWrite(chGREEN, greenValue);
    sigmaDeltaWrite(chBLUE, blueValue);
    delay(delayTime);
  }

  redValue = 0;
  greenValue = 0;
  blueValue = 255;

  for(int i = 0; i < 255; i += 1) // fades out blue bring red full when i=255
  {
    // The following code has been rearranged to match the other two similar sections
    blueValue -= 1;
    redValue += 1;

    sigmaDeltaWrite(chBLUE, blueValue);
    sigmaDeltaWrite(chRED, redValue);
    delay(delayTime);
  }
}