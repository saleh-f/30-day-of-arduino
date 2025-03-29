const int knockPin = A0;  // Piezo sensor connected to A0
const int ledPin = 13;    // LED on pin 13
int threshold = 100;      // Adjust based on sensitivity
int sensorValue;
void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  sensorValue = analogRead(knockPin);
  Serial.println(sensorValue);  // Monitor sensor readings

  if (sensorValue > threshold) {
    digitalWrite(ledPin, HIGH); // Turn LED on if knock detected
    delay(200);                 // Debounce
    digitalWrite(ledPin, LOW);  // Turn LED off
  }
}

