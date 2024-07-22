int read;
int BUZ=2;
//int LED=2;uncomment to use the LED version !!! comment the line above as well 
bool state=false;
void setup() {
pinMode(A0,INPUT);
pinMode(BUZ,OUTPUT);
Serial.begin(9600);
}

void loop() {
  read=analogRead(A0);
  Serial.println(read);
  ///--------   buzzer version--------- ///
  if(read<100){
    digitalWrite(BUZ,HIGH);
    delay(1000);
  }
  else digitalWrite(BUZ,LOW);
  ///--------          --------- ///


  ///*********** LED version ***********///
  // if(read<100&&state==false){
  //   digitalWrite(LED,HIGH);
  //   state=true;
  // }
  // else if(read<100&&state==true){
  //   digitalWrite(LED,LOW);
  //   state=false;
  // }

  ///**************          ************///
  delay(100);
}
