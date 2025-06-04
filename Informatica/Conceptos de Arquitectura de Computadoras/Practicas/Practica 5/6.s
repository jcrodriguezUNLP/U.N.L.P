; 6) Muchas instrucciones que normalmente forman parte del repertorio de un procesador con arquitectura CISC no existen en el MIPS64.
;    El siguiente programa muestra un ejemplo de invocación a una subrutina.

; a) ¿Qué hace el programa? ¿Cómo está estructurado el código del mismo?
;    El programa calcula la potencia entera: result = valor1 ^ valor2 (es decir, valor1 elevado a valor2).
;    - Carga dos valores desde memoria en $a0 (base) y $a1 (exponente).
;    - Llama a la subrutina a_la_potencia usando jal.
;    - La subrutina multiplica $a0 por sí mismo $a1 veces (bucle), guardando el resultado en $v0.
;    - El resultado se almacena en memoria en 'result'.
;    - El programa termina con halt.

; b) ¿Qué acciones produce la instrucción jal? ¿Y la instrucción jr?
;    - jal etiqueta: Salta a la subrutina indicada y guarda la dirección de retorno (la siguiente instrucción) en $ra.
;    - jr $ra: Salta a la dirección almacenada en $ra, retornando al punto donde se llamó la subrutina.

; c) ¿Qué valor se almacena en el registro $ra? ¿Qué función cumplen los registros $a0 y $a1? ¿Y el registro $v0?
;    - $ra almacena la dirección de retorno (la instrucción después de jal).
;    - $a0: contiene la base de la potencia (valor1).
;    - $a1: contiene el exponente (valor2).
;    - $v0: almacena el resultado de la potencia y es el valor de retorno de la subrutina.

; d) ¿Qué sucedería si la subrutina a_la_potencia necesitara invocar a otra subrutina para realizar la multiplicación?
;    ¿Cómo sabría cada una de las subrutinas a qué dirección de memoria deben retornar?
;    - Si a_la_potencia llama a otra subrutina, la nueva llamada sobrescribiría $ra.
;    - Para evitar perder la dirección de retorno original, antes de llamar a otra subrutina se debe guardar $ra en la pila (stack).
;    - Al retornar, se recupera $ra desde la pila, asegurando que cada subrutina retorne correctamente a su llamador.

.data
    valor1: .word 16         ; Base de la potencia (valor1)
    valor2: .word 4          ; Exponente de la potencia (valor2)
    result: .word 0          ; Espacio para almacenar el resultado

.code
    ld    $a0, valor1($0)    ; Carga valor1 en $a0 (base)
    ld    $a1, valor2($0)    ; Carga valor2 en $a1 (exponente)
    jal   a_la_potencia      ; Llama a la subrutina para calcular la potencia
    sd    $v0, result($0)    ; Guarda el resultado en memoria
    halt                     ; Fin del programa

; ---------------------------------------------------------------
; Subrutina: a_la_potencia
; Calcula $a0 ^ $a1 (base elevado a exponente) usando multiplicaciones sucesivas.
; El resultado se devuelve en $v0.
; ---------------------------------------------------------------
a_la_potencia:
    daddi $v0, $0, 1         ; Inicializa $v0 = 1 (acumulador del resultado)

    lazo:
        slt   $t1, $a1, $0       ; ¿$a1 < 0? (verifica si el exponente es negativo)
        bnez  $t1, terminar      ; Si $a1 < 0, termina el bucle
        daddi $a1, $a1, -1       ; Decrementa el exponente ($a1 = $a1 - 1)
        dmul  $v0, $v0, $a0      ; Multiplica el acumulador por la base ($v0 = $v0 * $a0)
        j     lazo               ; Repite el bucle

terminar:
    jr    $ra                ; Retorna a la dirección de llamada (regresa al programa principal)