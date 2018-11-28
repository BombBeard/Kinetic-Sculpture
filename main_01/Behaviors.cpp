#include "Behaviors.h"
/* Interpolation Styles:
     LINEAR, SMOOTH, ACCELERATE, DECELERATION, NONE
*/

Behaviors::Behaviors() {
  Color* colors;
  int* durations;
  INTERPOLATION_STYLE* styles;
  int index = 0;
  int sizeOf;

  // SimpleFade init
  colors = new Color[2] { {255, 0, 0}, {0, 255, 255} };
  durations = new int[2] {500, 500};
  styles = new INTERPOLATION_STYLE[2] { SMOOTH, SMOOTH };
  sizeOf = 2;

  simpleFade.values = colors;
  simpleFade.duration = durations;
  simpleFade.style = styles;
  simpleFade.timeBegan = 0;
  simpleFade.index = index;
  simpleFade.sizeOf = sizeOf;


  //Flash On and Off init
  colors = new Color[2] { {0, 0, 0}, {200, 200, 200} };
  durations = new int[2] {125, 125};
  styles = new INTERPOLATION_STYLE[2] { ACCELERATE, DECELERATION };
  sizeOf = 2;

  flash.values = colors;
  flash.duration = durations;
  flash.style = styles;
  flash.timeBegan = 0;
  flash.index = index;
  flash.sizeOf = sizeOf;


  int* speeds;

  // SimpleFade servo init
  sizeOf = 3;
  speeds = new int[sizeOf]{ 90, 120, 60 };
  durations = new int[sizeOf] {2000, 2400, 1000};
  styles = new INTERPOLATION_STYLE[sizeOf] { LINEAR, LINEAR, LINEAR};
  

  simpleFade_servo.speeds = speeds;
  simpleFade_servo.durations = durations;
  simpleFade_servo.styles = styles;
  simpleFade_servo.index = index;
  simpleFade_servo.sizeOf = sizeOf;
}
