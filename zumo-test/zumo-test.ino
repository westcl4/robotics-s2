#include <Wire.h>
#include <ZumoShield.h>

LSM303 compass;
L3G gyro;
ZumoMotors motors;
float old_tap_value = 0;
float new_tap_value = 0;
boolean tap_flag = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  delay(5000);
  compass.read();
  new_tap_value = compass.a.z;
  gyro.init();
  gyro.enableDefault();
}

void loop() {
  compass.read(); //both accelerometer and compass

    gyro.read();
  Serial.print(gyro.g.x);
  Serial.print(gyro.g.y);
  Serial.print(gyro.g.z);
  Serial.println();

  old_tap_value = new_tap_value;
  new_tap_value = compass.a.z;
  
  float diff = (new_tap_value - old_tap_value);
  Serial.println(diff);
  
  if (diff > 1500)
  {
    tap_flag = true;
    }

  if (tap_flag == true)
  {
    drive_forward(100);
    }
  delay(100);
}

void drive_forward(int speed){
  motors.setSpeeds(speed, speed);
  }
