int red=9;
int blue=10;
int green=11;
String  opt;
void setup() {
pinMode(red,OUTPUT);
pinMode(blue,OUTPUT);
pinMode(green,OUTPUT);
Serial.begin(9600);
}

void loop() {
  while(Serial.available()>0){
Serial.println("enter which LED you want to turn on 1)red 2)blue 3)green 4)none 5)all");
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

if(opt.equalsIgnoreCase("yellow")){
      analogWrite(red,255);
  analogWrite(green,80);
  analogWrite(blue,0);
}

if(opt.equalsIgnoreCase("purple")){
    analogWrite(red,133);
  analogWrite(blue,173);
  analogWrite(green,0);
}

if(opt.equalsIgnoreCase("cyan")){
      analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,255);
}

if(opt.equalsIgnoreCase("magenta")){
      analogWrite(red,255);
  analogWrite(green,0);
  analogWrite(blue,255);
}

if(opt.equalsIgnoreCase("lightPink")){
      analogWrite(red,200);
  analogWrite(green,10);
  analogWrite(blue,10);
}

if(opt.equalsIgnoreCase("none")){
  analogWrite(red,0);
  analogWrite(blue,0);
  analogWrite(green,0);
}

if(opt.equalsIgnoreCase("all")){
    analogWrite(red,255);
  analogWrite(blue,255);
  analogWrite(green,255);
}

  }
}
