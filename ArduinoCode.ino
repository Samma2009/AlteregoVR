#include <MPU6050_tockn.h>
#include <Wire.h>

MPU6050 mpu6050(Wire);

void setup() {
  // put your setup code here, to run once:

Serial.begin(9600);
Wire.begin();
mpu6050.begin();
mpu6050.calcGyroOffsets(true);

}

unsigned long t1,dt;
int x,y,z;

void loop() {
  // put your main code here, to run repeatedly:

  mpu6050.update();

 // dt = millis() -t1;

  if (x != mpu6050.getAccX())
  {

    //t1 = millis();
    x= mpu6050.getAngleX();
    y= mpu6050.getAngleY();
    z= mpu6050.getAngleZ();

    Serial.print(x);
    Serial.print(":");
    Serial.print(y);
    Serial.print(":");
    Serial.println(z);
  }

  delay(25);

}
