#include <msp430.h>
#include "timerLib/libTimer.h"
#include "button_P13/Button_P13Handler.h"
#include "button_P2/SoundHandler.h"

#define SW13 BIT3
#define SW20 BIT0
#define SW21 BIT1
#define SW22 BIT2
#define SW23 BIT3

#define SWITCHESP1 SW13
#define SWITCHESP2 SW20 | SW21 | SW22 | SW23


void switch_p1_init() {
  P1REN |= SWITCHESP1;/* enables resistors for switches */
  P1IE |= SWITCHESP1;/* enable interrupts from switches */
  P1OUT |= SWITCHESP1;/* pull-ups for switches */
  P1DIR &= ~SWITCHESP1;/* set switches' bits for input */
}

void switch_p2_init() {
  P2REN |= SWITCHESP2;/* enables resistors for switches */
  P2IE |= SWITCHESP2;/* enable interrupts from switches */
  P2OUT |= SWITCHESP2;/* pull-ups for switches */
  P2DIR &= ~SWITCHESP2;/* set switches' bits for input */
}

void wdt_init() {
  configureClocks();/* setup master oscillator, CPU & peripheral clocks */
  enableWDTInterrupts();/* enable periodic interrupt */
}

static int P13buttonDown;

void switchP1_interrupt_handler()
{
  char p1val = P1IN;/* switch is in P1 */

  /* update switch interrupt sense to detect changes from current buttons */
  P1IES |= (p1val & SWITCHESP1);/* if switch up, sense down */
  P1IES &= (p1val | ~SWITCHESP1);/* if switch down, sense up */

  if (p1val & SWITCHESP1) {/* button up */
    P13buttonDown = 0;
  } else {/* button down */
    P13buttonDown = 1;
  }
}

static int P2buttonDown;
static char buttonPressed;
void switchP2_interrupt_handler()
{
  char p2val = P2IN;/* switch is in P2 */
  buttonPressed = p2val;
  /* update switch interrupt sense to detect changes from current buttons */
  P2IES |= (p2val & SWITCHESP2);/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHESP2);/* if switch down, sense up */

  if (p2val & SWITCHESP2) {/* button up */
    P2buttonDown = 0;
  } else {/* button down */
    P2buttonDown = 1;
  }
}


/*Switch on P1 (S2) */
void __interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & SWITCHESP1) {      /* did a button cause this interrupt? */
   P1IFG &= ~SWITCHESP1;      /* clear pending sw interrupts */
   switchP1_interrupt_handler();/* single handler for all switches */
  }
}

/*Switch on P2 (S2) */
void __interrupt_vec(PORT2_VECTOR) Port_2(){
 if(P2IFG & SWITCHESP2){
    P2IFG &= ~SWITCHESP2;
    switchP2_interrupt_handler();
 }
}

static int count = 0;
void __interrupt_vec(WDT_VECTOR) WDT()/* 250 interrupts/sec */
{
  if(!P2buttonDown){
    SingleSound(buttonPressed);
  }
  if(count >= 12500){
    P13Handler();
    count = 0;
  }else{
    count ++;
  }
} 
/*
static int check = 1;
static int count = 0 ;
*/
//void __interrupt_vec(WDT_VECTOR) WDT()/* 250 interrupts/sec */
/*{
  if(check){
    check = 0;
    P13Handler();
  }
    if(!P2buttonDown)
    SingleSound(buttonPressed);
    else{
    if(count == 12500){
      count = 0;
      P13Handler();
    }
    count ++;
    }*/
 
