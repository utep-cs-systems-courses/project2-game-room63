/*  stateMachines.c hold 3 state machines
the first three are light pattern and the
fourth one is making a secuence of sound */

#include <msp430.h>
#include "stateMachines.h" 
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "sounds.h"  // sound.h has the defined notes for make a sound secuence.

int stateR = 0;               // 
int stateG = 0;              //

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

void dim100r() {                      // turn led red on all four states.
  Redlight(1);
  stateR = 0;
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
  else if (stateG == 1 || stateG == 2 || stateG == 3) {                                                   Greenlight(1);
    stateG = 0;
    }
}

void dim100g() {                        // turn led green on all four states.
  Greenlight(1);
  stateG = 0;
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
  else if (stateR == 1 || stateR == 2 || stateR == 3) {                                             Redlight(1);                         // state 1, 2 and 3 turn on red light.
    stateR = 0;
    }
}

void dim100gr() {                        // turn led green on all four states.
  Greenlight(1);
  stateG = 0;
}




// state machine for the sound secuence.
void sound(){
  static char Csound = 0;

  // array of the sound sequence.
  int sound[9] = {Dsharp, F, Fsharp, Gsharp, A, B, Cn, D, Dsharp };
  int s = 9; 

  // this if statmentent iterate through the sound secuence.
  if(Csound < s){
    buzzer_set_period(sound[Csound]);
    Csound++;
    
}
  else{
    Csound = 0;
  }
}


