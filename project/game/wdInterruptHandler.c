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
  
  // blink_count % 63) == 0 && pAgain == 1
  if ((blink_count % 63) == 0 && pAgain == 1) {
    buzzer_set_period(0); // turn of completly the sound of sound();
    led_update();
    sound();  // secuence of sounds.x
    blink_count = 0;
    
  }
  /*
  else if ((blink_countR < 125) == 0 && pAgain2 == 1){
     if(blink_countR < 125){
    
       blink_countR = 0;
    }
     
    else if (blink_countR < 500){
      dim50r();
      blink_countR = 0;
    }
    else if (blink_countR < 750){
      dim75r();
      blink_countR++;
      }
      
  }
  */
  // state machine using the red LED.
  if ((blink_countR % 63) == 0 && pAgain2 == 1){
    // led_update();
       
  // if (blink_count < 63){
      //dimR(); // switch statment for red light.
  //   dim25r();
       
  //}
    
  //else if ( blink_count < 125){
  //  dim50r();
    
  //}
  //else if (blink_count < 188){
    led_update();
    redSequence();
    blink_countR = 0;
  }

  
  // state machine using gren LED.
  else if ((blink_count % 125) == 0 && pAgain3 == 1){
    led_update();
         
    if (blink_count < 63){
      //dimG(); // switch statment for green light.
      //led_update();
      dim25g();
    }
    else if ( blink_count < 125){
      dim50g();
    }
    else if (blink_count < 188){
      dim75g();
    }
  
    //dimG(); // switch statment for green light.
     blink_count = 0;
  }

  
  /*  
  // state machine combination of green and red LED.
  else if ((blink_count % 250) == 0 && pAgain4 == 1){
    led_update();
    
     dimGR(); // switch statment for green and red light.
     blink_count = 0;
  }
  
  */  

}
