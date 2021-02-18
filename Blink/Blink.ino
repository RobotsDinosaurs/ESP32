/*
    Blink

    Blink the built-in LED in 1 second intervals (On/Off).
*/

// remove this line if using Arduino IDE
#include <Arduino.h>

void setup() {
    // initialize
    pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
    // turn the LED On
    digitalWrite(LED_BUILTIN, HIGH);
    // wait 1 second
    delay(1000);
    // turn the LED Off
    digitalWrite(LED_BUILTIN, LOW);
    // wait 1 second
    delay(1000);
}