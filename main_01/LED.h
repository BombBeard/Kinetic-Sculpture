#ifndef LED_H
#define LED_H

#include <Adafruit_PWMServoDriver.h>
#include <SharpDistSensor.h>

struct Color {
  //Only supply 0-255
  int r;
  int g;
  int b;
  Color( int _r, int _g, int _b) {
    r = _r;
    g = _g;
    b = _b;
  }
  Color() {
    Color(255, 255, 255);
  }
};
class LED {

    int r;
    int g;
    int b;
    int power;
    int pirOffset;
    Color prevColor;
    Color curColor;

    Adafruit_PWMServoDriver pwm;

    bool isFucky = true;

  public:

    /* Constructors */
    LED(int _r, int _g, int _b, int _power, int _pirOffset);
    LED(int _r, int _g, int _b, int _power, int _pirOffset, Adafruit_PWMServoDriver _pwm);
    LED(int _r, int _g, int _b, int _power);
    LED();

    /* Getters and Setters */
    Color getPreviousColor();

    Color getCurColor();
    void setCurColor(Color _c);

    int getR();
    void setR(int _i);
    int getG();
    void setG(int _i);
    int getB();
    void setB(int _i);
    int getPower();
    void setPower(int _i);
    int getPirOffset();
    void setPirOffset(int _i);

    void setIsFucky( bool _b );
};
#endif
