#include <LiquidCrystal.h>
//ultra sonic configurations//
int trig=10;
int echo= 11;
int PTT;
///////////////////////
// LCD configurations//you can chose this option insted of potentiometer
//int vo=3;
int rs=4;
int en=5;
int d4=6;
int d5=7;
int d6=8;
int d7=9;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
/////////////////////////
void setup() {
  //pinMode(vo,OUTPUT);
 // analogWrite(vo,100);// you can chose this option insted of potentiometer
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  pinMode(trig,OUTPUT);
  pinMode(echo,INPUT);
  Serial.begin(9600);

}

void loop() {
  digitalWrite(trig,LOW);
  delayMicroseconds(10);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  PTT=pulseIn(echo,HIGH)* 0.034 / 2;
  Serial.print("distance is: ");
  Serial.print(PTT);
  Serial.println(" cm");
  
  if(PTT<10){
    lcd.print("distance : " + String(PTT)+" cm");
    lcd.setCursor(0, 10);
    lcd.print("(-_-) Too Close");
    delay(200);

  }
  else if(PTT>10&&PTT<25){
    lcd.print("distance : " + String(PTT)+" cm");
    lcd.setCursor(0, 10);
    lcd.print("!-_-!   Close!");
    delay(200);
  }
  else{
    lcd.print("distance : " + String(PTT)+" cm");
    lcd.setCursor(0, 10);
    lcd.print("(*_*) Far Enough");
  } 
  delay(200);
  lcd.clear();


}
