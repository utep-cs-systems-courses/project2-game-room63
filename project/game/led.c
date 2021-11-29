#include <msp430.h>
#include "led.h"
#include "switches.h"


void Redlight(int on)
{
  // 0 means off light 
  if(on == 0)
    {
      P1OUT &= ~LED_RED;  //turn off red LED.
    }
  // else 1 on light 
  else if (on == 1){
    P1OUT |= LED_RED;     // turn on red LED.
  }
}


void Greenlight(int on)
{
  // 0 means off light.
  if(on ==0)
    {
      P1OUT &= ~LED_GREEN; // turn off green LED.
    }
  // else 1 on light.
  else if (on == 1){
    P1OUT |= LED_GREEN;  //turn on gren LED.
   }
  }
  
void led_init()
{
 
  P1DIR |= LEDS;                // bits attached to leds are output.
  
  led_update();       // call led_update function.
}

void led_update()
{
  // Initialize LED as an off light.
  P1OUT &= ~LEDS;
}

void led_on(int on)
{
  if( on == 0)
    {
     P1OUT &= ~LEDS;
    }
  else if ( on == 1)
    {
      P1OUT |= LEDS;
    }
}
