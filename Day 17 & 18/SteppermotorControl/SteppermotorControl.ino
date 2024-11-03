#include <Stepper.h>
Stepper ms(2048,8,10,9,11);
int Xpin=A1;
int Ypin=A0;
int swVal;
int Xval;
int Yval;
void setup() {
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  ms.setSpeed(10);
  Serial.begin(9600);
}

void loop() {
Xval=analogRead(Xpin);
Yval=analogRead(Ypin);
if(Xval>600&&Xval<850)ms.step(2);
if(Xval>850&&Xval<1000)ms.step(5);
if(Xval>1000)ms.step(7);
if(Xval<400&&Xval>250)ms.step(-2);
if(Xval<250&&Xval>100)ms.step(-5);
if(Xval<100)ms.step(-7);
delay(20);
}
