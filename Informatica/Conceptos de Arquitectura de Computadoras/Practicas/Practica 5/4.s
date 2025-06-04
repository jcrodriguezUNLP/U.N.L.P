; 4) Programa para calcular el Índice de Masa Corporal (IMC) y clasificar el estado nutricional según el valor calculado.
;    IMC = peso / (altura^2)
;    Clasificación:
;      IMC <  18.5  -> Infrapeso   (estado = 1)
;      IMC <  25    -> Normal      (estado = 2)
;      IMC <  30    -> Sobrepeso   (estado = 3)
;      30  <= IMC   -> Obeso       (estado = 4)

.data
    peso:     .double 70.0          ; Peso en kg
    altura:   .double  1.75         ; Altura en metros
    IMC:      .double  0.0          ; Espacio para almacenar el IMC calculado
    lim18_5:  .double 18.5          ; Límite inferior para "Normal"
    lim25:    .double 25.0          ; Límite inferior para "Sobrepeso"
    lim30:    .double 30.0          ; Límite inferior para "Obeso"
    estado:   .word   0             ; Espacio para almacenar el estado nutricional

.code
    ; Cargar peso y altura
    l.d   f1, peso(r0)              ; f1 = peso
    l.d   f2, altura(r0)            ; f2 = altura

    ; Calcular altura^2
    mul.d f3, f2, f2                ; f3 = altura * altura

    ; Calcular IMC = peso / (altura^2)
    div.d f4, f1, f3                ; f4 = IMC

    ; Guardar IMC en memoria
    s.d   f4, IMC(r0)

    ; Cargar límites para comparación
    l.d   f10, lim18_5(r0)          ; f10 = 18.5
    l.d   f11, lim25(r0)            ; f11 = 25.0
    l.d   f12, lim30(r0)            ; f12 = 30.0

    ; Clasificación del IMC
    ; Si IMC < 18.5 -> Infrapeso
    c.lt.d f4, f10                  ; ¿IMC < 18.5?
    bc1t  infrapeso

    ; Si IMC < 25 -> Normal
    c.lt.d f4, f11                  ; ¿IMC < 25?
    bc1t  normal

    ; Si IMC < 30 -> Sobrepeso
    c.lt.d f4, f12                  ; ¿IMC < 30?
    bc1t  sobrepeso

    ; Si 30 <= IMC -> Obeso
    j     obeso

infrapeso:
    daddi $t0, $zero, 1         ; Pone 1 en $t0 (1 = Infrapeso)
    sw    $t0, estado(r0)       ; Guarda 1 en la variable 'estado'
    j     fin                   ; Salta al final del programa

normal:
    daddi $t0, $zero, 2         ; Pone 2 en $t0 (2 = Normal)
    sw    $t0, estado(r0)       ; Guarda 2 en la variable 'estado'
    j     fin                   ; Salta al final del programa

sobrepeso:
    daddi $t0, $zero, 3         ; Pone 3 en $t0 (3 = Sobrepeso)
    sw    $t0, estado(r0)       ; Guarda 3 en la variable 'estado'
    j     fin                   ; Salta al final del programa

obeso:
    daddi $t0, $zero, 4         ; Pone 4 en $t0 (4 = Obeso)
    sw    $t0, estado(r0)       ; Guarda 4 en la variable 'estado'

fin:
    halt


; ---------------------------------------------------------------
; RESUMEN DE TIPOS DE REGISTROS EN MIPS
; ---------------------------------------------------------------
; 1. Registros de propósito general (enteros):
;    $zero (r0)   : Siempre contiene 0
;    $at (r1)     : Reservado para el ensamblador
;    $v0-$v1      : Valores de retorno de funciones
;    $a0-$a3      : Argumentos para funciones
;    $t0-$t9      : Temporales (no preservados entre subrutinas)
;    $s0-$s7      : Salvados (preservados entre subrutinas)
;    $k0-$k1      : Uso del sistema operativo
;    $gp          : Puntero global
;    $sp          : Puntero de pila (stack pointer)
;    $fp          : Puntero de marco (frame pointer)
;    $ra          : Dirección de retorno de subrutinas
;
; 2. Registros de punto flotante:
;    f0-f31       : Para operaciones en coma flotante (float/double)
;
; 3. Registros especiales:
;    HI y LO      : Resultados de multiplicación y división
;    PC           : Contador de programa (no accesible directamente)
; ---------------------------------------------------------------