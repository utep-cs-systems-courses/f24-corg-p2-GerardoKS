#include <msp430.h>
#include "timerLib/libTimer.h"
#include "SwitchControl.h"

void main(void){
  switch_p1_init();
  switch_p2_init();
  wdt_init();
  or_sr(0x18);  // CPU off, GIE on
}
