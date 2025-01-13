int ti=2; //ti stands for touch input
int tiv; //tiv stands for touch input value
int counter; // this is used to count how many seconds is the button being pressed
int LED=3;
void setup() {
  pinMode(ti,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);

}

void loop() {
  tiv=digitalRead(ti);
  if(tiv>0){
    digitalWrite(LED,HIGH);
    counter++;
    if (counter>10){
      digitalWrite(LED,LOW);
    }
  }
  else counter=0;
delay(200);
}
