; Registros No Preservados (Caller-Saved)

; | Nombre            | Nombres de Registro | Rango            | Uso Principal                                                                  | Preservación |
; | :---------------- | :------------------ | :--------------- | :----------------------------------------------------------------------------- | :----------- |
; | Cero              | $zero               | r0               | Siempre mantiene el valor **0**.                                               | N/A          |
; | Ensamblador       | $at                 | r1               | Reservado para el ensamblador para pseudo-instrucciones.                       | No           |
; | Valores (Retorno) | $v0-$v1             | r2-r3            | Almacenan los **valores de retorno** de las funciones.                         | No           |
; | Argumentos        | $a0-$a3             | r4-r7            | Se usan para pasar los **primeros cuatro argumentos** a una subrutina.         | No           |
; | Temporales        | $t0-$t9             | r8-r15, r24-r25  | Se usan para valores temporales que **no** necesitan sobrevivir a una llamada. | No           |
; | Retorno           | $ra                 | r31              | Almacena la **dirección de retorno** (`PC + 4`) después de un `jal`.           | No           |


; Registros Preservados (Callee-Saved)

; | Nombre           | Nombres de Registro | Rango   | Uso Principal                                                                         | Preservación |
; | :--------------- | :------------------ | :------ | :------------------------------------------------------------------------------------ | :----------- |
; | Guardados        | $s0-$s7             | r16-r23 | Se usan para variables de programa a largo plazo que **deben ser preservadas**.       | Sí           |
; | Kernel           | $k0-$k1             | r26-r27 | Reservados para el **Sistema Operativo** (manejo de interrupciones).                  | Sí           |
; | Puntero Global   | $gp$                | r28     | Puntero a la sección de datos globales.                                               | Sí           |
; | Puntero de Pila  | $sp$                | r29     | **Puntero de pila (Stack Pointer).** Apunta al tope de la pila.                       | Sí           |
; | Puntero de Marco | $fp$ / $s8$         | r30     | Puntero de marco (Frame Pointer). Se usa para acceder a variables locales en la pila. | Sí           |