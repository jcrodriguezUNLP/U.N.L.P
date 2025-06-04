; 5) El procesador MIPS64 posee 32 registros, de 64 bits cada uno, llamados r0 a r31 ($0 a $31).
;    La siguiente tabla muestra la convención empleada para nombrar a los 32 registros mencionados:
;    r0 $zero
;    r1 $at
;    r2-r3 $v0-$v1
;    r4-r7 $a0-$a3
;    r8-r15 $t0-$t7
;    r16-r23 $s0-$s7
;    r24-r25 $t8-$t9
;    r26-r27 $k0-$k1
;    r28 $gp
;    r29 $sp
;    r30 $fp
;    r31 $ra
;    Complete la tabla anterior explicando el uso que normalmente se le da cada uno de los registros nombrados.
;    Marque en la columna “¿Preservado?” si el valor de cada grupo de registros debe ser preservado luego de realizada una llamada a una subrutina.

; -------------------------------------------------------------------------------
; Registro   Nombre    Uso habitual                                  ¿Preservado?
; -------------------------------------------------------------------------------
; r0         $zero     Siempre contiene 0                            No
; r1         $at       Reservado para el ensamblador                 No
; r2-r3      $v0-$v1   Valores de retorno de funciones               No
; r4-r7      $a0-$a3   Argumentos para funciones/subrutinas          No
; r8-r15     $t0-$t7   Temporales, uso general                       No
; r16-r23    $s0-$s7   Salvados, variables locales                   Sí
; r24-r25    $t8-$t9   Temporales, uso general                       No
; r26-r27    $k0-$k1   Reservados para el sistema operativo          No
; r28        $gp       Puntero a datos globales                      No
; r29        $sp       Puntero de pila (stack pointer)               Sí
; r30        $fp       Puntero de marco (frame pointer)              Sí
; r31        $ra       Dirección de retorno de subrutinas            No
; -------------------------------------------------------------------------------
; "¿Preservado?" indica si el valor debe mantenerse tras una llamada a subrutina.
