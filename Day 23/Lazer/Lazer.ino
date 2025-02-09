int value;
int LazerPin=6;
int buz=7;
void setup() {
  pinMode(LazerPin,OUTPUT);
  pinMode(buz,OUTPUT);
  pinMode(INPUT,A0);
  Serial.begin(9600);
}

void loop() {
///-----   FOR TRANSPASING ALARM   -----///
  // value=analogRead(A0);
  // Serial.println(value);
  // if(value<250)
  //   digitalWrite(buz,HIGH);
  // else 
  // digitalWrite(buz,LOW);
////-----  FOR CONTROLLING THE DELAY WITH AN POTENTIOMETER   -----////  
  // value=analogRead(A0);
  // Serial.println(value);
  // if(value>0&&value<100){
  // digitalWrite(LazerPin,HIGH);
  // delay(40);
  // digitalWrite(LazerPin,LOW);
  // delay(40);
  // }
  //   if(value>100&&value<250){
  // digitalWrite(LazerPin,HIGH);
  // delay(80);
  // digitalWrite(LazerPin,LOW);
  // delay(80);
  // }
  //   if(value>250&&value<400){
  // digitalWrite(LazerPin,HIGH);
  // delay(150);
  // digitalWrite(LazerPin,LOW);
  // delay(150);
  // }
  //   if(value>400&&value<600){
  // digitalWrite(LazerPin,HIGH);
  // delay(220);
  // digitalWrite(LazerPin,LOW);
  // delay(220);
  // }
  //     if(value>600&&value<800){
  // digitalWrite(LazerPin,HIGH);
  // delay(300);
  // digitalWrite(LazerPin,LOW);
  // delay(300);
  // }


///----------   FOR SIMPLE DELAY    ------///
  // digitalWrite(LazerPin,HIGH);
  // delay(150);
  // digitalWrite(LazerPin,LOW);
  // delay(150);

}
