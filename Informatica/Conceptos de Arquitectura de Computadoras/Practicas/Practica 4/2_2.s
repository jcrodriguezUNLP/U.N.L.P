; 2. Salvado de registros ⭐  
; Los siguientes programas tienen errores en el uso de la convención de registros.
; Indicar en qué registros, cuál es el error y cómo se podría arreglar el problema en cada caso. 
 
; A)

.code   
    daddi $t0, $0, 5    ; base
    daddi $t1, $0, 7    ; exponente
    
    jal subrutina       ; llamar a subrutina

    sd $t2, variable($0)  ; guardar resultado
halt 
 
subrutina:
    daddi $t4, $0,  2   ; base de la primera potencia
    dmul  $t0, $t0, $t4 ; primera potencia
    dmul  $t1, $t1, $t4 ; segunda potencia
    dadd  $t2, $t1, $t0 ; suma de potencias
jr $ra 

; B) 

; .code 
;       daddi $a0, $0, tabla 
;       jal subrutina 
;       daddi $t0, $0, 10 
;       daddi $t1, $0, 0 
; loop: bnez $t0, fin 
;       ld $t2, 0($a0) 
;       dadd $t1, $t1, $t2 
;       daddi $t0, $t0, -1 
;       daddi $a0, $a0, 8 
;       j loop 
; fin: halt 
 
              
;                                                                                                                                   4/8 
; Arquitectura de Computadoras                                                                                                                                                2025 
; C) 
; .code 
; daddi $a0, $0, 5 
; daddi $a1, $0, 7  
; jal subrutina 
; dmul $t2, $a0, $v0 
; sd $t2, variable ($0) 
; halt 
; D) 
; .code 
;       daddi $t0, $0, 10 # dimension 
;       daddi $t1, $0, 0 # contador 
;       daddi $t2, $0, 0 # desplazamiento 
; loop: bnez $t0, fin 
;       ld $a0, tabla ($t2) 
;       jal espar 
;       bnez $v0, seguir  
;       dadd1 $t1, $t1, 1 
;  seguir:daddi $t2, $t2, 1 
;       daddi $t0, $t0, -1 
;       daddi $t2, $t2, 8 
;       j loop 
;         sd $t1, resultado($0) 
; fin: halt