; 1. Tipos de instrucciones en WinMIPS64
; Consigna:
; Para cada una de las siguientes instrucciones del WinMIPS64, indicar si son:
;   SI   = salto incondicional   ; saltos que cambian el PC sin condición
;   SC   = salto condicional     ; comparan registros y saltan solo si se cumple la condición
;   LMEM = lectura de memoria    ; instrucciones de carga que leen memoria a registros
;   EMEM = escritura de memoria  ; instrucciones de store que escriben registros a memoria
;   AL   = aritmético-lógica     ; operaciones aritméticas o lógicas y otras instrucciones no-branch/no-mem
;
; Instrucciones (completar la columna "Tipo"):
; -----------------------------------------------------------------
; Instr.      | Tipo
; -----------------------------------------------------------------
; beq         | SC
; bne         | SC
; beqz        | SC
; bnez        | SC
; or          | AL
; ori         | AL
; and         | AL
; andi        | AL
; xor         | AL
; xori        | AL
; dadd        | AL
; daddi       | AL
; dmul        | AL
; ddiv        | AL
; halt        | AL
; nop         | AL
; slt         | AL
; slti        | AL
; j           | SI
; jal         | SI
; jr          | SI
; ld          | LMEM
; lb          | LMEM
; lbu         | LMEM
; lw          | LMEM
; lwu         | LMEM
; sb          | EMEM
; sd          | EMEM
; sw          | EMEM
; -----------------------------------------------------------------