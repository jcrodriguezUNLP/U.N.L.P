; 6. Elevar vector al cuadrado ⭐⭐

; Escribir una subrutina vector_cuadrado, que reciba la dirección de un vector de números, por referencia, y su longitud, por valor, y eleve cada uno de ellos al cuadrado.
; Para ello, utilizar la subrutina potencia implementada previamente.

.data
    vector:    .word 1, 2, 3, 4, 5
    longitud:  .word 5
    exponente: .word 2

.code
    ; inicializar pila
        daddi $sp, $0, 0x400
    
    daddi $a0, $0, vector                ; Cargar la dirección del vector
    ld    $a1, longitud($0)              ; Cargar la longitud del vector

    jal vector_cuadrado
halt

vector_cuadrado:
    ; recibe:
    ;   $a0 = &vector
    ;   $a1 = longitud
    ; devuelve:
    ;   vector modificado en memoria

    ; salvar $ra, $s0, $s1, $s2
        daddi $sp, $sp, -32                 ; Reservar espacio en pila
        sd    $ra,  0($sp)                  ; Guardar $ra
        sd    $s0,  8($sp)                  ; Guardar $s0
        sd    $s1, 16($sp)                  ; Guardar $s1
        sd    $s2, 24($sp)                  ; Guardar $s2

    dadd  $s0, $0, $a0                      ; Guardar la dirección del vector en $s0
    dadd  $s1, $0, $a1                      ; Cargar la longitud en $s1
    daddi $s2, $0, exponente                ; Dirección del exponente (2) 

    beqz $s1, finalizar_vector_cuadrado     ; Si la longitud es 0, terminar

    calcular_Cuadrados:
        dadd $a0, $0, $s0                   ; Cargar la dirección del elemento actual del vector
        dadd $a1, $0, $s2                   ; Cargar la dirección del exponente (2)

        jal potencia                        ; Llamar a la subrutina potencia

        sd $v0, 0($s0)                      ; Guardar el resultado al cuadrado en el vector

        daddi $s0, $s0, 8                   ; Mover al siguiente elemento del vector (asumiendo .word de 8 bytes)
        daddi $s1, $s1, -1                  ; Decrementar la longitud
    bnez $s1, calcular_Cuadrados            ; Fin del bucle

    finalizar_vector_cuadrado:
        ; restaurar $ra, $s0, $s1, $s2
            ld    $ra, 0($sp)               ; Restaurar $ra
            ld    $s0, 8($sp)               ; Restaurar $s0
            ld    $s1, 16($sp)              ; Restaurar $s1
            ld    $s2, 24($sp)              ; Restaurar $s2
            daddi $sp, $sp, 32              ; Liberar la pila
jr $ra

potencia:
    ; recibe:
    ;   $a0 = &base
    ;   $a1 = &exponente
    ; devuelve:
    ;   $v0 = resultado

    ld $t0, 0($a0)                          ; $t0 = base. Carga el valor (2) desde la dirección $a0
    ld $t1, 0($a1)                          ; $t1 = exponente. Carga el valor (5) desde la dirección $a1
    
    daddi $v0, $0, 1                        ; $v0 = Resultado (Inicializar a 1)
    
    beqz $t1, retornar_potencia             ; Si exponente es 0, retornar 1

    ; base = 1 termina
        daddi $t2, $t0, -1                  ; $t2 = base - 1
        beqz  $t2, retornar_potencia        ; Si base es 1, retornar 1
    
    loop:
        dmul  $v0, $v0, $t0                 ; $v0 = $v0 * base 
        daddi $t1, $t1, -1                  ; exponente -= 1
    bnez $t1, loop                          ; Repetir si exponente > 0

    retornar_potencia:
jr $ra                                      ; Devuelve el resultado por valor en $v0