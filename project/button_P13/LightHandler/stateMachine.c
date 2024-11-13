#include <msp430.h>
#include "stateMachine.h"
#include "PulsingLights.h"


void timeAdvStateMachine()/* alternate between toggling red & green */
{
  blinkUpdate();
  secondUpdate();
}
