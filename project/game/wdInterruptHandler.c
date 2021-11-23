#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"


// variables to indicate times that button is push.
   int pAgain = 0;
   int pAgain2 = 0;
   int pAgain3 = 0;
   int pAgain4 = 0;



void
__interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */
  static int  blink_count = 0;         /* counter of blink timeson the MSP-430 */

  blink_count++;
  if ((blink_count % 250) == 0 && pAgain == 1) {
    led_update();
    sound();
  }
  // state machine using the red LED.
  else if ((blink_count % 500) == 0 && pAgain2 == 2){
    led_update();
     dim25r();
     dim50r();
     dim75r();
     dim100r();
  }
  // state machine using gren LED.
  else if ((blink_count % 750) == 0 && pAgain3 == 3){
    led_update();
     dim25g();
     dim50g();
     dim75g();
     dim100g();
  }
  // state machine combination of green and red LED.
  else if ((blink_count % 1000) == 0 && pAgain == 4){
    led_update();
     dim25gr();
     dim50gr();
     dim75gr();
     dim100gr();
  }
}
