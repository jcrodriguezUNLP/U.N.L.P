; 1 Operaciones con strings ⭐ 
 
; a)
;     Longitud de un string Escribir un programa que cuente la longitud de un string iterando el mismo hasta llegar al valor 0 y guarde el resultado en una variable llamada LONGITUD.
;     Probarlo con el string “ArquiTectuRa de ComPutaDoras”.

; b)
;     Contar apariciones de carácter Escribir un programa que cuente la cantidad de veces que un determinado carácter aparece en una cadena de texto.

.data
    cadena: .asciiz "adbdcdedfdgdhdid"  ; cadena a analizar
    car:    .ascii "d"                  ; carácter buscado
    cant:   .word 0                     ; cantidad de veces que se repite el carácter car en cadena

; c)
;     Contar mayúsculas Escribir un programa que cuente la cantidad de letras mayúsculas de un string.
;     Probarlo con el string “ArquiTectuRa de ComPutaDoras”.
    
;     Pista: El código ASCII de la “A” es 65, y el de la “Z” es 90.

; d)
;     Generar string Escribir un programa que genere un string de la siguiente forma:
;     “abbcccddddeeeee....”, así hasta la letra “h”.

;     Para ello debe utilizar un loop e ir guardando los códigos ascii en la memoria.
;     El string debe finalizar con el valor ascii 0 para que esté bien formado (debe agregar un elemento más, que valga 0, al final del string).
