COMMON_OBJECTS = game_main.o
CPU            = msp430g2553
CFLAGS         = -mmcu=${CPU} -I../h
LDFLAGS 	= -L/opt/ti/msp430_gcc/include


CC	       = msp430-elf-gcc
AS 	       = msp430-elf-as

all: led.elf

led.elf: ${COMMON_OBJECTS} game_main.o stateMachines.o p2_interrupt_handler.o wdInterruptHandler.o led.o buzzer.o switches.o redSequence.o greenSequence.o
	${CC} ${CFLAGS} ${LDFLAGS} -o  $@ $^ ../lib/libTimer.a

led2.elf: ${COMMON_OBJECTS} game_main.o stateMachines.o p2_interrupt_handler.o wdInterruptHandler.o led.o buzzer.o switches.o redSequenceS.o greenSequence.o
	${CC} ${CFLAGS} ${LDFLAGS} -o  $@ $^ ../lib/libTimer.a

load: led.elf
	msp430loader.sh led.elf

load2: led2.elf
	msp430loader.sh led2.elf

clean:
	 rm -f *.o *.c~ .h~ *~ *.c# *.elf

greenSequence.o: stateMachines.o led.h

redSequence.o: stateMachines.o led.h

redSequenceS.o: stateMachines.o led.h

stateMachines.o: stateMachines.h buzzer.h sounds.h switches.h led.h

p2_interrupt_handler.o:	switches.h

game_main.o: led.h switches.h led.h

buzzer.o: buzzer.h

led.o: led.c led.h 

wdInterrumptHandler.o: buzzer.h led.h stateMachines.h switches.h

switches.o: switches.h led.h
