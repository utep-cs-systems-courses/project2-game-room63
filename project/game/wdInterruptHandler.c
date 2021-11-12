#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches"


// variables to indicate times that button is push.
pAgain = 0;
pAgain2 = 0;
pAgain3 = 0;
pAgain4 = 0;


void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static int  blink_count = 0;

  bink_count++;
  if ((blink_count%50) ==0 && pAgain ==1) {
    led_update();
    sound();
  }
}
