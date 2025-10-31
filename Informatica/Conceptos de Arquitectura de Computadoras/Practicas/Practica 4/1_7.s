; 7.
; Codificación de Strings⭐ 
 
; a) Strings en memoria:
;    En WinMIPS los strings se almacenan como vectores de caracteres.
;    Observar cómo se almacenan en memoria los códigos ASCII de los caracteres (código de la letra “a” es 61H).
;    Además, los strings se suelen terminar con un carácter de fin con código 0, es decir el valor 0.
;    Para definir un string en una variable y no tener que agregar a mano el valor 0, se puede utilizar el tipo de datos asciiz.
;    Si en lugar de eso se utiliza el tipo ascii (sin la z) no se agrega el 0 de forma automática.
;    Probar estas definiciones en el simulador y observar cómo se organizan en la memoria las variables.

;    .data
;        cadena:  .asciiz "ABCdef1"
;        cadena2: .ascii  "ABCdef11"
;        cadena3: .asciiz "ABCdef1111111"
;        num:     .word   5

; b) Lectura de caracteres:
;    lbu vs lb vs ld: En un string, cada código ASCII ocupa 1 byte.
;    No obstante, los registros del simulador tienen 8 bytes (64 bits) de capacidad.
;    Por ende, al cargar un byte en un registro, se desperdician 7 bytes de espacio (esta ineficiencia es inevitable).
;    Más allá de eso, esta diferencia nos trae otra dificultad.
;    Cuando se carga un valor de memoria, no se puede utilizar ld, porque ello traería 8 caracteres (8 bytes) al registro, y sería muy difícil hacer operaciones sobre los caracteres individuales.
;    Por ello, existen instrucciones para traer solo un byte desde la memoria: lbu y lb.
;    ¿Cuál es la diferencia? 
;    - lbu asume que el valor que se trae está codificado en BSS y entonces rellena los últimos 7 bytes con 0.
;    - lb asume que el valor que se trae de memoria está codificado en CA2, y entonces si el número es negativo realiza la expansión de signo.
;    ¿De qué trata esto?
;    Para que el número siga valiendo lo mismo en CA2 de 8 bytes, se rellenan los últimos 7 bytes con 1.
     
;    Para probar la diferencia entre estas 3 instrucciones, ejecutar el siguiente programa en el simulador que intenta cargar el primer valor del vector de números datos y observar los valores finales de $t1, $t2 y $t3.
     
;    .data 
;        datos: .byte -2, 2, 2, 2, 2, 2 

;    .code 
;        ld  $t1, datos($zero) 
;        lb  $t2, datos($zero) 
;        lbu $t3, datos($zero) 
;    halt 
 
; Responde: 
;    a) ¿Qué registro tiene el valor “correcto” del primer valor? 
;    b) ¿Qué instrucción deberías utilizar de las 3 para cargar un código ASCII que siempre es positivo?
;       Tené en cuenta que, por ejemplo, el código ASCII de la Á es 181, que en BSS se escribe como 10110101

; ------------------------------------------------------------------------------------------------
; MI RESPUESTA:
; ------------------------------------------------------------------------------------------------

; RESUMEN DE LA CONSIGNAS (PRÁCTICA DE LABORATORIO):
;
; La práctica explica cómo se manejan datos de 1 byte (caracteres ASCII) en la arquitectura MIPS64
; que utiliza registros de 8 bytes (64 bits).
;
; ------------------------------------------------------------------------------------------------
; A) STRINGS EN MEMORIA (.asciiz vs .ascii):
;
; CONCEPTO: Los strings se almacenan como vectores de códigos ASCII de 1 byte.
; - .asciiz: Define una cadena y **AGREGA AUTOMÁTICAMENTE** un byte nulo (00H) al final. 
;            Esto es crucial para delimitar el fin de la cadena.
; - .ascii: Define una cadena, pero **NO AGREGA** el byte nulo final.
;
; TAREA: Observar en el simulador cómo se almacenan las cadenas y verificar la presencia del 00H.
; ------------------------------------------------------------------------------------------------
; B) LECTURA DE CARACTERES (ld vs lb vs lbu):
;
; CONCEPTO: Los registros son de 64 bits, pero los caracteres son de 8 bits. La forma en que
;           el bit más significativo (MSB) se extiende a los 56 bits superiores es vital.
;
; INSTRUCCIONES DE CARGA:
;
; | Instrucción | Bytes leídos | Propósito              | Extensión de 64 bits                                             |
; | :---------- | :----------- | :--------------------- | :--------------------------------------------------------------- |
; | ld          | 8 bytes      | Carga Doble Palabra.   | No aplica (carga 8 bytes completos)                              |
; | lb          | 1 byte       | Load Byte (CON SIGNO). | Expansión de **SIGNO** (rellena con 1s si el valor es negativo). |
; | lbu         | 1 byte       | Load Byte (SIN SIGNO). | Expansión por **CERO** (rellena los 7 bytes superiores con 0s).  |
;
; ------------------------------------------------------------------------------------------------
; PREGUNTAS A RESPONDER (BASADAS EN EL PROGRAMA DE PRUEBA: datos: .byte -2, 2, 2, 2, 2, 2):
;
; a) ¿Qué registro tiene el valor "correcto" del primer valor? 
;    -> El valor a cargar es -2 (negativo).
;    -> La instrucción que **preserva el valor con signo** de un byte en un registro de 64 bits es **lb**.
;
; b) ¿Qué instrucción deberías utilizar de las 3 para cargar un código ASCII que siempre es positivo?
;    -> Los códigos ASCII son valores **positivos** (sin signo).
;    -> La instrucción que rellena los bits superiores con ceros es **lbu**.
; ------------------------------------------------------------------------------------------------