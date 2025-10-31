; Parte 2: Pila y Subrutinas.

; 1. Comprendiendo la primer subrutina: potencia ⭐

; Muchas instrucciones que normalmente forman parte del repertorio de un procesador con arquitectura CISC como PUSH y POP no existen en el MIPS64.
; En particular, el soporte para la invocación a subrutinas es más simple que el provisto en la arquitectura x86, y por eso tenemos que hacer algunos pasos extra para usarlas.
; El siguiente programa muestra un ejemplo de invocación a una subrutina llamada potencia:

.data
    base:      .word 5
    exponente: .word 4 
    result:    .word 0 
   
.code
    ; registros usados:
    ; $a0 := base
    ; $a1 := exponente
    ; $v0 := resultado

    ; cargar base y exponente
        ld    $a0, base($zero) 
        ld    $a1, exponente($zero) 
    
    ; llamar a subrutina potencia
        jal potencia 
    
    ; guardar resultado
        sd    $v0, result($zero) 
halt 
 
; subrutinas
potencia:
    daddi $v0, $zero, 1 
    
    lazo:
        beqz  $a1, retornar
        
        daddi $a1, $a1, -1 
        dmul  $v0, $v0, $a0 
    j lazo 

    retornar:
jr $ra 
 
; a)  ¿Qué hace el programa?
;     ¿Cómo está estructurado el código del mismo? 
; b)  ¿Qué acciones produce la instrucción jal?
;     ¿Y la instrucción jr? 
; c)  ¿Qué valor se almacena en el registro $ra?
;     ¿Qué función cumplen los registros $a0 y $a1?
;     ¿Y el registro $v0? 
;     ¿Qué valores posibles puede recibir en $a0 y $a1 la subrutina potencia? 
; d)  Supongamos que el WinMIPS no posee la instrucción dmul
;     ¿Qué sucede si la subrutina potencia necesita invocar a otra subrutina para realizar la multiplicación en lugar de usar la instrucción dmul?
;     ¿Cómo sabe cada una de las subrutinas a que dirección de memoria debe retornar? 
; e)  Escriba un programa que utilice potencia.
;     En el programa principal debe cargar desde memoria la base y el exponente (ambos enteros) y se deberá utilizar la subrutina potencia para calcular el resultado pedido.
;     Guarde el resultado en una variable llamada RES 
; f)  Escriba un programa que cargue de la memoria un exponente x y calcule 2^x + 3^x utilizando dos llamadas a potencia.
;     Guarde el resultado en la variable RES.
;     ¿Funciona correctamente?
;     Si no lo hace, revise su implementación del programa ¿Qué sucede cuando realiza una segunda llamada a potencia? Pista: Como caso de prueba, intente calcular 2^3 + 3^3 = 8 + 27 = 35

; respuestas:
; a) El programa calcula la potencia de un número (base^exponente).
;    El código está estructurado en una sección de datos donde se definen las variables base, exponente y result,
;    y una sección de código donde se carga la base y el exponente, se llama a la subrutina potencia y se almacena el resultado.
; b) La instrucción jal (jump and link) salta a la dirección de la subrutina y guarda la dirección de retorno en el registro $ra.
;    La instrucción jr (jump register) salta a la dirección almacenada en el registro $ra, retornando así a la instrucción siguiente a la llamada a la subrutina.
; c) El registro $ra almacena la dirección de retorno después de la llamada a la subrutina.
;    Los registros $a0 y $a1 se utilizan para pasar argumentos a la subrutina (base y exponente respectivamente).
;    El registro $v0 se utiliza para devolver el resultado de la subrutina (la potencia calculada).
;    Los valores posibles para $a0 y $a1 son enteros no negativos.
; d) Si la subrutina potencia necesita invocar a otra subrutina, el valor en $ra se sobrescribiría, perdiendo la dirección de retorno original.
;    Para manejar esto, se debe guardar el valor de $ra en la pila antes de la llamada a la segunda subrutina y restaurarlo después de que la segunda subrutina retorne.
; e) El programa ya está implementado en el código proporcionado.
; f) El programa no funcionará correctamente en su forma actual debido a que la segunda llamada a potencia sobrescribirá el valor en $v0.
;    Para solucionarlo, se debe guardar el resultado de la primera llamada a potencia en una variable temporal antes de hacer la segunda llamada.
