; 1) Muchas instrucciones comunes en procesadores con arquitectura CISC no forman parte del repertorio de instrucciones del MIPS64,
;    pero pueden implementarse haciendo uso de una única instrucción. Evaluar las siguientes instrucciones, indicar qué tarea
;    realizan y cuál sería su equivalente en lenguaje assembly del x86.

.data
; Acá se declaran los datos (variables) en memoria
    var1: .word 5       ; Ejemplo: una variable con valor 5

.text
main:
    ; Acá va tu código (instrucciones en ensamblador)
    dadd  r1, r2, r0
;       → r1 = r2 + r0 (r0 siempre vale 0 en MIPS) → copia el contenido de r2 en r1
;       → equivalente x86: MOV r1, r2
    daddi r3, r0, 5
;       → r3 = r0 + 5 (r0 = 0) → carga inmediato 5 en r3
;       → equivalente x86: MOV r3, 5
    dsub  r4, r4, r4
;       → r4 = r4 - r4 → r4 = 0 (pone en cero el registro)
;       → equivalente x86: XOR r4, r4
    daddi r5, r5, -1
;       → r5 = r5 - 1 → decrementa el valor de r5
;       → equivalente x86: DEC r5 (o SUB r5, 1)
    xori  r6, r6, 0xffffffffffffffff
;       → r6 = r6 XOR -1 (todos 1s) → bitwise NOT (niega todos los bits)
;       → equivalente x86: NOT r6
halt            ; Finaliza el programa