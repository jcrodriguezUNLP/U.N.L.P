; 5. Salvado de registros en subrutinas anidadas ⭐⭐
 
; Las siguientes subrutinas anidadas funcionan, pero tienen errores en el uso de la convención de los registros, en especial con respecto a cuales tienen que salvarse y cuáles no, y también cuándo y en qué caso debe hacerse.
; Indicar los errores y corregir el código para que las subrutinas usen la convención correctamente. 

.data
    A:         .word 5
    B:         .word 3
    resultado: .word 0

.code
    ; inicializar pila
        daddi $sp, $0, 0x400

    ; codigo para espar
        ld $a0, A($0)

        jal esPar

        sb $v0, resultado($0)
    
    ; codigo para cant0
        ld $a0, A($0)

        jal cant0

        sb $v0, resultado($0)
    
    ; codigo para diffvol
        ld $a0, A($0)
        ld $a1, B($0)

        jal diffvol

        sb $v0, resultado($0)
halt
              
; A)
    ; ----------------------------- ORIGINAL ------------------------------------------------
    esImpar:
        ; recibe:
        ;   $a0 = número entero cualquiera
        ; devuelve:
        ;   $v0 = 1 si a0 es impar, 0 si es par
        
        andi $v0, $a0, 1    ; $v0 = a0 AND 1
    jr $ra 
    
    esPar:
        ; recibe:
        ;   $a0 = número entero cualquiera
        ; devuelve:
        ;   $v0 = 1 si a0 es par, 0 si es impar

        ; ERROR: No se salva $ra antes de la llamada anidada
        
        jal esImpar         ; Llamada anidada que sobrescribe $ra
        
        ;truco: espar = 1 - esimpar 
        daddi $s0, $0, 1        ; $s0 = 1   --> ERROR debería usarse un registro temporal
        dsub  $v0, $s0, $v0     ; $v0 = 1 - esimpar
    jr $ra

    ; ---------------------------- CORRECCION ------------------------------------------------
        esImpar:
            ; recibe:
            ;   $a0 = número entero cualquiera
            ; devuelve:
            ;   $v0 = 1 si a0 es impar, 0 si es par
            
            andi $v0, $a0, 1 
        jr $ra 
        
        esPar:
            ; recibe:
            ;   $a0 = número entero cualquiera
            ; devuelve:
            ;   $v0 = 1 si a0 es par, 0 si es impar

            ; salvar $ra
                daddi $sp, $sp, -8
                sd    $ra, 0($sp)
            
            jal esImpar                 ; Llamada anidada que sobrescribe $ra
            
            ;truco: espar = 1 - esimpar 
                daddi $t0, $0 , 1       ; $t0 = 1   --> USAR REGISTRO TEMPORAL
                dsub  $v0, $t0, $v0     ; $v0 = 1 - esimpar

            ; restaurar $ra
                ld    $ra, 0($sp) 
                daddi $sp, $sp, 8
        jr $ra

; B) 
    ; ------------------------ ORIGINAL: ---------------------------------
    cant0:
        ; recibe:
        ;   $a0 = número entero cualquiera
        ; devuelve:
        ;   $v0 = cantidad de bits 0 en el número de 64 bits

        ; ERROR No se salva $ra antes de la llamada anidada
        
        ; ERROR usa $t0 y $t1 sin salvaguardarlos, la subrutina anidada puede modificarlos
        daddi $t0, $0, 0                ; $t0 = Contador de ceros
        daddi $t1, $0, 64               ; $t1 = Contador de bits
        
        loop:
            jal esPar                   ; Llamada anidada que sobrescribe $ra
            
            dadd $t0, $t0, $v0          ; Incrementar contador si es par
            
            ; desplazo a la derecha para quitar el último bit 
                dsrl  $a0, $a0, 1       ; Desplazar a la derecha  --> ERROR se asume q $a0 tiene el valor original, deberia salvarse previamente
                daddi $t1, $t1, -1      ; Decrementar contador de bits
        bnez $t1, loop

        ; ERROR: no retorna el valor correcto en $v0
    jr $ra

    ; ------------------------ CORRECCION: ---------------------------------
        cant0:
            ; recibe:
            ;   $a0 = número entero cualquiera
            ; devuelve:
            ;   $v0 = cantidad de bits 0 en el número de 64 bits

            ; salvar $ra, $s0, $s1, $s2 en la pila
                daddi $sp, $sp, -32 
                sd    $ra, 0($sp)
                sd    $s0, 8($sp) 
                sd    $s1, 16($sp) 
                sd    $s2, 24($sp)
            
            dadd  $s0, $0, $a0          ; $s0 = Guardar el valor original de $a0 (NECESARIO)
            daddi $s1, $0, 0            ; $s1 = Contador de ceros (OK, temporal)
            daddi $s2, $0, 64           ; $s2 = Contador de bits (OK, temporal)

            loop:
                jal espar               ; Llamada anidada que sobrescribe $ra

                dadd $s1, $s1, $v0      ; Incrementar contador si es par

                ; Desplazamiento del número
                dsrl $s0, $s0, 1        ; Desplazar a la derecha (usar $s0, que tiene el valor original)
                daddi $s2, $s2, -1      ; Decrementar contador de bits
            bnez $s2, loop

            dadd $v0, $s1, $0         ; Mover el resultado a $v0

            ; Restaurar $ra, $s0, $s1, $s2
                ld $ra, 0($sp) 
                ld    $s0, 8($sp)
                ld    $s1, 16($sp)
                ld    $s2, 24($sp)
                daddi $sp, $sp, 32
        jr $ra
 
