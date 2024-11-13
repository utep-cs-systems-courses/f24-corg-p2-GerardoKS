#include <msp430.h>
#include "../../timerLib/libTimer.h"
#include "SoundSetUp.h"
#include "MarryHadALittleLamb.h"

void play(){
  static int currentNote = 0;
  static int countTicks = 0;
  if(countTicks == duration[currentNote]){
    countTicks = 0;
    currentNote ++;
    if(currentNote == 52)
      currentNote = 0;
  }else{
    countTicks++;
    set_period(note[currentNote]);
  }
}



