;		ORG 0
;		MOV 20H,#00H
;		SETB 20H.1
;		MOV A,20H
;		SETB 03H
;		MOV A,20H
;		SJMP $
;		END

;		ORG 0
;		MOV R0,#30H
;		MOV R1,#10H
;		MOV 30H,#55H
;		MOV 31H,#24H
;		MOV A,R0
;		SJMP $
;		END

;		ORG 0
;		MOV DPTR,#TABLE
;		MOV A,#00H
;		MOVC A,@A+DPTR
;		SJMP $		
;TABLE:  DB 01H
;		DB 02H
;		END