#include "led.h"
#include "stateMachines.h"


void redSequence(){
  
  static int redState = 0;

  switch (redState) {
    
  case 1:
    dim25r(); // dimming red light 25%
    redState++;
    break;
     
  case 2:
    dim50r(); // dimming red light 50%
    redState++;
    break;
      
  case 3:
    dim75r(); // dimming red light 75%
    redState = 0;
    break;
  default:
    break;

    
  }
}
