//Alternate LEDs from Off, Green, and Red
#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "LightHandler/PulsingLights.h"
#include "LightHandler/stateMachine.h"
#include "SoundHandler/SoundSetUp.h"
#include "SoundHandler/MarryHadALittleLamb.h"

int P13Handler(void) {
  led_init();
  timeAdvStateMachine();
  sound_init();
  play();
}
