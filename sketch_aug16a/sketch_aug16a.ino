#include <Servo.h>
int servo_pin = 11;
int servo_angle;
Servo my_servo;

// JoyStick
int x_pin = A0;
int y_pin = A1;
int x_val;
int y_val;

//DC Motor 1
int DC_speed_pin = 10;
int dir_pin0 = 9;
int dir_pin1 = 8;
int DC_val;

// DC Motor 2
int DC_speed2_pin = 6;
int dir_pin2 = 5;
int dir_pin3 = 4;
int DC_val2;


void setup() {
  // put your setup code here, to run once:

  //Servo Motor
  my_servo.attach(servo_pin);
  pinMode(servo_pin, OUTPUT);

  //JoyStick
  pinMode(x_pin, INPUT);
  pinMode(y_pin, INPUT);

  //DC Motor 1
  pinMode(DC_speed_pin, OUTPUT);
  pinMode(dir_pin0, OUTPUT);
  pinMode(dir_pin1, OUTPUT);

  //DC Motor 2
  pinMode(DC_speed2_pin, OUTPUT);
  pinMode(dir_pin2, OUTPUT);
  pinMode(dir_pin3, OUTPUT);
 

  Serial.begin(2000000);

}

void loop() {
  // put your main code here, to run repeatedly:
  x_val = analogRead(x_pin);
  y_val = analogRead(y_pin);
  servo_angle = (180./1023. * (x_val));
  DC_val = (255. / 1023. * (y_val));
  DC_val2 = (255. / 1023. * (y_val));
  Serial.println(DC_val);
  
  my_servo.write(servo_angle);

  // DC Motor 1
  digitalWrite(dir_pin0, HIGH);
  digitalWrite(dir_pin1, LOW);

  // DC Motor 2
  digitalWrite(dir_pin2, LOW);
  digitalWrite(dir_pin3, HIGH);

  // DC Motor 1
  analogWrite(DC_speed_pin, DC_val);

  // DC Motor 2
  analogWrite(DC_speed2_pin, DC_val2);

  
  Serial.println(DC_val);
}
