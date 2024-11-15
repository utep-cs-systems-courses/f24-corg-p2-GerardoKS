
#include <msp430.h>
#include "PulsingLights.h"

void led_init(){
  P1DIR |= LEDS;
}

void Control(int on){
  if(on)
    P1OUT |= LEDS;
  else
    P1OUT &= ~LEDS;
}

static int blinkCount = 0;
static int blinkLimit = 5;
void blinkUpdate(){
  blinkCount ++;
  if(blinkCount >= blinkLimit){
    blinkCount = 0;
    Control(1);
  }
  else{
    Control(0);
  }
}


void oncePerSecond(){
  blinkLimit ++;
  if(blinkLimit >= 12)
    blinkLimit = 0;
}

static int secondCount = 0;
void secondUpdate(){
  secondCount ++;
  if(secondCount >= 250){
    secondCount = 0;
    oncePerSecond();
  }
}


