; 1) Simular el siguiente programa de suma de números en punto flotante y analizar minuciosamente la ejecución paso a paso.
; Inhabilitar Delay Slot y mantener habilitado Forwarding.

; a) Tomar nota de la cantidad de ciclos, instrucciones y CPI luego de la ejecución del programa.
;    - Instrucciones: 6 (l.d, l.d, add.d, mul.d, s.d, s.d, halt)
;    - Ciclos: Depende del simulador, pero típicamente ~10-12 ciclos si hay forwarding y sin delay slot.
;    - CPI: Ciclos / Instrucciones, por ejemplo, si son 12 ciclos y 6 instrucciones, CPI = 2.

; b) ¿Cuántos atascos por dependencia de datos se generan? Observar en cada caso cuál es el dato en conflicto y las instrucciones involucradas.
;    - Hay dependencias de datos entre:
;      1. l.d f1, n1(r0) -> add.d f3, f2, f1 (f1)
;      2. l.d f2, n2(r0) -> add.d f3, f2, f1 (f2)
;      3. add.d f3, f2, f1 -> s.d f3, res1(r0) (f3)
;      4. mul.d f4, f2, f1 -> s.d f4, res2(r0) (f4)
;    - Con forwarding, los atascos (stalls) se minimizan, pero puede haber 1-2 ciclos de stall en total.

; c) ¿Por qué se producen los atascos estructurales? Observar cuales son las instrucciones que los generan y en qué etapas del pipeline aparecen.
;    - Los atascos estructurales pueden ocurrir si dos instrucciones requieren el mismo recurso de hardware en el mismo ciclo.
;    - Por ejemplo, si ambas l.d intentan acceder a memoria al mismo tiempo, o si una instrucción de punto flotante y una de acceso a memoria coinciden en la etapa MEM.
;    - En este código, no suelen aparecer atascos estructurales si el hardware tiene unidades separadas para memoria y punto flotante.

; d) Modificar el programa agregando la instrucción mul.d f1, f2, f1 entre las instrucciones add.d y mul.d.
;    Repetir la ejecución y observar los resultados. ¿Por qué aparece un atasco tipo WAR?
;    - Aparece un atasco WAR (Write After Read) porque la instrucción add.d lee f1 y la siguiente mul.d escribe f1.
;    - Si el pipeline permite que mul.d escriba f1 antes de que add.d termine de leerlo, se produce un conflicto.

; e) Explicar por qué colocando un NOP antes de la suma, se soluciona el RAW de la instrucción ADD y como consecuencia se elimina el WAR.
;    - Si se coloca un NOP antes de add.d, se da tiempo a que las instrucciones l.d terminen de escribir en f1 y f2 antes de que add.d las lea.
;    - Esto elimina el conflicto RAW (Read After Write) y, al no haber RAW, tampoco se produce el WAR en la instrucción siguiente.

; .data
;     n1:   .double 9.13      ; Define la variable n1 con el valor 9.13 (doble precisión)
;     n2:   .double 6.58      ; Define la variable n2 con el valor 6.58 (doble precisión)
;     res1: .double 0.0       ; Reserva espacio para el resultado 1 (inicializado en 0.0)
;     res2: .double 0.0       ; Reserva espacio para el resultado 2 (inicializado en 0.0)

; .code
;     l.d   f1, n1(r0)        ; Carga el valor de n1 en el registro de punto flotante f1
;     l.d   f2, n2(r0)        ; Carga el valor de n2 en el registro de punto flotante f2

;     add.d f3, f2, f1        ; Suma f2 + f1 y guarda el resultado en f3
;     mul.d f4, f2, f1        ; Multiplica f2 * f1 y guarda el resultado en f4
    
;     s.d   f3, res1(r0)      ; Almacena el valor de f3 en la variable res1
;     s.d   f4, res2(r0)      ; Almacena el valor de f4 en la variable res2
; halt                        ; Detiene la ejecución del programa

; d)
; Modificación del programa agregando la instrucción mul.d f1, f2, f1
; y observando el atasco WAR.
; .data
;     n1:   .double 9.13
;     n2:   .double 6.58
;     res1: .double 0.0
;     res2: .double 0.0
; .code
;     l.d   f1, n1(r0)
;     l.d   f2, n2(r0)

;     add.d f3, f2, f1
;     mul.d f1, f2, f1  ; Aquí se produce el WAR
;     mul.d f4, f2, f1
    
;     s.d   f3, res1(r0)
;     s.d   f4, res2(r0)
; halt

; e)
; Colocando un NOP antes de la suma para evitar el RAW y eliminar el WAR.
.data
    n1:   .double 9.13
    n2:   .double 6.58
    res1: .double 0.0
    res2: .double 0.0
.code
    l.d   f1, n1(r0)
    l.d   f2, n2(r0)
    
    nop  ; NOP para evitar RAW

    add.d f3, f2, f1
    mul.d f1, f2, f1  ; Ahora no hay WAR
    mul.d f4, f2, f1
    
    s.d   f3, res1(r0)
    s.d   f4, res2(r0)
halt