; 2. Salvado de registros ⭐  
; Los siguientes programas tienen errores en el uso de la convención de registros.
; Indicar en qué registros, cuál es el error y cómo se podría arreglar el problema en cada caso. 
 
; A)
    ; -----------------------------------------------------------
    ; CÓDIGO CON ERROR: USA EL REGISTRO TEMPORAL $t2 PARA RETORNO
    ; (Viola la Convención MIPS ABI para resultados)
    ; -----------------------------------------------------------

        .code   
            daddi $t0, $zero, 5    ; $t0 = 5
            daddi $t1, $zero, 7    ; $t1 = 7

            jal subrutina          ; Llama a la subrutina.

            sd $t2, variable($zero)  ; !!! ERROR AQUÍ: Espera el resultado en $t2 !!!
        halt 
        
        subrutina:
            ; [Error: $t2 no es el registro de retorno]
            daddi $t4, $zero, 2   ; $t4 = 2 (Multiplicador)
            dmul  $t0, $t0  , $t4   ; $t0 = 10 (Se sobrescribe el valor original de 5)
            dmul  $t1, $t1  , $t4   ; $t1 = 14 (Se sobrescribe el valor original de 7)
            dadd  $t2, $t1  , $t0   ; $t2 = 24. El resultado está en el REGISTRO INCORRECTO.
        jr $ra                   ; Regresa al llamador.

    ; -----------------------------------------------------------
    ; CÓDIGO CORREGIDO: USA EL REGISTRO $v0 PARA EL VALOR DE RETORNO
    ; (Adhesión a la Convención MIPS ABI)
    ; -----------------------------------------------------------

        .code   
            daddi $t0, $zero, 5    ; $t0 = 5 
            daddi $t1, $zero, 7    ; $t1 = 7 

            jal subrutina          ; Llama a la subrutina.

            sd $v0, result($zero)  ; ARREGLO: Guarda el resultado desde el REGISTRO CORRECTO ($v0).
        halt 
        
        subrutina:
            ; [Cálculo]
            daddi $t4, $zero, 2     ; $t4 = 2
            dmul  $t0, $t0  , $t4   ; $t0 = 10 (Uso temporal del registro)
            dmul  $t1, $t1  , $t4   ; $t1 = 14 (Uso temporal del registro)
            
            ; [Retorno del Valor]
            dadd  $v0, $t1, $t0   ; ARREGLO: $v0 = 24. Almacena el resultado final en $v0 (Value).
        jr $ra                   ; Regresa al llamador.

; B) 
    ; -----------------------------------------------------------
    ; CÓDIGO ORIGINAL B: CONTIENE ERRORES LÓGICOS Y DE CONVENCIÓN
    ; -----------------------------------------------------------

        .code 
            daddi $a0, $zero, tabla     ; $a0 = dirección de la tabla.
                                        ; !!! ERROR DE CONVENCIÓN (ABI) !!!
                                        ; $a0 es Caller-Saved, la subrutina puede SOBRESCRIBIR este puntero.

            jal subrutina               ; Llama a la subrutina. (Si existe, SOBRESCRIBE $a0)

            daddi $t0, $zero, 10        ; $t0 = 10 (Contador/Dimensión)
            daddi $t1, $zero, 0         ; $t1 = 0 (Suma acumulada)

            loop: 
                bnez $t0, fin           ; !!! ERROR LÓGICO: CONDICIÓN INVERSA !!!
                                        ; Si $t0 != 0 (Dimensión es 10), SALTA a 'fin'.
                                        ; El loop nunca se ejecuta si la tabla no está vacía.
                
                ; El loop usa el valor potencialmente corrompido de $a0:
                ld $t2, 0($a0)          ; Carga el elemento (usando $a0 como puntero)
                dadd $t1, $t1, $t2      ; Suma += elemento

                daddi $t0, $t0, -1      ; Contador -= 1
                daddi $a0, $a0, 8       ; Puntero avanza 8 bytes. (Si $a0$ fue sobrescrito antes, esto es basura)
            j loop                      ; Salto incondicional de repetición
            
            fin:
        halt

    ; -----------------------------------------------------------
    ; CÓDIGO CORREGIDO B: ADHESIÓN A CONVENCIÓN Y LÓGICA
    ; -----------------------------------------------------------

        .code 
            ; ARREGLO ABI: GUARDAR EL PUNTERO
            daddi $s0, $zero, tabla     ; ARREGLO: $s0 = dirección de 'tabla'. 
                                        ; Carga la dirección (puntero) en el registro $s0 (Callee-Saved) para preservar la dirección.
            
            jal subrutina               ; Llama a la subrutina. (Ahora es seguro, $s0$ está protegido)
            
            daddi $t0, $zero, 10        ; $t0 = 10 (Contador)
            daddi $t1, $zero, 0         ; $t1 = 0 (Suma)
            
            loop: 
                ; ARREGLO LÓGICO: Chequeo de salida (salir si dimensión == 0)
                beqz $t0, fin           ; Si $t0 == 0, salir del loop.
                
                ld $t2, 0($s0)          ; Carga elemento usando el puntero PRESERVADO $s0.
                dadd $t1, $t1, $t2      ; Suma += elemento
                
                daddi $s0, $s0, 8       ; Puntero ($s0$) avanza 8 bytes (tamaño de .word).
                daddi $t0, $t0, -1      ; Contador -= 1
            j loop                      ; Repetir
            
            fin:
        halt
 
              
