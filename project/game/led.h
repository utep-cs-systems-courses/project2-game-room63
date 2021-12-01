#ifndef led_included
#define led_included

#define LED_RED BIT0               // P1.0
#define LED_GREEN BIT6             // P1.6
#define LEDS (BIT0 | BIT6)


void led_init();
void led_update();
void Redlight( int on);
void Greenlight(int on);
void led_on(int on);
void changeC(int on);

#endif // included