; C)
    ; ----------------------------- ORIGINAL: ---------------------------------
    vol:
        ; recibe:
        ;   $a0 = longitud del lado del cubo
        ; devuelve:
        ;   $v0 = volumen del cubo (lado^3)

        daddi $sp, $sp, -16     ; Reservar espacio en pila
        sd $ra, 0($sp)          ; Salvar $ra$
        sd $s0, 8($sp)          ; Salvar $s0$
        
        dadd  $s0, $a0, $0      ; Guardar la longitud del lado en $s0
        dmul  $s0, $a0, $a0     ; $s0 = lado * lado
        dmul  $s0, $s0, $a0     ; $s0 = (lado^2) * lado (volumen)
        daddi $v0, $s0, 0       ; Mover el resultado a $v0
        
        ld $ra, 0($sp)          ; Restaurar $ra$
        ld $s0, 8($sp)          ; Restaurar $s0$
        daddi $sp, $sp, 16      ; Liberar espacio en pila 
    jr $ra
 
    diffvol:
        ; recibe:
        ;   $a0 = longitud del lado del cubo más grande
        ;   $a1 = longitud del lado del cubo más chico
        ; devuelve:
        ;   $v0 = diferencia de volumen entre los dos cubos
        
        ; ERROR: No se salvan los registros necesarios antes de las llamadas anidadas
            ; $ra
            ; $a1 (porque se usa en la segunda llamada a vol)

        jal vol                 ; Calcular volumen del cubo grande
        
        daddi $t0, $v0, 0       ; Guardar volumen del cubo grande en $t0 --> ERROR debería salvarse en un registro preservado
        
        daddi $a0, $a1, 0       ; Mover lado chico a $a0
        
        jal vol                 ; Calcular volumen del cubo chico
        
        dsub $v0, $t0, $v0      ; Diferencia de volúmenes (grande - chico) --> ERROR $t0 no es un registro preservado
    jr $ra

    ;----------------------------- CORRECCION: ---------------------------------
        vol:
            ; recibe:
            ;   $a0 = longitud del lado del cubo
            ; devuelve:
            ;   $v0 = volumen del cubo (lado^3)

            ; ARREGLO: Eliminar salvado de $ra y $s0. vol no llama a subrutinas.

            ; Cálculo directo en $v0 (retorno) o $t0 (temporal)
            dmul $v0, $a0, $a0        ; $v0 = lado * lado
            dmul $v0, $v0, $a0        ; $v0 = (lado^2) * lado (volumen)
        jr $ra 
            
        diffvol:
            ; recibe:
            ;   $a0 = longitud del lado del cubo más grande
            ;   $a1 = longitud del lado del cubo más chico
            ; devuelve:
            ;   $v0 = diferencia de volumen entre los dos cubos

            ; salvar $ra y $a1 y $s0
                daddi $sp, $sp, -24
                sd    $ra, 0($sp)
                sd    $a1, 8($sp)
                sd    $s0, 16($sp)

            jal vol 
            
            daddi $s0, $v0, 0       ; $s0 = Vol_Grande (Preservado a través de la 2da llamada)
            
            ; restaurar $a1 para la siguiente llamada
                ld $a0, 8($sp)      ; Restaurar lado_chico en $a0

            jal vol                 ; $v0 = Vol_Chico
            
            dsub $v0, $s0, $v0      ; $v0 = $s0 (Vol_Grande) - $v0 (Vol_Chico)

            ; restaurar $ra y $s0
                ld    $ra, 0($sp)
                ld    $s0, 16($sp)
                daddi $sp, $sp, 24
        jr $ra