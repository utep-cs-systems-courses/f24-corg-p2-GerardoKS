#include <msp430.h>
#include "../../timerLib/libTimer.h"
#include "led.h"

void GreenOn(){
  P1DIR |= LEDS;
  P1OUT &= ~LED_RED;
  P1OUT |= LED_GREEN;
}

void RedOn(){
  P1DIR |= LEDS;
  P1OUT &= ~LED_GREEN;
  P1OUT |= LED_RED;
}
