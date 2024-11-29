int ReadPin=A0;
int valueRead;


void setup() {
  Serial.begin(9600);
}

void loop() {
  valueRead=analogRead(ReadPin);
  Serial.print("moisture value is: ");
  Serial.println(valueRead);
  
  delay(100);
}
