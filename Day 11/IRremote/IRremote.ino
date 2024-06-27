#include <IRremote.h>
int IRpin=9;
IRrecv IR(IRpin);
decode_results cmd;
int ledPinR=3;
int ledPin=5;
void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(ledPin,OUTPUT);
  pinMode(ledPinR,OUTPUT);
}

void loop() {
  while(IR.decode(&cmd)==0){}
  Serial.println(cmd.value,HEX);
  if(cmd.value==0xFE708F)digitalWrite(ledPin,HIGH);
  if(cmd.value==0xFE58A7)digitalWrite(ledPin,LOW);
  if(cmd.value==0xFE609F)digitalWrite(ledPinR,HIGH);
  if(cmd.value==0xFEF00F)digitalWrite(ledPinR,LOW);
  delay(500);
  IR.resume();
}
