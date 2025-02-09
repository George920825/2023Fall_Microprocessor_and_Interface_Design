ORG 0 ;code start from 0
MOV P1, #00H ;set P1 pins low
LOOP: SETBP1.0 ;set P1.0 pin high
CALL DELAY_500_ms ;call delay function
CLR P1.0 ;set P1.0 pin low
CALL DELAY_500_ms ;call delay function
SJMP LOOP ;jump back to loop symbol
DELAY_500_ms: MOV R5, #5 ;move decimal 5 into R5 register
DELAY_100_ms: MOV R6, #200 ;move decimal 200 into R6 register
DELAY_500_us: MOV R7, #250 ;move decimal 250 into R7 register
DJNZ R7, $ ;jump to itself, it cost 2microseconds for R7(250) times
DJNZ R6, DELAY_500_ us ;jump to address DELAY_500_ us for R6(200) times
DJNZ R5, DELAY_100_ms ;jump to address DELAY_100_ ms for R5(5) times
RET ;return to call function address
END ;end the code
