;ORG 0000H ; start from 0000H
;MOV A, #032H ; move 032H into ACC
;MOV B, #006H ; move 006H into B
;SUBB A, B ; A-B, then save into ACC
;MOV B, #007H ; move multiplier 007H into B
;MUL AB ; AxB
;END

;ORG 0 ; start from 0000H
;MOV A, #064H ; move 064H into ACC
;MOV B, #00DH ; move 00DH into B
;ADD A, B ; A+B, then save into ACC
;MOV B, #006H ; move divisor 006H into B
;DIV AB ; A/B
;END

ORG 0 ; start from 0000H
MOV A, #10111101B ; move 10111101B into ACC
ANL A, #11101111B ; use AND Gate to turn Bit 4 into 0
MOV B, A ; move the value into B
MOV A, #01000010B ; move 01000010B into ACC
ORL A, #00010000B ; use OR Gate to turn Bit 4 into 1
CPL A ; use NOT Gate
END