const int joypinmotor = A0;
//const int joypinsteer = A1;
const int motorbck = 9;
const int motorfwd = 6;
const int motoren = 10;
int joymotor;
//int joysteer;
int joymotorneutral;
//int joysteerneutral;
const int deadzone = 20;
int motorspeed;
//int myservo;
//int val;

void setup(){
  pinMode(joypinmotor,INPUT);
  //pinMode(joypinsteer,INPUT);
  pinMode(motorfwd,OUTPUT);
  pinMode(motorbck,OUTPUT);
  pinMode(motoren,OUTPUT);
  joymotorneutral = analogRead(joypinmotor);
  //joysteerneutral = analogRead(joypinsteer);
  Serial.begin(9600);
}

void loop (){
  joymotor = analogRead(joypinmotor);
  Serial.print("motor");
  Serial.println(joymotor);

  //joysteer = analogRead(joypinsteer);
  //Serial.print("steer");
  //Serial.println(joysteer);

  if((joymotor - joymotorneutral) > -deadzone){
    digitalWrite(motorbck,HIGH);
    digitalWrite(motorfwd,LOW);
    motorspeed = map(joymotor,joymotorneutral,0,0,255);
    analogWrite(motoren,motorspeed);
    Serial.print("bck");
  }
  else if((joymotor - joymotorneutral) < deadzone){
    digitalWrite(motorbck,LOW);
    digitalWrite(motorfwd,HIGH);
    motorspeed = map(joymotor,joymotorneutral,1023,0,255);
    analogWrite(motoren,motorspeed);
    Serial.print("fwd");
  }
  else{
  digitalWrite(motorbck,LOW);
  digitalWrite(motorfwd,LOW);
  motorspeed = 0;
  Serial.print("stop");
  }
  //analogWrite(motoren,motorspeed);

  //int val = analogRead(joypinsteer);            // reads the value of the potentiometer (value between 0 and 1023)
  //val = map(val, 0, 1023, 0, 180);     // scale it to use it with the servo (value between 0 and 180)
 // myservo.write(val);                  // sets the servo position according to the scaled value
  //delay(15); 
}
