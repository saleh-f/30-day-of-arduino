const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};
int D1=9;
int D2=10;
int D3=11;
int D4=12;
int dot=13;
int count=5009;
const int digitPatterns[10][7] = {
    {0, 0, 0, 0, 0, 0, 1}, // 0
    {1, 0, 0, 1, 1, 1, 1}, // 1
    {0, 0, 1, 0, 0, 1, 0}, // 2
    {0, 0, 0, 0, 1, 1, 0}, // 3
    {1, 0, 0, 1, 1, 0, 0}, // 4
    {0, 1, 0, 0, 1, 0, 0}, // 5
    {0, 1, 0, 0, 0, 0, 0}, // 6
    {0, 0, 0, 1, 1, 1, 1}, // 7
    {0, 0, 0, 0, 0, 0, 0}, // 8
    {0, 0, 0, 0, 1, 0, 0}  // 9
};
void setup() {
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
pinMode(dot,OUTPUT);
pinMode(D1,OUTPUT);
pinMode(D2,OUTPUT);
pinMode(D3,OUTPUT);
pinMode(D4,OUTPUT);
Serial.begin(9600);
}

void loop() {
  getNum(count);
  count--;
  if(count<0)while(true){}
    
}


void getNum(int num){
  int digit4=num/1000;
  num=num%1000;
  Serial.print(digit4);
  int digit3=num/100;
  num=num%100;
  Serial.print(digit3);
  int digit2=num/10;
  num=num%10;
  Serial.print(digit2);
  int digit1=num;
  Serial.println(digit1);
  Serial.println("--------------------");
  turnOn(digit4,digit3,digit2,digit1);
}

void turnOn(int digit4,int digit3,int digit2,int digit1){
  digitalWrite(D1,HIGH);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit4][i]);
  }
  delay(10);
  digitalWrite(D1,LOW);
  digitalWrite(D2,HIGH);
  digitalWrite(D3,LOW);
  digitalWrite(D4,LOW);
    for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit3][i]);
  }
  delay(10);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,HIGH);
  digitalWrite(D4,LOW);
    for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit2][i]);
  }
  delay(5);
  digitalWrite(D1,LOW);
  digitalWrite(D2,LOW);
  digitalWrite(D3,LOW);
  digitalWrite(D4,HIGH);
    for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit1][i]);  
   }


}
