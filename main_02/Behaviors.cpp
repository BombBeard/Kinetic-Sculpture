#include "Behaviors.h"
/* Default Behaviors */

/* LEDs */

Color ledValues[] = { {255, 0, 0}, {0, 255, 255} };
int ledDurations[] = {500, 500};
INTERPOLATION_STYLE ledStyles[] = { SMOOTH, SMOOTH };

LEDBehavior simpleFade{
  ledValues,
  ledDurations,
  ledStyles,
  0,
  2,
  0
};

/*
LEDBehavior flash{
  { {0, 0, 0}, {200, 200, 200} },
  {125, 125},
  { ACCELERATE, DECELERATION },
  0,
  2
};
*/

/* Servos */

/*
servoBehavior continuousClockwise{
  { 93 },
  {2000},
  { LINEAR },
  0,
  1
};
*/


