; 6. Recorrido básico de vectores ⭐

; Dado un vector definido como: V: .word 5, 2, 6
; escribir programas para: 
; a)  Calcular la suma de los 3 valores sin utilizar un loop o lazo  
;     Pista: Usar tres instrucciones ld $t1, V($t2), donde $t2 va aumentando de a 8 bytes el desplazamiento. 
; b) Calcular la suma de los 3 valores utilizando un lazo con la dirección base y un registro como desplazamiento. 
;     Pista: Idem anterior, pero ahora con una única instrucciones de lectura y $t2 se incrementa dentro de un loop 
; c) Calcular la suma de los 3 valores utilizando un lazo, con una dirección base de 0 y un registro como puntero. 
;     Pista: Cargar la dirección en un registro con daddi $t2, $zero, V  y luego cargar los valores con ld $t1, 0($t2) 
; d) ¿Qué cambios se deberían realizar al programa del inciso b) si los elementos fueran de 32 bits:
;     V: .word32 5, 2, 6?

; a) Suma sin loop
; .data
;     V:    .word 5, 2, 6        ; Vector de 3 elementos (8 bytes cada uno)
;     suma: .word 0              ; Resultado de la suma

; .code
;     ; Registro usado:
;     ; $t0 := V
;     ; $t1 := suma parcial
;     ; $t2 := desplazamiento

;     ; cargar el vector
;         ld $t0, V($zero)       ; $t0 = V[0]
;         ld $t1, suma($zero)    ; $t1 = 0 (inicializar suma)

;     dadd $t1, $t1, $t0         ; suma += V[0]
;     daddi $t2, $zero, 8        ; desplazamiento = 8 bytes

;     ld    $t0, V($t2)          ; $t0 = V[1]
;     dadd  $t1, $t1, $t0        ; suma += V[1]
;     daddi $t2, $t2, 8          ; desplazamiento = 16 bytes

;     ld   $t0, V($t2)           ; $t0 = V[2]
;     dadd $t1, $t1, $t0         ; suma += V[2]

;     sd $t1, suma($zero)        ; guardar resultado en suma
; halt

; b) Suma con loop y desplazamiento
; .data
;     V:    .word 5, 2, 6         ; Vector de 3 elementos (8 bytes cada uno)
;     suma: .word 0               ; Resultado de la suma
;     N:    .word 3               ; Número de elementos en el vector

; .code
;     ; Registro usado:
;     ; $t0 := V
;     ; $t1 := suma parcial
;     ; $t2 := desplazamiento
;     ; $t3 := contador

;     ; cargar el vector y N
;         ld $t1, suma($zero)     ; $t1 = 0 (inicializar suma)
;         ld $t3, N($zero)        ; $t3 = N (contador)
    
;     beqz $t3, guardar_suma      ; si contador == 0, saltar a guardar_suma
    
;     daddi $t2, $zero, 0         ; desplazamiento = 0

;     loop_suma:
;         ld    $t0, V($t2)       ; $t0 = V[i]
;         dadd  $t1, $t1, $t0     ; suma += V[i]
;         daddi $t2, $t2, 8       ; desplazamiento += 8 bytes
;         daddi $t3, $t3, -1      ; contador -= 1
;     bnez  $t3, loop_suma        ; si contador != 0, repetir el ciclo

;     guardar_suma:
;         sd $t1, suma($zero)     ; guardar resultado en suma
; halt

; .data
;     V:    .word 5, 2, 6         ; Vector de 3 elementos (8 bytes cada uno)
;     suma: .word 0               ; Resultado de la suma
;     N:    .word 3               ; Número de elementos en el vector

; .code
;     ; Registro usado:
;     ; $t0 := V
;     ; $t1 := suma parcial
;     ; $t2 := desplazamiento
;     ; $t3 := contador

;     ; cargar el vector y N
;         ld $t3, N($zero)        ; $t3 = N (contador)
;         ld $t1, suma($zero)     ; $t1 = 0 (inicializar suma)
    
