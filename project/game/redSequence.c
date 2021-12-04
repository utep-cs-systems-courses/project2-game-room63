#include "led.h"
#include "stateMachines.h"
int  Redstate = 1;
void redSequence(){

  switch (Redstate) {
    
  case 1:
    dim25r(); // dimming red light 25%
    Redstate++;
    break;
     
  case 2:
    dim50r(); // dimming red light 50%
    Redstate++;
    break;
      
  case 3:
    dim75r(); // dimming red light 75%
    Redstate = 1;
    break;
  default:
    break;

    
  }
}
