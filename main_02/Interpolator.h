#ifndef INTERPOLATOR_H
#define INTERPOLATOR_H
#include <Arduino.h>

enum INTERPOLATION_STYLE {
  LINEAR,
  SMOOTH,
  ACCELERATE,
  DECELERATION,
  NONE
};

class Interpolator{
  
  public:
  
  static int interpolateLinear(int source, int target, float percentComplete);
  static int interpolateSmooth(int source, int target, float percentComplete);
  static int interpolateAccelerate(int source, int target, float percentComplete);
  static int interpolateDecelerate(int source, int target, float percentComplete);
  static int interpolateStepped(int source, int target, float percentComplete);

  static float calcPercentComplete( int timeStarted, int timeCurrent );
  
};
#endif
