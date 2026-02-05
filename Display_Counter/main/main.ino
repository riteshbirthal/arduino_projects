

//  ##D0##
//  D1  D6
//  ##D2##
//  D3  D5
//  ##D4##  D7

// DIS :  { A,  F,  G,  E,  D,  C,  B, DP}
//          |   |   |   |   |   |   |   |       connections in board
// num :  {D0, D1, D2, D3, D4, D5, D6, D7}
// 0   :  { 1,  1,  0,  1,  1,  1,  1,  0}
// 1   :  { 0,  0,  0,  0,  0,  1,  1,  0}
// 2   :  { 1,  0,  1,  1,  1,  0,  1,  0}
// 3   :  { 1,  0,  1,  0,  1,  1,  1,  0}
// 4   :  { 0,  1,  1,  0,  0,  1,  1,  0}
// 5   :  { 1,  1,  1,  0,  1,  1,  0,  0}
// 6   :  { 1,  1,  1,  1,  1,  1,  0,  0}
// 7   :  { 1,  0,  0,  0,  0,  1,  1,  0}
// 8   :  { 1,  1,  1,  1,  1,  1,  1,  0}
// 9   :  { 1,  1,  1,  0,  1,  1,  1,  0}


unsigned int num = 0, D0=2, D1=3, D2=4, D3=5, D4=6, D5=7, D6=8, D7=9;
char code[] = "11011110000001101011101010101110011001101110110011111100100001101111111011101110";

void lightNumber(){
  digitalWrite(D0, code[num*8+0]=='0' ? LOW : HIGH);
  digitalWrite(D1, code[num*8+1]=='0' ? LOW : HIGH);
  digitalWrite(D2, code[num*8+2]=='0' ? LOW : HIGH);
  digitalWrite(D3, code[num*8+3]=='0' ? LOW : HIGH);
  digitalWrite(D4, code[num*8+4]=='0' ? LOW : HIGH);
  digitalWrite(D5, code[num*8+5]=='0' ? LOW : HIGH);
  digitalWrite(D6, code[num*8+6]=='0' ? LOW : HIGH);
  digitalWrite(D7, code[num*8+7]=='0' ? LOW : HIGH);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Counter Device Up...");
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(num==10)
    num = 0;
  lightNumber();
  num += 1;
  delay(1000);
}
