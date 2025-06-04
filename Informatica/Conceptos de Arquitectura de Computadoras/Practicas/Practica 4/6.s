; 6) Escribir un programa que lea tres números A, B y C de memoria
;    y determine cuántos de ellos son iguales.

.data
    A: .word 5
    B: .word 5
    C: .word 3
    count: .word 0  ; Contador de números iguales
.code
    ld r1, A(r0)       ; Carga A en r1
    ld r2, B(r0)       ; Carga B en r2
    ld r3, C(r0)       ; Carga C en r3
    dadd r4, r0, r0    ; r4 = 0 (contador de iguales)

    ; Compara A y B
    beq r1, r2, increment_count  ; Si A == B, incrementa el contador

    ; Compara A y C
    beq r1, r3, increment_count  ; Si A == C, incrementa el contador

    ; Compara B y C
    beq r2, r3, increment_count  ; Si B == C, incrementa el contador

    j end_program                ; Salta al final si no hay iguales

increment_count:
    dadd r4, r4, 1                ; Incrementa el contador
    j end_program

end_program:
    sd r4, count(r0)             ; Guarda el resultado en memoria
    halt                          ; Detiene la ejecución del programa
; El programa carga tres números de memoria, compara cada par de números
; y cuenta cuántos de ellos son iguales. El resultado se guarda en la variable 'count'.
; Dependiendo de los valores de A, B y C, el contador puede ser 0, 1, 2 o 3.
; Si A, B y C son iguales, el contador será 3.
; Si dos son iguales y uno diferente, el contador será 2.
; Si todos son diferentes, el contador será 0.
; Si A y B son iguales, pero C es diferente, el contador será 1.
; Si A y C son iguales, pero B es diferente, el contador será 1.
; Si B y C son iguales, pero A es diferente, el contador será 1.
; El programa utiliza instrucciones de carga y comparación para determinar la cantidad de números iguales.
; El resultado final se almacena en la dirección de memoria 'count'.
; El programa es eficiente y directo, utilizando un enfoque de comparación simple.
; El uso de instrucciones de salto y comparación permite determinar rápidamente cuántos números son iguales.
; El contador se incrementa solo cuando se encuentra una igualdad, lo que optimiza el flujo del programa.
; El programa finaliza guardando el resultado en memoria y deteniendo la ejecución.