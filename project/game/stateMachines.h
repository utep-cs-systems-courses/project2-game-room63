#ifndef stateMachine_included
#define stateMachine_included

 // Red LED.
 void dim25r();
 void dim50r();
 void dim75r();

 // Green LED.
 void dim25g();
 void dim50g();
 void dim75g();
 void dimG();// switch statement of green light.

// external switch statements to call dimming sequences.
void redSequence();
void greenSequence();

 // Secuence of sounds.
void sound(); // normal sond sequence.
void sound2(); // backward sound sequence.


#endif // included

