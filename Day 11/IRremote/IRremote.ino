#include <IRremote.h>
int IRpin=9;
IRrecv IR(IRpin);
decode_results cmd;
int red=3;
int green=5;
int blue=6;
void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(red,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);
}

void loop() {
  while(IR.decode(&cmd)==0){}
  Serial.println(cmd.value,HEX);
  // if(cmd.value==0xFFA25D)digitalWrite(ledPin,HIGH);
  // if(cmd.value==0xFF9867)digitalWrite(ledPin,LOW);
  // if(cmd.value==0xFF629D)digitalWrite(ledPin,HIGH);
  // if(cmd.value==0xFFE21D)digitalWrite(ledPinR,LOW);
  if(cmd.value==0xFFA25D){
  analogWrite(red,255);
  analogWrite(blue,0);
  analogWrite(green,0);
}
if(cmd.value==0xFF629D){
  analogWrite(red,0);
  analogWrite(blue,255);
  analogWrite(green,0);
}
if(cmd.value==0xFFE21D){
  analogWrite(red,0);
  analogWrite(blue,0);
  analogWrite(green,255);
}

if(cmd.value==0xFF22DD){
      analogWrite(red,255);
  analogWrite(green,80);
  analogWrite(blue,0);
}

if(cmd.value==0xFF02FD){
    analogWrite(red,130);
  analogWrite(blue,170);
  analogWrite(green,0);
}

if(cmd.value==0xFFC23D){
      analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,255);
}

if(cmd.value==0xFFE01F){
      analogWrite(red,255);
  analogWrite(green,0);
  analogWrite(blue,255);
}

// if(opt.equalsIgnoreCase("lightPink")){
//       analogWrite(red,200);
//   analogWrite(green,10);
//   analogWrite(blue,10);
// }

if(cmd.value==0xFF9867){
  analogWrite(red,0);
  analogWrite(blue,0);
  analogWrite(green,0);
}
  delay(500);
  IR.resume();
}
