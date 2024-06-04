int btn1=10;
int btn2=11;
int btnVal1;
int btnVal2;
int j=0;
// Pin mapping for the segments
const int segmentPins[] = {2, 3, 4, 5, 6, 7, 8};
// Patterns for digits 0-9 (common cathode)
const int digitPatterns[10][7] = {
    {1, 1, 1, 1, 1, 1, 0}, // 0
    {0, 1, 1, 0, 0, 0, 0}, // 1
    {1, 1, 0, 1, 1, 0, 1}, // 2
    {1, 1, 1, 1, 0, 0, 1}, // 3
    {0, 1, 1, 0, 0, 1, 1}, // 4
    {1, 0, 1, 1, 0, 1, 1}, // 5
    {1, 0, 1, 1, 1, 1, 1}, // 6
    {1, 1, 1, 0, 0, 0, 0}, // 7
    {1, 1, 1, 1, 1, 1, 1}, // 8
    {1, 1, 1, 1, 0, 1, 1}  // 9
};

void setup() {
  pinMode(btn1,INPUT);
  digitalWrite(btn1,HIGH);
    pinMode(btn2,INPUT);
  digitalWrite(btn2,HIGH);
  Serial.begin(9600);
  // Set segment pins as output
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }
}

void loop() {
btnVal1=digitalRead(btn1);
Serial.print("btn 1 val is :");
Serial.println(btnVal1);
btnVal2=digitalRead(btn2);
Serial.print("btn 2 val is :");
Serial.println(btnVal2);
if(btnVal1==0){
  j++;
delay(100);
}
if(btnVal2==0){
  j--;
  delay(100);
}
if(j>9||j<0)j=0;
displayDigit(j);
delay(100);

 }

void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit][i]);
  }
}
