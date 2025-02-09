;		ORG 0
;		MOV R0,#01H
;		MOV R1,#0FFH
;		SETB RS0
;		MOV R0,00H
;		MOV A,01H
;		MOV A,R0
;		MOV A,08H
;		MOV A,@R0
;		CLR RS0
;		MOV A,R0
;		SJMP $
;		END

;		ORG 0
;		MOV A,#11H
;		MOV 0E0H,#22H
;		SJMP $
;		END

		ORG 0
		MOV DPTR, #TABLE
START:  MOV R7, #04H
LOOP:   MOV A, R7
		MOVC A, @A+DPTR
		DJNZ R7, LOOP
		SJMP START
TABLE:  DB 5BH ;
		DB 7CH
		DB 1CH
		DB 1CH
		DB 3FH
		END
