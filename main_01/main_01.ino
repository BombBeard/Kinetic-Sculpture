#include "LED.h"
#include "LEDController.h"
#include "Interpolator.h"
#include "Behaviors.h"
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <Servo.h>

Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();

LEDController controller = LEDController();
Behaviors behaviors = Behaviors();

Servo myServo;

unsigned long timeBegan_s1 = 0;
unsigned long curTime = 0;

int prevSpeed = 90;
int curSpeed = 90;



void setup() {
  Serial.begin(9600);
  myServo.attach(9);

  LED bodyLED = LED(0, 1, 2, 3, 0, pwm);
  /*
    LEDBehavior simpleFade {
    Color[] { Color(255,0,0), Color(0, 255, 255) };
    };
  */
  controller.addLED(bodyLED, "bodyLED");
  timeBegan_s1 = millis();
  curTime = millis();

}

void loop() {
  // put your main code here, to run repeatedly:
  controller.updateCurrentTime();
  curTime = millis();

  if ( (curTime - timeBegan_s1) >= behaviors.simpleFade_servo.durations[behaviors.simpleFade_servo.index]  ) {
    timeBegan_s1 = millis();
    prevSpeed = curSpeed;
    if ( behaviors.simpleFade_servo.index + 1 >= behaviors.simpleFade_servo.sizeOf)
      behaviors.simpleFade_servo.index = 0;
    else {
      behaviors.simpleFade_servo.index++;
    }
  }
  //Serial.println((curTime - timeBegan_s1) - behaviors.simpleFade_servo.durations[behaviors.simpleFade_servo.index]);
  delay(50);
  int tmpSpeed = 0;
  /* TODO Investigate why it is returning only 0 in the old config.
     The new config is using massive numbers and getting insane results as a result.
  */
  switch (behaviors.simpleFade_servo.styles[behaviors.simpleFade_servo.index]) {

    case LINEAR:
      tmpSpeed = Interpolator::interpolateLinear( prevSpeed,
                 behaviors.simpleFade_servo.speeds[behaviors.simpleFade_servo.index],
                 (behaviors.simpleFade_servo.durations[behaviors.simpleFade_servo.index] - (curTime - timeBegan_s1)) / behaviors.simpleFade_servo.durations[behaviors.simpleFade_servo.index]);//the new config

      break;

    case SMOOTH:
      tmpSpeed = Interpolator::interpolateSmooth( prevSpeed,
                 behaviors.simpleFade_servo.speeds[behaviors.simpleFade_servo.index],
                 (curTime - timeBegan_s1) - behaviors.simpleFade_servo.durations[behaviors.simpleFade_servo.index]);
      break;

    case ACCELERATE:
      tmpSpeed = Interpolator::interpolateAccelerate( prevSpeed,
                 behaviors.simpleFade_servo.speeds[behaviors.simpleFade_servo.index],
                 (curTime - timeBegan_s1) - behaviors.simpleFade_servo.durations[behaviors.simpleFade_servo.index]);
      break;

    case DECELERATION:
      tmpSpeed = Interpolator::interpolateDecelerate( prevSpeed,
                 behaviors.simpleFade_servo.speeds[behaviors.simpleFade_servo.index],
                 (curTime - timeBegan_s1) - behaviors.simpleFade_servo.durations[behaviors.simpleFade_servo.index]);
      break;

    case NONE:
      tmpSpeed = Interpolator::interpolateStepped( prevSpeed,
                 behaviors.simpleFade_servo.speeds[behaviors.simpleFade_servo.index],
                 (curTime - timeBegan_s1) - behaviors.simpleFade_servo.durations[behaviors.simpleFade_servo.index]);
      break;

  }/* endSwitch */
  Serial.println(tmpSpeed);
  curSpeed = tmpSpeed;
  //Serial.println( curSpeed );
  myServo.write(curSpeed);
}
