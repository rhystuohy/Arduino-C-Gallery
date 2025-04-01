const int forwardPin = 8;
const int backwardPin = 12;
const int delayTime = 2000;
const int delayTIme2 = 300

void setup() {
  pinMode(forwardPin,OUTPUT);
  pinMode(backwardPin,OUTPUT);
}

void loop() {
  // stop
  //digitalWrite(forwardPin,LOW);
  //digitalWrite(backwardPin,LOW);
  //delay(delayTime);
  //spinfoward
  digitalWrite(forwardPin,LOW);
  digitalWrite(backwardPin,HIGH);
  delay(delayTime);
  digitalWrite(forwardPin,LOW);
  digitalWrite(backwardPin,HIGH);
  delay(delayTime);
  //stop
  digitalWrite(forwardPin,LOW);
  digitalWrite(backwardPin,LOW);
  delay(delayTime2);
  //spinbackward
  //digitalWrite(forwardPin,LOW);
  //digitalWrite(backwardPin,HIGH);
  //delay(delayTime);
}
