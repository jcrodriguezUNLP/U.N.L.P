; 4) Programa de búsqueda en tabla:
; a) Ejecutar con Forwarding. ¿Qué hace el programa? ¿Resultado?
;    El programa realiza una búsqueda secuencial del número almacenado en 'num' dentro del arreglo 'tabla'.
;    Si encuentra el número, r10 = 1; si no, r10 = 0.
;    Con Forwarding, se reducen los stalls por dependencias de datos (RAW), mejorando el rendimiento.

; b) Ejecutar con Branch Target Buffer. ¿Qué mejora trae?
;    El uso de un Branch Target Buffer (BTB) permite predecir la dirección de salto de las instrucciones de branch,
;    reduciendo los ciclos perdidos por branch taken stalls y mejorando el flujo de ejecución.

; c) Comparar: ciclos, CPI, RAWs, Branch Taken Stalls (con y sin BTB).
;    - Con Forwarding: Menos ciclos y menor CPI debido a menos stalls por RAW.
;    - Sin Forwarding: Más ciclos y mayor CPI por más stalls por RAW.
;    - Con BTB: Menos branch taken stalls, menor cantidad de ciclos y menor CPI.
;    - Sin BTB: Más branch taken stalls, más ciclos y mayor CPI.

.data
    tabla: .word 20, 1, 14, 3, 2, 58, 18, 7, 12, 11   ; Arreglo de 10 números
    num:   .word 7                                    ; Número a buscar
    long:  .word 10                                   ; Cantidad de elementos en la tabla
.code
    ld r1, long(r0)       ; r1 = longitud de la tabla (contador de elementos)
    ld r2, num(r0)        ; r2 = número a buscar
    dadd r3 , r0, r0      ; r3 = 0 (índice/offset en bytes)
    dadd r10, r0, r0      ; r10 = 0 (resultado: 0 = no encontrado, 1 = encontrado)

    loop: 
        ld r4, tabla(r3)      ; r4 = tabla[i] (carga el elemento actual)

        beq r4, r2, listo     ; Si tabla[i] == num, salta a 'listo'
        
        daddi r1, r1, -1      ; r1-- (decrementa el contador de elementos)
        daddi r3, r3,  8      ; r3 += 8 (avanza al siguiente elemento, 8 bytes por word)    
    bnez r1, loop         ; Si quedan elementos, repite el bucle

    j fin       ; Si termina el loop sin encontrar, salta a fin

listo: 
    daddi r10, r0, 1      ; r10 = 1 (encontrado)
fin: 
    halt                  ; Fin del programa

; --- ¿Qué hace este programa? ---
; Busca el valor almacenado en 'num' dentro del arreglo 'tabla'.
; Si lo encuentra, deja r10 = 1; si no lo encuentra, r10 = 0.
; Es un algoritmo de búsqueda secuencial en un arreglo de enteros.

; --- ¿Qué mejora trae el uso de Forwarding? ---
; Con Forwarding, se evitan los stalls por dependencias de datos (RAW) entre las instrucciones de carga y comparación.
; Esto permite que el programa se ejecute más rápido, ya que las instrucciones pueden continuar sin esperar a que los datos estén disponibles en los registros.
; --- ¿Qué mejora trae el uso de Branch Target Buffer? ---
; El uso de un Branch Target Buffer (BTB) permite predecir la dirección de salto de las instrucciones de branch,
; reduciendo los ciclos perdidos por branch taken stalls y mejorando el flujo de ejecución.

; ---------------------------------------------------------------
; RESUMEN: TIPOS DE JUMPS Y BRANCHES EN MIPS
; ---------------------------------------------------------------
; Saltos incondicionales:
;   j etiqueta           ; Salta incondicionalmente a 'etiqueta'
;   jr registro          ; Salta a la dirección almacenada en 'registro' (usado para retornar de subrutinas)
;   jal etiqueta         ; Salta a 'etiqueta' y guarda la dirección de retorno en $ra (llamada a subrutina)
;   jalr registro        ; Salta a la dirección en 'registro' y guarda la dirección de retorno en $ra

; Saltos condicionales básicos:
;   beq r1, r2, etiqueta ; Salta si r1 == r2
;   bne r1, r2, etiqueta ; Salta si r1 != r2

; Saltos condicionales con cero:
;   beqz r1, etiqueta    ; Salta si r1 == 0 (pseudoinstrucción)
;   bnez r1, etiqueta    ; Salta si r1 != 0 (pseudoinstrucción)

; Saltos condicionales con comparación (pseudoinstrucciones):
;   blt r1, r2, etiqueta ; Salta si r1 < r2
;   ble r1, r2, etiqueta ; Salta si r1 <= r2
;   bgt r1, r2, etiqueta ; Salta si r1 > r2
;   bge r1, r2, etiqueta ; Salta si r1 >= r2

; Nota: Las pseudoinstrucciones son traducidas por el ensamblador a instrucciones básicas.
; ---------------------------------------------------------------