; C) 
    ; -----------------------------------------------------------
    ; CÓDIGO ORIGINAL C: ERROR POR NO PRESERVAR EL ARGUMENTO $a0
    ; -----------------------------------------------------------

        .code 
            daddi $a0, $zero, 5    ; $a0 = 5 (Argumento 1)
            daddi $a1, $zero, 7    ; $a1 = 7 (Argumento 2)
            
            jal subrutina 
            
            ; !!! ERROR DE CONVENCIÓN (ABI) !!!
            ; $a0 es Caller-Saved. La subrutina puede haberlo modificado legalmente.
            dmul $t2, $a0, $v0      ; Intenta usar el valor original de $a0 (5), que puede ser incorrecto.
            
            sd $t2, variable($zero) 
        halt

    ; -----------------------------------------------------------
    ; CÓDIGO CORREGIDO C: PRESERVACIÓN DEL OPERANDO ANTES DEL CÁLCULO
    ; -----------------------------------------------------------

        .code 
            daddi $a0, $zero, 5     ; $a0 = 5 (Usado como Argumento 1)
            daddi $a1, $zero, 7     ; $a1 = 7 (Argumento 2)
            
            ; ARREGLO ABI: GUARDAR EL OPERANDO NECESARIO
            ; Guardamos el valor 5 en un registro temporal ($t0) ANTES de la llamada.
            dadd $t0, $a0, $zero    ; $t0 = 5. (Usamos $t0$ porque es el operando en el *llamador*)
            
            jal subrutina           ; La subrutina es libre de modificar $a0$.
            
            ; Usamos $t0 (que mantiene el valor 5) para el cálculo.
            dmul $t2, $t0, $v0      ; $t2 = $t0 (5) * $v0 (Resultado de subrutina).
            
            sd $t2, variable($zero) 
        halt


; D) 
    ; -----------------------------------------------------------
    ; CÓDIGO ORIGINAL D: MULTIPLES ERRORES
    ; -----------------------------------------------------------

        .code 
            daddi $t0, $zero, 10   ; $t0 = Dimensión (Contador del loop)
            daddi $t1, $zero, 0    ; $t1 = Contador de pares (Debe ser $s1$)
            daddi $t2, $zero, 0    ; $t2 = Desplazamiento (Debe ser $s2$)

            loop: 
                bnez $t0, fin       ; !!! ERROR LÓGICO !!!: Si $t0 != 0, salta. El loop no corre.
                
                ld $a0, tabla($t2)  ; Carga elemento (Argumento, OK)
                
                jal espar           ; Llama a subrutina. (Puede destruir $t1$ y $t2$)

                bnez $v0, seguir    ; Si $v0 != 0 (es impar), salta a 'seguir'

                dadd1 $t1, $t1, 1   ; !!! ERROR SINTAXIS !!!: Debe ser daddi. (Cuenta pares)
                
                seguir:
                    daddi $t2, $t2, 1   ; !!! ERROR LÓGICO 1 !!!: Incremento de 1 byte (incorrecto para .word)
                    daddi $t0, $t0, -1  ; Decrementa contador del loop
                    daddi $t2, $t2, 8   ; !!! ERROR LÓGICO 2 !!!: Doble incremento (Incremento de 8 bytes)
            j loop              
            
            sd $t1, resultado($zero) ; Esto no es accesible
            fin:
        halt

    ; -----------------------------------------------------------
    ; CÓDIGO CORREGIDO D: ADHESIÓN A CONVENCIÓN Y LÓGICA
    ; (Variables de Loop persistentes en $s-registers)
    ; -----------------------------------------------------------

        .code 
            daddi $t0, $zero, 10            ; $t0 = Dimensión (Contador del loop, Caller-Saved OK)
            daddi $s1, $zero, 0             ; ARREGLO ABI: $s1 = Contador de Pares (CALLEE-SAVED para persistir)
            daddi $s2, $zero, 0             ; ARREGLO ABI: $s2 = Desplazamiento (CALLEE-SAVED para persistir)

            loop: 
                ; ARREGLO LÓGICO: Si $t0 == 0, salir (condición correcta)
                beqz $t0, fin           

                ld $a0, tabla($s2)          ; $a0 = elemento. Usa el desplazamiento PRESERVADO $s2.
                
                jal espar                   ; Llama a la subrutina. (Puede destruir $t0$ y $a0$)

                bnez $v0, seguir            ; Si $v0 != 0 (IMPAR), salta a 'seguir'
                
                daddi $s1, $s1, 1           ; ARREGLO SINTAXIS (Incrementa el contador PRESERVADO)
                
                seguir:
                    daddi $s2, $s2, 8       ; ARREGLO LÓGICO: Desplazamiento ($s2$) += 8 bytes (.word)
                    daddi $t0, $t0, -1      ; Dimensión -= 1
            j loop                          ; Repetir

            fin: 
                sd $s1, resultado($zero)    ; Guarda el contador de pares (desde el registro PRESERVADO)
        halt