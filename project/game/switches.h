#ifndef switches_included
#define switches_included

#define SW1 BIT0 /* switch 1 is p2.0 */
#define SW2 BIT1 /* switch 2 is p2.1 */
#define SW3 BIT2 /* switch 3 is p2.2 */
#define SW4 BIT3 /* switch 4 is p2.3 */

#define SWITCHES (SW1 | SW2 | SW3 | SW4)  /* the four switches */

void switch_init();
void switch_interrupt_handler();

extern int pressB1,pressB2, pressB3, pressB4;
extern int  pAgain, pAgain2, pAgain3, pAgain4; 

#endif // included
