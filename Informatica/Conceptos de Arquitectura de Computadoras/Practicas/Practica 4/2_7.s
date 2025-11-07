; 7. Pasaje por pila ⭐⭐

; La versión anterior de potencia utiliza pasaje por registros y por valor, y ya escribiste una versión alternativa que recibe los parámetros por referencia.
; Ahora adapta la subrutina y el programa asociado para estos casos: 

; b) Valor y Pila Pasando los parámetros por valor desde el programa principal a través de la pila, y devolviendo el resultado a través de un registro por valor.

; c) Referencia y Pila Pasando los parámetros por referencia desde el programa principal a través de la pila, y devolviendo el resultado a través de un registro por valor

.data
    base: .word 2
    exponente: .word 5
    resultado: .word 0

.code
    ; b) Valor y Pila
        ld $t0, base                ; Cargar base
        ld $t1, exponente           ; Cargar exponente

        daddi $sp, $sp, -16         ; Reservar espacio en la pila
        sd    $t0, 0($sp)           ; Guardar base en la pila
        sd    $t1, 8($sp)           ; Guardar exponente en la pila

        jal potenciaB               ; Llamar a la subrutina

        sd $v0, resultado           ; Guardar el resultado

    ; c) Referencia y Pila
        daddi $t0, $0, base         ; Cargar dirección de base
        daddi $t1, $0, exponente    ; Cargar dirección de exponente

        daddi $sp, $sp, -16         ; Reservar espacio en la pila
        sd    $t0, 0($sp)           ; Guardar base en la pila
        sd    $t1, 8($sp)           ; Guardar exponente en la pila

        jal potenciaC               ; Llamar a la subrutina

        sd $v0, resultado           ; Guardar el resultado
halt

potenciaB:                          ; Parámetros por valor desde la pila
    ld    $t0, 0($sp)               ; Cargar base
    ld    $t1, 8($sp)               ; Cargar exponente
    daddi $sp, $sp, 16              ; Liberar espacio en la pila

    daddi $v0, $0, 1                ; resultado = 1

    beqz $t1, endB                  ; Si exponente == 0, terminar
    
    ; si base = 1 terminar
        daddi $t2, $t0, -1
        beqz $t2, endB

    loopB:
        dmul $v0, $v0, $t0          ; resultado *= base
        daddi $t1, $t1, -1          ; exponente--
    bnez $t1, loopB

    endB:
jr $ra                              ; Retornar

potenciaC:                          ; Parámetros por referencia desde la pila
    ld    $t0, 0($sp)               ; Cargar dirección de base
    ld    $t1, 8($sp)               ; Cargar dirección de exponente
    daddi $sp, $sp, 16              ; Liberar espacio en la pila

    ld    $t0, 0($t0)               ; Cargar valor de base
    ld    $t1, 0($t1)               ; Cargar valor de exponente

    daddi $v0, $0, 1                ; resultado = 1

    beqz $t1, endB                  ; Si exponente == 0, terminar
    
    ; si base = 1 terminar
        daddi $t2, $t0, -1
        beqz $t2, endB

    loopC:
        dmul $v0, $v0, $t0          ; resultado *= base
        daddi $t1, $t1, -1          ; exponente--
    bnez $t1, loopC

    endC:
jr $ra                              ; Retornar