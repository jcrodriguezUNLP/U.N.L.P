; 3. Uso de la pila ⭐ 
; En WinMIPS no existen las instrucciones PUSH y POP.
; Por ese motivo, deben implementarse utilizando otras instrucciones existentes.
; No solo eso, sino que el registro SP es en realidad un registro usual, r29, que con la convención se puede llamar por otro nombre, $sp.
; El siguiente programa debería intercambiar los valores de $t0 y $t1 utilizando la pila.
; No obstante, así como está no va a funcionar porque push y pop no son instrucciones válidas.
; Implementar la funcionalidad que tendrían estas operaciones utilizando instrucciones daddi, sd y ld para que el programa funcione correctamente.
; Recordar que los registros ocupan 8 bytes, y por ende el push y el pop deberán modificar a $sp con ese valor.

; .code
;     daddi $sp, $0, 0x400 
;     daddi $t0, $0, 5 
;     daddi $t1, $0, 8 
;     push $t0 
;     push $t1 
;     pop $t0 
;     pop $t1 
; halt

; correccion
.code
    daddi $sp, $0, 0x400 
    daddi $t0, $0, 5 
    daddi $t1, $0, 8 

    ; push $t0
    daddi $sp, $sp, -8      ; Decrementar el puntero de pila
    sd    $t0, 0($sp)       ; Almacenar el valor de $t0 en la pila

    ; push $t1
    daddi $sp, $sp, -8      ; Decrementar el puntero de pila
    sd    $t1, 0($sp)       ; Almacenar el valor de $t1 en la pila

    ; pop $t0
    ld    $t0, 0($sp)       ; Cargar el valor de la pila en $t0
    daddi $sp, $sp, 8       ; Incrementar el puntero de pila

    ; pop $t1
    ld    $t1, 0($sp)       ; Cargar el valor de la pila en $t1
    daddi $sp, $sp, 8       ; Incrementar el puntero de pila
halt