#include "LED.h"
#include "Interpolator.h"
#include "LEDController.h"
#include <Adafruit_PWMServoDriver.h>
#include <Arduino.h>
#include <Servo.h>


Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver(0x40);

LEDController controller = LEDController();

LED led1 = LED(0, 1, 2, 3, 0, pwm);
LEDBehavior* led1Behaviors;
LED led2 = LED(4, 5, 6, 7, 8, pwm);

unsigned long timeBegan_s1 = 0;
unsigned long curTime = 0;

int prevSpeed = 90;
int curSpeed = 90;


void setup() {

  pwm.begin();
  pwm.setPWMFreq(120);

  Serial.begin(9600);

  controller.addLED(led1, "led1");
  controller.addLED(led2, "led2");
  timeBegan_s1 = millis();
  curTime = millis();

  //led1.setCurColor({120, 120, 120});
  pwm.setPin(led1.getPower(), 4096, false );
  pwm.setPin(led1.getR(), 4096, true );
  pwm.setPin(led1.getG(), 4096, true );
  pwm.setPin(led1.getB(), 4096, true );

}

void loop() {



}
