// Números naturales y enteros en C: 
// a. ¿Qué tipos de datos pueden usarse para representar enteros en C?
//      Los tipos de datos básicos para representar enteros en C son:
//          - char: Aunque es para caracteres, también puede usarse para enteros pequeños 
//          - short (o short int): Enteros cortos
//          - int: Enteros estándar
//          - long (o long int): Enteros largos
//          - long long (o long long int): Enteros muy largos (C99 en adelante)
//
// b. ¿Qué modificadores pueden utilizarse con estos tipos?
//
//    RESPUESTA:
//    Los modificadores que pueden usarse con tipos enteros son:
//    - signed: Permite valores positivos y negativos (por defecto en la mayoría)
//    - unsigned: Solo permite valores positivos (0 y números positivos)
//    
//    Estos modificadores se pueden combinar con todos los tipos enteros:
//    signed char, unsigned char, signed short, unsigned short, etc.
//
// c. Para cada combinación de tipo y modificadores indique el tamaño en bytes que ocupa, el sistema de representación binario y el rango del mismo.
//
//    RESPUESTA:
//    Tabla de tipos enteros (tamaños típicos en sistemas de 32/64 bits):
//
//    TIPO               | BYTES | REPRESENTACIÓN  | RANGO
//    -------------------|-------|-----------------|--------------------------------------------------------
//    char               |   1   | Complemento a 2 | -128 a 127
//    unsigned char      |   1   | Binario natural | 0 a 255
//    short              |   2   | Complemento a 2 | -32,768 a 32,767
//    unsigned short     |   2   | Binario natural | 0 a 65,535
//    int                |   4   | Complemento a 2 | -2,147,483,648 a 2,147,483,647
//    unsigned int       |   4   | Binario natural | 0 a 4,294,967,295
//    long               |   4   | Complemento a 2 | Depende del sistema*
//    unsigned long      |   4   | Binario natural | Depende del sistema*
//    long long          |   8   | Complemento a 2 | -9,223,372,036,854,775,808 a 9,223,372,036,854,775,807
//    unsigned long long |   8   | Binario natural | 0 a 18,446,744,073,709,551,615
//
//    * long: 4 bytes en sistemas de 32 bits, 8 bytes en sistemas de 64 bits
//
//    SISTEMAS DE REPRESENTACIÓN:
//    - Complemento a 2: Para números con signo. El bit más significativo indica el signo.
//    - Binario natural: Para números sin signo. Todos los bits representan magnitud.