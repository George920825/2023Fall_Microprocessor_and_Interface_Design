			ORG 0 ; start from 0000H
			MOV DPTR, #TABLE ; DPTR point to TABLE
START:  	MOV R0, #0 ; initialize typed signal
			MOV R1, #4 ; set 4 rows
			MOV R2, #11110111B ; scan first row
			MOV R6, #9
			MOV R7, #7
SCAN: 		MOV A, R2 ; move R2 to A
			MOV P2, A ; input scanned signal
			JNB P2.7, KEYIN ; scan column 1
			INC R0 ; add #001H into R0
			JNB P2.6, KEYIN ; scan column 2
			INC R0 ; add #001H into R0
			JNB P2.5, KEYIN ; scan column 3
			INC R0 ; add #001H into R0
			JNB P2.4, KEYIN ; scan column 4
			INC R0 ; add #001H into R0
			RR A ; next row
			MOV R2, A ; move A to R2
			DJNZ R1, SCAN ; scan 4 rows
			SJMP START ; jump to scan keypad again
KEYIN:  	CALL DEBOUNCE ; call debounce function
			MOV A, R0 ; get typed signal
			SUBB A, #3
			JZ ADDER
			SUBB A, #4
			JZ SUBER
			SUBB A, #4
			JZ MULER
			SUBB A, #4
			JZ DIVER
			
;			MOVC A, @A+DPTR ; get signal from TABLE
;			MOV P1, A ; output displayed signal
			
			SJMP START ; jump to scan keypad again
			
ADDER:		MOV A, R6
			MOV B, R7
			ADD A, B
			SJMP DISPLAYER
SUBER:		MOV A, R6
			MOV B, R7
			SUBB A, B
			SJMP DISPLAYER
MULER:		MOV A, R6
			MOV B, R7
			MUL AB
			SJMP DISPLAYER
DIVER:		MOV A, R6
			MOV B, R7
			DIV AB
			SJMP DISPLAYER2
			
DISPLAYER:  MOV B, #10
			DIV AB
			MOVC A, @A+DPTR ; get signal from TABLE
			MOV P1, A ; output displayed signal
			CALL DE_250_us
			MOV A, B
			MOVC A, @A+DPTR ; get signal from TABLE
			MOV P1, A ; output displayed signal
			
DISPLAYER2: MOVC A, @A+DPTR ; get signal from TABLE
			MOV P1, A ; output displayed signal
			CALL DE_250_us
			MOV A, B
			MOVC A, @A+DPTR ; get signal from TABLE
			MOV P1, A ; output displayed signal
			
DEBOUNCE:   MOV R4, #50 ; move 50 times into R4
DE_500_us:  MOV R3, #250 ; move 250 times into R3
			DJNZ R3, $ ; jump to itself R3 times
			DJNZ R4, DE_500_us ; delay 25ms
			RET ; return to main code
DE_250_us:  MOV R3, #125 ; move 125 times into R3
			DJNZ R3, $ ; jump to itself R3 times
			DJNZ R4, DE_250_us ; delay 25ms
			RET ; return to main code
TABLE:      DB 00000011B ; display "0"
			DB 10011111B ; display "1"
			DB 00100101B ; display "2"
			DB 00001101B ; display "3"
			DB 10011001B ; display "4"
			DB 01001001B ; display "5"
			DB 01000001B ; display "6"
			DB 00011011B ; display "7"
			DB 00000001B ; display "8"
			DB 00001001B ; display "9"
			END