;     beqz $t3, guardar_suma      ; si contador == 0, saltar a guardar_suma
    
;     daddi $t2, $zero, 0         ; desplazamiento = 0

;     loop_suma:
;         ld    $t0, V($t2)       ; $t0 = V[i]
;         daddi $t3, $t3, -1      ; contador -= 1
;         daddi $t2, $t2, 8       ; desplazamiento += 8 bytes
;         dadd  $t1, $t1, $t0     ; suma += V[i]
;     bnez  $t3, loop_suma        ; si contador != 0, repetir el ciclo

;     guardar_suma:
;         sd $t1, suma($zero)     ; guardar resultado en suma
; halt

; c) Suma con loop y puntero
; .data
;     V:    .word 5, 2, 6         ; Vector de 3 elementos (8 bytes cada uno)
;     N:    .word 3               ; Número de elementos en el vector
;     suma: .word 0               ; Resultado de la suma

; .code
;     ; Registro usado:
;     ; $t0 := valor actual
;     ; $t1 := suma parcial
;     ; $t2 := puntero
;     ; $t3 := contador

;     ; cargar el vector y N
;         ld    $t1, suma($zero)     ; $t1 = 0 (inicializar suma)
;         ld    $t3, N($zero)        ; $t3 = N (contador)
;         daddi $t2, $zero, V        ; puntero = dirección base de V
    
;     beqz $t3, guardar_suma      ; si contador == 0, saltar a guardar_suma

;     loop_suma:
;         ld    $t0, 0($t2)       ; $t0 = *puntero
;         dadd  $t1, $t1, $t0     ; suma += *puntero
;         daddi $t2, $t2, 8       ; puntero += 8 bytes
;         daddi $t3, $t3, -1      ; contador -= 1
;     bnez $t3, loop_suma         ; si contador != 0, repetir el ciclo

;     guardar_suma:
;         sd $t1, suma($zero)     ; guardar resultado en suma
; halt

.data
    V:    .word 5, 2, 6         ; Vector de 3 elementos (8 bytes cada uno)
    N:    .word 3               ; Número de elementos en el vector
    suma: .word 0               ; Resultado de la suma

.code
    ; Registro usado:
    ; $t0 := valor actual
    ; $t1 := suma parcial
    ; $t2 := puntero
    ; $t3 := contador

    ; cargar el vector y N
        ld    $t3, N($zero)        ; $t3 = N (contador)
        daddi $t2, $zero, V        ; puntero = dirección base de V
        ld    $t1, suma($zero)     ; $t1 = 0 (inicializar suma)
    
    beqz $t3, guardar_suma      ; si contador == 0, saltar a guardar_suma

    loop_suma:
        ld    $t0, 0($t2)       ; $t0 = *puntero
        daddi $t3, $t3, -1      ; contador -= 1
        daddi $t2, $t2, 8       ; puntero += 8 bytes
        dadd  $t1, $t1, $t0     ; suma += *puntero
    bnez $t3, loop_suma         ; si contador != 0, repetir el ciclo

    guardar_suma:
        sd $t1, suma($zero)     ; guardar resultado en suma
halt

; d) Cambios para elementos de 32 bits
; Si los elementos fueran de 32 bits (4 bytes), los cambios en el programa del inciso b) serían:
; - Cambiar la instrucción de carga de 'ld' a 'lw' para cargar palabras de 32 bits.
; - Cambiar el incremento del desplazamiento de 8 bytes a 4 bytes (daddi $t2, $t2, 4).

; Ejemplo de cambio en el loop_suma:
; loop_suma:
;     lw    $t0, V($t2)       ; $t0 = V[i] (cargar 32 bits)
;     add   $t1, $t1, $t0     ; suma += V[i]
;     daddi $t2, $t2, 4       ; desplazamiento += 4 bytes
;     daddi $t3, $t3, -1      ; contador -= 1
; bnez  $t3, loop_suma        ; si contador != 0, repetir el ciclo