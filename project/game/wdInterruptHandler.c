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
  static int  blink_countR = 0;
  blink_count++;
  blink_countR++;
  redSequence(0); // The switch statemment that I try to run on button 4.
  led_on(0); // to turn in on LED green and red.    
  //changeC(0); 
  if ((blink_count % 63) == 0 && pAgain == 1) {
    buzzer_set_period(0); // turn of completly the sound of sound();
    led_update();
    sound();  // secuence of sounds is on stateMachines.c
    led_on(1);
    blink_count = 0;
    
  }// end of if-statement.
  
   if ((blink_countR % 8 == 0) && pAgain2 == 1){
     led_update();
     // dim25r();
     // led_on(1);
     Greenlight(1); // for some reason it turn on the red LED.
     Redlight(1); // // for some reason it turn on the green LED.
     // changeC(1);
     //redSequence();
    blink_count = 0;
    // sound();
      
  }// end of if-statement.

   
  
  // state machine using the red LED.
  if ((blink_countR % 63) == 0 && pAgain3 == 1){
    buzzer_set_period(0); // turn of completly the sound of sound();
    led_update();
    sound2();  // secuence of sounds.
    blink_count = 0;
  }// end of if-statement.

  if ((blink_countR % 63 == 0) == 0 && pAgain4 == 1){
    led_update();
    redSequence(); // switch statement that hold all the switch corresponding to RED LED
                   // redSequence.c
    blink_countR = 0;
  }// end of if-statement.
  
} // end of interrupt.
