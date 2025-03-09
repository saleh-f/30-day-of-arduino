#include <Wire.h>
#include "Adafruit_TCS34725.h"

// Initialize the TCS34725 sensor
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

// Define the pins for the RGB LED
const int redPin = 9;
const int greenPin = 10;
const int bluePin = 11;

void setup() {
  Serial.begin(9600);

  // Initialize the sensor
  if (tcs.begin()) {
    Serial.println("Found sensor");
  } else {
    Serial.println("No TCS34725 found ... check your connections");
    while (1);
  }

  // Set the RGB LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}

void loop() {
  uint16_t r, g, b, c;

  // Read the sensor values
  tcs.getRawData(&r, &g, &b, &c);

  // Print the values to the Serial Monitor
  Serial.print("Red: "); Serial.print(r, DEC); Serial.print(" ");
  Serial.print("Green: "); Serial.print(g, DEC); Serial.print(" ");
  Serial.print("Blue: "); Serial.print(b, DEC); Serial.print(" ");
  Serial.print("Clear: "); Serial.print(c, DEC); Serial.print(" ");
  Serial.println();

  // Map the sensor values to PWM values for the RGB LED
  int redValue = map(r, 0, 65535, 0, 255);
  int greenValue = map(g, 0, 65535, 0, 255);
  int blueValue = map(b, 0, 65535, 0, 255);

  // Set the RGB LED color
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);

  delay(100); // Wait for 100ms before the next reading
}