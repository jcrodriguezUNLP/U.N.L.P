; PRACTICA 5 - Procesador RISC: instrucciones de Punto Flotante y pasaje de parámetros
; Objetivos: Familiarizarse con las instrucciones de MIPS64 para manejar datos en formato de Punto Flotante.
; Familiarizarse con los conceptos que rodean a la escritura de subrutinas en una arquitectura RISC:
; Uso normalizado de los registros, pasaje de parámetros y retorno de resultados, generación y manejo de la pila y anidamiento de subrutinas.

; 8) Escriba una subrutina que reciba como parámetros las direcciones del comienzo de dos cadenas terminadas en cero y
;    retorne la posición en la que las dos cadenas difieren. En caso de que las dos cadenas sean idénticas, debe retornar -1.
;
; 9) El siguiente programa espera usar una subrutina que calcule en forma recursiva el factorial de un número entero:
;
; .data
; valor: .word 10
; result: .word 0
;
; .text
; daddi $sp, $0, 0x400 ; Inicializa el puntero al tope de la pila (1)
; ld    $a0, valor($0)
; jal   factorial
; sd    $v0, result($0)
; halt
;
; factorial: ...
; ...
; ...
; (1) La configuración inicial de la arquitectura del WinMIPS64 establece que el procesador posee un bus de direcciones de 10 bits
;     para la memoria de datos. Por lo tanto, la mayor dirección dentro de la memoria de datos será de 2^10 = 1024 = 40016.
;
; a) Implemente la subrutina factorial definida en forma recursiva.
; b) ¿Es posible escribir la subrutina factorial sin utilizar una pila? Justifique.