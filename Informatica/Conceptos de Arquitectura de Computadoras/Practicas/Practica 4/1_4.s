; 4. Registros del MIPS64 ⭐.  
; El procesador MIPS64 posee 32 registros, de 64 bits cada uno, llamados r0 a r31 (también conocidos como $0 a $31). 
; Sin embargo, al programar resulta más conveniente darles nombres más significativos a esos registros. 
; La siguiente tabla muestra la convención empleada para nombrar a los 32 registros mencionados: 
 
; Registros | Nombres | ¿Para qué se los utiliza?                                                      | ¿Preservado?
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r0        | $zero   | Contiene el valor **cero constante (0)**.                                      | No
;           |         | Ignora cualquier intento de escritura.                                         | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r1        | $at     | **Reservado para el Ensamblador**.                                             | No
;           |         | Usado para expandir pseudo-instrucciones a varias instrucciones reales.        | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r2-r3     | $v0-$v1 | **Valores de Retorno de Funciones**.                                           | No
;           |         | Resultados (hasta dos) de una función o códigos de *syscall*.                  | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r4-r7     | $a0-$a3 | **Argumentos de Funciones**.                                                   | No
;           |         | Utilizados para pasar los primeros cuatro argumentos a una subrutina.          | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r8-r15    | $t0-$t7 | **Temporales** (Caller-Saved).                                                 | No
;           |         | Almacenan valores temporales. El **llamador** debe guardarlos si los necesita. |
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r16-r23   | $s0-$s7 | **Guardados** (Callee-Saved).                                                  | Sí
;           |         | Almacenan valores que deben persistir.                                         |
;           |         | La **función llamada** debe guardarlos/restaurarlos.                           |
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r24-r25   | $t8-$t9 | **Temporales** (Caller-Saved).                                                 | No
;           |         | Almacenan valores temporales.                                                  |
;           |         | El **llamador** debe guardarlos si los necesita.                               | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r26-r27   | $k0-$k1 | **Reservado para el Sistema Operativo/Núcleo (Kernel)**.                       | Sí
;           |         | Usados para el manejo de excepciones e interrupciones.                         | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r28       | $gp     | **Puntero Global**.                                                            | Sí
;           |         | Utilizado para acceder eficientemente a variables globales estáticas.          | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r29       | $sp     | **Puntero de Pila (Stack Pointer)**.                                           | Sí
;           |         | Gestiona el tope de la pila de llamadas.                                       | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r30       | $fp/$s8 | **Puntero de Marco (Frame Pointer)** o registro guardado adicional.            | Sí
;           |         | Usado para acceder a variables locales.                                        | 
;-----------+---------+--------------------------------------------------------------------------------+---------------
; r31       | $ra     | **Dirección de Retorno (Return Address)**.                                     | No
;           |         | Almacena la dirección a donde debe volver el control (`jal`).                  | 
;-----------+---------+--------------------------------------------------------------------------------+---------------

; Complete  la  tabla  anterior  explicando  el  uso  que  normalmente  se  le  da  a cada uno de los registros nombrados. 
; Marque en la columna “¿Preservado?” si el valor de cada grupo de registros debe ser preservado luego de realizada 
; una llamada a una subrutina. Puede encontrar información útil en el apunte “Programando sobre MIPS64”.