/*  stateMachines.c hold 2 sound sequences
the first one is 9 notes and the secound one
is the same one but backwards, and then the ligh
secuence with green and red light */

#include <msp430.h>
#include "stateMachines.h" 
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "sounds.h"  // sound.h has the defined notes for make a sound secuence.

int stateR = 1; // state red.
int stateG = 1; // state green.


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
      stateR = 1;      
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
      stateR = 1;
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
      stateR = 1;
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
      stateG = 1;
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
      stateG = 1;
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
      Greenlight(1); // green led on.
      stateG = 1;
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
