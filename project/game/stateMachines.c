/*  stateMachines.c hold 3 state machines
the first three are light pattern and the
fourth one is making a secuence of sound */

#include <msp430.h>
#include "stateMachines.h" 
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "sounds.h"  // sound.h has the defined notes for make a sound secuence.

static int stateR = 0;
static int stateG = 0;


  // state machine for the secuence of the red light.
  void dim25r() {
  if (stateR== 0 || stateR== 1 || stateR== 2) {  // state 0, 1 and 2 turn off the red light 
    Redlight(0);                         // red light off.
    stateR++;
    
  }
  else if (stateR== 3) {                 // state 3 turn on light.
    Redlight(1);                         // red light on .
    stateR = 0;
    }
  }


  void dim50r() {
  if (stateR== 0 || stateR== 1) {        // state 0 and 1 turn off red light.
    Redlight(0);
    stateR++;
  }
  else if (stateR== 2 || stateR== 3) {  // state 2 and 3 turn on red light.
    Redlight(1);
    stateR = 0;
    }
  }

  void dim75r(){
    if (stateR== 0) {                  // only state 0 turn off led red.
    Redlight(0);
    stateR++;
  }
  else if (stateR== 1 || stateR== 2 || stateR== 3) {                                                 Redlight(1);
  stateR = 0;
   
  }
 }

// Switch statement to call the secuence of the red light.
void dimR (){
  static int dimRS = 0;

  switch (dimRS){
  case 1:
    dim25r();
    dimRS++;
    break;

  case 2:
    dim50r();
    dimRS++;
    break;

  case 3:
    dim75r();
    dimRS++;
    break;
  default:
    break;
  }
}
 

  // state machine for the secuence of the green light.
  void dim25g() {
  if (stateG == 0 || stateG == 1 || stateG == 2) {  // state 0, 1 and 2 turn off the green light 
    Greenlight(0);                   // green light off.
    stateG++;
    
  }
  else if (stateG == 3) {           // state 3 turn on green light.
    Greenlight(1);                 // green light on .
    stateG = 0;
    }
  }


  void dim50g() {
  if (stateG == 0 || stateG == 1) {        // state 0 and 1 turn off green light.
    Greenlight(0);
    stateG++;
  }
  else if (stateG == 2 || stateG == 3) {  // state 2 and 3 turn on green light.
    Greenlight(1);
    stateG = 0;
    }
  }

  void dim75g() {
  if (stateG == 0) {                     // only state 0 turn off led green.
    Greenlight(0);
    stateG++;
  }
  else if (stateG == 1 || stateG == 2 || stateG == 3) {                                                Greenlight(1);
    stateG = 0;
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
    dimGS++;
    break;
  default:
    break;
  }
}


   // state machine for combination lights green and red.
  void dim25gr() {
  if (stateG == 0 || stateG == 1 || stateG == 2) {  // state 0, 1 and 2 turn off the green light 
    Greenlight(0);                   // green light off.
    stateG++;
    
  }
  else if (stateR == 3) {           // state 3 turn on green light.
    Redlight(1);                    // red light on .
    stateR = 0;
    }
  }


  void dim50gr() {
  if (stateR == 0 || stateR == 1) {        // state 0 and 1 turn off red light.
    Redlight(0);
    stateR++;
  }
  else if (stateG == 2 || stateG == 3) {  // state 2 and 3 turn on green light.
    Greenlight(1);
    stateG = 0;
    }
  }

  void dim75gr() {
  if (stateG == 0) {                     // only state 0 turn off led green.
    Greenlight(0);
    stateG++;
  }
  else if (stateR == 1 || stateR == 2 || stateR == 3) {                                                Redlight(1);                         // state 1, 2 and 3 turn on red light.
    stateR = 0;
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
    dimGRS++;
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
