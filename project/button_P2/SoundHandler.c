#include <msp430.h>
#include "../timerLib/libTimer.h"
#include "SingleSoundHandler/SingleSoundSetUp.h"
#include "SingleLightHandler/led.h"
static int count = 0;
static int limit = 0;
int SingleSound(char buttonPressed) {
  single_sound_init();
  if(!(buttonPressed & BIT3)){
    set_single_period(a);
    GreenOn();
  }
  else if(!(buttonPressed & BIT2)){
    set_single_period(f);
    if(count >= limit){   
      RedOn();
      count = 0;
      limit ++;
    }
    else
      P1OUT &= ~LED_RED;
  }
  else if(!(buttonPressed & BIT1)){
    set_single_period(e);
    if(count >= limit){   
      GreenOn();
      count = 0;
      limit ++;
    }
    else
      P1OUT &= ~LED_GREEN;
  }
  else if(!(buttonPressed & BIT0)){
    set_single_period(d);
    RedOn();
  }
  if(limit >= 15)
    limit = 0;
}
