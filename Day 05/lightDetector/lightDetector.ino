int lv;
void setup(){
  pinMode(A0,INPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  Serial.begin(9600);
}
void loop(){
  lv=analogRead(A0);
  Serial.println(lv);
  if(lv>25){
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
  }
  else{
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    digitalWrite(8,LOW);
  } 
  delay(300);
}



