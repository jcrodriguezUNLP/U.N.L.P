; 5. Programas simples ⭐⭐.  
 
; Escribir un programa en WinMIPS64 que:  
; a) Lee 2 números A y B de la memoria de datos a registros, y calcula S, P y D, que luego se guardan en la memoria de datos. 
; b) Dadas dos variables A y B de la memoria, calcula y almacena C 
; c) Calcula el factorial de N, y lo guarda en F 
; d) Calcula el logaritmo (entero) en base 2 de N (N positivo) mediante divisiones sucesivas y lo guarda en L 
; e) Guarda en B el valor 1 si A es impar y 0 de lo contrario 

; Los nombres de variables como A, B, C, etc, deben implementarse usando variables de tipo word a las cuales se lee y escribe de memoria con ld y sd. 
 
; a)
; S = A + B 
; P = 2 + (A*B) 
; D = A^2 / B 

; .data
;     A: .word 10          ; ejemplo: valor de A
;     B: .word 3           ; ejemplo: valor de B
;     S: .word 0           ; S = A + B (resultado)
;     P: .word 0           ; P = 2 + (A * B) (resultado)
;     D: .word 0           ; D = A^2 / B (resultado o A^2 si B==0)

; .code
;     ; Registro usado:
;     ; $t0 := A
;     ; $t1 := B
;     ; $t2 := S
;     ; $t3 := P
;     ; $t4 := D

;     ; cargar A y B desde memoria a registros
;         ld $t0, A($zero)    ; $t0 = A
;         ld $t1, B($zero)    ; $t1 = B

;     ; S = A + B
;         dadd $t2, $t0, $t1  ; $t2 = A + B (operación 64-bit)
;         sd   $t2, S($zero)  ; S <- $t2

;     ; P = 2 + (A * B)
;         dmul  $t3, $t0, $t1 ; $t3 = A * B (64-bit)
;         daddi $t3, $t3, 2   ; $t3 = (A*B) + 2
;         sd    $t3, P($zero) ; P <- $t3

;     ; D = A^2 / B  (si B == 0 se evita la división)
;         dmul $t4, $t0, $t0  ; $t4 = A^2

;         ; Si B == 0: saltar a guardarD (evita ddiv por cero)
;         beqz $t1, guardarD

;         ddiv $t4, $t4, $t1  ; $t4 = A^2 / B

;         guardarD:
;             sd $t4, D($zero) ; D <- $t4 (si B==0 guarda A^2, sino el cociente)
; halt

; b)
; if A == 0: 
;      C = 0 
; else: 
;      if B < A: 
;          C = A * 2  
;     else: 
;          C = B 

; .data
;     A: .word 10          ; ejemplo: valor de A
;     B: .word 3           ; ejemplo: valor de B
;     C: .word 0           ; C = resultado de la operación

; .code
;     ; Registro usado:
;     ; $t0 := A
;     ; $t1 := B
;     ; $t2 := C
;     ; $t3 := temporal

;     ; cargar A y B desde memoria a registros
;         ld $t0, A($zero)    ; $t0 = A
;         ld $t1, B($zero)    ; $t1 = B

;     beqz $t0, A_es_cero    ; si A == 0, saltar a A_es_cero

;     slt  $t3, $t1, $t0        ; si B < A, $t3 = 1; else $t3 = 0
;     bnez $t3, A_mayor_B      ; si $t3 != 0 (B < A), saltar a A_mayor_B

;     dadd $t2, $t1, $zero     ; C = B
;     j guardarC

;     A_mayor_B:
;         dsll $t2, $t0, 1      ; C = A * 2 (desplazar A a la izquierda 1 bit)
;         j guardarC
    
;     A_es_cero:
;         dadd $t2, $zero, $zero ; C = 0

;     guardarC:
;         sd $t2, C($zero)      ; guardar C en memoria
; halt

; c)
; F = 1 
; for i=1..N: 
;   F = F * i

; .data
;     N: .word 9           ; ejemplo: valor de N
;     F: .word 1           ; F = resultado del factorial

; .code
;     ; Registro usado:
;     ; $t0 := N
;     ; $t1 := F

;     ; cargar N desde memoria a registro
;         ld $t0, N($zero)     ; $t0 = N
;         ld $t1, F($zero)     ; $t1 = F

;     beqz $t0, guardarFactorial ; si N == 0, saltar a guardarFactorial
    
;     loopFactorial:
;         dmul $t1, $t1, $t0   ; F = F * i
    
;         daddi $t0, $t0, -1    ; i = i - 1
;     bnez $t0, loopFactorial ; si i != 0, repetir el ciclo

;     guardarFactorial:
;         sd $t1, F($zero)      ; guardar F en memoria
; halt

; d)
; L = 0 
; while 1 < N: 
;    N = N / 2 
;    L = L + 1

.data
    N: .word 64          ; ejemplo: valor de N
    L: .word 0           ; L = resultado del logaritmo

.code
    ; Registro usado:
    ; $t0 := N
    ; $t1 := L
    ; $t2 := temporal

    ; cargar N desde memoria a registro
        ld $t0, N($zero)     ; $t0 = N
        ld $t1, L($zero)     ; $t1 = L

    daddi $t2, $zero, 1   ; valor constante 1
    
    slt $t2, $t2, $t0      ; si 1 < N, $t2 = 1; else $t2 = 0
    beqz $t2, guardarLogaritmo ; si N <= 1, salir del ciclo
    
    loopLogaritmo:
        dsrl  $t0, $t0, 1       ; N = N / 2 (desplazar N a la derecha 1 bit)
        daddi $t1, $t1, 1      ; L = L + 1

        slt $t2, $t2, $t0      ; si 1 < N, $t2 = 1; else $t2 = 0
    bnez $t2, loopLogaritmo    ; si 1 < N, repetir el ciclo

    guardarLogaritmo:
        sd $t1, L($zero)      ; guardar L en memoria
halt

; e)
; if impar(A): 
;    B = 1 
; else: 
;    B = 0

; .data
;     A: .word 7           ; ejemplo: valor de A
;     B: .word 0           ; B = resultado (1 si A es impar, 0 si es par)

; .code
;     ; Registro usado:
;     ; $t0 := A
;     ; $t1 := B
;     ; $t2 := temporal

;     ; cargar A desde memoria a registro
;         ld $t0, A($zero)     ; $t0 = A

;     andi $t2, $t0, 1        ; $t2 = A & 1 (si A es impar, $t2 = 1; si es par, $t2 = 0)

;     ; guardar el resultado en B
;         sd $t2, B($zero)      ; B <- $t2
; halt