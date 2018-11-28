#ifndef LEDCONTROLLER_H
#define LEDCONTROLLER_H
#include "LED.h"
#include "Interpolator.h"
#include "Behaviors.h"

/* LEDBehavior Primer

   Value is what color value to transition to
   while duration is how long it will take to
   complete that transition.

   Program holds by having two consecutive identical
   values with a specified duration between the two.

   It is vital to have an equal number of values and
   durations.
*/

struct LEDContainer {
  LED led;
  String ledName;
  /* Having an array of behaviors allows the user to
      switch easily from one to the other.

      Consider creating an enum to make indexing simpler.
  */
  LEDBehavior* behaviors;
  int behaviorIndex;
  unsigned long behaviorBegan;
};

class LEDController {

    //TODO find runtime/Constructor solution for number of leds
    int numLEDs;
    LEDContainer* LEDs;

    unsigned long currentTime;



  public:

    LEDController(int _numLEDs);
    LEDController();

    void updateLEDs();

    void updateCurrentTime();

    void addLED(LED _led, String _ledName);
    void playBehavior(LEDContainer _c);

  
  private:
    float calcPercentComplete( LEDBehavior _b);
    Color calcNextColor( LEDContainer _c, LEDBehavior _b);
};
#endif
