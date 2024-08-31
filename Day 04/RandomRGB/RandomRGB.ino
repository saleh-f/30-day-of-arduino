int red=9;
int green=11;
int blue=10;
String  opt;
int randR;
int randG;
int randB;
void setup() {
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);
Serial.begin(9600);
randomSeed(analogRead(0));
}
void loop() {
  randR=random(20,255);
  randG=random(20,255);
  randB=random(20,255);
  analogWrite(red,randR);
  analogWrite(green,randG);
  analogWrite(blue,randB);

  delay(1200);


}
