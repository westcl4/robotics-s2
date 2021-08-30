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
  delay(5000);
  compass.read();
  new_tap_value = compass.a.z;
  gyro.init();
  gyro.enableDefault();
}

void loop() {
  // put your main code here, to run repeatedly:
  unsigned int sensor_values[8];
  reflectanceSensors.read(sensor_values);
  
  for (int i = 0; i < NUM_SENSORS; i++)
  {
    Serial.print(sensor_values[i]);
    Serial.print('\t');
    }
  Serial.println("");
  
  delay(250);
}

void gyroread() {
 
}

void forward() {
  
}

void linesensors() {
  
}
