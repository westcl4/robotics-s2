#include <Wire.h>
#include <ZumoShield.h>
ZumoMotors motors;

void setup() {
  // put your setup code here, to run once:
Wire.begin();
delay(5000);
  
}

void loop() {
  // put your main code here, to run repeatedly:

drive_forward(100);
}

void drive_forward(int speed){
  motors.setSpeeds(speed, speed);
}
