COMMON_OBJECTS = 
CPU            = msp430g2553
CFLAGS         = -mmcu=${CPU} -I../h
LDFLAGS	       = -L/opt/ti/msp430_gcc/include

CC	       =	 msp430-elf-gcc


all: led.elf

led.elf: ${COMMON_OBJECTS} game_main.o stateMachines.o p2_interrupt_handler.o wdInterruptHandler.o led.o buzzer.o switches.o
	${CC} ${CFLAGS} ${LDFLAGS} -o  $@ $^ ../lib/libTimer.a

load: led.elf
	msp430loader.sh led.elf



clean:
	 rm -f *.o *.c~ *.c# *~ *.elf .h~

p2_interrupt_handler.o:		switches.h
game_main.o:			led.h switches.h
buzzer.o:			buzzer.h
led.o:				led.h led.c
wdInterrumptHandler.o: 		buzzer.h led.h stateMachines.h switches.h
switches.o: 			switches.h led.h
