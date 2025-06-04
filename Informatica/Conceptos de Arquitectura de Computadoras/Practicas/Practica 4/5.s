; 5) Programa que multiplica por 2 los elementos de un arreglo:
; a) ¿Qué hace la opción Delay Slot?
;    El Delay Slot es la instrucción que se ejecuta inmediatamente después de un salto (branch o jump),
;    antes de que el salto se haga efectivo. Permite aprovechar el ciclo que de otra forma quedaría vacío.
; b) ¿Para qué sirve el NOP? ¿Qué pasa si se quita?
;    El NOP ("No Operation") es una instrucción que no hace nada. Se usa aquí para ocupar el delay slot
;    después del branch. Si se quita, la instrucción que esté después del branch se ejecutará en el delay slot,
;    lo que puede causar errores si no se tiene cuidado.
; c) Anotar ciclos, instrucciones y CPI.
;    Depende del pipeline y la simulación, pero el NOP agrega un ciclo extra por iteración.
; d) Optimizar Delay Slot con instrucción útil. Simular y comparar.
;    Se puede poner una instrucción útil en el delay slot para mejorar el rendimiento.

.data
    cant:  .word 8                       ; Cantidad de elementos del arreglo
    datos: .word 1, 2, 3, 4, 5, 6, 7, 8  ; Arreglo de entrada
    res:   .word 0                       ; Arreglo de salida (resultado)
.code
    dadd r1, r0, r0                 ; r1 = 0 (índice/offset en bytes)
    ld   r2, cant(r0)               ; r2 = cantidad de elementos

    loop:
        ld    r3, datos(r1)           ; r3 = datos[i]
        daddi r2, r2, -1              ; r2-- (decrementa contador)
        dsll  r3, r3, 1               ; r3 = r3 * 2 (multiplica por 2)
        sd    r3, res(r1)             ; res[i] = r3 (guarda resultado)
        daddi r1, r1, 8               ; i++ (avanza al siguiente elemento, 8 bytes por word)    
    bnez r2, loop           ; Si quedan elementos, repite el bucle

    nop                           ; Delay slot: instrucción que se ejecuta después del branch
halt

; --- Ciclos, instrucciones y CPI ---
; Ciclos: Depende del pipeline, pero cada iteración del bucle toma al menos 4 ciclos (fetch, decode, execute, memory).
; Instrucciones: 6 iteraciones * 4 instrucciones por iteración = 24 instrucciones.
; CPI: Si consideramos el NOP, el CPI puede ser mayor a 1. Por ejemplo, si hay 8 iteraciones y cada una toma 4 ciclos, el CPI podría ser 4.5.

; --- ¿Qué hace este programa? ---
; Recorre el arreglo 'datos', multiplica cada elemento por 2 y guarda el resultado en el arreglo 'res'.
; Utiliza un bucle controlado por el contador 'r2'.
; El NOP ocupa el delay slot después del branch para evitar efectos no deseados.

; d) Optimización del Delay Slot con instrucción útil:
; Se puede reemplazar el NOP por una instrucción útil que no afecte el resultado del programa.
; Por ejemplo, se podría usar una instrucción que cargue un valor en un registro que no se use inmediatamente.

.data
    cant:  .word 8                       ; Cantidad de elementos del arreglo
    datos: .word 1, 2, 3, 4, 5, 6, 7, 8  ; Arreglo de entrada
    res:   .word 0                       ; Arreglo de salida (resultado)
.code
    dadd r1, r0, r0                 ; r1 = 0 (índice/offset en bytes)
    ld   r2, cant(r0)               ; r2 = cantidad de elementos

    loop:
        ld    r3, datos(r1)           ; r3 = datos[i]
        daddi r2, r2, -1              ; r2-- (decrementa contador)
        dsll  r3, r3, 1               ; r3 = r3 * 2 (multiplica por 2)
        sd    r3, res(r1)             ; res[i] = r3 (guarda resultado)
        daddi r1, r1, 8               ; i++ (avanza al siguiente elemento, 8 bytes por word)    
    bnez r2, loop           ; Si quedan elementos, repite el bucle

    ld r3, datos(r1)              ; Instrucción útil en el delay slot: precarga el próximo dato (si hay)
halt

; Ahora el delay slot se aprovecha para precargar el siguiente valor de datos,
; lo que puede mejorar el rendimiento si el pipeline lo permite.

; --- ¿Qué hace la opción Delay Slot? ---
; El Delay Slot es la instrucción que se ejecuta inmediatamente después de un salto (branch o jump),
; antes de que el salto se haga efectivo. Permite aprovechar el ciclo que de otra forma quedaría vacío.
; --- ¿Para qué sirve el NOP? ¿Qué pasa si se quita? ---
; El NOP ("No Operation") es una instrucción que no hace nada. Se usa aquí para ocupar el delay slot
; después del branch. Si se quita, la instrucción que esté después del branch se ejecutará en el delay slot,
; lo que puede causar errores si no se tiene cuidado.