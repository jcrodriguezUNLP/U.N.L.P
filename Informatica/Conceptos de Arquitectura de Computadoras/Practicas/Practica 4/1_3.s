; 3. Tipos de variables en WinMIPS64 ⭐  
 
; Indicar qué tamaño (en bytes) ocupan cada uno de estos tipos de datos del simulador WinMIPS64.
; En el caso en que dos tipos de datos tengan el mismo tamaño, explicar sus diferencias: 
 
; -------------------------------------------------------------------------------------------------------------
; NOTA: WinMIPS64 es MIPS64, por lo que el "word" nativo es 8 bytes. r0 = r0.
; -------------------------------------------------------------------------------------------------------------
; Tipo de dato | Tamaño en bytes | Uso
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------
; space 1      | 1               | Reserva un espacio de 1 byte en memoria. (La directiva .space N reserva N bytes).
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------
; ascii        | Variable        | Define una cadena de caracteres. Ocupa 1 byte por cada carácter. NO incluye terminador nulo.
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------
; asciiz       | Variable (+1)   | Define una cadena de caracteres terminada en nulo. Ocupa 1 byte por cada carácter + 1 byte para el '\0'.
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------
; byte         | 1               | Define y almacena un valor entero de 8 bits (1 byte).
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------
; word16       | 2               | Define y almacena un valor entero de 16 bits (media-palabra).
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------
; word32       | 4               | Define y almacena un valor entero de 32 bits (palabra tradicional MIPS).
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------
; word         | 8               | Define y almacena un valor entero de 64 bits (palabra nativa MIPS64).
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------
; double       | 8               | Define y almacena un valor de coma flotante de doble precisión (IEEE 754).
;--------------+-----------------+-------------------------------------------------------------------------------------------------------------