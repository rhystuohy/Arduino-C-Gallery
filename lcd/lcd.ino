const int ledpin = 8;
const int butpin = 7;

void setup() {
  pinMode(ledpin,OUTPUT);
  pinMode(butpin,INPUT);
  //#include <LiquidCrystal.h>
}

void loop() {
  int butstate = digitalRead(butpin);
  if (butstate == HIGH){
    digitalWrite(ledpin,LOW);
  }
  else {
    digitalWrite(ledpin,HIGH);
  }
}
