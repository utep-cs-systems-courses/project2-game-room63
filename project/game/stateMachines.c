/*  stateMachines.c hold 3 state machines
the first three are light pattern and the
fourth one is making a secuence of sound */

#include <msp430.h>
#include "stateMachines.h" 
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "sounds.h"  // sound.h has the defined notes for make a sound secuence.

static int stateR = 0; // state red.
static int stateG = 0; // state green.
static int stateGR = 0; // state green & red.


  // state machine for the secuence of the red light.
  void dim25r() {
    /* Switch statment to dimming the red LED 25%
     stateR stands for state Red*/

    switch(stateR){

    case 1:
      Redlight(0); // red LED off.
      stateR++; 
    case 2:
      stateR++;
    case 3:
      stateR++;
      break;     // red LED is off until the break.
    case 4:
      Redlight(1); // red LED on.
      stateR = 0;       
      break;
    default:
      break;
    }
  }


  void dim50r() {
    /* Switch statment to dimming the red LED 50%
     stateR stands for state Red*/

    switch(stateR){

    case 1:
      Redlight(1); //red LED on.
      stateR++;
      break;
    case 2:
      Redlight(0); // red LED off.
      stateR++;
      break;
    case 3:
      stateR++;
      break;
    case 4:
      Redlight(1); // red LED on.
      stateR = 0;
      break;
    default:
      break;
    }
  }

  void dim75r(){
    /* Switch statment to dimming the red LED 75%
     stateR stands for state Red*/
    
    switch(stateR){

    case 1:
      Redlight(0);  // red LED is off.
      stateR++;
      break;
    case 2:
      stateR++;
      break;
    case 3:
      stateR++;
      break;
    case 4:
      Redlight(1); // red LED is on.
      stateR = 0;
      break;
    default:
      break;
    }
 }

  // state machine for the secuence of the green light.
  void dim25g() {
    /* Switch statment to dimming the green LED 25%
     stateG stands for state Green*/
    
    switch(stateG){

    case 1:
      Greenlight(0);  // green led off.
      stateG++;
    case 2:
      stateG++;
    case 3:
      stateG++;
      break;
    case 4:
      Greenlight(1);  // green led on.
      stateG = 0;
      break;
    default:
      break;
    }
    
  }


  void dim50g() {
     /* Switch statment to dimming the green LED 50%
     stateG stands for state Green*/

    switch(stateG){

    case 1:
      Greenlight(1);  // green led on.
      stateG++;
      break;
    case 2:
      Greenlight(0); // green led off.
      stateG++;
      break;
    case 3:
      stateG++;
      break;
    case 4:
      Greenlight(1); // green led on.
      stateG = 0;
      break;
    default:
      break;
    }
  }

  void dim75g() {
     /* Switch statment to dimming the green LED 75%
     stateG stands for state Green*/

    switch(stateG){

    case 1:
      Greenlight(0); // green led off.
      stateG++;
      break;
    case 2:
      stateG++;
      break;
    case 3:
      stateG++;
      break;
    case 4:
      Greenlight(1); // red led on.
      stateG = 0;
      break;
    default:
      break;
    }
  }

// Switch statement to call the secuence of the green light.
void dimG (){
  static int dimGS = 0;
  switch (dimGS){
  case 1:
    dim25g();
    dimGS++;
    break;

    
  case 2:
    dim50g();
    dimGS++;
    break;

  case 3:
    dim75g();
    dimGS = 0;
    break;
  default:
    break;
  }
}


   // state machine for combination lights green and red.
  void dim25gr() {

    
    switch(stateGR){

    case 1:
      changeC(0);  
      stateGR++;
    case 2:
      stateGR++;
    case 3:
      stateGR++;
      break;
    case 4:
      changeC(1); 
      stateGR = 0;
      break;
    default:
      break;
    }
    
  }


  void dim50gr() {

    switch(stateGR){

    case 1:
      changeC(1);  
      stateGR++;
      break;
    case 2:
      changeC(0); 
      stateGR++;
      break;
    case 3:
      stateGR++;
      break;
    case 4:
      changeC(1); 
      stateGR = 0;
      break;
    default:
      break;
    }

  }

  void dim75gr() {

    switch(stateGR){

    case 1:
      changeC(0);
      stateGR++;
      break;
    case 2:
      stateGR++;
      break;
    case 3:
      stateGR++;
      break;
    case 4:
      changeC(1);
      stateGR = 0;
      break;
    default:
      break;
    }
  }

// Switch statement to call the secuence of the green and red light.
void dimGR (){
  static int dimGRS = 0;

  switch (dimGRS){
  case 1:
    dim25gr();
    dimGRS++;
    break;

  case 2:
    dim50gr();
    dimGRS++;
    break;

  case 3:
    dim75gr();
    dimGRS = 0;
    break;
  default:
    break;
  }
}  


  // state machine for the sound secuence.
  void sound(){
    static char Csound = 0; // current sound.

  // array of the sound sequence.
  int sound[9] = {Dsharp, F, Fsharp, Gsharp, A, B, Cn, D, Dsharp };

  // varaible to iterate into the below if statement.
  int s = 9; // sound.

  // this if statmentent iterate through the sound secuence.
  if(Csound < s){  // Csound variable hold the current sound.
    buzzer_set_period(sound[Csound]);
    Csound++;
  }
  else{
    Csound = 0; // Set current sound to 0.
  }
  }


  // state machine for the sound secuence.
  void sound2(){
    static char Csound = 0; // current sound.

  // array of the sound sequence. 
  int sound[9] = {Dsharp, D, Cn, B, A, Gsharp, Fsharp, F, Dsharp };

  // varaible to iterate into the below if statement.
  int s = 9; // sound.

  // this if statmentent iterate through the sound secuence.
  if(Csound < s){  // Csound variable hold the current sound.
    buzzer_set_period(sound[Csound]);
    Csound++;    
  }
  else{
    Csound = 0; // Set current sound to 0.
  }



  
}
