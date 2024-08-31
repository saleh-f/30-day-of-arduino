#include <LiquidCrystal.h>
// LCD configurations//
int rs=4;
int en=5;
int d4=6;
int d5=7;
int d6=8;
int d7=9;
LiquidCrystal lcd(rs,en,d4,d5,d6,d7);
/////////////////////////
void setup() {
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  Serial.begin(9600);

}

void loop() {
  lcd.print("Hello world");
  delay(2000);
  lcd.clear();


}
