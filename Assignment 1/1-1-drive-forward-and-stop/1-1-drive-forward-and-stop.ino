#include <ZumoMotors.h>
#include <ZumoShield.h>
#include <Wire.h>

ZumoMotors motors;

int speed = 100;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Wire.begin();

  motors.setSpeeds (speed, speed);
  delay(2000);
  motors.setSpeeds (0,0);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  
  
}
