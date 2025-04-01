#include <SPI.h>
#include <Wire.h>
#include <Servo.h>
#define MPU 0x68  // I2C address of the MPU-6050

Servo ServoX, ServoY;
double AcX, AcY, AcZ;
int Pitch, Roll;

void setup() {
  Serial.begin(9600);
  ServoX.attach(8);
  ServoY.attach(9);
  init_MPU(); 
}

void loop()
{
  FunctionsMPU(); 

  Roll = FunctionsPitchRoll(AcX, AcY, AcZ);   
  Pitch = FunctionsPitchRoll(AcZ, AcX, AcY);  

  int ServoRoll = map(Roll, -90, 90, 0, 179);
  int ServoPitch = map(Pitch, -90, 90, 179, 0);

  ServoX.write(ServoPitch);
  ServoY.write(ServoRoll);


  Serial.print("Pitch: "); Serial.print(Pitch);
  Serial.print("\t");
  Serial.print("Roll: "); Serial.print(Roll);
  Serial.print("\n");

}

void init_MPU() {
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B);  // PWR_MGMT_1 register
  Wire.write(0);     // set to zero (wakes up the MPU-6050)
  Wire.endTransmission(true);
  delay(1000);
}


double FunctionsPitchRoll(double A, double B, double C) {
  double DatoA, DatoB, Value;
  DatoA = A;
  DatoB = (B * B) + (C * C);
  DatoB = sqrt(DatoB);

  Value = atan2(DatoA, DatoB);
  Value = Value * 180 / 3.14159;

  return (int)Value;
}


void FunctionsMPU() {
  Wire.beginTransmission(MPU);
  Wire.write(0x3B);  // starting with register 0x3B (ACCEL_XOUT_H)
  Wire.endTransmission(false);
  Wire.requestFrom(MPU, 6, true); // request a total of 14 registers
  AcX = Wire.read() << 8 | Wire.read(); // 0x3B (ACCEL_XOUT_H) & 0x3C (ACCEL_XOUT_L)
  AcY = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
  AcZ = Wire.read() << 8 | Wire.read(); // 0x3D (ACCEL_YOUT_H) & 0x3E (ACCEL_YOUT_L)
}
