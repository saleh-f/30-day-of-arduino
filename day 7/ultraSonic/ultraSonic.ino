int trig=4;
int echo=3;
int alert=2;
int PTT;
void setup() {
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  pinMode(alert,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  PTT=pulseIn(echo,HIGH)* 0.034 / 2;
  Serial.print("distance is: ");
  Serial.print(PTT);
  Serial.println(" cm");
  if(PTT<7)digitalWrite(alert,HIGH);
  else digitalWrite(alert,LOW);
  delay(100);



}
