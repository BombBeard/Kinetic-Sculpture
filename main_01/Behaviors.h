#include "LEDController.h"

struct servoBehavior{
  int* speeds;
  int* durations;
  INTERPOLATION_STYLE* styles;
  int index;
  int sizeOf;
};

class Behaviors {

  public:
    LEDBehavior simpleFade;
    LEDBehavior flash;

    servoBehavior simpleFade_servo;

    Behaviors();

};
