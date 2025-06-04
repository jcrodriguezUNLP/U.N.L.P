; 3) Programa con bucle y desplazamiento:

; a) Ejecutar con Forwarding:
;    - ¿Por qué hay RAW?
;      Hay RAW (Read After Write) entre las instrucciones que usan r1 y r2 después de ser modificadas, por ejemplo:
;        dsll r1, r1, 1   (escribe r1)
;        daddi r2, r2, -1 (escribe r2)
;        bnez r2, loop    (lee r2)
;      El RAW ocurre porque bnez necesita el valor actualizado de r2.

;    - ¿Qué significa Branch Taken y por qué ocurre?
;      "Branch Taken" significa que la instrucción de salto condicional (bnez) efectivamente salta al destino (loop) porque la condición se cumple (r2 != 0).
;      Ocurre mientras r2 no sea cero.

;    - Anotar ciclos, instrucciones y CPI.
;      (Depende del pipeline, pero con forwarding, hay menos stalls. Ejemplo: 3 instrucciones por iteración, 6 iteraciones, ~18 instrucciones, CPI cercano a 1.)

; b) Ejecutar sin Forwarding:
;    - ¿Qué instrucciones generan RAW y en qué etapas?
;      RAW entre:
;        dsll r1, r1, 1 (W) -> siguiente uso de r1 (no hay en este caso)
;        daddi r2, r2, -1 (W) -> bnez r2, loop (R) (ID/EX hazard)
;      El hazard principal es entre daddi y bnez.

;    - ¿Cuántos ciclos dura cada Branch Taken Stall?
;      Sin forwarding, el hazard entre daddi y bnez requiere insertar un ciclo de burbuja (stall) para que el valor de r2 esté disponible.
;      Cada branch taken stall dura 1 ciclo.

;    - Anotar ciclos, instrucciones y CPI. Comparar.
;      (Con stalls, el número de ciclos aumenta, el CPI es mayor que 1.)

; c) Reordenar para que no haya RAW (con Forwarding).
;    Una forma es insertar una instrucción independiente entre daddi y bnez:
;        ver abajo.

; d) Modificar para guardar valores parciales de r1 en un arreglo.
;    Por ejemplo, guardar r1 en un arreglo C en cada iteración:
;       ver abajo.

; ---------------------------------------------------------------
.data
    A: .word 1
    B: .word 6
.code
    ld r1, A(r0)
    ld r2, B(r0)

    loop:                   ; inicio del bucle etiquetado como "loop"
        dsll  r1, r1,  1    ; Desplaza r1 a la izquierda (multiplica por 2)
        daddi r2, r2, -1    ; Decrementa r2 en 1
    bnez  r2, loop      ; si r2 no es cero, salta al inicio del bucle
halt
    
; ---------------------------------------------------------------
; c) Reordenar para evitar RAW con forwarding:
.data
    A: .word 1
    B: .word 6
.code
    ld r1, A(r0)
    ld r2, B(r0)
    
    loop:
        daddi r2, r2, -1    ; Decrementa r2 en 1 (contador)
        dsll  r1, r1,  1    ; Multiplica r1 por 2 (desplazamiento a la izquierda)
    bnez  r2, loop      ; Si r2 != 0, repite el bucle
halt
;
; Esta versión hace exactamente lo mismo que el código original:
; - Realiza 6 iteraciones, multiplicando r1 por 2 en cada vuelta.
; - El bucle termina cuando r2 llega a 0.
;
; La modificación (cambiar el orden de daddi y dsll) se hace para evitar un hazard RAW (Read After Write) entre daddi y bnez.
; Así, al ejecutar daddi antes de dsll, se le da tiempo al pipeline para que el valor actualizado de r2 esté disponible cuando lo necesita bnez,
; reduciendo o eliminando stalls incluso con forwarding.
; ---------------------------------------------------------------
; d) Modificar para guardar valores parciales de r1 en un arreglo.
.data
    A: .word 1         ; Valor inicial para r1
    B: .word 6         ; Cantidad de iteraciones (valor inicial para r2)
    C: .space 48       ; Espacio para guardar 6 valores parciales de r1 (6*8 bytes)
.code
    ld r1, A(r0)       ; r1 := A (carga el valor inicial en r1)
    ld r2, B(r0)       ; r2 := B (carga el número de iteraciones en r2)
    daddi r3, r0, 0    ; r3 := 0 (índice para el arreglo C)

    loop:
        dsll  r1, r1, 1    ; r1 := r1 * 2 (desplaza a la izquierda, multiplica por 2)
        sd    r1, C(r3)    ; Guarda el valor actual de r1 en C[i]
        daddi r3, r3,  8   ; i++ (avanza el índice al siguiente elemento del arreglo)
        daddi r2, r2, -1   ; r2 := r2 - 1 (decrementa el contador de iteraciones)
    bnez  r2, loop     ; Si r2 != 0, repite el bucle
halt                   ; Fin del programa

; ---------------------------------------------------------------
; RESUMEN SOBRE LOOPS EN MIPS
; ---------------------------------------------------------------
; Un loop (bucle) en MIPS se estructura así:
; 1. Se coloca una etiqueta al inicio del loop (ej: loop:).
; 2. El cuerpo del loop son las instrucciones que se repiten.
; 3. Al final del cuerpo, se usa una instrucción de salto condicional
;    (por ejemplo, bnez, beq, bne, etc.) para volver al inicio del bucle
;    o salir de él.
; 4. El loop termina cuando la condición del salto no se cumple y la
;    ejecución continúa después del salto.
;
; Ejemplo genérico:
;     daddi r1, r0, 0      ; Inicialización
;     daddi r2, r0, 10
; loop:
;     ...                  ; Cuerpo del loop
;     daddi r1, r1, 1
;     bne   r1, r2, loop   ; Salto condicional
;     halt
;
; Saltos condicionales comunes en MIPS:
;     beq   r1, r2, etiqueta   ; Salta si r1 == r2
;     bne   r1, r2, etiqueta   ; Salta si r1 != r2
;     beqz  r1, etiqueta       ; Salta si r1 == 0
;     bnez  r1, etiqueta       ; Salta si r1 != 0
;     blt   r1, r2, etiqueta   ; Salta si r1 < r2 (pseudoinstrucción)
;     ble   r1, r2, etiqueta   ; Salta si r1 <= r2 (pseudoinstrucción)
;     bgt   r1, r2, etiqueta   ; Salta si r1 > r2 (pseudoinstrucción)
;     bge   r1, r2, etiqueta   ; Salta si r1 >= r2 (pseudoinstrucción)
;
; Las pseudoinstrucciones pueden ser traducidas por el ensamblador a
; instrucciones básicas.
; ---------------------------------------------------------------