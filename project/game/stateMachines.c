#include <msp430.h>
#include "stateMachines.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "sounds.h"

int stateR = 0;               // 
int stateG = 0;              //

void dim25r() {
  if (stateR== 0 || stateR== 1 || stateR== 2) {  // state 0, 1 and 2 turn off the red light 
    Redlight(0); // red light off.
    stateR++;
    
  }
  else if (stateR== 3) {       // state 3 turn on light.
    Redlight(1); // red light on .
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
  else if (stateR== 1 || stateR== 2 || stateR== 3) {                                                 RedLight(1);
    stateR = 0;
   
  }
}

void dim100r() {            // turn led red on all four states.
  Redlight(1);
  stateR = 0;
}



void dim25g() {
  if (stateG == 0 || stateG == 1 || stateG == 2) {  // state 0, 1 and 2 turn off the green light 
    Greenlight(0); // green light off.
    stateG++;
    
  }
  else if (stateG == 3) {       // state 3 turn on green light.
    Greenlight(1); // green light on .
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
  if (stateG == 0) {                  // only state 0 turn off led green.
    Greenlight(0);
    stateG++;
  }
  else if (stateG == 1 || stateG == 2 || stateG == 3) {                                                   GreenLight(1);
    stateG = 0;
    }
}

void dim100g() {            // turn led green on all four states.
  Greenlight(1);
  stateG = 0;
}


void sound(){
  static char Csound = 0;
  int size = 9;

  // array of the sound sequence.
  int sound[size] = {Dsharp, F, Fsharp, Gsharp, A, B, Cn, D, Dsharp };
  int s = size;

  if(Csound < s){
    buzzer_set_period(sound[Csound]);
    Csound++;
    
}
  else{
    Csound = 0;
  }
}


