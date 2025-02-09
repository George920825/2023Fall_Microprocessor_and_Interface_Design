			ORG 0000h
			JMP START ;jump into loop
			ORG 0030h
START:		MOV SP, #32H ;SP = #32H
			MOV R2, #00h
			MOV A, #0xfc ;A = #0xfc
			MOV P2, A ;P2 = A
LOOP:		SETB P1.0 ;set p1.0 to high
			SETB P1.1 ;set p1.1 to high
			MOV R0, #250d ;set the execution times of DELAY1
			CALL DELAY1 ;call DELAY1
			RL A ;left rotate A(left shift)
			MOV P2, A ;set the value of A into P2
			JNB P1.0, PU
			JNB P1.1, PO
			JMP LOOP ;back to LOOP
DELAY1: 	PUSH 00h
			;push the remain times of DELAY1 into stack
			MOV R0, #250d ;set the execution times of DELAY2
			CALL DELAY2 ;call DELAY2
			POP 00h
			;pop the remain times of DELAY1 back to R0
			DJNZ R0, DELAY1 ;loop until R0 is 0
			RET ;return to MARQUEE
DELAY2: 	DJNZ R0, DELAY2 ;loop untie R0 is 0
			RET ;return to DELAY1
DEBOUNCE:   MOV R4, #50 ;move 50 times into R4
DE_500_us:  MOV R3, #250 ;move 250 times into R3
			DJNZ R3, $ ;jump to itself R3 times
			DJNZ R4, DE_500_us ;delay 25ms
			RET ;return to main code
PU:			CALL DEBOUNCE ; call debounce function
			PUSH 0A0h
			INC R2
			JMP LOOP
PO:			CALL DEBOUNCE ; call debounce function
			POP 0A0h
			MOV R0, #250d ;set the execution times of DELAY1
			CALL DELAY1 ;call DELAY1
			DJNZ R2, PO
			END