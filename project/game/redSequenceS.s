	.arch msp430g2553
	.p2align 1, 0

	.data
redState:	.word 0
	.text
	.extern dim25r 		;dimining 25% on red LED.
	.extern dim50r 		;dimining 50% on red LED.
	.extern dim75r		;dimining 75% on red LED.
	.global redSequence
redSequence:
	cmp #1, &redState
	jl case_1 		;case 1 from redSecuence.
	cmp #2, &redState
	jl case_2		;case 2 from redSecuence.
	cmp #3, &redState
	jl case_3 		;case 3 from red secuence.
case_1:
	call #dim25r
	add #1, &redState
	jmp out
case_2:
	call #dim50r
	add #1, &redState
	jmp out
case_3:
	call #dim75r
	mov #0, &redState
	jmp out
out:
	pop r0
