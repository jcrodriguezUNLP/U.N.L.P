; 3) Escribir un programa que calcule la superficie de un triángulo rectángulo de base 5,85 cm y altura 13,47 cm.
;    Pista: la superficie de un triángulo se calcula como: Superficie = (base x altura) / 2

.data
    base:       .double 5.85           ; Define la base del triángulo (5.85)
    altura:     .double 13.47          ; Define la altura del triángulo (13.47)
    superficie: .double 0.0        ; Reserva espacio para el resultado (superficie)
    dos:        .double 2.0               ; Define el valor 2.0 para la división

.code
    l.d   f1, base(r0)             ; Carga la base en el registro f1
    l.d   f2, altura(r0)           ; Carga la altura en el registro f2
    
    mul.d f3, f1, f2               ; Multiplica base por altura, resultado en f3
    
    l.d   f5, dos(r0)              ; Carga el valor 2.0 en el registro f5

    div.d f4, f3, f5               ; Divide (base*altura) por 2, resultado en f4

    s.d   f4, superficie(r0)       ; Guarda el resultado (superficie) en memoria

halt                               ; Finaliza el programa