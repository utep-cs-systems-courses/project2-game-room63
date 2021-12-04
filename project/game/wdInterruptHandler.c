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
void __interrupt_vec(WDT_VECTOR) WDT(){	/* 250 interrupts/sec */

  static int  blink_count = 0;         /* counter of blink timeson the MSP-430 */
  static int  blink_countR = 1;
  static int   blink_countG = 1;
  blink_countR++; // counter for the redSequence() function.
  blink_count++; // counter for the sound() adn sound2() functions.
    
  if ((blink_count % 63) == 0 && pAgain == 1) {
    buzzer_set_period(0); // turn of completly the sound of sound();
    led_update();
    sound();  // secuence of sounds is on stateMachines.c
    blink_count = 0;
    
  }// end of if-statement.
  // need it to press four times to see the different light dimming.
  else if ((blink_countG % 125) && pAgain2 == 1){
    led_update();
    greenSequence();
    blink_countG = 1;
   
      
  }// end of if-statement.

    
  // state machine using the red LED.
   else if ((blink_count % 63) == 0 && pAgain3 == 1){
    buzzer_set_period(0); // turn of completly the sound of sound();
    led_update();
    sound2();  // secuence of sounds.
    blink_count = 0;
  }// end of if-statement.

   else if ((blink_count % 125) == 0 && pAgain4 == 1){
    led_update();
    redSequence();
    blink_countR = 1;
  }// end of if-statement.

} // end of interrupt.
