int sw=2;
int Xpin=A1;
int Ypin=A0;
int swVal;
int Xval;
int Yval;
void setup() {
  pinMode(sw,INPUT_PULLUP);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  digitalWrite(sw,HIGH);
  Serial.begin(9600);
}

void loop() {
  swVal=digitalRead(sw);
    Serial.print("Switch: ");
    Serial.println(swVal);
  Xval=analogRead(Xpin);
    Serial.print("X: ");
    Serial.println(Xval);
  Yval=analogRead(Ypin);
    Serial.print("Y: ");
    Serial.println(Yval);

    delay(100);
}
