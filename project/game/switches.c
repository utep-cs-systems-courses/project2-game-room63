#include <msp430.h>
#include "switches.h"
#include "led.h"


// variables for pressing button 1,2,3 and 4 from the msp430  
pressB1 =0;   // Pressing button 1.
pressB2 =0;   // Pressing button 2.
pressB3 =0;   // Pressing button 3.
pressB4 = 0;  // Pressing button 4.

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  led_update();
}

void
switch_interrupt_handler()
{
  char p2val = switch_update_interrupt_sense();

  int CHbutton1 = pressB1;
  int CHbutton2 = pressB2;
  int CHbutton3 = pressB3;
  int CHbutton4 = pressB4;

  pressB1 =( p2val & SW1) ? 0 : 1;
  pressB2 =( p2val & SW2) ? 0 : 1;
  pressB3 =( p2val & SW3) ? 0 : 1;
  pressB4 =( p2val & Sw4) ? 0 : 1;
  

  if(Chbutton1 !=  pressB1 && pressB1){
    pAgain ^= 1;
  
    pAgain2 = 0, pAgain3 = 0, pAgain4 = 0;
  
    }
 else if(Chbutton2 !=  pressB2 && pressB2){
    pAgain2^= 1;
  
    pAgain = 0, pAgain3 = 0, pAgain4 = 0;
    }
else if(Chbutton3 !=  pressB3 && pressB3){
    pAgain3^= 1;
  
    pAgain = 0, pAgain2 = 0, pAgain4 = 0;
    }
else if(Chbutton4 !=  pressB4 && pressB4){
    pAgain4^= 1;
  
    pAgain = 0, pAgain2 = 0, pAgain3 = 0;
    }
