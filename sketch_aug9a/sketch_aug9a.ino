#include <Servo.h>
Servo Servo1;

int servoPin = 9;
int servo_angle;

int yjoyPin = A0;
int xjoyPin = A1;
int xval;
int yval;

const int LB = 4;
const int LF = 6;
//const int RF = 8; //disclude if running only one motor
//const int RB = 7; //disclude if running only one motor
const int LP = 5;
//const int RP = 9; //disclude if running only one motor
//const int TRIGPIN = 11;
//const int ECHOPIN = 12;
//long dist;

void setup() {
  Servo1.attach(servoPin);
  Serial.begin(9600);
  pinMode(LF, OUTPUT);
  pinMode(LB, OUTPUT);
  //pinMode(RF, OUTPUT);
  //pinMode(RB, OUTPUT);
  //pinMode(TRIGPIN, OUTPUT);
  //pinMode(ECHOPIN, INPUT);// put your setup code here, to run once:
}

void loop() {
  int reading = analogRead(joyPin);
  int val = map(reading, 0, 1023, 0, 180);
  Servo1.write(val);
  forward255(); 
  delay(2000);
  forward200();
  delay(2000);
  back200();
  delay(2000);
  //disclude if using input sensor or pot
  //dist = checkStop();

  //Serial.println(dist); // check to make sure its L and not I (says 1 in normal code)

  //if (dist >= 20) {
    //forward();
  //}
  //else {
    //left();
  //}
}

void forward255() {
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  //digitalWrite(RF, HIGH);
  //digitalWrite(RB, LOW);
  analogWrite(LP, 255);
  //analogWrite(RP, 230);
}

void forward200() {
  digitalWrite(LF, HIGH);
  digitalWrite(LB, LOW);
  //digitalWrite(RF, HIGH);
  //digitalWrite(RB, LOW);
  analogWrite(LP, 200);
  //analogWrite(RP, 160);
}

void back200() {
  digitalWrite(LF, LOW);
  digitalWrite(LB, HIGH);
  //digitalWrite(RF, LOW);
  //digitalWrite(RB, HIGH);
  analogWrite(LP, 200);
  //analogWrite(RP, 230);
}

void left() {
  digitalWrite(LF, LOW);
  //digitalWrite(RF, HIGH);
  digitalWrite(LB, HIGH);
  //digitalWrite(RB, LOW);
}

long checkStop() {
  long distance, duration;

  //digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(5);
  //digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  //digitalWrite(TRIGPIN, LOW);

  //duration = pulseIn(ECHOPIN, HIGH);

  distance = (340 * (duration * 0.000001) * 0.5) * 100.0;

  return distance;
}