int waterSensorAnalogPin = A0; // Analog output from the sensor
int analogValue; // to store the value of analog output

void setup() {
  Serial.begin(9600);
}

void loop() {
   analogValue = digitalRead(waterSensorAnalogPin); // Read the water level
  // Print values to the Serial Monitor
  Serial.print("(Water Level): ");
  Serial.println(analogValue);

  delay(300); // Wait 0.2 second before next reading
}

