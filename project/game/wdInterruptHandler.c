#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "buzzer.h"
#include "switches.h"

// variables to indicate times that button is push.
int  pAgain = 0;
int  pAgain2 = 0;
int  pAgain3 = 0;
int  pAgain4 = 0;

void __interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  static int  blink_count = 0;         /* counter of blink timeson the MSP-430 */

  blink_count++;
  
  if ((blink_count % 63) == 0 && pAgain == 1) {
    led_update();
    sound();  // secuence of sounds.
    blink_count = 0;
    
  }
  
  // state machine using the red LED.
  else if ((blink_count % 125) == 0 && pAgain2 == 1){
    led_update();
    dimR(); // switch statment for red light.
    blink_count = 0;
  }
  
  // state machine using gren LED.
  else if ((blink_count % 188) == 0 && pAgain3 == 1){
    led_update();
    dimG(); // switch statment for green light.
    blink_count = 0;
  }

 
  // state machine combination of green and red LED.
  else if ((blink_count % 250) == 0 && pAgain4 == 1){
     led_update();
     dimGR(); // switch statment for green and red light.
     blink_count = 0;
  }

  
}
