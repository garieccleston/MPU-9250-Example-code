
#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  mpu6050.begin();
  mpu6050.calcGyroOffsets(true);
}

void loop() {
  mpu6050.update();
  Serial.print("angleX : ");
  Serial.print(mpu6050.getAngleX());
  Serial.print("\tangleY : ");
  Serial.print(mpu6050.getAngleY());
  Serial.print("\tangleZ : ");
  Serial.println(mpu6050.getAngleZ());
  int led = 6;
  pinMode (6, OUTPUT);
  if (mpu6050.getAngleZ()  > 88 && mpu6050.getAngleZ() < 92) {
    digitalWrite(6, HIGH);   
  }
  else 
  {
    digitalWrite(6, LOW);
  }
}