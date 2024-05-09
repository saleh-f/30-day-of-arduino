int red=9;
int blue=10;
int green=11;
String opt;
void setup() {
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);
Serial.begin(9600);
}

void loop() {
  while(Serial.available()>1){
Serial.println("enter which LED you want to turn on  red  blue  green  none");
opt=Serial.readStringUntil('\n');

if(opt.equalsIgnoreCase("red")){
  analogWrite(red,255);
  analogWrite(blue,0);
  analogWrite(green,0);
}
if(opt.equalsIgnoreCase("blue")){
  analogWrite(red,0);
  analogWrite(blue,255);
  analogWrite(green,0);
}
if(opt.equalsIgnoreCase("green")){
  analogWrite(red,0);
  analogWrite(blue,0);
  analogWrite(green,255);
}
if(opt.equalsIgnoreCase("none")){
  analogWrite(red,0);
  analogWrite(blue,0);
  analogWrite(green,0);
}
  }
}
