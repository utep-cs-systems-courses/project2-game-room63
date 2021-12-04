#ifndef led_included
#define led_included

//Major bug fixing with lights since
//The old version of MSP430 have the ports like that.
#define LED_RED BIT6               // P6.0
#define LED_GREEN BIT0             // P0.6
#define LEDS (BIT0 | BIT6)


void led_init();
void led_update();
void Redlight( int on);
void Greenlight(int on);
void led_on(int on);
void changeC(int on);

#endif // included
