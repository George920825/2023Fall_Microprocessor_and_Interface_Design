			ORG 00H ; code start from 000h
			SJMP MAIN ; jump to MAIN
			ORG 03H ; vector address for INT0
			SJMP INT0_ISR ; jump to INT0_ISR
			ORG 13H ; vector address for INT0
			SJMP INT1_ISR ; jump to INT0_ISR
			ORG 030H ;after vector table space
MAIN: 		MOV IE, #10000101B ; enable EA and EX0
			MOV SP, #30H ; stack start from #30H
			CLR IT0 ; low edge-triggered
			CLR IT1 ; low edge-triggered
			SETB IP.2 ; INT1 priority
			MOV A, #00000000B ; set ACC as 0000000B
LOOP: 		MOV P2, A ; P1 = A(LED output)
			CALL DELAY ; call delay function
			CPL A ; reverse A
			SJMP LOOP ; infinite loop
INT0_ISR: 	PUSH PSW ; push PSW into stack
			PUSH ACC ; push ACC into stack
			SETB RS0 ; switch to RB1
			MOV A, #11110000B ; set ACC as 11111110B
			MOV R0,#24 ; loop counter = 24
ROTATE_1: 	MOV P2, A ; P1 = A(LED output)
			CALL DELAY ; call delay function
			RL A ; rotate left
			DJNZ R0, ROTATE_1 ; loop until R0 is 0
			CLR RS0 ; switch to RB0
			CLR RS1 ; switch to RB0
			POP ACC ; pop out ACC from stack
			POP PSW ; pop out PSW from stack
			RETI ; return from ISR
INT1_ISR: 	PUSH PSW ; push PSW into stack
			PUSH ACC ; push ACC into stack
;			PUSH 08H
			CLR RS0 ; switch to RB2
			SETB RS1 ; switch to RB2
			MOV A, #11111110B ; set ACC as 11111110B
			MOV R0,#16 ; loop counter = 16
ROTATE_2: 	MOV P2, A ; P1 = A(LED output)
			CALL DELAY ; call delay function
			RL A ; rotate left
			DJNZ R0, ROTATE_2 ; loop until R0 is 0
			CLR RS0 ; switch to RB0
			CLR RS1 ; switch to RB0
;			POP 08H
			POP ACC ; pop out ACC from stack
			POP PSW ; pop out PSW from stack
			RETI ; return from ISR
DELAY: 		MOV R7, #200
D1: 		MOV R6, #250
			DJNZ R6, $
			DJNZ R7, D1
			RET ; return
			END ; end the code