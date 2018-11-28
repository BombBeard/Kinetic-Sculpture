#include "LED.h"
LED::LED(int _r, int _g, int _b, int _power, int _pirOffset) {
  pirOffset = _pirOffset;
  r = _r + pirOffset;
  g = _g + pirOffset;
  b = _b + pirOffset;
  pinMode( r, OUTPUT);
  pinMode( g, OUTPUT);
  pinMode( b, OUTPUT);
  power = _power + pirOffset;
  pinMode(power, OUTPUT);
  curColor = Color();

  pwm;
}

LED::LED(int _r, int _g, int _b, int _power, int _pirOffset, Adafruit_PWMServoDriver _pwm) {
  pwm = _pwm;
  pwm.setPin(power, HIGH, true);
  LED( _r, _g, _b, _power, _pirOffset);
}

LED::LED(int _r, int _g, int _b, int _power) {
  LED(_r, _b, _g, _power, 0);
}

LED::LED() {
  LED(0, 0, 0, 0);
}


/* Getters and Setters */
Color LED::getPreviousColor() {
  return prevColor;
}

Color LED::getCurColor() {
  return curColor;
}
void LED::setCurColor(Color _c) {
  prevColor = curColor;
  curColor = _c;
  if ( isFucky ) {
    pwm.setPin(r, 255 - curColor.r);
    pwm.setPin(g, 255 - curColor.g);
    pwm.setPin(b, 255 - curColor.b);
  }
  else {
    pwm.setPin(r, curColor.r);
    pwm.setPin(g, curColor.g);
    pwm.setPin(b, curColor.b);

  }
}

int LED::getR()        {
  return r;
}
void LED::setR(int _i) {
  r = _i;
}
int LED::getG()        {
  return g;
}
void LED::setG(int _i) {
  g = _i;
}
int LED::getB()        {
  return b;
}
void LED::setB(int _i) {
  b = _i;
}
int LED::getPower()    {
  return power;
}
void LED::setPower(int _i) {
  power = _i;
}
int LED::getPirOffset() {
  return pirOffset;
}
void LED::setPirOffset(int _i) {
  pirOffset = _i;
}
void LED::setIsFucky( bool _b ){
  isFucky = _b;
}
