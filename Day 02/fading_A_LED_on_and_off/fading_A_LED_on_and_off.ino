void setup() {
  pinMode(9,OUTPUT);
}

void loop() {
  for(int i=0;i<255;i++){// fading in
    analogWrite(9,i);
    delay(10);//adding a litile delay for each iteration 
  }

for(int i=255;i>0;i--){
  analogWrite(9,i);
  delay(10);
}
  }
  


