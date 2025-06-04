; 2) Intercambio de valores de memoria

; a) Ejecutar sin Forwarding. Analizar:
;    - ¿Qué instrucción genera atascos (stalls) y por qué?
;      Las instrucciones que generan atascos son las que dependen de los resultados de las cargas previas (ld). 
;      Por ejemplo, después de `ld r1, A(r0)`, la instrucción `sd r1, B(r0)` necesita el valor de r1, pero este aún no está disponible 
;      hasta que la carga se complete. Esto genera un 'stall' para esperar el dato.

;    - ¿Qué tipo de ‘stall’ aparece?
;      Aparece un 'stall' de tipo RAW (Read After Write), es decir, dependencia de datos.

;    - ¿CPI promedio en esta configuración?
;      El CPI promedio aumenta debido a los ciclos de espera (stalls). Por ejemplo, si hay 2 stalls, el CPI puede ser mayor a 1 (por ejemplo, 1.5 o 2).

; b) Ejecutar con Forwarding. Analizar:
;    - ¿Por qué ya no hay atascos? Explicar.
;      Con forwarding, los resultados de las instrucciones se pueden pasar directamente a las siguientes etapas del pipeline, 
;      evitando la espera por la escritura en el registro. Así, las instrucciones dependientes pueden ejecutarse sin stalls.

;    - ¿Qué indica el color de los registros en la ventana Register?
;      El color indica el estado de los registros: si están siendo escritos, leídos, o si hay forwarding activo.
;      Por ejemplo, si un registro está en verde, significa que está listo para ser leído o escrito sin esperar.

;    - ¿CPI promedio ahora? Comparar con anterior.
;      El CPI promedio disminuye, acercándose a 1, ya que se eliminan los stalls por dependencias de datos.

.data
    A: .word 1
    B: .word 2
.code
    ld r1, A(r0)      ; Carga en r1 el valor almacenado en la dirección de memoria A
    ld r2, B(r0)      ; Carga en r2 el valor almacenado en la dirección de memoria B
    sd r2, A(r0)      ; Guarda el valor de r2 (originalmente B) en la dirección de memoria A
    sd r1, B(r0)      ; Guarda el valor de r1 (originalmente A) en la dirección de memoria B
halt        ; Detiene la ejecución del programa

; ------------------------------------------------------------
; reordenado para evitar RAW con forwarding
.data
    A: .word 1
    B: .word 2
.code
    ld r1, A(r0)      ; Carga en r1 el valor almacenado en la dirección de memoria A
    ld r2, B(r0)      ; Carga en r2 el valor almacenado en la dirección de memoria B
    sd r1, B(r0)      ; Guarda el valor de r1 (originalmente A) en la dirección de memoria B
    sd r2, A(r0)      ; Guarda el valor de r2 (originalmente B) en la dirección de memoria A
halt        ; Detiene la ejecución del programa

; En este caso conviene invertir el orden de los sd porque así se reduce la dependencia directa entre las instrucciones de almacenamiento y las de carga previas. 
; Si primero hacemos `sd r1, B(r0)` y luego `sd r2, A(r0)`, la instrucción `sd r1, B(r0)` depende inmediatamente de la carga previa de r1, generando un stall si no hay forwarding. 
; Al invertir el orden y hacer primero `sd r2, A(r0)`, se da más tiempo para que la carga de r1 termine antes de que se necesite su valor para el almacenamiento en B, 
; lo que puede reducir o eliminar los stalls en arquitecturas sin forwarding.