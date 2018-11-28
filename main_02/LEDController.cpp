#include "LEDController.h"

LEDController::LEDController(int _numLEDs) {
  numLEDs = _numLEDs;

}

LEDController::LEDController() {
  LEDController(0);
}

void LEDController::addLED(LED _led, String _ledName) {
  if (numLEDs <= 0) {
    numLEDs = 1;
    LEDContainer tmp[numLEDs];
    tmp[0] = LEDContainer{_led, _ledName};
    LEDs = tmp;
  }
  else {
    numLEDs++;
    LEDContainer tmp[numLEDs];
    for (int i = 0; i < numLEDs - 1; i++) {
      tmp[i] = LEDs[i];
    }
    tmp[numLEDs - 1] = LEDContainer{_led, _ledName};
    LEDs = tmp;
  }
}

void LEDController::updateLEDs(){
  for(int i = 0; i < numLEDs; i++){
    playBehavior( LEDs[i] );
  }
}

void LEDController::playBehavior(LEDContainer _c) {
  //Find LED index
  //int LEDsIndex = -1;
  Color tmpColor;
  /*
  for (int i = 0; i < numLEDs; i++) {
    if (LEDs[i].ledName == _ledName) {
      LEDsIndex = i;
    }
  }
  // Make sure that the index isn't out of range
  if (LEDsIndex == -1 || LEDsIndex >= numLEDs - 1) return;
  */
  /* Here we know we have an appropriate LED index. */
  
  tmpColor = calcNextColor(_c, _c.behaviors[_c.behaviorIndex]);
  //Update LED color
  _c.led.setCurColor(tmpColor);
}

void LEDController::updateCurrentTime() {
  currentTime = millis();
}

float LEDController::calcPercentComplete( LEDBehavior _b) {
  float percentComplete = currentTime - _b.timeBegan;
  percentComplete = percentComplete / _b.duration[_b.index];
  if (percentComplete >= 100.0f) return 100.0f;
  else if (percentComplete < 0.0f) return 0.0f;
  else return percentComplete;
}

Color LEDController::calcNextColor( LEDContainer _c, LEDBehavior _b) {

  float percentComplete = calcPercentComplete(_b);
  Color tmpColor = Color();

  //Calculate the value based on the style of interpolation requested.
  switch (_b.style[_b.index]) {
    
    case LINEAR:
      tmpColor.r = Interpolator::interpolateLinear( _c.led.getPreviousColor().r,
                   _b.values[_b.index].r,
                   percentComplete);
      tmpColor.g = Interpolator::interpolateLinear( _c.led.getPreviousColor().g,
                   _b.values[_b.index].g,
                   percentComplete);
      tmpColor.b = Interpolator::interpolateLinear( _c.led.getPreviousColor().b,
                   _b.values[_b.index].b,
                   percentComplete);
      break;
      
    case SMOOTH:
      tmpColor.r = Interpolator::interpolateLinear( _c.led.getPreviousColor().r,
                   _b.values[_b.index].r,
                   percentComplete);
      tmpColor.g = Interpolator::interpolateLinear( _c.led.getPreviousColor().g,
                   _b.values[_b.index].g,
                   percentComplete);
      tmpColor.b = Interpolator::interpolateLinear( _c.led.getPreviousColor().b,
                   _b.values[_b.index].b,
                   percentComplete);

      break;
      
    case ACCELERATE:
      tmpColor.r = Interpolator::interpolateLinear( _c.led.getPreviousColor().r,
                   _b.values[_b.index].r,
                   percentComplete);
      tmpColor.g = Interpolator::interpolateLinear( _c.led.getPreviousColor().g,
                   _b.values[_b.index].g,
                   percentComplete);
      tmpColor.b = Interpolator::interpolateLinear( _c.led.getPreviousColor().b,
                   _b.values[_b.index].b,
                   percentComplete);
      break;
      
    case DECELERATION:
      tmpColor.r = Interpolator::interpolateLinear( _c.led.getPreviousColor().r,
                   _b.values[_b.index].r,
                   percentComplete);
      tmpColor.g = Interpolator::interpolateLinear( _c.led.getPreviousColor().g,
                   _b.values[_b.index].g,
                   percentComplete);
      tmpColor.b = Interpolator::interpolateLinear( _c.led.getPreviousColor().b,
                   _b.values[_b.index].b,
                   percentComplete);
      break;
      
      case NONE:
      tmpColor.r = Interpolator::interpolateStepped( _c.led.getPreviousColor().r,
                   _b.values[_b.index].r,
                   percentComplete);
      tmpColor.g = Interpolator::interpolateStepped( _c.led.getPreviousColor().g,
                   _b.values[_b.index].g,
                   percentComplete);
      tmpColor.b = Interpolator::interpolateStepped( _c.led.getPreviousColor().b,
                   _b.values[_b.index].b,
                   percentComplete);
      break;
      
  }/* endSwitch */
  return tmpColor;
}
