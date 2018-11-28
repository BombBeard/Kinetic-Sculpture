#ifndef BEHAVIORS_H
#define BEHAVIORS_H
#include "LED.h"
#include "Interpolator.h"

struct servoBehavior {
  int* speeds;
  int* durations;
  INTERPOLATION_STYLE* styles;
  int index;
  int sizeOf;
  unsigned int timeBegan;
};

struct LEDBehavior {
  Color* values;
  int* duration;
  INTERPOLATION_STYLE* style;
  int index;
  int sizeOf;
  unsigned int timeBegan;
};


#endif

