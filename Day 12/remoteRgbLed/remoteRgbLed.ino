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
  if(cmd.value==0xFFA25D){//RED
  analogWrite(red,255);
  analogWrite(blue,0);
  analogWrite(green,0);
}
if(cmd.value==0xFF629D){//BLUE
  analogWrite(red,0);
  analogWrite(blue,255);
  analogWrite(green,0);
}
if(cmd.value==0xFFE21D){//GREEN
  analogWrite(red,0);
  analogWrite(blue,0);
  analogWrite(green,255);
}

if(cmd.value==0xFF22DD){//YELLOW
      analogWrite(red,255);
  analogWrite(green,80);
  analogWrite(blue,0);
}

if(cmd.value==0xFF02FD){//PURPLE
    analogWrite(red,130);
  analogWrite(blue,170);
  analogWrite(green,0);
}

if(cmd.value==0xFFC23D){//CYAN
      analogWrite(red,0);
  analogWrite(green,255);
  analogWrite(blue,255);
}

if(cmd.value==0xFFE01F){//MAGENTA
      analogWrite(red,255);
  analogWrite(green,0);
  analogWrite(blue,255);
}

if(cmd.value==0xFF9867){//ALL OFF
  analogWrite(red,0);
  analogWrite(blue,0);
  analogWrite(green,0);
}
  delay(500);
  IR.resume();
}
