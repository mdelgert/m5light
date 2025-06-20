#include "M5Atom.h"
#include <Arduino.h>

void setup() {
    M5.begin(true, false, true); // Serial, I2C, Display (LED)
    delay(50);                  // Small delay to stabilize
    M5.dis.clear();             // Clear the LED
    pinMode(26, INPUT);         // Set pin 26 as input mode.
}

void loop() {
    M5.dis.fillpix(0x00FF00); // Set LED to green (RGB: 0xRRGGBB)
    delay(500);               // Wait 500ms
    M5.dis.clear();           // Turn off LED
    delay(500);               // Wait 500ms
    //Serial.println("Blinking LED");

    static uint16_t digitalRead_value = 0, analogRead_value = 0;
    analogRead_value = analogRead(32);    // Store the analog quantity read from
    digitalRead_value = digitalRead(26);  // Store the number read from pin 26.

    // Print the values to the serial monitor
    Serial.print("Analog Read Value: ");
    Serial.print(analogRead_value);
    Serial.print(" | Digital Read Value: ");
    Serial.println(digitalRead_value);
    delay(1000); // Wait 1 second before the next loop iteration
    M5.update(); // Update M5Stack state

}
