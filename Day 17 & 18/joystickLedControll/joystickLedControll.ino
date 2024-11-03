int sw=2;
int Xpin=A1;
int Ypin=A0;
int swVal;
int Xval;
int Yval;


int white=3;
int red=5;
int yellow=6;
int green=9;
int blue=10;
float color=0.0;//until color changes
int dim=50;
void setup() {
  pinMode(sw,INPUT_PULLUP);
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(red,OUTPUT);
  pinMode(white,OUTPUT);
  pinMode(yellow,OUTPUT);
  pinMode(green,OUTPUT);
  pinMode(blue,OUTPUT);

  digitalWrite(sw,HIGH);
  Serial.begin(9600);

}

void loop() {
  swVal=digitalRead(sw);
  Serial.print("Switch: ");
  Serial.println(swVal);
  Xval=analogRead(Xpin);
    Serial.print("X: ");
    Serial.println(Xval);
    Yval=analogRead(Ypin);
    Serial.print("Y: ");
    Serial.println(Yval);
//same as before



  if((color>=0&&color<1)){
    analogWrite(white, dim);
    analogWrite(red, 0);
    analogWrite(yellow, 0);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
    if((color>=1&&color<2)){
    analogWrite(white, 0);
    analogWrite(red, dim);
    analogWrite(yellow, 0);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
    if((color>=2&&color<3)){
    analogWrite(white, 0);
    analogWrite(red, 0);
    analogWrite(yellow, dim);
    analogWrite(green, 0);
    analogWrite(blue, 0);
  }
    if((color>=3&&color<4)){
    analogWrite(white, 0);
    analogWrite(red, 0);
    analogWrite(yellow, 0);
    analogWrite(green, dim);
    analogWrite(blue, 0);
  }
    if((color>=4&&color<5)){
    analogWrite(white, 0);
    analogWrite(red, 0);
    analogWrite(yellow, 0);
    analogWrite(green, 0);
    analogWrite(blue, dim);
  }


  if(Xval>800)color+=0.4;
  if(Xval<300)color-=0.4;
  if(Yval>800)dim-=5;
  if(Yval<300)dim+=5;
  if(color>=5)color=0.0;
  if(color<0)color=4.5;//to have both side controll
  if(dim>=255|| dim<0)dim=50;
  Serial.print("dim is: ");
  Serial.println(dim);
  Serial.print("color is: ");
  Serial.println(color);
  delay(10);



}
