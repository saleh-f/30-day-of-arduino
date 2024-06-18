 #include <IRremote.h>
int IRpin=9;
IRrecv IR(IRpin);
decode_results cmd;
int dim=10;
void setup() {
  Serial.begin(9600);
  IR.enableIRIn();
  pinMode(5,OUTPUT);

}

void loop() {
  while(IR.decode(&cmd)==0){

  }
  if(cmd.value == 0xFFA25D)analogWrite(5,dim);
  if(cmd.value == 0xFF5AA5){
    dim+=30;
    analogWrite(5,dim);
  }
   if(cmd.value == 0xFF10EF){
    dim-=30;
    analogWrite(5,dim);
   }
  if(cmd.value == 0xFF9867)analogWrite(5,0);
  if(dim>255||dim<0)dim=10;
  Serial.println(dim);
  Serial.println(cmd.value,HEX);
  delay(500);
  IR.resume();
}
