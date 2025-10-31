; -------------------------------------------------------------------------------
; 7) Subrutina para contar cuántos valores de una tabla son mayores que un número M
; -------------------------------------------------------------------------------
; El programa principal:
; - Define una tabla de 8 valores de 64 bits (inicialmente vacía).
; - Define una variable 'cantidad' para guardar el resultado.
; - Define una variable 'm' con el valor a comparar.
;
; Flujo principal:
; 1. Inicializa el puntero de pila.
; 2. Carga el valor M en $a0.
; 3. Carga la dirección base de la tabla en $a1.
; 4. Carga la cantidad de elementos (8) en $a2.
; 5. Llama a la subrutina contar_mayores.
; 6. Guarda el resultado devuelto en $v0 en la variable 'cantidad'.
; 7. Termina el programa.
;
; Subrutina contar_mayores:
; - Parámetros:
;     $a0 = valor M (comparador)
;     $a1 = dirección base de la tabla
;     $a2 = cantidad de elementos en la tabla
; - Retorno:
;     $v0 = cantidad de valores mayores que M
;
; Funcionamiento de la subrutina:
; 1. Inicializa el contador de mayores ($v0) en 0.
; 2. Inicializa el índice ($t0) en 0.
; 3. Bucle principal:
;    a. Verifica si el índice es menor que la cantidad de elementos.
;       Si no, termina el bucle.
;    b. Calcula la dirección del elemento actual: tabla[i].
;    c. Carga el valor actual de la tabla en $t4.
;    d. Compara si tabla[i] > M (sin signo).
;       Si es mayor, incrementa el contador.
;    e. Incrementa el índice y repite el bucle.
; 4. Al finalizar, retorna el resultado en $v0.
; -------------------------------------------------------------------------------

.data
    tabla: .space 64              ; Espacio para 8 valores de 64 bits (8 * 8 = 64 bytes)
    cantidad: .word 0             ; Espacio para almacenar la cantidad de valores mayores que M
    m: .dword 10                  ; Valor M a comparar (ejemplo)

.text
    daddi $sp, $0, 0x400          ; Inicializa el puntero de pila (stack pointer)
    ld    $a0, m($0)              ; $a0 = valor M (comparador)
    daddi $a1, $zero, tabla       ; $a1 = dirección base de la tabla
    daddi $a2, $zero, 8           ; $a2 = cantidad de elementos en la tabla (8)
    jal   contar_mayores          ; Llama a la subrutina que cuenta los mayores que M
    sd    $v0, cantidad($0)       ; Guarda el resultado (cantidad) en memoria

contar_mayores:
    daddi $v0, $zero, 0           ; Inicializa contador de mayores en $v0 = 0
    daddi $t0, $zero, 0           ; $t0 = índice (i = 0)

    loop:
        slt   $t1, $t0, $a2           ; ¿i < cantidad?
        beqz  $t1, fin_contar         ; Si no, termina

        dsll  $t2, $t0, 3             ; $t2 = i * 8 (desplazamiento en bytes)
        daddu $t3, $a1, $t2           ; $t3 = dirección de tabla[i]
        ld    $t4, 0($t3)             ; $t4 = tabla[i]

        sltu  $t5, $a0, $t4           ; ¿M < tabla[i]? (sin signo)
        beqz  $t5, siguiente          ; Si no, salta a siguiente

        daddi $v0, $v0, 1             ; Si es mayor, incrementa contador

siguiente:
    daddi $t0, $t0, 1             ; i++
    j     loop                    ; Repite el bucle

fin_contar:
    jr    $ra                     ; Retorna al llamador

halt                              ; Fin del programa