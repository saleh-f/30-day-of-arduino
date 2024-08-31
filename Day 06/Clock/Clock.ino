#include <Stepper.h>
Stepper ms(2048,8,10,9,11);
int voltPin=A0;
int LED=6;
int voltage;
String state;
String preState;
void setup() {
  ms.setSpeed(15);
  pinMode(LED,OUTPUT);
  pinMode(voltPin,INPUT);
  Serial.begin(9600);
}

 void loop() {
voltage=analogRead(voltPin);
Serial.print("voltage is: ");
Serial.println(voltage);
if(voltage>=1000){
  Serial.println("its night");
  analogWrite(LED,0);
  state="night";
  if(state.equalsIgnoreCase("night")&&preState.equalsIgnoreCase("morning"))ms.step(512);
  else if(state.equalsIgnoreCase("night")&&preState.equalsIgnoreCase("noon"))ms.step(256);
  preState=state;
}
if(voltage<=950){
  Serial.println("its noon");
  analogWrite(LED,235);
  state="noon";
  if(state.equalsIgnoreCase("noon")&&preState.equalsIgnoreCase("night"))ms.step(-256);
  else if(state.equalsIgnoreCase("noon")&&preState.equalsIgnoreCase("morning"))ms.step(256);
  preState=state;
}
if(voltage>951&&voltage<999){
  Serial.println("its morning");
  analogWrite(LED,170);
  state="morning";
  if(state.equalsIgnoreCase("morning")&&preState.equalsIgnoreCase("night"))ms.step(-512);
  else if(state.equalsIgnoreCase("morning")&&preState.equalsIgnoreCase("noon"))ms.step(-256);
  preState=state;
}
Serial.println(voltage);
delay(1000);
 }
