//#include <L3G.h>
//#include <LSM303.h>
//#include <PololuBuzzer.h>
//#include <Pushbutton.h>
//#include <QTRSensors.h>
//#include <ZumoBuzzer.h>
#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>
#include <ZumoShield.h>
#include <Wire.h>
LSM303 compass;
L3G gyro;
ZumoMotors motors;
float old_tap_value = 0;
float new_tap_value = 0;
boolean tap_flag = false;

ZumoReflectanceSensorArray reflectanceSensors;
#define NUM_SENSORS 6  // number of sensors used


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  reflectanceSensors.init();
  Wire.begin();
  compass.init();
  compass.enableDefault();
  //delay(5000);
  compass.read();
  new_tap_value = compass.a.z;
  gyro.init();
  gyro.enableDefault();


}

void loop() {
  // put your main code here, to run repeatedly:

  //This function starts the robot- tap to start using the built in gyro
  gyroread();
  //linesensors(sensor_values);
  if(gyroread == true){
    drive_forward(100);
    gyroread == false;
    return;
  }
  
}

boolean gyroread() {
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
  return tap_flag;
}

void drive_forward(int speed) {
  motors.setSpeeds (speed, speed);
  delay(1000);
  motors.setSpeeds(0,0);
  return;
}

int linesensors() {
  unsigned int sensor_values[8];
  reflectanceSensors.read(sensor_values);

  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensor_values[i]);
    Serial.print('\t');
  }
  Serial.println("");

  delay(250);
  return sensor_values[8];
}
