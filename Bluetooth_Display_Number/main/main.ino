

#include <SoftwareSerial.h>


unsigned int rx=10, tx=11, D0=2, D1=3, D2=4, D3=5, D4=6, D5=7, D6=8, D7=9;
char code[] = "11011110000001101011101010101110011001101110110011111100100001101111111011101110";
SoftwareSerial bt(rx, tx);

void lightNumber(int num){
  digitalWrite(D0, code[num*8+0]=='0' ? LOW : HIGH);
  digitalWrite(D1, code[num*8+1]=='0' ? LOW : HIGH);
  digitalWrite(D2, code[num*8+2]=='0' ? LOW : HIGH);
  digitalWrite(D3, code[num*8+3]=='0' ? LOW : HIGH);
  digitalWrite(D4, code[num*8+4]=='0' ? LOW : HIGH);
  digitalWrite(D5, code[num*8+5]=='0' ? LOW : HIGH);
  digitalWrite(D6, code[num*8+6]=='0' ? LOW : HIGH);
  digitalWrite(D7, code[num*8+7]=='0' ? LOW : HIGH);
}

void blankScreen(){
  digitalWrite(D0, LOW);
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Device is up...");
  bt.begin(9600);
  pinMode(D0, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
  blankScreen();
}


void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()>0){
    bt.write(Serial.read());
  }
  if(bt.available()>0){
    int num = bt.read();
    Serial.print("Received Data: ");
    int n = int(num)-48;
    Serial.write(n);
    if(0<=n && n<10){
      Serial.println("Calling LED Segment function..");
      lightNumber(n);
    }
    delay(1000);
    blankScreen();
    delay(200);
  }
}
