#include <ZumoMotors.h>
#include <ZumoShield.h>
#include <Wire.h>

LSM303 compass;
L3G gyro;
ZumoMotors motors;

int botSpeed, stopTime, difference;
float old_tap_value = 0;
float new_tap_value = 0;
boolean collision_detected = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();
  compass.init();
  compass.enableDefault();
  compass.read();
  delay(1000);
  new_tap_value = compass.a.z;
  gyro.init();
  gyro.enableDefault();
}

void loop() {
  // put your main code here, to run repeatedly:
  compass.read();
  gyro.read();

  Serial.print(gyro.g.x);
  Serial.print(gyro.g.y);
  Serial.print(gyro.g.z);
  Serial.println();

  old_tap_value = new_tap_value;
  new_tap_value = compass.a.z;

  float diff = (new_tap_value - old_tap_value);
  Serial.println(diff);

  if (diff <= 1750)
  {
    drive_forward(100);
  } else
  {
    
    backup(100);
    delay(500);
    backup(0);
    delay (9999);
  }

}

void drive_forward(int botSpeed) {
  motors.setSpeeds(botSpeed, botSpeed);
  //  delay(stopTime);
  //  motors.setSpeeds(0, 0);
  //  tap_flag = false;
  //  return;
}

void backup(int botSpeed) {
  motors.setSpeeds(-(botSpeed), -(botSpeed));
}
