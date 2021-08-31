#include <ZumoMotors.h>
#include <ZumoShield.h>
#include <Wire.h>

ZumoMotors motors;

int speed = 100;
int stop = 2000;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();

  //drive forward then stop
  motors.setSpeeds (speed, speed);
  delay(stop);
  motors.setSpeeds (0,0);
  delay(stop);

  //turn right 90 degrees
  motors.setSpeeds (speed, -speed);
  delay(1250);
  motors.setSpeeds (0,0);
  delay(stop);

  //drive forward then stop
  motors.setSpeeds (speed, speed);
  delay(stop);
  motors.setSpeeds (0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
}
