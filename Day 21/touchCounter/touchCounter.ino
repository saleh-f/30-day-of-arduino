int ti=9; //ti stands for touch input
int tiv; //tiv stands for touch input value
int counter=0; // this is used to count how many seconds is the button being pressed
int LED=3;
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
  pinMode(ti,INPUT);
  pinMode(LED,OUTPUT);
  Serial.begin(9600);
  // Set segment pins as output
  for (int i = 0; i < 7; i++) {
    pinMode(segmentPins[i], OUTPUT);
  }

}

void loop() {
  
    tiv=digitalRead(ti);
    displayDigit(counter);
  if(tiv>0){
    
    counter++;
    if(counter>9)counter=0;
  }
delay(150);

}
void displayDigit(int digit) {
  for (int i = 0; i < 7; i++) {
    digitalWrite(segmentPins[i], digitPatterns[digit][i]);
  }
}