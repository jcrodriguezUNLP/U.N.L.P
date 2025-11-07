; 4. Pasaje por registro y por referencia ⭐⭐ 

; La versión anterior de potencia utiliza pasaje por registros y por valor.
; Escribir otra versión que reciba los parámetros por referencia desde el programa principal a través de registros, y devuelva el resultado a través de un registro por valor.
; Adaptar el programa principal de prueba de forma acorde.

.data
    base:       .dword 2            ; ARREGLO: Definir la variable 'base' con valor 2
    exponente:  .dword 5            ; ARREGLO: Definir la variable 'exponente' con valor 5
    resultado:  .dword 0            ; ARREGLO: Definir la variable 'resultado' para almacenar el resultado

.code
    ; CARGAR REFERENCIAS (Direcciones de memoria) en $a0 y $a1
    ; $a0 = &base
    daddi $a0, $zero, base          ; ARREGLO: Carga la DIRECCIÓN de 'base' en $a0 (Referencia)
    
    ; $a1 = &exponente
    daddi $a1, $zero, exponente     ; ARREGLO: Carga la DIRECCIÓN de 'exponente' en $a1 (Referencia)

    ; Llamar a la subrutina
    jal potencia                    ; El resultado será devuelto POR VALOR en $v0
    
    ; GUARDAR RESULTADO (Recibido por Valor)
    sd $v0, resultado($zero)        ; ARREGLO: Guarda el valor final de $v0 en 'resultado'
    
    ; Terminar el programa
halt

; ----------------------------------------------------
; SUBRUTINA POTENCIA: RECIBE POR REFERENCIA
; (Potencia: $a0 = &base, $a1 = &exponente)
; ----------------------------------------------------
potencia:
    ; 1. DESREFERENCIAR: Cargar los valores usando las direcciones pasadas
    ld $t0, 0($a0)          ; $t0 = base. Carga el valor (2) desde la dirección $a0
    ld $t1, 0($a1)          ; $t1 = exponente. Carga el valor (5) desde la dirección $a1
    
    ; 2. CÁLCULO (Algoritmo anterior: resultado = 1)
    daddi $v0, $zero, 1     ; $v0 = Resultado (Inicializar a 1)
    
    ; Caso base: si el exponente es 0, retornar 1 inmediatamente.
    beqz $t1, retornar_potencia
    
    loop:
        dmul  $v0, $v0, $t0     ; $v0 = $v0 * base 
        daddi $t1, $t1, -1      ; exponente -= 1
    bnez $t1, loop          ; Repetir si exponente > 0
    
    retornar_potencia:
jr $ra                  ; Devuelve el resultado por valor en $v0