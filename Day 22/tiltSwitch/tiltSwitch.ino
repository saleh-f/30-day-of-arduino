int swPin=12; //  pin  used to  read the value of tilt switch
int LedBuz=4; // pin used for the LED and Buzzer 
int tiltState;// used to store the value recived by pin 12
void setup() {
pinMode(swPin,INPUT);
pinMode(LedBuz,OUTPUT);  

}

void loop() {
     tiltState = digitalRead(swPin);
  if (tiltState == HIGH) {
    Serial.println("Tilt detected!");
    digitalWrite(LedBuz,HIGH);
  } else {
    Serial.println("No tilt.");
    digitalWrite(LedBuz, LOW);
  }
  delay(50); // Delay for stability

}
