#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "switches.h"
#include "led.h"

int main (void)
{
  buzzer_init();
  led_init();
  switch_init();
  enableWDTInterrupt(); /* enable periodic interrupt */
  configureClocks();     /* setup master oscillator, CPU & peripheral clocks */

  or_sr(0x18);         /* CPU off, GIE on */
}

