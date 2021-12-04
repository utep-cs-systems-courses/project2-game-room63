#include "led.h"
#include "stateMachines.h"
int  Greenstate = 1;
void greenSequence(){

  switch (Greenstate) {
    
  case 1:
    dim25g(); // dimming red light 25%
    Greenstate++;
    break;
     
  case 2:
    dim50g(); // dimming red light 50%
    Greenstate++;
    break;
      
  case 3:
    dim75g(); // dimming red light 75%
    Greenstate = 1;
    break;
  default:
    break;
    
  }
}
