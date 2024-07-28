int read;
int sensorPin=A0;
int green=8;
int yellow=9;
int red=10;
void setup() {
  pinMode(green,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(red,OUTPUT);
  Serial.begin(9600);

}

void loop() {
 read=analogRead(sensorPin);
 Serial.println(read);
  if(read<10){
  digitalWrite(green,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
 }
 if(read>15&&read<90){
  digitalWrite(green,HIGH);
  digitalWrite(yellow,LOW);
  digitalWrite(red,LOW);
 }
   if(read>90&&read<170){
  digitalWrite(green,LOW);
  digitalWrite(yellow,HIGH);
  digitalWrite(red,LOW);
 }
   if(read>170){
  digitalWrite(green,LOW);
  digitalWrite(yellow,LOW);
  digitalWrite(red,HIGH);
 }
 delay(200);
}
