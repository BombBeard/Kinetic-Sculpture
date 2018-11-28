#include "Interpolator.h"
#include <math.h>


/* Basic reference for interpolation formulas
   found @:  https://codeplea.com/simple-interpolation
*/

int Interpolator::interpolateLinear(int source, int target, float percentComplete) {
  int tmp = source + (percentComplete * ( target - source ));
  return tmp;
}
int Interpolator::interpolateSmooth(int source, int target, float percentComplete) {
  float tmp = (percentComplete * percentComplete) * ( 3 - ( 2 * percentComplete ) );
  return interpolateLinear( source, target, tmp );
}
int Interpolator::interpolateAccelerate(int source, int target, float percentComplete) {
  float tmp = ( percentComplete * percentComplete );
  return interpolateLinear( source, target, tmp );
}
int Interpolator::interpolateDecelerate(int source, int target, float percentComplete) {
  //Factored polynomial from website
  float tmp = ( 1 - ( ( percentComplete * percentComplete ) - ( 2 * percentComplete ) + 1 ) );
  return interpolateLinear( source, target, tmp );
}
int Interpolator::interpolateStepped(int source, int target, float percentComplete){
  if(percentComplete < .5f) return source;
  else if(percentComplete >= .5f) return target;
}

float Interpolator::calcPercentComplete( int timeStarted, int timeCurrent ){
  float result;
  
}

