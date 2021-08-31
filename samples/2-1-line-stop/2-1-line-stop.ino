  // copied from https://github.com/pololu/zumo-shield/blob/master/ZumoExamples/examples/LineFollower/LineFollower.ino

#include <ZumoMotors.h>
#include <ZumoReflectanceSensorArray.h>
#include <ZumoMotors.h>
ZumoMotors motors;

ZumoReflectanceSensorArray reflectanceSensors;
#define NUM_SENSORS 6  // number of sensors used

int lastError = 0;
const int MAX_SPEED = 100;

void setup() {
  // put your setup code here, to run once:
  reflectanceSensors.init();


  delay(1000);
  int i;
  for (i = 0; i < 80; i++)
  {
    if ((i > 10 && i <= 30) || (i > 50 && i <= 70))
      motors.setSpeeds(-200, 200);
    else
      motors.setSpeeds(200, -200);
    reflectanceSensors.calibrate();

    // Since our counter runs to 80, the total delay will be
    // 80*20 = 1600 ms.
    delay(20);
  }
  motors.setSpeeds(0, 0);


}

void loop() {
  // put your main code here, to run repeatedly:

  unsigned int sensors[6];
  int position = reflectanceSensors.readLine(sensors);
  int error = position - 2500;
  int speedDifference = error / 4 + 6 * (error - lastError);
  lastError = error;

  int m1Speed = MAX_SPEED + speedDifference;
  int m2Speed = MAX_SPEED - speedDifference;

  if (m1Speed < 0)
    m1Speed = 0;
  if (m2Speed < 0)
    m2Speed = 0;
  if (m1Speed > MAX_SPEED)
    m1Speed = MAX_SPEED;
  if (m2Speed > MAX_SPEED)
    m2Speed = MAX_SPEED;

  motors.setSpeeds(m1Speed, m2Speed);
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
